#include "symbol.cpp"
using namespace std;

int NumOfKeywords=45;
int NumOfNon=33;
char *keywords[]={"case","continue","catch","char","class","const","default","do","double","else","enum","extends","final","finally","float","for","while","goto","if","implements","import","instanceof","int","interface","long","native","new","package","private","protected","public","return","short","static","String","strictfp","super","switch","synchornized","this","throw","throws","transient","try","void","volatile"};
char *Nonterminal[]={"Program","JavaClass","Modifier","ClassBody","ClassBodyDeclaration","DeclarationList","Declaration","VarDeclaration","TypeSpecifier","FunDeclaration","CompoundStmt","LocalDeclarations","StatementList","Statement","ExpressionStmt","ReturnStmt","RS1","Expression","SimpleExpression","S2","Relop","AdditiveExpression","Addop","Term","T2","Mulop","Factor","Statement","Loop","FunCall","Arg","IfS","WhileS"};



void init(){

	lineno=0;
	cout<<"符號表初始化中！！！\n";
	for(int p=0;p<NumOfKeywords;p++){
		insert(keywords[p],Keyword);
		//cout<<"symtable["<<p<<"].lexptr :"<<symtable[p].lexptr<<endl;
		//cout<<"symtable["<<p<<"].token :"<<symtable[p].token<<endl;
	}
}	
