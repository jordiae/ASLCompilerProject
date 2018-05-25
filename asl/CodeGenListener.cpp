//////////////////////////////////////////////////////////////////////
//
//    CodeGenListener - Walk the parser tree to do
//                             the generation of code
//
//    Copyright (C) 2018  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "CodeGenListener.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
CodeGenListener::CodeGenListener(TypesMgr       & Types,
				 SymTable       & Symbols,
				 TreeDecoration & Decorations,
				 code           & Code) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Code{Code} {
}

void CodeGenListener::enterProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
}
void CodeGenListener::exitProgram(AslParser::ProgramContext *ctx) {
  Symbols.popScope();
  DEBUG_EXIT();
}

void CodeGenListener::enterFunction(AslParser::FunctionContext *ctx) {
// to be modified
  DEBUG_ENTER();
  subroutine subr(ctx->ID()->getText());
  //TypesMgr::TypeId        t1 = getTypeDecor(ctx);
  //unsigned int n = Types.getNumOfParameters(t1);
  //if (not Types.isVoidFunction(t1)) {
  if (ctx->type()) {
    subr.add_param("_result");
  }
  //for (unsigned int i = 0; i < n; i++) {
  if (ctx->params()) {
    for (size_t i = 0; i < ctx->params()->param().size(); i++) {
      subr.add_param(ctx->params()->param(i)->ID()->getText());
    }
  }
  Code.add_subroutine(subr);
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  codeCounters.reset();
}
void CodeGenListener::exitFunction(AslParser::FunctionContext *ctx) {
  subroutine & subrRef = Code.get_last_subroutine();
  /*instructionList code;
  TypesMgr::TypeId        t1 = getTypeDecor(ctx);
  unsigned int n = Types.getNumOfParameters(t1);
  if (n != 0 or Types.isVoidFunction(t1)) {
     void add_param(const std::string &name);
    subrRef.add_param(t1.get)
    code = code || 
  }
  for (unsigned int i = 0; i < n; i++){
  }*/
  instructionList code = getCodeDecor(ctx->statements());

  // code = code || instruction::RETURN();
  for (size_t i = 0; i < ctx->return_statement().size(); i++) {
    code = code || getCodeDecor(ctx->return_statement(i));
  }
  if (ctx->return_statement().size() == 0)
    code = code || instruction::RETURN();

  subrRef.set_instructions(code);
  Symbols.popScope();
  DEBUG_EXIT();
}

void CodeGenListener::enterReturnStmt(AslParser::ReturnStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitReturnStmt(AslParser::ReturnStmtContext *ctx) {
  instructionList code;
  if (ctx->expr()) {
    std::string addr = getAddrDecor(ctx->expr());
    code = getCodeDecor(ctx->expr()) || instruction::LOAD("_result",addr) || instruction::RETURN();
  }
  else
    code = instruction::RETURN();
  putCodeDecor(ctx,code);
  DEBUG_EXIT();
}
void CodeGenListener::enterDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_EXIT();
}

void CodeGenListener::enterVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitVariable_decl(AslParser::Variable_declContext *ctx) {
  subroutine       & subrRef = Code.get_last_subroutine();
  //TypesMgr::TypeId        t1 = getTypeDecor(ctx->type());
  /*if (ctx->ARRAY()) {

  }*/
  //TypesMgr::TypeId        t1 = getTypeDecor(ctx);
  TypesMgr::TypeId  t1 = Symbols.getType(ctx->ID(0)->getText()); // needed to take into account arrays
  std::size_t           size = Types.getSizeOfType(t1);
  for (unsigned int i = 0; i < ctx->ID().size(); i++)
	subrRef.add_var(ctx->ID(i)->getText(), size);
  DEBUG_EXIT();
}

