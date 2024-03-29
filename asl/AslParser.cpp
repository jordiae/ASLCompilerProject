
// Generated from Asl.g4 by ANTLR 4.7.1


#include "AslListener.h"

#include "AslParser.h"


using namespace antlrcpp;
using namespace antlr4;

AslParser::AslParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AslParser::~AslParser() {
  delete _interpreter;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AslParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}

void AslParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void AslParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(28);
      function();
      setState(31); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(33);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

tree::TerminalNode* AslParser::FunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::ParamsContext* AslParser::FunctionContext::params() {
  return getRuleContext<AslParser::ParamsContext>(0);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

AslParser::TypeContext* AslParser::FunctionContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}

std::vector<AslParser::Return_statementContext *> AslParser::FunctionContext::return_statement() {
  return getRuleContexts<AslParser::Return_statementContext>();
}

AslParser::Return_statementContext* AslParser::FunctionContext::return_statement(size_t i) {
  return getRuleContext<AslParser::Return_statementContext>(i);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}

void AslParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void AslParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    match(AslParser::FUNC);
    setState(36);
    match(AslParser::ID);
    setState(37);
    match(AslParser::OPENPAREN);
    setState(39);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::ID) {
      setState(38);
      params();
    }
    setState(41);
    match(AslParser::T__0);
    setState(63);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::VAR:
      case AslParser::IF:
      case AslParser::WHILE:
      case AslParser::ENDFUNC:
      case AslParser::READ:
      case AslParser::WRITE:
      case AslParser::RETURN:
      case AslParser::ID: {
        setState(42);
        declarations();
        setState(43);
        statements();
        setState(47);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::RETURN) {
          setState(44);
          return_statement();
          setState(49);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(50);
        match(AslParser::ENDFUNC);
        break;
      }

      case AslParser::T__1: {
        setState(52);
        match(AslParser::T__1);
        setState(53);
        type();
        setState(54);
        declarations();
        setState(55);
        statements();
        setState(57); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(56);
          return_statement();
          setState(59); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == AslParser::RETURN);
        setState(61);
        match(AslParser::ENDFUNC);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}

void AslParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void AslParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(65);
      variable_decl();
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

AslParser::TypeContext* AslParser::Variable_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Variable_declContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

tree::TerminalNode* AslParser::Variable_declContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

tree::TerminalNode* AslParser::Variable_declContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::Variable_declContext::OF() {
  return getToken(AslParser::OF, 0);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}

void AslParser::Variable_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_decl(this);
}

void AslParser::Variable_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_decl(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleVariable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(71);
      match(AslParser::VAR);

      setState(72);
      match(AslParser::ID);
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__2) {
        setState(73);
        match(AslParser::T__2);
        setState(74);
        match(AslParser::ID);
        setState(79);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(80);
      match(AslParser::T__1);
      setState(81);
      type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(82);
      match(AslParser::VAR);

      setState(83);
      match(AslParser::ID);
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__2) {
        setState(84);
        match(AslParser::T__2);
        setState(85);
        match(AslParser::ID);
        setState(90);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(91);
      match(AslParser::T__1);
      setState(92);
      match(AslParser::ARRAY);
      setState(93);
      match(AslParser::OPENARRAY);
      setState(94);
      match(AslParser::INTVAL);
      setState(95);
      match(AslParser::T__3);
      setState(96);
      match(AslParser::OF);
      setState(97);
      type();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

AslParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::ParamContext *> AslParser::ParamsContext::param() {
  return getRuleContexts<AslParser::ParamContext>();
}

AslParser::ParamContext* AslParser::ParamsContext::param(size_t i) {
  return getRuleContext<AslParser::ParamContext>(i);
}


size_t AslParser::ParamsContext::getRuleIndex() const {
  return AslParser::RuleParams;
}

void AslParser::ParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParams(this);
}

void AslParser::ParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParams(this);
}

AslParser::ParamsContext* AslParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    param();
    setState(105);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__2) {
      setState(101);
      match(AslParser::T__2);
      setState(102);
      param();
      setState(107);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

AslParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ParamContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::TypeContext* AslParser::ParamContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}

tree::TerminalNode* AslParser::ParamContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

tree::TerminalNode* AslParser::ParamContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::ParamContext::OF() {
  return getToken(AslParser::OF, 0);
}


