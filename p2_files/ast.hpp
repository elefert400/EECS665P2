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
class DeclListNode;
class DeclNode;
class TypeNode;
class IdNode;

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
};
/*ExpNode Sub-Section*/
class ExpNode : public ASTNode{
public:
	ExpNode(size_t line, size_t col) : ASTNode(line, col){}
};

class IntLitNode: public ExpNode{
public:
	IntLitNode(IntLitToken* token) : ExpNode(token->_line, token->_column){
		value = token->value();
	}
	void unparse(std::ostream& out, int indent);
private:
	int value;
};

class IdNode : public ExpNode{
public:
	IdNode(IDToken * token) : ExpNode(token->_line, token->_column){
		myStrVal = token->value();
	}
	void unparse(std::ostream& out, int indent);
private:
	std::string myStrVal;
};

class BinaryExpNode : public ExpNode{
public:
	BinaryExpNode(ExpNode* lExp , ExpNode* rExp) : ExpNode(0, 0){}
	void unparse(std::ostream& out, int indent);
}

class PlusNode()

class DeclListNode : public ASTNode{
public:
	DeclListNode(std::list<DeclNode *> * declsIn) : ASTNode(0, 0){
		myDecls = declsIn;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<DeclNode *> * myDecls;
};

class TypeNode : public ASTNode{
public:
	TypeNode(size_t lineIn, size_t colIn) : ASTNode(lineIn, colIn){
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
};

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



class IntNode : public TypeNode{
public:
	IntNode(size_t lineIn, size_t colIn): TypeNode(lineIn, colIn){ }
	void unparse(std::ostream& out, int indent);
};

} //End namespace lake

#endif