void CodeGenListener::enterType(AslParser::TypeContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitType(AslParser::TypeContext *ctx) {
  DEBUG_EXIT();
}

void CodeGenListener::enterStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitStatements(AslParser::StatementsContext *ctx) {
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    code = code || getCodeDecor(stCtx);
  }
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitAssignStmt(AslParser::AssignStmtContext *ctx) {
  if (ctx->left_expr()->ident()->OPENARRAY()) {
    // create new instruction "a1[a2] = a3" 
    //static instruction XLOAD(const std::string &a1, const std::string &a2, const std::string &a3);
    instructionList  code;
    //std::string     addr1 = getAddrDecor(ctx->left_expr()->ident());

    std::string addr1;
    if (Symbols.isParameterClass(ctx->left_expr()->ident()->ID()->getText())) { // for jp_genc_07, load pointer of array (param). todo: it should only be done once
      addr1 = "%" + codeCounters.newTEMP();
      code = instruction::LOAD(addr1,getAddrDecor(ctx->left_expr()->ident()));
      putAddrDecor(ctx->left_expr()->ident(), addr1);
      
    }
    else {
      //addr2 = getAddrDecor(ctx->ident());//->ID());
      addr1 = getAddrDecor(ctx->left_expr()->ident());
    }

    // std::string     offs1 = getOffsetDecor(ctx->left_expr());
    //instructionList code1 = getCodeDecor(ctx->left_expr());
    
    instructionList codeIndex = getCodeDecor(ctx->left_expr()->ident()->expr());
    std::string addrIndex = getAddrDecor(ctx->left_expr()->ident()->expr());

    // TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
    std::string     addr2 = getAddrDecor(ctx->expr());
    // std::string     offs2 = getOffsetDecor(ctx->expr());
    instructionList code2 = getCodeDecor(ctx->expr());
    // TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());

    instructionList codeL = instruction::XLOAD(addr1,addrIndex,addr2);

    //code = code1 || code2 || instruction::LOAD(addr1, addr2);
    code = code || codeIndex || code2 || codeL;
    putCodeDecor(ctx, code);

  }
  else { // assuming ID, todo?: grammar should't allow assignments to functions
    instructionList  code;
    std::string     addr1 = getAddrDecor(ctx->left_expr());
    // std::string     offs1 = getOffsetDecor(ctx->left_expr());
    instructionList code1 = getCodeDecor(ctx->left_expr());
    // TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
    std::string     addr2 = getAddrDecor(ctx->expr());
    // std::string     offs2 = getOffsetDecor(ctx->expr());
    instructionList code2 = getCodeDecor(ctx->expr());
    // TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());
    code = code1 || code2 || instruction::LOAD(addr1, addr2);
    putCodeDecor(ctx, code);
  }
  DEBUG_EXIT();
}

void CodeGenListener::enterIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitIfStmt(AslParser::IfStmtContext *ctx) {
  if (ctx->ELSE()) {
    instructionList   code;
    std::string      addr1 = getAddrDecor(ctx->expr());
    instructionList  code1 = getCodeDecor(ctx->expr());
    instructionList  code2 = getCodeDecor(ctx->statements(0));
    instructionList code3 = getCodeDecor(ctx->statements(1));
    std::string      label = codeCounters.newLabelIF();
    std::string labelElse = "else" + label;
    std::string labelEndIf = "endif"+label;
    code = code1 || instruction::FJUMP(addr1, labelElse) ||
         code2 || instruction::UJUMP(labelEndIf) || instruction::LABEL(labelElse) || code3 ||instruction::LABEL(labelEndIf);
    putCodeDecor(ctx, code);
  }
  else {
    instructionList   code;
    std::string      addr1 = getAddrDecor(ctx->expr());
    instructionList  code1 = getCodeDecor(ctx->expr());
    instructionList  code2 = getCodeDecor(ctx->statements(0));
    std::string      label = codeCounters.newLabelIF();
    std::string labelEndIf = "endif"+label;
    code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
         code2 || instruction::LABEL(labelEndIf);
    putCodeDecor(ctx, code);
  }
  DEBUG_EXIT();
}

void CodeGenListener::enterExprIdentProcedure(AslParser::ExprIdentProcedureContext *ctx) {
  DEBUG_ENTER();
}


void CodeGenListener::exitExprIdentProcedure(AslParser::ExprIdentProcedureContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->procedure()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->procedure()));
  putCodeDecor(ctx, getCodeDecor(ctx->procedure()));

  DEBUG_EXIT();
}

void CodeGenListener::enterProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
}


