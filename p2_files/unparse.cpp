#include "ast.hpp"

namespace lake{

void ProgramNode::unparse(std::ostream& out, int indent){
	myDeclList->unparse(out, indent);
}

void DeclListNode::unparse(std::ostream& out, int indent){
	/*
	Extended for loop: Iterates over every element in
	   *myDecls
	*/
	for (DeclNode * elt : *myDecls){
		elt->unparse(out, indent);
	}
}

void VarDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	this->myType->unparse(out, 0);
	out << " ";
	this->myId->unparse(out, 0);
	out << ";\n";
}

void FnDeclNode::unparse(std::ostream& out, int indent){

}

void FormalDeclNode::unparse(std::ostream& out, int indent){

}

void FormalsListNode::unparse(std::ostream& out, int indent){

}

void FnBodyNode::unparse(std::ostream& out, int indent){

}

void StmtListNode::unparse(std::ostream& out, int indent){

}

void ExpListNode::unparse(std::ostream& out, int indent){

}

void IdNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << this->strValue;
}

void IntNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << this->strValue;
}

void BoolNode::unparse(std::ostream& out, int indent){

}

void VoidNode::unparse(std::ostream& out, int indent){

}

void AssignStmtNode::unparse(std::ostream& out, int indent){

}

void PostIncStmtNode::unparse(std::ostream& out, int indent){

}

void PostDecStmtNode::unparse(std::ostream& out, int indent){

}

void ReadStmtNode::unparse(std::ostream& out, int indent){

}

void WriteStmtNode::unparse(std::ostream& out, int indent){

}

void IfStmtNode::unparse(std::ostream& out, int indent){

}

void IfElseStmtNode::unparse(std::ostream& out, int indent){

}

void WhileStmtNode::unparse(std::ostream& out, int indent){

}

void CallStmtNode::unparse(std::ostream& out, int indent){

}

void ReturnStmtNode::unparse(std::ostream& out, int indent){

}

void IntLitNode::unparse(std::ostream& out, int indent){

}

void StrLitNode::unparse(std::ostream& out, int indent){

}

void TrueNode::unparse(std::ostream& out, int indent){

}

void FalseNode::unparse(std::ostream& out, int indent){

}

void IdNode::unparse(std::ostream& out, int indent){

}

void DerefNode::unparse(std::ostream& out, int indent){

}

void AssignNode::unparse(std::ostream& out, int indent){

}

void CallExpNode::unparse(std::ostream& out, int indent){

}

void UnaryMinusNode::unparse(std::ostream& out, int indent){

}

void NotNode::unparse(std::ostream& out, int indent){

}

void PlusNode::unparse(std::ostream& out, int indent){

}

void MinusNode::unparse(std::ostream& out, int indent){

}

void TimesNode::unparse(std::ostream& out, int indent){

}

void DivideNode::unparse(std::ostream& out, int indent){

}

void AndNode::unparse(std::ostream& out, int indent){

}

void OrNode::unparse(std::ostream& out, int indent){

}

void EqualsNode::unparse(std::ostream& out, int indent){

}

void NotEqualsNode::unparse(std::ostream& out, int indent){

}

void LessNode::unparse(std::ostream& out, int indent){

}

void GreaterNode::unparse(std::ostream& out, int indent){

}

void LessEqNode::unparse(std::ostream& out, int indent){

}

void GreaterEqNode::unparse(std::ostream& out, int indent){

}

} // End namespace lake
