#include<iostream>
using namespace std;

#define BSIZE 128
#define TSIZE 100
#define NONE -1
#define EOS '\0'

/*define token*/
#define Keyword 123
#define Operator 124
#define SpecialSymbol 125
#define Identifier 126
#define Char 127
#define String 128
#define Int 129
#define Float 130
#define Comment 131
#define Error 132

int tokenval;//for analysis
int lineno=0;//for result
bool NotNewRaw=true;//for analysis & fileinput
char FileNameIn[]="TestFile1.java";
char FileNameIn2[]="grammarSLR.txt";
char FileNameOut[]="Result.txt";
char FileNameOut2[]="output1.txt";
char FileNameOut3[]="output2.txt";
char FileNameOut4[]="output3.txt";

char *lexbuffer;//for analysis

struct entry{		//table entry
	char lexptr[500];
	int token;
	int scope;
};

//fot analysis
entry symtable[TSIZE];

//for result
struct SecondDir{
	entry array[128];
	int itNum;

	};

SecondDir lexmem[100];

//for view of generator
struct R{
	char RHS[50];
};
struct rule{
	char LHS[50];
	R array[15];
	int rNum;
};

rule CFG[100];

//for parser
int prod_mem[256];//memo the order of parsing by rule

//for IG






