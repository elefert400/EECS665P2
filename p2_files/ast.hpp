#ifndef LAKE_AST_HPP
#define LAKE_AST_HPP

#include <ostream>
#include <list>
#include "tokens.hpp"

//Here is a suggestion for some of the different kinds of AST nodes
// and what kinds of children you might want to give them.
// All of these kinds of AST nodes are subclasses of ASTNode.
// Please note that you do NOT have to use this AST structure and
// you should feel free to include additional classes or not use
// the ones provided here. All that matters for P2 is that you
// unparse the tree as the oracle does.

//
// Indentation indicates further subclassing:
//
//     Subclass		Children
//     --------		------
//     ProgramNode	DeclListNode
//     DeclListNode	linked list of DeclNode
//     DeclNode
//       VarDeclNode	TypeNode, IdNode, int
//       FnDeclNode	TypeNode, IdNode, FormalsListNode, FnBodyNode
//       FormalDeclNode    TypeNode, IdNode
//
//     FormalsListNode     linked list of FormalDeclNode
//     FnBodyNode          DeclListNode, StmtListNode
//     StmtListNode        linked list of StmtNode
//     ExpListNode         linked list of ExpNode
//
//     TypeNode:
//       IntNode           -- none --
//       BoolNode          -- none --
//       VoidNode          -- none --
//       PtrNode           IdNode (base type), (int for indirection level)
//
//     StmtNode:
//       AssignStmtNode      AssignNode
//       PostIncStmtNode     ExpNode
//       PostDecStmtNode     ExpNode
//       ReadStmtNode        ExpNode
//       WriteStmtNode       ExpNode
//       IfStmtNode          ExpNode, DeclListNode, StmtListNode
//       IfElseStmtNode      ExpNode, DeclListNode, StmtListNode,
//                                    DeclListNode, StmtListNode
//       WhileStmtNode       ExpNode, DeclListNode, StmtListNode
//       CallStmtNode        CallExpNode
//       ReturnStmtNode      ExpNode
//
//     ExpNode:
//       IntLitNode          -- none --
//       StrLitNode          -- none --
//       TrueNode            -- none --
//       FalseNode           -- none --
//       IdNode              -- none --
//       DerefNode           ExpNode, IdNode
//       AssignNode          ExpNode, ExpNode
//       CallExpNode         IdNode, ExpListNode
//       UnaryExpNode        ExpNode
//         UnaryMinusNode
//         NotNode
//       BinaryExpNode       ExpNode ExpNode
//         PlusNode
//         MinusNode
//         TimesNode
//         DivideNode
//         AndNode
//         OrNode
//         EqualsNode
//         NotEqualsNode
//         LessNode
//         GreaterNode
//         LessEqNode
//         GreaterEqNode
//
//
// Here are the different kinds of AST nodes again, organized according to
// whether they are leaves, internal nodes with linked lists of children, or
// internal nodes with a fixed number of children:
//
// (1) Leaf nodes:
//        IntNode,   BoolNode,  VoidNode,  IntLitNode,  StrLitNode,
//        TrueNode,  FalseNode, IdNode
//
// (2) Internal nodes with (possibly empty) lists of children:
//        DeclListNode, FormalsListNode, StmtListNode, ExpListNode
//
// (3) Internal nodes with fixed numbers of direct descendants:
//        ProgramNode,     VarDeclNode,     FnDeclNode,     FormalDeclNode,
//        FnBodyNode,      AssignStmtNode,
//        PostIncStmtNode, PostDecStmtNode, ReadStmtNode,   WriteStmtNode
//        IfStmtNode,      IfElseStmtNode,  WhileStmtNode,  CallStmtNode
//        ReturnStmtNode,  CallExpNode,
//        UnaryExpNode,    BinaryExpNode,   UnaryMinusNode, NotNode,
//        PlusNode,        MinusNode,       TimesNode,      DivideNode,
//        AndNode,         OrNode,          EqualsNode,     NotEqualsNode,
//        LessNode,        GreaterNode,     LessEqNode,     GreaterEqNode
//
// **********************************************************************

// **********************************************************************
// ASTnode class (base class for all other kinds of nodes)
// **********************************************************************

