#include "lexer.cpp"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int result(){
	
	cout<<"Hello Lexical Analysis Results!!!"<<endl;
	ifstream FileInPut;
	ofstream FileOutPut;
	FileInPut.open(FileNameIn);
	FileOutPut.open(FileNameOut);

	int Table_Addr=0;
	int value_lexer=0;
	char str[128];//the buffer for file reading

	init();//Keywords init	

/*逐列分析 By lexbuffer*/
	while(FileInPut.peek()!=EOF){
		FileInPut.getline(str,128,'\n');//global stringbuf
		lexbuffer=str;//with global scope
		value_lexer=lexer(value_lexer);
	}
/*Results Output By lexmem[]*/
	for(int i=0;i<lineno;i++){
		cout<<"Line :"<< i+1<<"	   ";
		FileOutPut<<"Line :"<< i+1<<"		";

		for(int j=0;j<lexmem[i].itNum;j++){	//inNum memo by lexan
			cout<<" "<<lexmem[i].array[j].lexptr<<" ";
			FileOutPut<<"  "<<lexmem[i].array[j].lexptr<<"  ";

		}

		cout<<'\n';
		FileOutPut<<'\n';
		for(int j=0;j<lexmem[i].itNum;j++){	//token output
			cout<<"		";
			FileOutPut<<"		";

			cout<<lexmem[i].array[j].scope;
			FileOutPut<<lexmem[i].array[j].scope;

			cout<<": ";
			FileOutPut<<": ";

			switch(lexmem[i].array[j].token){
				case 123:cout<<"<Keyword> :	   ";
				FileOutPut<<"<Keyword> :	   ";break;
				case 124:cout<<"<Operator> :	   ";
				FileOutPut<<"<Operator> :	   ";break;
				case 125:cout<<"<SpecialSymbol> :	   ";
				FileOutPut<<"<SpecialSymbol> :	   ";break;
				case 126:cout<<"<Identifier> :	   ";
				FileOutPut<<"<Identifier> :	   ";break;
				case 127:cout<<"<Char> :	   ";
				FileOutPut<<"<Char> :	   ";break;
				case 128:cout<<"<String> :	    ";
				FileOutPut<<"<String> :	    ";break;
				case 129:cout<<"<Int> :	    ";
				FileOutPut<<"<Int> :	    ";break;
				case 130:cout<<"<Float> :	   ";
				FileOutPut<<"<Float> :	   ";break;
				case 131:cout<<"<Comment> :	   ";
				FileOutPut<<"<Comment> :	   ";break;
				case 132:cout<<"<Error> :	   ";
				FileOutPut<<"<Error> :	   ";break;
				default: break;
			}
			cout<<lexmem[i].array[j].lexptr;
			FileOutPut<<lexmem[i].array[j].lexptr;

			cout<<'\n';
			FileOutPut<<'\n';

		}
	}			


	FileInPut.close();
	FileOutPut.close();
	
}
