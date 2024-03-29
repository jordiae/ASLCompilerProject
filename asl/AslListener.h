
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AslParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AslParser.
 */
class  AslListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(AslParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(AslParser::ProgramContext *ctx) = 0;

  virtual void enterFunction(AslParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(AslParser::FunctionContext *ctx) = 0;

  virtual void enterDeclarations(AslParser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(AslParser::DeclarationsContext *ctx) = 0;

  virtual void enterVariable_decl(AslParser::Variable_declContext *ctx) = 0;
  virtual void exitVariable_decl(AslParser::Variable_declContext *ctx) = 0;

  virtual void enterParams(AslParser::ParamsContext *ctx) = 0;
  virtual void exitParams(AslParser::ParamsContext *ctx) = 0;

  virtual void enterParam(AslParser::ParamContext *ctx) = 0;
  virtual void exitParam(AslParser::ParamContext *ctx) = 0;

  virtual void enterType(AslParser::TypeContext *ctx) = 0;
  virtual void exitType(AslParser::TypeContext *ctx) = 0;

  virtual void enterStatements(AslParser::StatementsContext *ctx) = 0;
  virtual void exitStatements(AslParser::StatementsContext *ctx) = 0;

  virtual void enterAssignStmt(AslParser::AssignStmtContext *ctx) = 0;
  virtual void exitAssignStmt(AslParser::AssignStmtContext *ctx) = 0;

  virtual void enterIfStmt(AslParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(AslParser::IfStmtContext *ctx) = 0;

  virtual void enterWhileStmt(AslParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(AslParser::WhileStmtContext *ctx) = 0;

  virtual void enterProcCall(AslParser::ProcCallContext *ctx) = 0;
  virtual void exitProcCall(AslParser::ProcCallContext *ctx) = 0;

  virtual void enterReadStmt(AslParser::ReadStmtContext *ctx) = 0;
  virtual void exitReadStmt(AslParser::ReadStmtContext *ctx) = 0;

  virtual void enterWriteExpr(AslParser::WriteExprContext *ctx) = 0;
  virtual void exitWriteExpr(AslParser::WriteExprContext *ctx) = 0;

  virtual void enterWriteString(AslParser::WriteStringContext *ctx) = 0;
  virtual void exitWriteString(AslParser::WriteStringContext *ctx) = 0;

  virtual void enterReturnStmt(AslParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(AslParser::ReturnStmtContext *ctx) = 0;

  virtual void enterLeft_expr(AslParser::Left_exprContext *ctx) = 0;
  virtual void exitLeft_expr(AslParser::Left_exprContext *ctx) = 0;

  virtual void enterBoolean(AslParser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(AslParser::BooleanContext *ctx) = 0;

  virtual void enterExprIdentProcedure(AslParser::ExprIdentProcedureContext *ctx) = 0;
  virtual void exitExprIdentProcedure(AslParser::ExprIdentProcedureContext *ctx) = 0;

  virtual void enterParenth(AslParser::ParenthContext *ctx) = 0;
  virtual void exitParenth(AslParser::ParenthContext *ctx) = 0;

  virtual void enterExprIdent(AslParser::ExprIdentContext *ctx) = 0;
  virtual void exitExprIdent(AslParser::ExprIdentContext *ctx) = 0;

  virtual void enterArithmetic(AslParser::ArithmeticContext *ctx) = 0;
  virtual void exitArithmetic(AslParser::ArithmeticContext *ctx) = 0;

  virtual void enterRelational(AslParser::RelationalContext *ctx) = 0;
  virtual void exitRelational(AslParser::RelationalContext *ctx) = 0;

  virtual void enterUnary(AslParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(AslParser::UnaryContext *ctx) = 0;

  virtual void enterValue(AslParser::ValueContext *ctx) = 0;
  virtual void exitValue(AslParser::ValueContext *ctx) = 0;

  virtual void enterIdentID(AslParser::IdentIDContext *ctx) = 0;
  virtual void exitIdentID(AslParser::IdentIDContext *ctx) = 0;

  virtual void enterIdentArrayAccess(AslParser::IdentArrayAccessContext *ctx) = 0;
  virtual void exitIdentArrayAccess(AslParser::IdentArrayAccessContext *ctx) = 0;

  virtual void enterProcedure(AslParser::ProcedureContext *ctx) = 0;
  virtual void exitProcedure(AslParser::ProcedureContext *ctx) = 0;


};

