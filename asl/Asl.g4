//////////////////////////////////////////////////////////////////////
//
//    Asl - Another simple language (grammar)
//
//    Copyright (C) 2017  Universitat Politecnica de Catalunya
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
//    contact: José Miguel Rivero (rivero@cs.upc.es)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

grammar Asl;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF
        ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID '(' (params)? ')' ((declarations statements return_statement* ENDFUNC) |  (':' type declarations statements return_statement+ ENDFUNC ) )
        ;

declarations
        : (variable_decl)*
        ;

variable_decl
        : VAR (ID)(','ID)* ':' type
        | VAR (ID)(','ID)* ':' ARRAY '[' INTVAL ']' OF type
        ;

params
		: (param) (',' param)*
		;

param   : (ID ':' type)
        | ID ':' ARRAY '[' INTVAL ']' OF type 
		;

type    : INT
		| BOOL
		| FLOAT
		| CHAR
        ;

statements
        : (statement)*
        ;

// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'           # assignStmt
          // if-then-else statement (else is optional)
        | IF expr THEN statements (ELSE statements)? ENDIF       # ifStmt
          // while statement
        | WHILE expr DO statements ENDWHILE   # whileStmt
          // A function/procedure call has a list of arguments in parenthesis (possibly empty)
        //| ident '(' ')' ';'                   # procCall
        | procedure  ';'                # procCall
          // Read a variable
        | READ left_expr ';'                  # readStmt
          // Write an expression
        | WRITE expr ';'                      # writeExpr
          // Write a string
        | WRITE STRING ';'                    # writeString
        //| ident '(' (expr (','expr)*)? ')' ';'       # functionCall
        ;
        
return_statement
		: RETURN (expr)? ';' 				  #returnStmt
		;

// Grammar for left expressions (l-values in C++)
left_expr
        : ident
        | ID op=OPENARRAY expr ']'
        ;

// Grammar for expressions with boolean, relational and aritmetic operators
expr    : '(' expr ')'						       	       # parenth
		| op=SUB expr						               # unary
		| expr op=(MUL|DIV) expr                           # arithmetic
        | expr op=(PLUS|SUB) expr                          # arithmetic
        | expr op=MOD expr                                 # arithmetic
        | op=NOT expr								       # unary
        | expr op=(EQUAL|GEQUAL|LEQUAL|NEQUAL) expr        # relational
        | expr op=(GREATER|LESSER) expr				       # relational
        | expr op=(OR|AND) expr				     	       # boolean
        | INTVAL                                           # value
        | FLOATVAL							               # value
        | CHARVAL							               # value
        | BOOLVAL							               # value
        | ident                                            # exprIdent
        | ID op=OPENARRAY expr ']'                         # exprIdentArray
        | procedure                                        # exprIdentFunc
        ;

ident   : ID
        ;
        
procedure: ID op=OPENPAREN (expr (','expr)*)? ')' ;

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

OPENARRAY : '[' ;
OPENPAREN : '(' ;
ASSIGN    : '=' ;
EQUAL     : '==' ;
GEQUAL	  : '>=' ;
LEQUAL	  : '<=' ;
GREATER	  : '>' ;
LESSER	  : '<' ;
NEQUAL    : '!=' ;
NOT		  : 'not' ;
AND		  : 'and' ;
OR		  : 'or' ;
PLUS      : '+' ;
SUB		  : '-';
MUL       : '*';
DIV		  : '/';
MOD       : '%';
VAR       : 'var';
INT       : 'int';
BOOL	  : 'bool';
FLOAT	  : 'float';
CHAR	  : 'char';
ARRAY     : 'array';
OF        : 'of';
IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
ENDIF     : 'endif' ;
WHILE	  : 'while' ;
DO		  : 'do' ;
ENDWHILE  : 'endwhile' ;
FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
READ      : 'read' ;
WRITE     : 'write' ;
RETURN	  : 'return' ;
BOOLVAL   : ('true'|'false');
ID        : ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;
INTVAL    : ('0'..'9')+ ;
FLOATVAL  : (INTVAL('.')?|('0'..'9')*('.')('0'..'9')+);
CHARVAL   : '\''('a'..'z'|'A'..'Z'|'_')'\'';


// Strings (in quotes) with escape sequences
STRING    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"' ;

fragment
ESC_SEQ   : '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\') ;

// Comments (inline C++-style)
COMMENT   : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;

// White spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;
// Alternative description
// WS        : [ \t\r\n]+ -> skip ;