void CodeGenListener::exitProcCall(AslParser::ProcCallContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->procedure()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->procedure()));
  putCodeDecor(ctx, getCodeDecor(ctx->procedure()));

  

  // instructionList code = instruction::PUSH(); // Nope, because we don't care about the result (if any)
  // std::string name = ctx->ident()->ID()->getSymbol()->getText();
  // similar to void CodeGenListener::exitExprIdent(AslParser::ExprIdentContext *ctx) { if (ctx->ident()->OPENPAREN()){
  
  
  /*instructionList code;

  if (not Types.isVoidFunction(getTypeDecor(ctx->ident()))) {
    code = code || instruction::PUSH(); // added for jp_genc_06. space for _result. otherwise, a parameter may be overwritten, even if we don't use _result because it's a proccall
  }


  for (unsigned int i = 0; i < ctx->expr().size(); i++){
      // check int -> float for implicit conversion
      TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr(i)); // type of value to pass as parameter
      TypesMgr::TypeId tid2 =  Types.getParameterType(getTypeDecor(ctx->ident()),i); // actual parameter type
      if (Types.isIntegerTy(tid1) && Types.isFloatTy(tid2)) {
        std::string     addr1 = getAddrDecor(ctx->expr(i));
        instructionList code1 = getCodeDecor(ctx->expr(i));
        std::string temp = "%"+codeCounters.newTEMP();
        instructionList codeCast = instruction::FLOAT(temp, addr1);
        code = code || code1 || codeCast || instruction::PUSH(temp);
      }
      else if (Types.isArrayTy(tid2)) { // array as a ref, the same should be done for exitexpr function
        std::string     addr1 = getAddrDecor(ctx->expr(i));
        //instructionList code1 = getCodeDecor(ctx->expr(i));

        std::string temp = "%"+codeCounters.newTEMP();        

        // create new instruction "a1 = &a2" 
        // static instruction ALOAD(const std::string &a1, const std::string &a2);
        instructionList code1 = instruction::ALOAD(temp,addr1);

        code = code || code1 || instruction::PUSH(temp);
      }
      else {
        std::string     addr1 = getAddrDecor(ctx->expr(i));
        instructionList code1 = getCodeDecor(ctx->expr(i));

        code = code || code1 || instruction::PUSH(addr1);
      }
  }
  code = code || instruction::CALL(ctx->ident()->ID()->getText());
  for (unsigned int i = 0; i < ctx->expr().size(); i++){
      code = code || instruction::POP();
  }



  if (not Types.isVoidFunction(getTypeDecor(ctx->ident()))) {
    code = code || instruction::POP(); // added for jp_genc_06. space for _result. otherwise, a parameter may be overwritten, even if we don't use _result because it's a proccall
  }


  //std::string name = ctx->ident()->getText();
  //code = instruction::CALL(name);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();*/
}

void CodeGenListener::enterReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitReadStmt(AslParser::ReadStmtContext *ctx) {
  if (ctx->left_expr()->ident()->OPENARRAY()) { // todo: refactor: left_expr...
    // create new instruction "a1[a2] = a3" 
    //static instruction XLOAD(const std::string &a1, const std::string &a2, const std::string &a3);
    instructionList  code;
    std::string     addr1 = getAddrDecor(ctx->left_expr()->ident());

    // std::string     offs1 = getOffsetDecor(ctx->left_expr());
    //instructionList code1 = getCodeDecor(ctx->left_expr());
    
    instructionList codeIndex = getCodeDecor(ctx->left_expr()->ident()->expr());
    std::string addrIndex = getAddrDecor(ctx->left_expr()->ident()->expr());
/*
    // TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
    std::string     addr2 = getAddrDecor(ctx->expr());
    // std::string     offs2 = getOffsetDecor(ctx->expr());
    instructionList code2 = getCodeDecor(ctx->expr());
    // TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());*/

    std::string temp = "%"+codeCounters.newTEMP();

    //instructionList codeR = instruction::READI(temp); // TODO: not only READI, other cases
    // like this?
    instructionList codeR;
    TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

    if (Types.isIntegerTy(tid1) or Types.isBooleanTy(tid1))
      codeR = instruction::READI(temp);
    else if (Types.isFloatTy(tid1))
      codeR = instruction::READF(temp);
    else if (Types.isCharacterTy(tid1))
      codeR = instruction::READC(temp);
    
    instructionList codeL = instruction::XLOAD(addr1,addrIndex,temp);

    //code = code1 || code2 || instruction::LOAD(addr1, addr2);
    code = codeIndex || codeR || codeL;
    putCodeDecor(ctx, code);

  }
  else {
    instructionList  code;
    std::string     addr1 = getAddrDecor(ctx->left_expr());
    // std::string     offs1 = getOffsetDecor(ctx->left_expr());
    instructionList code1 = getCodeDecor(ctx->left_expr());
    TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

    if (Types.isIntegerTy(tid1) or Types.isBooleanTy(tid1))
      code = code1 || instruction::READI(addr1);
    else if (Types.isFloatTy(tid1))
      code = code1 || instruction::READF(addr1);
    else if (Types.isCharacterTy(tid1))
      code = code1 || instruction::READC(addr1);
    //code = code1 || instruction::READI(addr1); // TODO: not only READI, other cases
    putCodeDecor(ctx, code);
    DEBUG_EXIT();
  }
}