size_t AslParser::ParamContext::getRuleIndex() const {
  return AslParser::RuleParam;
}

void AslParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void AslParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}

AslParser::ParamContext* AslParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(108);
      match(AslParser::ID);
      setState(109);
      match(AslParser::T__1);
      setState(110);
      type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      match(AslParser::ID);
      setState(112);
      match(AslParser::T__1);
      setState(113);
      match(AslParser::ARRAY);
      setState(114);
      match(AslParser::OPENARRAY);
      setState(115);
      match(AslParser::INTVAL);
      setState(116);
      match(AslParser::T__3);
      setState(117);
      match(AslParser::OF);
      setState(118);
      type();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::TypeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::TypeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::TypeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::TypeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}

void AslParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void AslParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::INT)
      | (1ULL << AslParser::BOOL)
      | (1ULL << AslParser::FLOAT)
      | (1ULL << AslParser::CHAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}

void AslParser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void AslParser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::IF)
      | (1ULL << AslParser::WHILE)
      | (1ULL << AslParser::READ)
      | (1ULL << AslParser::WRITE)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(123);
      statement();
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProcCallContext ------------------------------------------------------------------

AslParser::ProcedureContext* AslParser::ProcCallContext::procedure() {
  return getRuleContext<AslParser::ProcedureContext>(0);
}

AslParser::ProcCallContext::ProcCallContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ProcCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcCall(this);
}
void AslParser::ProcCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcCall(this);
}
//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WriteExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteExpr(this);
}
void AslParser::WriteExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteExpr(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WhileStmtContext::WHILE() {
  return getToken(AslParser::WHILE, 0);
}

AslParser::ExprContext* AslParser::WhileStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::DO() {
  return getToken(AslParser::DO, 0);
}

AslParser::StatementsContext* AslParser::WhileStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::ENDWHILE() {
  return getToken(AslParser::ENDWHILE, 0);
}

AslParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}
void AslParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

std::vector<AslParser::StatementsContext *> AslParser::IfStmtContext::statements() {
  return getRuleContexts<AslParser::StatementsContext>();
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements(size_t i) {
  return getRuleContext<AslParser::StatementsContext>(i);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

tree::TerminalNode* AslParser::IfStmtContext::ELSE() {
  return getToken(AslParser::ELSE, 0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}
void AslParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ReadStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReadStmt(this);
}
void AslParser::ReadStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReadStmt(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::AssignStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStmt(this);
}
void AslParser::AssignStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStmt(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WriteStringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteString(this);
}
void AslParser::WriteStringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteString(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(129);
      left_expr();
      setState(130);
      match(AslParser::ASSIGN);
      setState(131);
      expr(0);
      setState(132);
      match(AslParser::T__4);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(134);
      match(AslParser::IF);
      setState(135);
      expr(0);
      setState(136);
      match(AslParser::THEN);
      setState(137);
      statements();
      setState(140);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(138);
        match(AslParser::ELSE);
        setState(139);
        statements();
      }
      setState(142);
      match(AslParser::ENDIF);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(144);
      match(AslParser::WHILE);
      setState(145);
      expr(0);
      setState(146);
      match(AslParser::DO);
      setState(147);
      statements();
      setState(148);
      match(AslParser::ENDWHILE);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(150);
      procedure();
      setState(151);
      match(AslParser::T__4);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(153);
      match(AslParser::READ);
      setState(154);
      left_expr();
      setState(155);
      match(AslParser::T__4);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(157);
      match(AslParser::WRITE);
      setState(158);
      expr(0);
      setState(159);
      match(AslParser::T__4);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(161);
      match(AslParser::WRITE);
      setState(162);
      match(AslParser::STRING);
      setState(163);
      match(AslParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

AslParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::Return_statementContext::getRuleIndex() const {
  return AslParser::RuleReturn_statement;
}

void AslParser::Return_statementContext::copyFrom(Return_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReturnStmtContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::ReturnStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ReturnStmtContext::ReturnStmtContext(Return_statementContext *ctx) { copyFrom(ctx); }

void AslParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}
void AslParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}
AslParser::Return_statementContext* AslParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 18, AslParser::RuleReturn_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<Return_statementContext *>(_tracker.createInstance<AslParser::ReturnStmtContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(AslParser::RETURN);
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::OPENPAREN)
      | (1ULL << AslParser::NOT)
      | (1ULL << AslParser::PLUS)
      | (1ULL << AslParser::SUB)
      | (1ULL << AslParser::BOOLVAL)
      | (1ULL << AslParser::ID)
      | (1ULL << AslParser::INTVAL)
      | (1ULL << AslParser::FLOATVAL)
      | (1ULL << AslParser::CHARVAL))) != 0)) {
      setState(167);
      expr(0);
    }
    setState(170);
    match(AslParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::Left_exprContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}