namespace lake{

/* You may find it useful to forward declare AST subclasses
   here so that you don't have to worry about the order
   in which you declare your subclasses below */

class ProgramNode;
class DeclListNode;
class DeclNode;
class VarDeclNode;
class FnDeclNode;
class FormalDeclNode;
class FormalsListNode;
class FnBodyNode;
class StmtListNode;
class ExpListNode;
class TypeNode;
class IntNode;
class BoolNode;
class VoidNode;
class StmtNode;
class AssignStmtNode;
class PostIncStmtNode;
class PostDecStmtNode;
class ReadStmtNode;
class WriteStmtNode;
class IfStmtNode;
class IfElseStmtNode;
class WhileStmtNode;
class CallStmtNode;
class ReturnStmtNode;
class ExpNode;
class IntLitNode;
class StrLitNode;
class TrueNode;
class FalseNode;
class IdNode;
class DerefNode;
class AssignNode;
class CallExpNode;
class UnaryExpNode;
class UnaryMinusNode;
class NotNode;
class BinaryExpNode;
class PlusNode;
class MinusNode;
class DivideNode;
class AndNode;
class OrNode;
class EqualsNode;
class NotEqualsNode;
class LessNode;
class GreaterNode;
class LessEqNode;
class GreaterEqNode;


class ASTNode{
public:
	ASTNode(size_t lineIn, size_t colIn){
		this->line = lineIn;
		this->col = colIn;
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
	void doIndent(std::ostream& out, int indent){
		for (int k = 0 ; k < indent; k++){ out << " "; }
	}
	size_t getLine(){ return line; }
	size_t getCol() { return col; }
private:
	size_t line;
	size_t col;
};

class ProgramNode : public ASTNode{
public:
	ProgramNode(DeclListNode * declsIn) : ASTNode(0, 0){
		myDeclList = declsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	DeclListNode * myDeclList;
};

class DeclNode : public ASTNode{
public:
	DeclNode(size_t line, size_t col) : ASTNode(line, col){}
	void unparse(std::ostream& out, int indent);
};

class ExpNode : public ASTNode{
public:
	ExpNode(size_t line, size_t col) : ASTNode(line, col){}
	void unparse(std::ostream& out, int indent);
};

class AssignNode : public ExpNode{
public:
	AssignNode(ExpNode* lExp, ExpNode* rExp) : ExpNode(lExp->getLine(), lExp->getCol()){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class UnaryExpNode : public ExpNode{
public:
	UnaryExpNode(ExpNode* expIn) : ExpNode(expIn->getLine(), expIn->getCol()){
		myExp = expIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myExp;
};

class BinaryExpNode : public ExpNode{
public:
	BinaryExpNode(ExpNode* lExp , ExpNode* rExp) : ExpNode(lExp->getLine(), lExp->getCol()){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class DeclListNode : public ASTNode{
public:
	DeclListNode() : ASTNode(0, 0){
		myDecls = nullptr;
	}
	DeclListNode(std::list<DeclNode *> * declsIn) : ASTNode(0, 0){
		myDecls = declsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<DeclNode *> * myDecls;
};

class TypeNode : public ASTNode{
public:
	TypeNode(size_t line, size_t col) : ASTNode(line, col){
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
	int indirDepth;
};

class StmtNode : public ASTNode{
public:
	StmtNode(size_t line, size_t col) : ASTNode(line, col){ };
	void unparse(std::ostream& out, int indent);
};



class FormalsListNode : public ASTNode{
public:
	FormalsListNode() : ASTNode(0, 0){
		myFormals = nullptr;
	}
	FormalsListNode(std::list<FormalDeclNode *> * formalsIn) : ASTNode(0, 0){
		myFormals = formalsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<FormalDeclNode *> * myFormals;
};

class FnBodyNode : public ASTNode{
public:
	FnBodyNode(DeclListNode* declListIn, StmtListNode* stmtListIn) : ASTNode(0, 0){
		myDeclList = declListIn;
		myStmtList = stmtListIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	DeclListNode* myDeclList;
	StmtListNode* myStmtList;
};

class StmtListNode : public ASTNode{
public:
	StmtListNode(std::list<StmtNode *> * stmtListIn) : ASTNode(0, 0){
		myStmtList = stmtListIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<StmtNode *> * myStmtList;
};

class ExpListNode : public ASTNode{
public:
	ExpListNode(std::list<ExpNode *> * expListIn) : ASTNode(0, 0){
		myExpList = expListIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<ExpNode *> * myExpList;
};

/*ExpNode Sub-Section---------------------------------------------------------------------------------------*/


class IntLitNode: public ExpNode{
public:
	IntLitNode(IntLitToken* token) : ExpNode(token->_line, token->_column){
		value = token->value();
	}
	void unparse(std::ostream& out, int indent);
private:
	int value;
};

class StrLitNode : public ExpNode{
public:
	StrLitNode(StringLitToken* token) : ExpNode(token->_line, token->_column){
		value = token->value();
	}
	void unparse(std::ostream& out, int indent);
private:
	std::string value;
};

class TrueNode : public ExpNode{
public:
	TrueNode(NoArgToken* token) : ExpNode(token->_line, token->_column){ }
	void unparse(std::ostream& out, int indent);
};

class FalseNode : public ExpNode{
public:
	FalseNode(NoArgToken* token) : ExpNode(token->_line, token->_column){ }
	void unparse(std::ostream& out, int indent);
};

class IdNode : public ExpNode{
public:
	IdNode(IDToken * token) : ExpNode(token->_line, token->_column){
		strValue = token->value();
		derefDepth = 0;
	}
	void unparse(std::ostream& out, int indent);
	int derefDepth;
private:
	std::string strValue;
};

class DerefNode : public ExpNode{
public:
	DerefNode(ExpNode* expIn, IdNode* idIn) : ExpNode(expIn->getLine(), expIn->getCol()){
		myExp = expIn;
		myId = idIn;
	}
	void unparse(std::ostream& out, int indent);
	//void incr_Deref_Count();

private:
	ExpNode* myExp;
	IdNode* myId;
};



class CallExpNode : public ExpNode{
public:
	CallExpNode(IdNode* idIn, ExpListNode* expListIn) : ExpNode(idIn->getLine(), idIn->getCol()){
		myId = idIn;
		myExpList = expListIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	IdNode* myId;
	ExpListNode* myExpList;
};



class UnaryMinusNode : public UnaryExpNode{
public:
	UnaryMinusNode(ExpNode* expIn) : UnaryExpNode(expIn){
		myExp = expIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myExp;
};

class NotNode : public UnaryExpNode{
public:
	NotNode(ExpNode* expIn) : UnaryExpNode(expIn){
		myExp = expIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myExp;
};



class PlusNode : public BinaryExpNode{
public:
	PlusNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class MinusNode : public BinaryExpNode{
public:
	MinusNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class TimesNode : public BinaryExpNode{
public:
	TimesNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class DivideNode : public BinaryExpNode{
public:
	DivideNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class AndNode : public BinaryExpNode{
public:
	AndNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class OrNode : public BinaryExpNode{
public:
	OrNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class EqualsNode : public BinaryExpNode{
public:
	EqualsNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class NotEqualsNode : public BinaryExpNode{
public:
	NotEqualsNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class LessNode : public BinaryExpNode{
public:
	LessNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class GreaterNode : public BinaryExpNode{
public:
	GreaterNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class LessEqNode : public BinaryExpNode{
public:
	LessEqNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};

class GreaterEqNode : public BinaryExpNode{
public:
	GreaterEqNode(ExpNode* lExp, ExpNode* rExp) : BinaryExpNode(lExp, rExp){
		myLeftExp = lExp;
		myRightExp = rExp;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myLeftExp;
	ExpNode* myRightExp;
};





/*LinkedList Nodes--------------------------------------------------------------------------------------------*/








/*DeclNode Subclasses--------------------------------------------------------------------------------------------*/
class VarDeclNode : public DeclNode{
public:
	VarDeclNode(TypeNode * type, IdNode * id) : DeclNode(type->getLine(), type->getCol()){
		myType = type;
		myId = id;
	}
	void unparse(std::ostream& out, int indent);
private:
	TypeNode * myType;
	IdNode * myId;
};

class FnDeclNode : public DeclNode{
public:
	FnDeclNode(TypeNode* type, IdNode* id, FormalsListNode* formals, FnBodyNode* body) : DeclNode(type->getLine(), type->getCol()){
		myType = type;
		myId = id;
		myFormals = formals;
		myBody = body;
	}
	void unparse(std::ostream& out, int indent);
private:
	TypeNode * myType;
	IdNode * myId;
	FormalsListNode* myFormals;
	FnBodyNode* myBody;
};

class FormalDeclNode : public DeclNode{
public:
	FormalDeclNode(TypeNode * type, IdNode * id) : DeclNode(type->getLine(), type->getCol()){
		myType = type;
		myId = id;
	}
	void unparse(std::ostream& out, int indent);
private:
	TypeNode * myType;
	IdNode * myId;
};







/*TypeNode Subclasses---------------------------------------------------------------------------------------------*/

class IntNode : public TypeNode{
public:
	IntNode(NoArgToken* token) : TypeNode(token->_line, token->_column){ }
	void unparse(std::ostream& out, int indent);
};

class BoolNode : public TypeNode{
public:
	BoolNode(NoArgToken* token) : TypeNode(token->_line, token->_column){ }
	void unparse(std::ostream& out, int indent);
};

class VoidNode : public TypeNode{
public:
	VoidNode(NoArgToken* token) : TypeNode(token->_line, token->_column){ }
	void unparse(std::ostream& out, int indent);
};









/*StmtNode Subclasses-----------------------------------------------------------------------------------------------*/


class AssignStmtNode : public StmtNode{
public:
	AssignStmtNode(AssignNode* assignIn) : StmtNode(assignIn->getLine(), assignIn->getCol()){
		myAssign = assignIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	AssignNode* myAssign;
};

class PostIncStmtNode : public StmtNode{
public:
	PostIncStmtNode(IdNode* idIn) : StmtNode(idIn->getLine(), idIn->getCol()){
		myId = idIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	IdNode* myId;
};

class PostDecStmtNode : public StmtNode{
public:
	PostDecStmtNode(IdNode* idIn) : StmtNode(idIn->getLine(), idIn->getCol()){
		myId = idIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	IdNode* myId;
};

class ReadStmtNode : public StmtNode{
public:
	ReadStmtNode(IdNode* idIn) : StmtNode(idIn->getLine(), idIn->getCol()){
		myId = idIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	IdNode* myId;
};

class WriteStmtNode : public StmtNode{
public:
	WriteStmtNode(ExpNode* expIn) : StmtNode(expIn->getLine(), expIn->getCol()){
		myExp = expIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myExp;
};

class IfStmtNode : public StmtNode{
public:
	IfStmtNode(ExpNode* expIn, DeclListNode* declListIn, StmtListNode* stmtListIn) :
		StmtNode(expIn->getLine(), expIn->getCol()){
			myExp = expIn;
			myDeclList = declListIn;
			myStmtList = stmtListIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myExp;
	DeclListNode* myDeclList;
	StmtListNode* myStmtList;
};

class IfElseStmtNode : public StmtNode{
public:
	IfElseStmtNode(ExpNode* expIn, DeclListNode* declListIn_if, StmtListNode* stmtListIn_if,
		DeclListNode* declListIn_else, StmtListNode* stmtListIn_else) :
		StmtNode(expIn->getLine(), expIn->getCol()){
			myExp = expIn;
			myDeclList_if = declListIn_if;
			myStmtList_if = stmtListIn_if;
			myDeclList_else = declListIn_else;
			myStmtList_else = stmtListIn_else;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myExp;
	DeclListNode* myDeclList_if;
	StmtListNode* myStmtList_if;
	DeclListNode* myDeclList_else;
	StmtListNode* myStmtList_else;
};

class WhileStmtNode : public StmtNode{
public:
	WhileStmtNode(ExpNode* expIn, DeclListNode* declListIn, StmtListNode* stmtListIn) : StmtNode(expIn->getLine(), expIn->getCol()){
			myExp = expIn;
			myDeclList = declListIn;
			myStmtList = stmtListIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myExp;
	DeclListNode* myDeclList;
	StmtListNode* myStmtList;
};

class CallStmtNode : public StmtNode{
public:
	CallStmtNode(CallExpNode* callExpIn) : StmtNode(callExpIn->getLine(), callExpIn->getCol()){
		myCallExp = callExpIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	CallExpNode* myCallExp;
};

class ReturnStmtNode : public StmtNode{
public:
	ReturnStmtNode(Token* returnToken, ExpNode* expIn) :
		StmtNode(returnToken->_line, returnToken->_column){
		myExp = expIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	ExpNode* myExp;
};

} //End namespace lake

#endif