void CodeGenListener::enterWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitWriteExpr(AslParser::WriteExprContext *ctx) {
  instructionList code;
  std::string     addr1 = getAddrDecor(ctx->expr());
  // std::string     offs1 = getOffsetDecor(ctx->expr());
  instructionList code1 = getCodeDecor(ctx->expr());
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  // assuming int or float
  if (Types.isIntegerTy(tid1) or Types.isBooleanTy(tid1))
    code = code1 || instruction::WRITEI(addr1);
  else if (Types.isFloatTy(tid1))
    code = code1 || instruction::WRITEF(addr1);
  else if (Types.isCharacterTy(tid1))
    code = code1 || instruction::WRITEC(addr1);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitWriteString(AslParser::WriteStringContext *ctx) {
  instructionList code;
  std::string s = ctx->STRING()->getText();
  std::string temp = "%"+codeCounters.newTEMP();
  int i = 1;
  while (i < int(s.size())-1) {
    if (s[i] != '\\') {
      code = code ||
	     instruction::CHLOAD(temp, s.substr(i,1)) ||
	     instruction::WRITEC(temp);
      i += 1;
    }
    else {
      assert(i < int(s.size())-2);
      if (s[i+1] == 'n') {
        code = code || instruction::WRITELN();
        i += 2;
      }
      else if (s[i+1] == 't' or s[i+1] == '"' or s[i+1] == '\\') {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,2)) ||
	       instruction::WRITEC(temp);
        i += 2;
      }
      else {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,1)) ||
	       instruction::WRITEC(temp);
        i += 1;
      }
    }
  }
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitLeft_expr(AslParser::Left_exprContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->ident()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
  putCodeDecor(ctx, getCodeDecor(ctx->ident()));
  DEBUG_ENTER();
}

