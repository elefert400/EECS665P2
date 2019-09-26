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
%type <typeNode> primtype
%type <counterTrans> ptrdepth
%type <fnDecl> fnDecl
%type <fnBody> fnBody
%type <stmtList> stmtList
%type <formalsType> formals
%type <formalsList> formalsList
%type <formalDecl> formalDecl
%type <stmtNode> stmt
%type <exp> exp
%type <exp> loc
%type <callNode> fncall
%type <assignNode> assignExp
%type <expList> actualList

/* NOTE: Make sure to add precedence and associativity
 * declarations!
*/
%right ASSIGN
$left OR
%left AND
%left CROSS DASH
%left STAR SLASH
%left NOT
%nonassoc LESS
%nonassoc GREATER
%nonassoc LESSEQ
%nonassoc GREATEREQ
%nonassoc EQUALS
%nonassoc NOTEQUALS
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
    | fnDecl {
    //needs to be filled in
    }
varDecl : type id SEMICOLON {
		$$ = new VarDeclNode($1, $2);
			    }
fnDecl : type id formals fnBody {
  //needs to be filled in
}
formals : LPAREN RPAREN {
  //needs to be filled in
}
  | LPAREN formalsList RPAREN {
  //needs to be filled in
  }
formalsList : formalDecl {
  //needs to be filled in
}
  | formalDecl COMMA formalsList {
  //needs to be filled in
  }
formalDecl : type id {
  //needs to be filled in
}
fnBody : LCURLY varDeclList stmtList RCURLY {
  //needs to be filled in
}
stmtList : stmtList stmt {
  //needs to be filled in
}
  | /*epsilon*/ {
  //needs to be filled in
  }
stmt : assignExp SEMICOLON {
  //needs to be filled in
}
  | loc PLUSPLUS SEMICOLON {
  //needs to be filled in
  }
  | loc MINUSMINUS SEMICOLON {
  //needs to be filled in
  }
  | READ loc SEMICOLON {
  //needs to be filled in
  }
  | WRITE exp SEMICOLON {
  //needs to be filled in
  }
  | IF LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY {
  //needs to be filled in
  }
  | IF LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY ELSE LCURLY varDeclList stmtList RCURLY {
  //needs to be filled in
  }
  | WHILE LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY {
  //needs to be filled in
  }
  | RETURN exp SEMICOLON {
  //needs to be filled in
  }
  | RETURN SEMICOLON {
  //needs to be filled in
  }
  | fncall SEMICOLON {
  //needs to be filled in
  }
assignExp : loc ASSIGN exp {
  //needs to be filled in
  }
exp : assignExp {
  //needs to be filled in
  }
  | exp PLUS exp {
  //needs to be filled in
  }
  | exp MINUS exp {
  //needs to be filled in
  }
  | exp TIMES exp {
  //needs to be filled in
  }
  | exp DIVIDE exp {
  //needs to be filled in
  }
  | NOT exp {
  //needs to be filled in
  }
  | exp AND exp {
  //needs to be filled in
  }
  | exp OR exp {
  //needs to be filled in
  }
  | exp EQUALS exp {
  //needs to be filled in
  }
  | exp NOTEQUALS exp {
  //needs to be filled in
  }
  | exp LESS exp {
  //needs to be filled in
  }
  | exp GREATER exp {
  //needs to be filled in
  }
  | exp LESSEQ exp {
  //needs to be filled in
  }
  | exp GREATEREQ exp {
  //needs to be filled in
  }
  | MINUS term {
  //needs to be filled in
  }
  | term {
  //needs to be filled in
  }
term : loc {
//needs to be filled in
}
  | INTLITERAL {
  //needs to be filled in
  }
  | STRINGLITERAL {
  //needs to be filled in
  }
  | TRUE {
  //needs to be filled in
  }
  | FALSE {
  //needs to be filled in
  }
  | LPAREN exp RPAREN {
  //needs to be filled in
  }
  | fncall {
  //needs to be filled in
  }
fncall : id LPAREN RPAREN {
  //no args fn call
  //needs to be filled in
  }
  | id LPAREN actualList RPAREN {
  //with args fn call
  //needs to be filled in
  }
actualList : exp {
  //needs to be filled in
  }
  | actualList COMMA exp {
  //needs to be filled in
  }
type : INT { $$ = new IntNode($1->_line, $1->_column); }
primtype : INT {
  //needs to be filled in
  }
  | BOOL {
  //needs to be filled in
  }
  | VOID {
  //needs to be filled in
  }
indirect : indirect DEREF {
  //needs to be filled in
  }
  | /*epsilon*/ {
  //needs to be filled in
  }
loc : id {
  //needs to be filled in
  }
  | DEREF loc {
  //needs to be filled in
  }
id : ID { $$ = new IdNode($1); }
%%
void
lake::Parser::error(const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n";
}