void AslParser::Left_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeft_expr(this);
}

void AslParser::Left_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeft_expr(this);
}

AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 20, AslParser::RuleLeft_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    ident();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BooleanContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::BooleanContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::BooleanContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::BooleanContext::OR() {
  return getToken(AslParser::OR, 0);
}

tree::TerminalNode* AslParser::BooleanContext::AND() {
  return getToken(AslParser::AND, 0);
}

AslParser::BooleanContext::BooleanContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}
void AslParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}
//----------------- ExprIdentProcedureContext ------------------------------------------------------------------

AslParser::ProcedureContext* AslParser::ExprIdentProcedureContext::procedure() {
  return getRuleContext<AslParser::ProcedureContext>(0);
}

AslParser::ExprIdentProcedureContext::ExprIdentProcedureContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ExprIdentProcedureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprIdentProcedure(this);
}
void AslParser::ExprIdentProcedureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprIdentProcedure(this);
}
//----------------- ParenthContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::ParenthContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ParenthContext::ParenthContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ParenthContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenth(this);
}
void AslParser::ParenthContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenth(this);
}
//----------------- ExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprIdentContext::ExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ExprIdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprIdent(this);
}
void AslParser::ExprIdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprIdent(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::SUB() {
  return getToken(AslParser::SUB, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MOD() {
  return getToken(AslParser::MOD, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ArithmeticContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic(this);
}
void AslParser::ArithmeticContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::EQUAL() {
  return getToken(AslParser::EQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GEQUAL() {
  return getToken(AslParser::GEQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LEQUAL() {
  return getToken(AslParser::LEQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::NEQUAL() {
  return getToken(AslParser::NEQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GREATER() {
  return getToken(AslParser::GREATER, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LESSER() {
  return getToken(AslParser::LESSER, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::RelationalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational(this);
}
void AslParser::RelationalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::UnaryContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::UnaryContext::SUB() {
  return getToken(AslParser::SUB, 0);
}

tree::TerminalNode* AslParser::UnaryContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::UnaryContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

AslParser::UnaryContext::UnaryContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}
void AslParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}
//----------------- ValueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::FLOATVAL() {
  return getToken(AslParser::FLOATVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::CHARVAL() {
  return getToken(AslParser::CHARVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::BOOLVAL() {
  return getToken(AslParser::BOOLVAL, 0);
}

AslParser::ValueContext::ValueContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}
void AslParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, AslParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenthContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(175);
      match(AslParser::OPENPAREN);
      setState(176);
      expr(0);
      setState(177);
      match(AslParser::T__0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(179);
      dynamic_cast<UnaryContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AslParser::PLUS

      || _la == AslParser::SUB)) {
        dynamic_cast<UnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(180);
      expr(14);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(181);
      dynamic_cast<UnaryContext *>(_localctx)->op = match(AslParser::NOT);
      setState(182);
      expr(10);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(183);
      match(AslParser::INTVAL);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(184);
      match(AslParser::FLOATVAL);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(185);
      match(AslParser::CHARVAL);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      match(AslParser::BOOLVAL);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(187);
      ident();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ExprIdentProcedureContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(188);
      procedure();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(211);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(209);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(191);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(192);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::MUL

          || _la == AslParser::DIV)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(193);
          expr(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(194);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(195);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::PLUS

          || _la == AslParser::SUB)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(196);
          expr(13);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(197);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(198);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::MOD);
          setState(199);
          expr(12);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(200);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(201);
          dynamic_cast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::EQUAL)
            | (1ULL << AslParser::GEQUAL)
            | (1ULL << AslParser::LEQUAL)
            | (1ULL << AslParser::NEQUAL))) != 0))) {
            dynamic_cast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(202);
          expr(10);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(203);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(204);
          dynamic_cast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::GREATER

          || _la == AslParser::LESSER)) {
            dynamic_cast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(205);
          expr(9);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BooleanContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(206);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(207);
          dynamic_cast<BooleanContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::AND

          || _la == AslParser::OR)) {
            dynamic_cast<BooleanContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(208);
          expr(8);
          break;
        }

        } 
      }
      setState(213);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

AslParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::IdentContext::getRuleIndex() const {
  return AslParser::RuleIdent;
}

void AslParser::IdentContext::copyFrom(IdentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IdentArrayAccessContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IdentArrayAccessContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::ExprContext* AslParser::IdentArrayAccessContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IdentArrayAccessContext::OPENARRAY() {
  return getToken(AslParser::OPENARRAY, 0);
}

AslParser::IdentArrayAccessContext::IdentArrayAccessContext(IdentContext *ctx) { copyFrom(ctx); }

void AslParser::IdentArrayAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentArrayAccess(this);
}
void AslParser::IdentArrayAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentArrayAccess(this);
}
//----------------- IdentIDContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IdentIDContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::IdentIDContext::IdentIDContext(IdentContext *ctx) { copyFrom(ctx); }

void AslParser::IdentIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentID(this);
}
void AslParser::IdentIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentID(this);
}
AslParser::IdentContext* AslParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 24, AslParser::RuleIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<IdentContext *>(_tracker.createInstance<AslParser::IdentIDContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(214);
      match(AslParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<IdentContext *>(_tracker.createInstance<AslParser::IdentArrayAccessContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(215);
      match(AslParser::ID);
      setState(216);
      dynamic_cast<IdentArrayAccessContext *>(_localctx)->op = match(AslParser::OPENARRAY);
      setState(217);
      expr(0);
      setState(218);
      match(AslParser::T__3);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureContext ------------------------------------------------------------------

AslParser::ProcedureContext::ProcedureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProcedureContext::ID() {
  return getToken(AslParser::ID, 0);
}

tree::TerminalNode* AslParser::ProcedureContext::OPENPAREN() {
  return getToken(AslParser::OPENPAREN, 0);
}

std::vector<AslParser::ExprContext *> AslParser::ProcedureContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ProcedureContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}


size_t AslParser::ProcedureContext::getRuleIndex() const {
  return AslParser::RuleProcedure;
}

void AslParser::ProcedureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedure(this);
}

void AslParser::ProcedureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedure(this);
}