void CodeGenListener::enterArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitArithmetic(AslParser::ArithmeticContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId t  = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  //TypesMgr::TypeId t  = getTypeDecor(ctx);
  if (Types.isFloatTy(t1) or Types.isFloatTy(t2)){
  //if (Types.isFloatTy(t1) or Types.isFloatTy(t2)){
    if (Types.isIntegerTy(t1)){
      std::string temp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp2, addr1);
      addr1 = temp2;
    }
    else if (Types.isIntegerTy(t2)){
      std::string temp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp2, addr2);
      addr2 = temp2;
    }
      
  }
  
  if (Types.isFloatTy(t1) or Types.isFloatTy(t2)){
    if (ctx->MUL())
      code = code || instruction::FMUL(temp, addr1, addr2);
    else if (ctx->DIV())
      code = code || instruction::FDIV(temp, addr1, addr2);
    else if (ctx->PLUS())
      code = code || instruction::FADD(temp, addr1, addr2);
    else if (ctx->SUB())
      code = code || instruction::FSUB(temp, addr1, addr2); 
  }
  else if (Types.isIntegerTy(t1) and Types.isIntegerTy(t2)){
    if (ctx->MUL())
      code = code || instruction::MUL(temp, addr1, addr2);
    else if (ctx->DIV())
      code = code || instruction::DIV(temp, addr1, addr2);
    else if (ctx->PLUS())
      code = code || instruction::ADD(temp, addr1, addr2);
    else if (ctx->SUB())
      code = code || instruction::SUB(temp, addr1, addr2);
    else if (ctx->MOD()) {
      std::string temp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::DIV(temp2, addr1, addr2);
      std::string temp3 = "%"+codeCounters.newTEMP();
      code = code || instruction::MUL(temp3,temp2,addr2);
      code = code || instruction::SUB(temp,addr1,temp3);
    } 
  }
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitRelational(AslParser::RelationalContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId t  = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  
  if (Types.isFloatTy(t1) or Types.isFloatTy(t2)){
  //if (Types.isFloatTy(t1) or Types.isFloatTy(t2)){
    if (Types.isIntegerTy(t1)){
      std::string temp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp2, addr1);
      addr1 = temp2;
    }
    else if (Types.isIntegerTy(t2)){
      std::string temp2 = "%"+codeCounters.newTEMP();
      code = code || instruction::FLOAT(temp2, addr2);
      addr2 = temp2;
    }
      
  }
  
  if (Types.isFloatTy(t1) or Types.isFloatTy(t2)){
    if (ctx->EQUAL())
      code = code || instruction::FEQ(temp, addr1, addr2);
    else if (ctx->NEQUAL())
      code = code || instruction::FEQ(temp, addr1, addr2) || instruction::NOT(temp, temp);
    else if (ctx->GEQUAL()) //b >= a  -> not b < a
      code = code || instruction::FLT(temp, addr1, addr2) || instruction::NOT(temp, temp);
    else if (ctx->LEQUAL())
      code = code || instruction::FLE(temp, addr1, addr2);
    else if (ctx->GREATER()) //idem
      code = code || instruction::FLE(temp, addr1, addr2) || instruction::NOT(temp, temp);
    else if (ctx->LESSER())
      code = code || instruction::FLT(temp, addr1, addr2);
  }
  else if ((Types.isIntegerTy(t1) and Types.isIntegerTy(t2)) or (Types.isCharacterTy(t1) and Types.isCharacterTy(t2)) ){
    if (ctx->EQUAL())
      code = code || instruction::EQ(temp, addr1, addr2);
    else if (ctx->NEQUAL())
      code = code || instruction::EQ(temp, addr1, addr2) || instruction::NOT(temp, temp);
    else if (ctx->GEQUAL()) //idem
      code = code || instruction::LT(temp, addr1, addr2) || instruction::NOT(temp, temp);
    else if (ctx->LEQUAL())
      code = code || instruction::LE(temp, addr1, addr2);
    else if (ctx->GREATER()) //idem
      code = code || instruction::LE(temp, addr1, addr2) || instruction::NOT(temp, temp);
    else if (ctx->LESSER())
      code = code || instruction::LT(temp, addr1, addr2);  
  }
  else if (Types.isBooleanTy(t1) and Types.isBooleanTy(t2)){
    if (ctx->EQUAL())
      code = code || instruction::EQ(temp, addr1, addr2);
    else if (ctx->NEQUAL())
      code = code || instruction::EQ(temp, addr1, addr2) || instruction::NOT(temp, temp);
  }
  
  
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitValue(AslParser::ValueContext *ctx) {
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();
  std::string tempText = ctx->getText();
  if (tempText == "true")
    tempText = "1";
  else if (tempText == "false")
    tempText = "0";
  if (ctx->INTVAL() or ctx->BOOLVAL())
    code = instruction::ILOAD(temp, tempText);
  else if (ctx->FLOATVAL())
    code = instruction::FLOAD(temp, tempText);
  else{/*
    std::string s = std::string(1, tempText.c_str()[1]);
    std::cout << tempText << "   SPACE   " << tempText.c_str()[1] << std::endl;
    code = instruction::CHLOAD(temp, s);*/ //TODO
    std::string mychar = tempText.substr(1, tempText.length()-2);
    code = instruction::CHLOAD(temp,mychar);
      // CODE FROM WRITESTRING
      /*instructionList code;
      std::string s = ctx->STRING()->getText();
      std::string temp = "%"+codeCounters.newTEMP();
      int i = 1;
      while (i < int(s.size())-1) {
        if (s[i] != '\\') {
          code = code ||
	         instruction::CHLOAD(temp, s.substr(i,1)) ||
	         instruction::WRITEC(temp);
          i += 1;
        }
        else {
          assert(i < int(s.size())-2);
          if (s[i+1] == 'n') {
            code = code || instruction::WRITELN();
            i += 2;
          }
          else if (s[i+1] == 't' or s[i+1] == '"' or s[i+1] == '\\') {
            code = code ||
                   instruction::CHLOAD(temp, s.substr(i,2)) ||
	           instruction::WRITEC(temp);
            i += 2;
          }
          else {
            code = code ||
                   instruction::CHLOAD(temp, s.substr(i,1)) ||
	           instruction::WRITEC(temp);
            i += 1;
          }
        }
      }
      putCodeDecor(ctx, code);
      DEBUG_EXIT();*/
  }
    
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
}

