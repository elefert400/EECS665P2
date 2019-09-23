%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines
%define api.namespace {lake}
%define parser_class_name {Parser}
%output "parser.cc"
%token-table

%code requires{
   #include <list>
   #include "tokens.hpp"
   #include "ast.hpp"
   namespace lake {
      class Scanner;
   }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { lake::Scanner  &scanner  }
%parse-param { lake::ProgramNode** root }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for interoperation between scanner/parser */
   #include "scanner.hpp"

#undef yylex
#define yylex scanner.yylex
}

/*%define api.value.type variant*/
%union {
	lake::Token * tokenValue;
	lake::IDToken * idTokenValue;
	lake::ASTNode * astNode;
	lake::ProgramNode * programNode;
	std::list<DeclNode *> * declList;
	lake::DeclNode * declNode;
	lake::VarDeclNode * varDeclNode;
	lake::TypeNode * typeNode;
	lake::IdNode * idNode;
}

%define parse.assert

%token               END    0     "end of file"
%token               NEWLINE "newline"
%token               BOOL
%token <tokenValue>  INT
%token               VOID
%token               TRUE
%token               FALSE
%token               IF
%token               ELSE
%token               WHILE
%token               RETURN
%token <idTokenValue> ID
%token               INTLITERAL
%token               STRINGLITERAL
%token               DEREF
%token               LCURLY
%token               RCURLY
%token               LPAREN
%token               RPAREN
%token               SEMICOLON
%token               COMMA
%token               DOT
%token               WRITE
%token               READ
%token               CROSSCROSS
%token               DASHDASH
%token               CROSS
%token               DASH
%token               STAR
%token               SLASH
%token               NOT
%token               AND
%token               OR
%token               EQUALS
%token               NOTEQUALS
%token               LESS
%token               GREATER
%token               LESSEQ
%token               GREATEREQ
%token               ASSIGN

/* Nonterminals
*  NOTE: You will need to add more nonterminals
*  to this list as you add productions to the grammar
*  below. 
*/
%type <programNode> program
%type <declList> declList
%type <declNode> decl
%type <varDeclNode> varDecl
%type <typeNode> type
%type <idNode> id


/* NOTE: Make sure to add precedence and associativity 
 * declarations!
*/

%%

/* TODO: fill out the rest of the rules */
program : declList {
		   $$ = new ProgramNode(new DeclListNode($1));
		   *root = $$;
		   }
  	;

declList : declList decl {
			 $1->push_back($2);
			 $$ = $1;
			 }
	| /* epsilon */ {
			$$ = new std::list<DeclNode *>();
			}
	;

decl : varDecl {
		//Make sure to fill out this rule
		}
varDecl : type id SEMICOLON {
		$$ = new VarDeclNode($1, $2);
			    }
type : INT { $$ = new IntNode($1->_line, $1->_column); }
id : ID { $$ = new IdNode($1); }
%%
void
lake::Parser::error(const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n";
}
