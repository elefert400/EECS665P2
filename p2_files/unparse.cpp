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
	if(myDecls == nullptr){
		out << "";
	}
	else{
		for (DeclNode * elt : *myDecls){
			elt->unparse(out, indent);
			out << "\n";
		}
	}
}

void VarDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	this->myType->unparse(out, indent);
	out << " ";
	this->myId->unparse(out, indent);
	out << ";\n";
}

void FnDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myType->unparse(out, indent);
	out << " ";
	myId->unparse(out, indent);
	myFormals->unparse(out, indent);
	myBody->unparse(out, indent+4);
}

void FormalDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myType->unparse(out, indent);
	out << " ";
	myId->unparse(out, indent);
}

void FormalsListNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	if(myFormals == nullptr){
		out << "()";
		//return;
	}
	else{
		out << "(";
		for (FormalDeclNode * elt : *myFormals){
			elt->unparse(out, indent);
			if(elt == myFormals->back){
				//Don't print comma
			}
			else{
				out << ", ";
			}			
		}
		out << ")";
	}	
}

void FnBodyNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "{";
	myDeclList->unparse(out, indent+4);
	myStmtList->unparse(out, indent+4);
	out << "\n}\n";
}

void StmtListNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	if(myStmtList == nullptr){
		out << "";		
	}
	else{
		for (StmtNode * elt : *myStmtList){
			elt->unparse(out, indent);
		}
	}
}

void ExpListNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	if(myExpList == nullptr){
		out << "";		
	}
	else{
		for (ExpNode * elt : *myExpList){
			elt->unparse(out, indent);
			if(elt == myExpList->back){
				//Don't print comma
			}
			else{
				out << ", ";
			}	
		}
	}
}

void IdNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	if(derefDepth > 0){
		for(int i=0; i < derefDepth;i++){
			out << "@";
		}
	}
	out << this->strValue;
}

void IntNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "int";
	if(indirDepth > 0){
		for(int i=0; i < indirDepth;i++){
			out << "@";
		}
	}
}

void BoolNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "bool";
	if(indirDepth > 0){
		for(int i=0; i < indirDepth;i++){
			out << "@";
		}
	}
}

void VoidNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "void";
	if(indirDepth > 0){
		for(int i=0; i < indirDepth;i++){
			out << "@";
		}
	}
}

void StmtNode::unparse(std::ostream& out, int indent){
	//doIndent(out, indent);
}

void AssignStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myAssign->unparse(out, indent);
	out << ";\n";
}

void PostIncStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myId->unparse(out, indent);
	out << "++;\n";
}

void PostDecStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myId->unparse(out, indent);
	out << "--;\n";
}

void ReadStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "read ";
	myId->unparse(out, indent);
	out << ";\n";
}

void WriteStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "write ";
	myExp->unparse(out, indent);
	out << ";\n";
}

void IfStmtNode::unparse(std::ostream& out, int indent){
 	doIndent(out, indent);
	out << "if(";
	myExp->unparse(out, indent);
	out << "){\n";
	myDeclList->unparse(out, indent+4);
	myStmtList->unparse(out, indent+4);
	out << "}\n"; 
}

void IfElseStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "if(";
	myExp->unparse(out, indent);
	out << "){\n";
	myDeclList_if->unparse(out, indent+4);
	myStmtList_if->unparse(out, indent+4);
	out << "\n}\n";
	out << "else{\n";
	myDeclList_else->unparse(out, indent+4);
	myStmtList_else->unparse(out, indent+4);
	out << "\n}\n";
}

void WhileStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "while(";
	myExp->unparse(out, indent);
	out << "){\n";
	myDeclList->unparse(out, indent+4);
	myStmtList->unparse(out, indent+4);
	out << "\n}\n";
}

void CallStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myCallExp->unparse(out, indent);
	out << ";\n";
}

void ReturnStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "return";
	if(myExp == nullptr){
		//dont unparse nullptr
	}
	else{
		out << "(";
		myExp->unparse(out, indent);
		out << ")";
	}
	out << ";\n";
}

void ExpNode::unparse(std::ostream& out, int indent){
	//doIndent(out, indent);
}


void IntLitNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << value;
}

void StrLitNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << value;
}

void TrueNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "True";
}

void FalseNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "False";
}

void IdNode::unparse(std::ostream& out, int indent){
	doIndent(out, 0);
	out << strValue;
}

void DerefNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myExp->unparse(out, indent);
	myId->unparse(out, indent);
}

void AssignNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " = ";
	myRightExp->unparse(out, indent);
}

void CallExpNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myId->unparse(out, indent);
	out << "(";
	myExpList->unparse(out, indent);
	out << ")";
}

void UnaryExpNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "(";
	myExp->unparse(out, indent);
	out << ")";
}

void UnaryMinusNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "(";
	myExp->unparse(out, indent);
	out << ")";
}

void NotNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "!";
	myExp->unparse(out, indent);
}

void PlusNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " + ";
	myRightExp->unparse(out, indent);
}

void MinusNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " - ";
	myRightExp->unparse(out, indent);
}

void TimesNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " * ";
	myRightExp->unparse(out, indent);
}

void DivideNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " / ";
	myRightExp->unparse(out, indent);
}

void AndNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " && ";
	myRightExp->unparse(out, indent);
}

void OrNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " || ";
	myRightExp->unparse(out, indent);
}

void EqualsNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " == ";
	myRightExp->unparse(out, indent);
}

void NotEqualsNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " != ";
	myRightExp->unparse(out, indent);
}

void LessNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " < ";
	myRightExp->unparse(out, indent);
}

void GreaterNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " > ";
	myRightExp->unparse(out, indent);
}

void LessEqNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " <= ";
	myRightExp->unparse(out, indent);
}

void GreaterEqNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myLeftExp->unparse(out, indent);
	out << " >= ";
	myRightExp->unparse(out, indent);
}

} // End namespace lake
