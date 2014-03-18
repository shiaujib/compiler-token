#include"init.cpp"
#include<iostream>
using namespace std;
int state=0;
int start=0;
int scope=0;
int lexical_value=0;// return
bool exit=0;
char gtmp[128];


int memo(char *ch,int tok,int tmp,int n){

		

		if(tmp==0){
				insert(ch,tok);
				strcpy(lexmem[lineno].array[n].lexptr,ch);
				lexmem[lineno].array[n].token =tok;
				lexmem[lineno].array[n].scope =scope;
			}
		else{
				strcpy(lexmem[lineno].array[n].lexptr,ch);
				lexmem[lineno].array[n].token =tmp;
				lexmem[lineno].array[n].scope =scope;
				
			}
return 0;
}




int fail(){
	
//	forward=token_beginning;
	switch(start){
		case 0: start=9;break;
		case 9: start=12;break;
		case 12: start=18;break;
		case 18: start=41;break;
		case 41: cout<<"Compile error~";start=0;break; 
		default: break;//error
	}
	return start;
}

int lexer(int stat){
	cout<<"Welcome to the lex Analyzer\n";
	int itcout=0;//該列單元個數
	int bufid=0;
	int chfid=0;
	char chbuf1[3];
	char chbuf2[20];
	char chbuf3[64];
	char chbuf4[500];
	char chbuf5[1000];

	int toktmp;
	char c;//lookahead
	
	state=stat;//start state
	
//	cin>>state;
	while(1){
		
		switch(state){
		case 0://Operator START && LexStart :test c weather operator or not
			chfid=0;	// chbuf init
			start=0;
			chbuf1[0]='\0';
			c=lexbuffer[bufid++];
			cout<<" State :"<<state<<" lookhead : "<<c<<" lexbuffer : "<<lexbuffer<<endl;
//			cin>>exit;
			if(exit==1){
				return 0;
			}
			else if(isspace(c)||c=='\t'||c=='\n'||c=='\0'){
				state=0;
				if(c=='!'||c=='\n'||c=='\0'){
                                 lexmem[lineno++].itNum=itcout;
                                 return 0;//line finished
                    		 }
				//lb++
			}
			else if (c=='<') state =1;
			else if (c=='=') state =5;
			else if (c=='>') state =6;
			else state = fail();
			break;
		case 1: //followed by = or > or other

			chbuf1[chfid++]=c;	//注意避免過長
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;
			
			if(c=='='){
				state =2;
				chbuf1[chfid++]=c;	
				chbuf1[chfid]='\0';
			}
			else if(c=='<'){
				state=39 ;// < << ,< <= or << ~~
				chbuf1[chfid++]=c;	
				chbuf1[chfid]='\0';
			}
			else if(c=='>'){
				state=3;
				chbuf1[chfid++]=c;	
				chbuf1[chfid]='\0';
			}
			else state =4;
			break;
		case 2://chbuf will be <= in this case
			
			 toktmp=lookup(chbuf1);
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			memo(chbuf1,Operator,toktmp,itcout);
			itcout++;
			state=0;
			break;
			//return Operator	

		case 3://chbuf will be <> in this case
			
			toktmp=lookup(chbuf1);
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			memo(chbuf1,Operator,toktmp,itcout);
			itcout++;
			state=0;
			break;

			//return Operator	


		case 4:	//chbuf is still <
			bufid--;//組合錯誤 多讀一位元 下標退回一格
			toktmp=lookup(chbuf1);
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			memo(chbuf1,Operator,toktmp,itcout);
			itcout++;
			state=0;
			break;

			//return Operator	

		case 5://chbuf will be =
			
			chbuf1[chfid++]=c;	//注意避免過長
			chbuf1[chfid]='\0';
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;
			if(c=='='){// == equal?
				chbuf1[chfid++]=c;	
				chbuf1[chfid]='\0';
			}
			toktmp=0;
			memo(chbuf1,Operator,toktmp,itcout);
			itcout++;
			state=0;
			break;

			//return Operator
		case 6://chbuf will be >
			chbuf1[chfid++]=c;
			chbuf1[chfid]='\0';
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			chbuf1[chfid++]=c;	//注意避免過長
			if(c=='=')state =7;
			else if(c=='>')state=40;// >> >,>> = or >> ~~
			else state =8;
			break;
		case 7://chbuf will be >=
			
			chbuf1[chfid++]=c;	//注意避免過長
			 toktmp=lookup(chbuf1);
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			memo(chbuf1,Operator,toktmp,itcout);
			itcout++;
			state=0;
			break;
		case 8://chbuf1 is still >
			bufid--;//組合錯誤 多讀一位元 下標退回一格
		 	toktmp=lookup(chbuf1);
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			memo(chbuf1,Operator,toktmp,itcout);
			itcout++;
			state=0;
			break;
		case 9:	//Letter START :c has been assigned 	by case0 ~
			chbuf2[0]='\0';
			if(isalpha(c)) state=10;
			else state = fail();
			cout<<"State :"<<state<<"lookhead :"<<c<<" lexbuffer: "<<lexbuffer<<endl;

			break;
		case 10:	
			chbuf2[chfid++]=c;	
			chbuf2[chfid]='\0';
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			if(isalpha(c)||isdigit(c)||c=='.'||c=='_'||c=='$'){
				if(c=='.'||c=='_'||c=='$'){
					chbuf2[chfid++]=c;	
					chbuf2[chfid]='\0';
					c=lexbuffer[bufid++];
					if(!isalpha(c)&&isdigit(c)){//illegal handle
						while(isalpha(c)||isdigit(c)||c=='.'||c=='_'||c=='$'){
							chbuf2[chfid++]=c;
							chbuf2[chfid]='\0';
							c=lexbuffer[bufid++];
						}
						toktmp=0;
						memo(chbuf2,Error,toktmp,itcout++);
						state=0;
					}
					else state=10;
				}
				else state=10;
			}
			else state=11;

			break;
		case 11:
			toktmp=lookup(chbuf2);
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;
			memo(chbuf2,Identifier,toktmp,itcout);
			itcout++;
			state=0;
			break;

                case 12://Digit START
			chbuf3[0]='\0';
			if(isdigit(c))state=13;
			else state=fail();
			cout<<"State :"<<state<<"lookhead :"<<c<<" lexbuffer: "<<lexbuffer<<endl;

			break;
                case 13://Int
			chbuf3[chfid++]=c;
			chbuf3[chfid]='\0';
			c=lexbuffer[bufid++];	
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			if(isdigit(c))state=13;
			else if(c=='.')state=14;
			else if(c=='E'||c=='e')state=16;
			else if(isspace(c)||c=='\n'||c=='\0'||c==';'){
				toktmp=lookup(chbuf3);
				memo(chbuf3,Int,toktmp,itcout);
				itcout++;
				state=0;}
			else state=20;
			break;
                case 14://Float or not
			chbuf3[chfid++]=c;
			chbuf3[chfid]='\0';
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			if(isdigit(c))state=15;
			else state=20;
			break;

                case 15://Float or science sym
			chbuf3[chfid++]=c;
			chbuf3[chfid]='\0';
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			if(isdigit(c))state=15;
			else if(c=='E'||c=='e')state=16;
			else if(c==' '||c==';'||c=='\n'||c=='\0'){
			        toktmp=lookup(chbuf3);
				memo(chbuf3,Float,toktmp,itcout);
				itcout++;
				state=0;}
			else state=20;
			break;

                case 16://upper index
			chbuf3[chfid++]=c;
			chbuf3[chfid]='\0';
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			if(c=='+'||c=='-')state=17;
			else if(isspace(c)||c=='\n'){
				 toktmp=lookup(chbuf3);
				memo(chbuf3,Float,toktmp,itcout);
				itcout++;
				state=0;}
			else state=20;
			break;

                case 17:
			chbuf3[chfid++]=c;
			chbuf3[chfid]='\0';
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			if(isdigit(c))state=17;
			else if(isspace(c)||c=='\n'||c==';'||c=='\0'){
				toktmp=lookup(chbuf3);
				memo(chbuf3,Float,toktmp,itcout);
				itcout++;
				state=0;}
			else state=20;
			break;

                case 18://Special Symbols START
			chbuf4[0]='\0';
			chfid=0;
			cout<<"State :"<<state<<"lookhead :"<<c<<" lexbuffer: "<<lexbuffer<<endl;

			if(c=='{'||c=='}'||c=='['||c==']'||c=='('||c==')'||c==';'||c=='\\'||c=='/'||c=='$'||c=='_'||c=='#')state=19;
			else if(c=='%'||c=='*'||c=='-'||c=='+'||c=='='||c=='^'||c=='&'||c=='|'||c=='~'||c=='!'||c=='?'||c==':')state=29;
			else if(c=='\'')state=25;
			else if(c=='\"')state=27;
			else	state=fail();
				
			break;
			
                case 19://make sure which token the state can accept~~

			cout<<"State :"<<state<<"lookhead :"<<c<<endl;
			if(c=='{'){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				scope++;
				memo(chbuf4,SpecialSymbol,toktmp,itcout);
				itcout++;
			}
			else if(c=='}'){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,SpecialSymbol,toktmp,itcout);
				itcout++;
				scope--;
			}
			else if(c=='/'){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				state=21;	// /**/
				break;}
			else if(c=='_'||c=='$'){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				state=41;
			}
			else{
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,SpecialSymbol,toktmp,itcout);
				itcout++;
			}
			state=0;
			break;
                case 20://handle illegal identifier or rule
			chbuf3[chfid++]=c;
			chbuf3[chfid]='\0';
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			if(c=='\n'||isspace(c)||c=='	'){
				 toktmp=lookup(chbuf3);
				memo(chbuf3,Error,toktmp,itcout);
				itcout++;
				state=0;
			}else state=20;
			break;
		case 21:// //, /* ; /= , /

			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			if(c=='/')state=22;
			else if(c=='*'){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				state=23;}
			else if(c=='='){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;
				}
			else if(c==' '||c=='	'||isdigit(c)||isalpha(c)){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				bufid--;
				state=0;}	
			else state=20;//error
			break;
		case 22://  //
			chbuf4[chfid++]=c;
			chbuf4[chfid]='\0';
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			if(c!='\n'&&c!='\0')state=22;
			else {	
			        toktmp=0;
				memo(chbuf4,Comment,toktmp,itcout);
				itcout++;
				bufid--;
				state=0;
			}
			break;
		case 23:// /* *
	
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;
			if(c=='\n'||c=='\0'){
				toktmp=0;
				memo(chbuf4,Comment,toktmp,itcout);
				itcout++;
				lexmem[lineno++].itNum=itcout;
				return 23; //not finish but need new line
			}
			else if(c!='*'){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				state=23;}
			else state=24;
			break;
		case 24:// /* */
			chbuf4[chfid++]=c;
			chbuf4[chfid]='\0';
			c=lexbuffer[bufid++];
			cout<<"State :"<<state<<"lookhead :"<<c<<endl;

			if(c!='/'){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';	
				state=23;}
			else{
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Comment,toktmp,itcout);
				itcout++;
				state=0;}
			break;
		case 25://'Char
			chbuf4[chfid++]=c;
			chbuf4[chfid]='\0';
			c=lexbuffer[bufid++];
			if(c=='\\'){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				c=lexbuffer[bufid++];
				if(c=='\\'||c=='\''||c=='\"')state=26;//escape char for
				else state=20;
			}else{
				state=26;
				break;}
		case 26://'Char'
			chbuf4[chfid++]=c;
			chbuf4[chfid]='\0';
			c=lexbuffer[bufid++];
			if(c!='\'')state=20;//error ex: 'ab
			else {
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Char,toktmp,itcout);
				itcout++;
				state=0;
			}
			break;
		case 27://"String
			chbuf4[chfid++]=c;
			chbuf4[chfid]='\0';
			c=lexbuffer[bufid++];
			if(c!='\"'&&c!=';'&&c!='\n'&&c!='\0')state=27;
			else if(c==';'||c=='\n'||c=='\0')state=20;//ex: "abc ;
			else state=28;
			break;
		case 28://"String"
			chbuf4[chfid++]=c;
			chbuf4[chfid]='\0';
			toktmp=0;
			memo(chbuf4,String,toktmp,itcout);
			itcout++;
			state=0;
			break;
		case 29:// + - * % & | ^
			chbuf4[chfid++]=c;
			chbuf4[chfid]='\0';
			if(c=='+')state=30;
			else if(c=='-')state=31;
			else if(c=='*')state=32;
			else if(c=='%')state=33;
			else if(c=='&')state=34;
			else if(c=='|')state=37;
			else if(c=='^')state=36;
			else if(c=='~'){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;
			}
			else if(c=='!')state=38;
			else if(c=='?'){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;
			}

			else if(c==':'){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;
			}
			break;	

		case 30:// +,++,+=
			c=lexbuffer[bufid++];
			if(c=='+'||c=='='){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else if(c==' '||c=='	'||isalpha(c)){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				bufid--;
				state=0;}
			else if(isdigit(c)){
		
				c=chbuf4[0];
				chfid=0;
				bufid--;
				state=13;}
			else state=20;//error
			break;
		case 31:// -,--,-=
			c=lexbuffer[bufid++];
			if(c=='-'||c=='='){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else if(c==' '||c=='	'||isalpha(c)){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				bufid--;
				state=0;}
			else if(isdigit(c)){
				c=chbuf4[0];
				chfid=0;
				bufid--;
				state=13;}
			else state=20;//error
			break;
			
		case 32://*=
			c=lexbuffer[bufid++];
			if(c=='='){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else if(c==' '||c=='	'||isdigit(c)||isalpha(c)){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				bufid--;
				state=0;}	


			else state=20;//error
			break;
		case 33://%=
			c=lexbuffer[bufid++];
			if(c=='='){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else if(c==' '||c=='	'||isdigit(c)||isalpha(c)){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				bufid--;
				state=0;}	


			else state=20;//error
			break;
	
		case 34://&&,&=,&
			c=lexbuffer[bufid++];
			if(c=='&'||c=='='){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else if(c==' '||c=='	'||isdigit(c)||isalpha(c)){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				bufid--;
				state=0;}
			else state=20;//error
			break;
	
		case 36://^=
			c=lexbuffer[bufid++];
			if(c=='='){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else if(c==' '||c=='	'||isdigit(c)||isalpha(c)){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				bufid--;
				state=0;}
			else state=20;//error
			break;
	
		case 37:// ||,|=,|
			c=lexbuffer[bufid++];
			if(c=='|'||c=='='){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else if(c==' '||c=='	'||isdigit(c)||isalpha(c)){
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				bufid--;
				state=0;}
			else state=20;//error
			break;
		case 38:// != ,!
			c=lexbuffer[bufid++];
			if(c=='='){
				chbuf4[chfid++]=c;
				chbuf4[chfid]='\0';
				toktmp=0;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else if(c==' '||c=='	'||isdigit(c)||isalpha(c)){
				toktmp=0;
				bufid--;
				memo(chbuf4,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else state=20;//error
			break;

		case 39://<<= <<
			c=lexbuffer[bufid++];
			if(c=='='){
				chbuf1[chfid++]=c;
				chbuf1[chfid]='\0';
				toktmp=0;
				memo(chbuf1,Operator,toktmp,itcout);
				itcout++;
				state=0;
			}
			else if(c==' '||c=='	'||isdigit(c)||isalpha(c)){
				toktmp=0;
				bufid--;
				memo(chbuf1,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else state=20;//error
			break;

				
		case 40://>> >,>> =,>>
			chbuf1[chfid++]=c;
			chbuf1[chfid]='\0';
			c=lexbuffer[bufid];
			if(c=='>'||c=='='){
				chbuf1[chfid++]=c;
				chbuf1[chfid]='\0';
				toktmp=0;
				memo(chbuf1,Operator,toktmp,itcout);
				itcout++;
				state=0;}
			else if(c==' '||c=='	'||isdigit(c)||isalpha(c)){
				toktmp=0;
				memo(chbuf1,Operator,toktmp,itcout);
				itcout++;
				bufid--;
				state=0;}
			else state=20;//error
			break;
		case 41://_abc ,$abc
			c=lexbuffer[bufid++];
			if(!isalpha(c)){
				toktmp=0;
				memo(chbuf4,SpecialSymbol,toktmp,itcout);
				bufid--;
				itcout++;
				break;}
			else {
				if(chbuf4[0]=='_')c='_';
				else c='$';
				chfid=0;
				bufid--;
				state=10;
				break;
			}
		case 42://Error START 
			chbuf5[0]='\0';
			chbuf5[chfid++]=c;
			chbuf5[chfid]='\0';
			cout<<"State :"<<state<<"lookhead :"<<c<<" lexbuffer: "<<lexbuffer<<endl;
		  	toktmp=0;
			memo(chbuf5,Error,toktmp,itcout);
			itcout++;
			state=0;
			break;

		}
	}
}



