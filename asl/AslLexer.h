
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, ASSIGN = 6, EQUAL = 7, 
    GEQUAL = 8, LEQUAL = 9, GREATER = 10, LESSER = 11, NEQUAL = 12, NOT = 13, 
    AND = 14, OR = 15, PLUS = 16, SUB = 17, MUL = 18, DIV = 19, VAR = 20, 
    INT = 21, BOOL = 22, FLOAT = 23, CHAR = 24, IF = 25, THEN = 26, ELSE = 27, 
    ENDIF = 28, WHILE = 29, DO = 30, ENDWHILE = 31, FUNC = 32, ENDFUNC = 33, 
    READ = 34, WRITE = 35, RETURN = 36, BOOLVAL = 37, ID = 38, INTVAL = 39, 
    FLOATVAL = 40, CHARVAL = 41, STRING = 42, COMMENT = 43, WS = 44
  };

  AslLexer(antlr4::CharStream *input);
  ~AslLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

