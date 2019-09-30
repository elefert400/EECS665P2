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
  size_t counterTrans;

	lake::Token * tokenValue;
	lake::IDToken * idTokenValue;
  lake::IntLitToken * intTokenValue;
	lake::StringLitToken * strTokenValue;

	lake::ASTNode * astNode;
	lake::ProgramNode * programNode;
	std::list<DeclNode *> * declList;
	lake::DeclNode * declNode;
	lake::VarDeclNode * varDeclNode;
	lake::TypeNode * typeNode;
	lake::IdNode * idNode;
  lake::FnDeclNode * fnDecl;
  lake::FormalDeclNode * formalDecl;
	std::list<FormalDeclNode *> * formalsList;
	lake::FormalsListNode * formalsType;
	lake::FnBodyNode * fnBody;
  std::list<StmtNode *> * stmtList;
	std::list<ExpNode *> * expList;
  lake::StmtNode * stmtNode;
  lake::ExpNode * exp;
  lake::AssignNode * assignNode;
  lake::CallExpNode * callNode;
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
%left DOT
%right ASSIGN
$left OR
%left AND
%nonassoc LESS
%nonassoc GREATER
%nonassoc LESSEQ
%nonassoc GREATEREQ
%nonassoc EQUALS
%nonassoc NOTEQUALS
%left CROSS DASH
%left STAR SLASH
%left NOT
%precedence DEREF
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
		$$ = $1;
		}
    | fnDecl {
    $$ = $1;
    }
varDecl : type id SEMICOLON {
		$$ = new VarDeclNode($1, $2);
			    }
fnDecl : type id formals fnBody {
  $$ = new FnDeclNode($1, $2, $3, $4);
}
formals : LPAREN RPAREN {
  $$ = new FormalsListNode(new std::list<FormalDeclNode*> ();)
}
  | LPAREN formalsList RPAREN {
  $$ = new FormalsListNode($2);
  }
formalsList : formalDecl {
  $$ = new std::list<FormalDeclNode*>;
  $$->push_back($1);
}
  | formalDecl COMMA formalsList {
  $3->push_front($1);
  $$ = $3;
  }
formalDecl : type id {
  $$ = new FormalDeclNode($1, $2);
}
fnBody : LCURLY varDeclList stmtList RCURLY {
  $$ = new FnBodyNode($2, $3);
}
stmtList : stmtList stmt {
  $$ = $1;
  $1->push_back($2);
}
  | /*epsilon*/ {
  $$ = new std::list<StmtNode*> ();
  }
stmt : assignExp SEMICOLON{
  $$ = new AssignStmtNode($1);
  }
  | loc PLUSPLUS SEMICOLON {
  $$ = new PostIncStmtNode($1);
  }
  | loc MINUSMINUS SEMICOLON {
  $$ = new PostDecStmtNode($1);
  }
  | READ loc SEMICOLON {
  $$ = new ReadStmtNode($2);
  }
  | WRITE exp SEMICOLON {
  $$ = new WriteStmtNode($2);
  }
  | IF LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY {
  $$ = new IfStmtNode($3, $6, $7);
  }
  | IF LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY ELSE LCURLY varDeclList stmtList RCURLY {
  $$ = new IfElseStmtNode($3, $6, $7, $11, $12);
  }
  | WHILE LPAREN exp RPAREN LCURLY varDeclList stmtList RCURLY {
  $$ = new WhileStmtNode($3, $6, $7);
  }
  | RETURN exp SEMICOLON {
  $$ = new ReturnStmtNode($1, $2);
  }
  | RETURN SEMICOLON {
  $$ = new ReturnStmtNode($1, nullptr);
  }
  | fncall SEMICOLON {
  $$ = new CallStmtNode($1);
  }
assignExp : loc ASSIGN exp {
  $$ = new AssignNode($1, $3);
  }
exp :  exp PLUS exp {
  $$ = new PlusNode($1, $3);
  }
  | exp MINUS exp {
  $$ = new MinusNode($1, $3);
  }
  | exp TIMES exp {
  $$ = new TimesNode($1, $3);
  }
  | exp DIVIDE exp {
  $$ = new DivideNode($1, $3);
  }
  | NOT exp {
  $$ = new NotNode($2);
  }
  | exp AND exp {
  $$ = new AndNode($1, $3);
  }
  | exp OR exp {
  $$ = new OrNode($1, $3);
  }
  | exp EQUALS exp {
  $$ = new EqualsNode($1, $3);
  }
  | exp NOTEQUALS exp {
  $$ = new NotEqualsNode($1, $3);
  }
  | exp LESS exp {
  $$ = new LessNode($1, $3);
  }
  | exp GREATER exp {
  $$ = new GreaterNode($1, $3);
  }
  | exp LESSEQ exp {
  $$ = new LessEqNode($1, $3);
  }
  | exp GREATEREQ exp {
  $$ = new GreaterEqNode($1, $3);
  }
  | MINUS term {
  $$ = new UnaryMinusNode($2);
  }
  | term {
  $$ = $1;
  }
term : loc {
  $$ = $1;
  }
  | INTLITERAL {
  $$ = new IntLitNode($1);
  }
  | STRINGLITERAL {
  $$ = new StrLitNode($1);
  }
  | TRUE {
  $$ = new TrueNode($1);
  }
  | FALSE {
  $$ = new FalseNode($1);
  }
  | LPAREN exp RPAREN {
  $$ = $2;
  }
  | fncall {
  $$ = $2;
  }
fncall : id LPAREN RPAREN {
  //no args fn call
  $$ = new CallExpNode($1, new std::list<ExpNode*>());
  }
  | id LPAREN actualList RPAREN {
  //with args fn call
  $$ = new CallExpNode($1, new std::list<ExpNode*>($3));
  }
actualList : exp {
  $$ = new std::list<ExpNode*> ();
  $$->push_back($1);
  }
  | actualList COMMA exp {
  $$ = $1;
  $$->push_back($3);
  }
type : primtype indirect {
  $$ = $1;
  $$->indirDepth = $2;
  }
primtype : INT {
  $$ = new IntNode($1);
  }
  | BOOL {
  $$ = new BoolNode($1);
  }
  | VOID {
  $$ = new VoidNode($1);
  }
indirect : indirect DEREF {
  $$ = $1 + 1;
  }
  | /*epsilon*/ {
  $$ = 0;
  }
loc : id {
  $$ = new IdNode($1);
  }
  | DEREF loc {
  $2->derefDepth += 1;
  $$ = $2;
  }
id : ID { $$ = new IdNode($1); }
%%
void
lake::Parser::error(const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n";
}
