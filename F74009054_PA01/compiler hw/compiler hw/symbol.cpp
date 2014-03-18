#include"error.cpp"
#include<cstring>
using namespace std;
#define STRMAX 999 //size of lexemes array
#define SYMMAX 100 //size of symtable

char lexemes[STRMAX];
int lastchar = -1;
//entry symtable[SYMMAX];

int lastentry =0;

int lookup(char *s){
	

	cout<<"I'm lookup~~ str is :"<<s<<endl;
	int p ;
	for(p = lastentry; p > 0; p-=1){
		if(strcmp(symtable[p].lexptr,s)==0)
			return symtable[p].token;//找到後回傳token
	}
	return 0;
}


int insert(char *s,int tok){
	
	cout<<"I'm insert~~ str is :"<<s<<endl;
	int len;
	len = strlen(s);
	if(lastentry + 1 >=SYMMAX){
		error("symbol table full");
	}
	if(lastchar + len + 1 >=STRMAX){
		error("lexemes array full");
	}
	lastentry +=1;
	symtable[lastentry].token = tok;
//	symtable[lastentry].lexptr =&lexemes[lastchar + 1];
	lastchar +=len + 1;
	strcpy(symtable[lastentry].lexptr,s);
	
//	cout<<"I'm symtable[0] :"<<symtable[lastentry].lexptr;
	
	return lastentry;//回傳該次插入的位置下標
	
}

