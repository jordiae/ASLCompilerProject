
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, OPENARRAY = 6, OPENPAREN = 7, 
    ASSIGN = 8, EQUAL = 9, GEQUAL = 10, LEQUAL = 11, GREATER = 12, LESSER = 13, 
    NEQUAL = 14, NOT = 15, AND = 16, OR = 17, PLUS = 18, SUB = 19, MUL = 20, 
    DIV = 21, VAR = 22, INT = 23, BOOL = 24, FLOAT = 25, CHAR = 26, ARRAY = 27, 
    OF = 28, IF = 29, THEN = 30, ELSE = 31, ENDIF = 32, WHILE = 33, DO = 34, 
    ENDWHILE = 35, FUNC = 36, ENDFUNC = 37, READ = 38, WRITE = 39, RETURN = 40, 
    BOOLVAL = 41, ID = 42, INTVAL = 43, FLOATVAL = 44, CHARVAL = 45, STRING = 46, 
    COMMENT = 47, WS = 48
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