AslParser::ProcedureContext* AslParser::procedure() {
  ProcedureContext *_localctx = _tracker.createInstance<ProcedureContext>(_ctx, getState());
  enterRule(_localctx, 26, AslParser::RuleProcedure);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(AslParser::ID);
    setState(223);
    dynamic_cast<ProcedureContext *>(_localctx)->op = match(AslParser::OPENPAREN);
    setState(232);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::OPENPAREN)
      | (1ULL << AslParser::NOT)
      | (1ULL << AslParser::PLUS)
      | (1ULL << AslParser::SUB)
      | (1ULL << AslParser::BOOLVAL)
      | (1ULL << AslParser::ID)
      | (1ULL << AslParser::INTVAL)
      | (1ULL << AslParser::FLOATVAL)
      | (1ULL << AslParser::CHARVAL))) != 0)) {
      setState(224);
      expr(0);
      setState(229);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__2) {
        setState(225);
        match(AslParser::T__2);
        setState(226);
        expr(0);
        setState(231);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(234);
    match(AslParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 9);
    case 4: return precpred(_ctx, 8);
    case 5: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AslParser::_decisionToDFA;
atn::PredictionContextCache AslParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AslParser::_atn;
std::vector<uint16_t> AslParser::_serializedATN;

std::vector<std::string> AslParser::_ruleNames = {
  "program", "function", "declarations", "variable_decl", "params", "param", 
  "type", "statements", "statement", "return_statement", "left_expr", "expr", 
  "ident", "procedure"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "')'", "':'", "','", "']'", "';'", "'['", "'('", "'='", "'=='", "'>='", 
  "'<='", "'>'", "'<'", "'!='", "'not'", "'and'", "'or'", "'+'", "'-'", 
  "'*'", "'/'", "'%'", "'var'", "'int'", "'bool'", "'float'", "'char'", 
  "'array'", "'of'", "'if'", "'then'", "'else'", "'endif'", "'while'", "'do'", 
  "'endwhile'", "'func'", "'endfunc'", "'read'", "'write'", "'return'"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "", "", "OPENARRAY", "OPENPAREN", "ASSIGN", "EQUAL", "GEQUAL", 
  "LEQUAL", "GREATER", "LESSER", "NEQUAL", "NOT", "AND", "OR", "PLUS", "SUB", 
  "MUL", "DIV", "MOD", "VAR", "INT", "BOOL", "FLOAT", "CHAR", "ARRAY", "OF", 
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "FUNC", "ENDFUNC", 
  "READ", "WRITE", "RETURN", "BOOLVAL", "ID", "INTVAL", "FLOATVAL", "CHARVAL", 
  "STRING", "COMMENT", "WS"
};

dfa::Vocabulary AslParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AslParser::_tokenNames;

AslParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x33, 0xef, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x3, 0x2, 0x6, 0x2, 0x20, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 
    0x21, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x2a, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0x30, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x33, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x6, 0x3, 0x3c, 0xa, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0x3d, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x42, 0xa, 
    0x3, 0x3, 0x4, 0x7, 0x4, 0x45, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x48, 0xb, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x4e, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x51, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x59, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x5c, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x65, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x7, 0x6, 0x6a, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x6d, 0xb, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x7a, 0xa, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x7, 0x9, 0x7f, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x82, 0xb, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x8f, 0xa, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x5, 0xa, 0xa7, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xab, 
    0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0xc0, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xd4, 
    0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xd7, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xdf, 0xa, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xe6, 0xa, 0xf, 0xc, 
    0xf, 0xe, 0xf, 0xe9, 0xb, 0xf, 0x5, 0xf, 0xeb, 0xa, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x2, 0x3, 0x18, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x2, 0x8, 0x3, 0x2, 0x1a, 
    0x1d, 0x3, 0x2, 0x14, 0x15, 0x3, 0x2, 0x16, 0x17, 0x4, 0x2, 0xb, 0xd, 
    0x10, 0x10, 0x3, 0x2, 0xe, 0xf, 0x3, 0x2, 0x12, 0x13, 0x2, 0x105, 0x2, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x25, 0x3, 0x2, 0x2, 0x2, 0x6, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x64, 0x3, 0x2, 0x2, 0x2, 0xa, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x79, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7b, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x80, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0x16, 0xae, 0x3, 0x2, 0x2, 0x2, 0x18, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xde, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x20, 0x5, 0x4, 0x3, 0x2, 0x1f, 0x1e, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x23, 0x24, 0x7, 0x2, 0x2, 0x3, 0x24, 0x3, 0x3, 0x2, 0x2, 0x2, 0x25, 
    0x26, 0x7, 0x27, 0x2, 0x2, 0x26, 0x27, 0x7, 0x2d, 0x2, 0x2, 0x27, 0x29, 
    0x7, 0x9, 0x2, 0x2, 0x28, 0x2a, 0x5, 0xa, 0x6, 0x2, 0x29, 0x28, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x2b, 0x41, 0x7, 0x3, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0x6, 0x4, 
    0x2, 0x2d, 0x31, 0x5, 0x10, 0x9, 0x2, 0x2e, 0x30, 0x5, 0x14, 0xb, 0x2, 
    0x2f, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 0x2, 0x31, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 
    0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x7, 
    0x28, 0x2, 0x2, 0x35, 0x42, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x4, 
    0x2, 0x2, 0x37, 0x38, 0x5, 0xe, 0x8, 0x2, 0x38, 0x39, 0x5, 0x6, 0x4, 
    0x2, 0x39, 0x3b, 0x5, 0x10, 0x9, 0x2, 0x3a, 0x3c, 0x5, 0x14, 0xb, 0x2, 
    0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x28, 0x2, 0x2, 0x40, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x41, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x41, 0x36, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x5, 0x3, 0x2, 0x2, 0x2, 0x43, 0x45, 0x5, 0x8, 0x5, 
    0x2, 0x44, 0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 
    0x7, 0x19, 0x2, 0x2, 0x4a, 0x4f, 0x7, 0x2d, 0x2, 0x2, 0x4b, 0x4c, 0x7, 
    0x5, 0x2, 0x2, 0x4c, 0x4e, 0x7, 0x2d, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x3, 0x2, 0x2, 0x2, 
    0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0x4, 0x2, 0x2, 0x53, 
    0x65, 0x5, 0xe, 0x8, 0x2, 0x54, 0x55, 0x7, 0x19, 0x2, 0x2, 0x55, 0x5a, 
    0x7, 0x2d, 0x2, 0x2, 0x56, 0x57, 0x7, 0x5, 0x2, 0x2, 0x57, 0x59, 0x7, 
    0x2d, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 
    0x5d, 0x5e, 0x7, 0x4, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x1e, 0x2, 0x2, 0x5f, 
    0x60, 0x7, 0x8, 0x2, 0x2, 0x60, 0x61, 0x7, 0x2e, 0x2, 0x2, 0x61, 0x62, 
    0x7, 0x6, 0x2, 0x2, 0x62, 0x63, 0x7, 0x1f, 0x2, 0x2, 0x63, 0x65, 0x5, 
    0xe, 0x8, 0x2, 0x64, 0x49, 0x3, 0x2, 0x2, 0x2, 0x64, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x65, 0x9, 0x3, 0x2, 0x2, 0x2, 0x66, 0x6b, 0x5, 0xc, 0x7, 
    0x2, 0x67, 0x68, 0x7, 0x5, 0x2, 0x2, 0x68, 0x6a, 0x5, 0xc, 0x7, 0x2, 
    0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6b, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 
    0x2d, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x4, 0x2, 0x2, 0x70, 0x7a, 0x5, 0xe, 
    0x8, 0x2, 0x71, 0x72, 0x7, 0x2d, 0x2, 0x2, 0x72, 0x73, 0x7, 0x4, 0x2, 
    0x2, 0x73, 0x74, 0x7, 0x1e, 0x2, 0x2, 0x74, 0x75, 0x7, 0x8, 0x2, 0x2, 
    0x75, 0x76, 0x7, 0x2e, 0x2, 0x2, 0x76, 0x77, 0x7, 0x6, 0x2, 0x2, 0x77, 
    0x78, 0x7, 0x1f, 0x2, 0x2, 0x78, 0x7a, 0x5, 0xe, 0x8, 0x2, 0x79, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x79, 0x71, 0x3, 0x2, 0x2, 0x2, 0x7a, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x7b, 0x7c, 0x9, 0x2, 0x2, 0x2, 0x7c, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x7f, 0x5, 0x12, 0xa, 0x2, 0x7e, 0x7d, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x82, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x11, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x80, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x5, 0x16, 0xc, 0x2, 0x84, 0x85, 
    0x7, 0xa, 0x2, 0x2, 0x85, 0x86, 0x5, 0x18, 0xd, 0x2, 0x86, 0x87, 0x7, 
    0x7, 0x2, 0x2, 0x87, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x20, 
    0x2, 0x2, 0x89, 0x8a, 0x5, 0x18, 0xd, 0x2, 0x8a, 0x8b, 0x7, 0x21, 0x2, 
    0x2, 0x8b, 0x8e, 0x5, 0x10, 0x9, 0x2, 0x8c, 0x8d, 0x7, 0x22, 0x2, 0x2, 
    0x8d, 0x8f, 0x5, 0x10, 0x9, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 
    0x7, 0x23, 0x2, 0x2, 0x91, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 
    0x24, 0x2, 0x2, 0x93, 0x94, 0x5, 0x18, 0xd, 0x2, 0x94, 0x95, 0x7, 0x25, 
    0x2, 0x2, 0x95, 0x96, 0x5, 0x10, 0x9, 0x2, 0x96, 0x97, 0x7, 0x26, 0x2, 
    0x2, 0x97, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x5, 0x1c, 0xf, 0x2, 
    0x99, 0x9a, 0x7, 0x7, 0x2, 0x2, 0x9a, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x9c, 0x7, 0x29, 0x2, 0x2, 0x9c, 0x9d, 0x5, 0x16, 0xc, 0x2, 0x9d, 0x9e, 
    0x7, 0x7, 0x2, 0x2, 0x9e, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x7, 
    0x2a, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x18, 0xd, 0x2, 0xa1, 0xa2, 0x7, 0x7, 
    0x2, 0x2, 0xa2, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x2a, 0x2, 
    0x2, 0xa4, 0xa5, 0x7, 0x31, 0x2, 0x2, 0xa5, 0xa7, 0x7, 0x7, 0x2, 0x2, 
    0xa6, 0x83, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x88, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x98, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0xa6, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa3, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xaa, 0x7, 0x2b, 
    0x2, 0x2, 0xa9, 0xab, 0x5, 0x18, 0xd, 0x2, 0xaa, 0xa9, 0x3, 0x2, 0x2, 
    0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 
    0xac, 0xad, 0x7, 0x7, 0x2, 0x2, 0xad, 0x15, 0x3, 0x2, 0x2, 0x2, 0xae, 
    0xaf, 0x5, 0x1a, 0xe, 0x2, 0xaf, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 
    0x8, 0xd, 0x1, 0x2, 0xb1, 0xb2, 0x7, 0x9, 0x2, 0x2, 0xb2, 0xb3, 0x5, 
    0x18, 0xd, 0x2, 0xb3, 0xb4, 0x7, 0x3, 0x2, 0x2, 0xb4, 0xc0, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xb6, 0x9, 0x3, 0x2, 0x2, 0xb6, 0xc0, 0x5, 0x18, 0xd, 
    0x10, 0xb7, 0xb8, 0x7, 0x11, 0x2, 0x2, 0xb8, 0xc0, 0x5, 0x18, 0xd, 0xc, 
    0xb9, 0xc0, 0x7, 0x2e, 0x2, 0x2, 0xba, 0xc0, 0x7, 0x2f, 0x2, 0x2, 0xbb, 
    0xc0, 0x7, 0x30, 0x2, 0x2, 0xbc, 0xc0, 0x7, 0x2c, 0x2, 0x2, 0xbd, 0xc0, 
    0x5, 0x1a, 0xe, 0x2, 0xbe, 0xc0, 0x5, 0x1c, 0xf, 0x2, 0xbf, 0xb0, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb7, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xba, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xd5, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0xc, 0xf, 0x2, 0x2, 0xc2, 0xc3, 
    0x9, 0x4, 0x2, 0x2, 0xc3, 0xd4, 0x5, 0x18, 0xd, 0x10, 0xc4, 0xc5, 0xc, 
    0xe, 0x2, 0x2, 0xc5, 0xc6, 0x9, 0x3, 0x2, 0x2, 0xc6, 0xd4, 0x5, 0x18, 
    0xd, 0xf, 0xc7, 0xc8, 0xc, 0xd, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x18, 0x2, 
    0x2, 0xc9, 0xd4, 0x5, 0x18, 0xd, 0xe, 0xca, 0xcb, 0xc, 0xb, 0x2, 0x2, 
    0xcb, 0xcc, 0x9, 0x5, 0x2, 0x2, 0xcc, 0xd4, 0x5, 0x18, 0xd, 0xc, 0xcd, 
    0xce, 0xc, 0xa, 0x2, 0x2, 0xce, 0xcf, 0x9, 0x6, 0x2, 0x2, 0xcf, 0xd4, 
    0x5, 0x18, 0xd, 0xb, 0xd0, 0xd1, 0xc, 0x9, 0x2, 0x2, 0xd1, 0xd2, 0x9, 
    0x7, 0x2, 0x2, 0xd2, 0xd4, 0x5, 0x18, 0xd, 0xa, 0xd3, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0xd3, 0xca, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xdf, 0x7, 
    0x2d, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x2d, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x8, 
    0x2, 0x2, 0xdb, 0xdc, 0x5, 0x18, 0xd, 0x2, 0xdc, 0xdd, 0x7, 0x6, 0x2, 
    0x2, 0xdd, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xde, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdf, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0xe1, 0x7, 0x2d, 0x2, 0x2, 0xe1, 0xea, 0x7, 0x9, 0x2, 0x2, 0xe2, 0xe7, 
    0x5, 0x18, 0xd, 0x2, 0xe3, 0xe4, 0x7, 0x5, 0x2, 0x2, 0xe4, 0xe6, 0x5, 
    0x18, 0xd, 0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe9, 0x3, 0x2, 
    0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 
    0xec, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 0x3, 0x2, 0x2, 0xed, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x17, 0x21, 0x29, 0x31, 0x3d, 0x41, 0x46, 0x4f, 
    0x5a, 0x64, 0x6b, 0x79, 0x80, 0x8e, 0xa6, 0xaa, 0xbf, 0xd3, 0xd5, 0xde, 
    0xe7, 0xea, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AslParser::Initializer AslParser::_init;