/*
// check int -> float for implicit conversion (similar to procCall)
      TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr(i)); // type of value to pass as parameter
      TypesMgr::TypeId tid2 =  Types.getParameterType(getTypeDecor(ctx->ident()),i); // actual parameter type
      if (Types.isIntegerTy(tid1) && Types.isFloatTy(tid2)) {
        std::string     addr1 = getAddrDecor(ctx->expr(i));
        instructionList code1 = getCodeDecor(ctx->expr(i));
        std::string temp = "%"+codeCounters.newTEMP();
        instructionList codeCast = instruction::FLOAT(temp, addr1);
        code = code || code1 || codeCast || instruction::PUSH(temp);
      }
      else {
        std::string     addr1 = getAddrDecor(ctx->expr(i));
        instructionList code1 = getCodeDecor(ctx->expr(i));

        code = code || code1 || instruction::PUSH(addr1);
      }*/


void CodeGenListener::exitExprIdent(AslParser::ExprIdentContext *ctx) {
  
  // let's take arrays into account
  // arrays in right expression
  if (ctx->ident()->OPENARRAY()) { // OPENARRAY = "["
    // create new instruction "a1 = a2[a3]" 
    //static instruction LOADX(const std::string &a1, const std::string &a2, const std::string &a3);
    instructionList code = getCodeDecor(ctx->ident()->expr());
    std::string addr1 = "%" + codeCounters.newTEMP();

    std::string addr2;
    if (Symbols.isParameterClass(ctx->ident()->ID()->getText())) { // for jp_genc_07, load pointer of array (param), todo ? should the same be done in assignment? yes, at least left_expr
      addr2 = "%" + codeCounters.newTEMP();
      code = code || instruction::LOAD(addr2,getAddrDecor(ctx->ident()));
      putAddrDecor(ctx->ident(), addr2);
      
    }
    else {
      addr2 = getAddrDecor(ctx->ident());//->ID());
    }
    std::string addr3 = getAddrDecor(ctx->ident()->expr());
    code = code || instruction::LOADX(addr1,addr2,addr3);
    putAddrDecor(ctx, addr1);
    putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
    putCodeDecor(ctx, code);


  }
  else{ //not taking into account OPENARRAY
    //is an ID
    putAddrDecor(ctx, getAddrDecor(ctx->ident()));
    putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
    putCodeDecor(ctx, getCodeDecor(ctx->ident()));
  }
  
  DEBUG_EXIT();
}

void CodeGenListener::enterProcedure(AslParser::ProcedureContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitProcedure(AslParser::ProcedureContext *ctx) {
  if (ctx->OPENPAREN()){
    instructionList  code;
    if (not Types.isVoidFunction(Symbols.getType(ctx->ID()->getText())))
        code = instruction::PUSH();
    for (unsigned int i = 0; i < ctx->expr().size(); i++){
      // check int -> float for implicit conversion (similar to procCall)
      TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr(i)); // type of value to pass as parameter
      //TypesMgr::TypeId tid2 =  Types.getParameterType(getTypeDecor(ctx->ident()),i); // actual parameter type
      TypesMgr::TypeId tid2 =  Types.getParameterType(Symbols.getType(ctx->ID()->getText()),i); // actual parameter type
      if (Types.isIntegerTy(tid1) && Types.isFloatTy(tid2)) {
        std::string     addr1 = getAddrDecor(ctx->expr(i));
        instructionList code1 = getCodeDecor(ctx->expr(i));
        std::string temp = "%"+codeCounters.newTEMP();
        instructionList codeCast = instruction::FLOAT(temp, addr1);
        code = code || code1 || codeCast || instruction::PUSH(temp);
      }
      else if (Types.isArrayTy(tid2)) { // array as a ref, as in proccall (exactly the same?)
        // std::string     addr1 = getAddrDecor(ctx->expr(i));
        std::string     addr1 = getAddrDecor(ctx->expr(i));
        //instructionList code1 = getCodeDecor(ctx->expr(i));

        std::string temp = "%"+codeCounters.newTEMP();        

        // create new instruction "a1 = &a2" 
        // static instruction ALOAD(const std::string &a1, const std::string &a2);
        instructionList code1 = instruction::ALOAD(temp,addr1);

        code = code || code1 || instruction::PUSH(temp);
      }
      else {
        std::string     addr1 = getAddrDecor(ctx->expr(i));
        instructionList code1 = getCodeDecor(ctx->expr(i));
        code = code || code1 || instruction::PUSH(addr1);
      }
    }
    code = code || instruction::CALL(ctx->ID()->getText());
    
    for (unsigned int i = 0; i < ctx->expr().size(); i++){
      code = code || instruction::POP();
    }
    // std::string     addr = getAddrDecor(ctx->ident());
    // (temp reg, not function name)
    std::string addr = "";
    if (not Types.isVoidFunction(Symbols.getType(ctx->ID()->getText()))){
      addr = "%" + codeCounters.newTEMP();
      code = code || instruction::POP(addr);
    }
      
    putAddrDecor(ctx, addr);
    putOffsetDecor(ctx, getOffsetDecor(ctx));
    putCodeDecor(ctx, code);
  }
  DEBUG_EXIT();
}


void CodeGenListener::enterIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitIdent(AslParser::IdentContext *ctx) {
  putAddrDecor(ctx, ctx->ID()->getText());
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, instructionList());
  DEBUG_EXIT();
}

void CodeGenListener::enterUnary(AslParser::UnaryContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitUnary(AslParser::UnaryContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr());
  instructionList code1 = getCodeDecor(ctx->expr());
  std::string temp = "%"+codeCounters.newTEMP();
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if (ctx->SUB()){
    if (Types.isFloatTy(t1))
      code1 = code1 || instruction::FNEG(temp, addr1);
    else if (Types.isIntegerTy(t1))
      code1 = code1 || instruction::NEG(temp, addr1);
  }
  else if (ctx->NOT())
    code1 = code1 || instruction::NOT(temp, addr1);
  
  putAddrDecor(ctx, temp);
	putCodeDecor(ctx, code1);
  DEBUG_EXIT();
}

void CodeGenListener::enterParenth(AslParser::ParenthContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitParenth(AslParser::ParenthContext *ctx) {
	std::string     addr1 = getAddrDecor(ctx->expr());
  instructionList code1 = getCodeDecor(ctx->expr());
  putAddrDecor(ctx, addr1);
	putCodeDecor(ctx, code1);
  DEBUG_EXIT();
}

void CodeGenListener::enterBoolean(AslParser::BooleanContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitBoolean(AslParser::BooleanContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId t  = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->AND())
    code = code || instruction::AND(temp, addr1, addr2);
  else if (ctx->OR())
    code = code || instruction::OR(temp, addr2, addr1);
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitWhileStmt(AslParser::WhileStmtContext *ctx) {
  instructionList   code;
  std::string      addr1 = getAddrDecor(ctx->expr());
  instructionList  code1 = getCodeDecor(ctx->expr());
  instructionList  code2 = getCodeDecor(ctx->statements());
  std::string      label = codeCounters.newLabelWHILE();
  std::string labelStartWhile = "startwhile"+label;
  std::string labelEndWhile = "endwhile"+label;
  code = instruction::LABEL(labelStartWhile) || code1 || instruction::FJUMP(addr1, labelEndWhile) ||
         code2 || instruction::UJUMP(labelStartWhile) || instruction::LABEL(labelEndWhile);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

// void CodeGenListener::enterEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_ENTER();
// }
// void CodeGenListener::exitEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_EXIT();
// }
// void CodeGenListener::visitTerminal(antlr4::tree::TerminalNode *node) {
//   DEBUG(">>> visit " << node->getSymbol()->getLine() << ":" << node->getSymbol()->getCharPositionInLine() << " CodeGen TerminalNode");
// }
// void CodeGenListener::visitErrorNode(antlr4::tree::ErrorNode *node) {
// }


// Getters for the necessary tree node atributes:
//   Scope, Type, Addr, Offset and Code
SymTable::ScopeId CodeGenListener::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenListener::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
std::string CodeGenListener::getAddrDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getAddr(ctx);
}
std::string  CodeGenListener::getOffsetDecor(antlr4::ParserRuleContext *ctx) { // TODO: ask wtf is offset
  return Decorations.getOffset(ctx);
}
instructionList CodeGenListener::getCodeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getCode(ctx);
}

// Setters for the necessary tree node attributes:
//   Addr, Offset and Code
void CodeGenListener::putAddrDecor(antlr4::ParserRuleContext *ctx, const std::string & a) {
  Decorations.putAddr(ctx, a);
}
void CodeGenListener::putOffsetDecor(antlr4::ParserRuleContext *ctx, const std::string & o) {
  Decorations.putOffset(ctx, o);
}
void CodeGenListener::putCodeDecor(antlr4::ParserRuleContext *ctx, const instructionList & c) {
  Decorations.putCode(ctx, c);
}
