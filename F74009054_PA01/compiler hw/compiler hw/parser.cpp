#include "generator.cpp"

int innum=0;
int pn=0;
bool isError=0;
void parser(){


	int state=0,token=0,look=0,get=1;
	bool isf=0,isEmpty=0,isAccept=0,isFinish=0;
	char item[128];
	entry tmp[100];
	//handle input
	for(int i=0;i<lineno;i++){
		for(int j=0;j<lexmem[i].itNum;j++){

			token=lexmem[i].array[j].token;
			if(token==131||token==132){
				
			}
			else if(token==126||token==127||token==128||token==129
				||token==130){
			//	cout<<lexmem[i].array[j].token<<endl;
				
				switch(token){

					case 126:strcpy(tmp[innum++].lexptr,"Identifier");
						break;
					case 127:strcpy(tmp[innum++].lexptr,"Char");
						break;
					case 128:strcpy(tmp[innum++].lexptr,"String");
						break;
					case 129:strcpy(tmp[innum++].lexptr,"Int");
						break;
					case 130:strcpy(tmp[innum++].lexptr,"Float");
						break;
				}

			}
			else {
			//	cout<<lexmem[i].array[j].lexptr<<endl;
				strcpy(tmp[innum++].lexptr,lexmem[i].array[j].lexptr);
			}

		}
	}
	
	strcpy(tmp[innum++].lexptr,"$");

	for(int i=0;i<innum;i++){
		cout<<tmp[i].lexptr<<endl;
	}
	//DFA

	while(!isFinish){

		if(get){
			strcpy(item,tmp[look++].lexptr);//lookahead
		}else get=1;

		cout<<"Now lookahead is "<<item<<endl;
		cout<<"state is "<<state<<endl;
		switch(state){

			case 0:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"public")==0){// state's work for CFG
						state=1;//next state
						prod_mem[pn++]=0;
						prod_mem[pn++]=1;
						prod_mem[pn++]=2;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 1:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"class")==0){// state's work for CFG
						state=2;//next state
					
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 2:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"Identifier")==0){// state's work for CFG
						state=3;//next state
	
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 3:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"{")==0){// state's work for CFG
						state=4;//next state
						prod_mem[pn++]=5;//ClassBody {
						prod_mem[pn++]=6;
						prod_mem[pn++]=7;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 4:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"}")==0){// state's work for CFG
						state=5;//next state //Accept

						break;
					}
					else if(strcmp(item,"int")==0||strcmp(item,"float")==0||strcmp(item,"double")==0||strcmp(item,"public")==0){
						state=6;
						get=0;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 5:// Accept a Classbody
				isAccept=1;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<endl<<endl;
						cout<<"Success!!\n\n\n";
						//output23();
						isFinish=1;
						break;

					}
				}
			/*	else {
					if(strcmp(item,"")==0){// state's work for CFG
						state=1;//next state
						prod_mem[pn++]=0;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}*/
			case 6://for VD
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"int")==0){// state's work for CFG
						state=7;//next state
						prod_mem[pn++]=9;
						prod_mem[pn++]=11;
						break;
					}else
					if(strcmp(item,"float")==0){// state's work for CFG
						state=7;//next state
						prod_mem[pn++]=9;
						prod_mem[pn++]=12;
						break;
					}else
					if(strcmp(item,"double")==0){// state's work for CFG
						state=7;//next state
						prod_mem[pn++]=9;
						prod_mem[pn++]=13;
						break;
					}else
					if(strcmp(item,"char")==0){// state's work for CFG
						state=7;//next state
						prod_mem[pn++]=9;
						prod_mem[pn++]=14;
						break;
					}else
					if(strcmp(item,"String")==0){// state's work for CFG
						state=7;//next state
						prod_mem[pn++]=9;
						prod_mem[pn++]=15;
						break;
					}else
					if(strcmp(item,"public")==0){// state's work for CFG
						state=8;//next state
						prod_mem[pn++]=10;
						prod_mem[pn++]=17;
						prod_mem[pn++]=2;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 7:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"Identifier")==0){// state's work for CFG
						state=9;//next state
						
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 8:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"static")==0){// state's work for CFG
						state=10;//next state
			
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 9:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,";")==0){// state's work for CFG
						state=4;//next state VD;
					
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 10:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"int")==0){// state's work for CFG
						state=11;//next state
						prod_mem[pn++]=11;
						break;
					}else
					if(strcmp(item,"float")==0){// state's work for CFG
						state=11;//next state
						prod_mem[pn++]=12;
						break;
					}else
					if(strcmp(item,"double")==0){// state's work for CFG
						state=11;//next state
						prod_mem[pn++]=13;
						break;
					}else
					if(strcmp(item,"char")==0){// state's work for CFG
						state=11;//next state
						prod_mem[pn++]=14;
						break;
					}else
					if(strcmp(item,"String")==0){// state's work for CFG
						state=11;//next state
						prod_mem[pn++]=15;
						break;
					}else
					if(strcmp(item,"void")==0){// state's work for CFG
						state=11;//next state
						prod_mem[pn++]=16;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 11:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"Identifier")==0){// state's work for CFG
						state=12;//next state VD;
					
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 12:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"(")==0){// state's work for CFG
						state=13;//next state VD;
					
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 13:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"String")==0){// state's work for CFG
						state=14;//next state FD;
					
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 14:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"[")==0){// state's work for CFG
						state=15;//next state VD;
					
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 15:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"]")==0){// state's work for CFG
						state=16;//next state VD;
					
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 16:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"Identifier")==0){// state's work for CFG
						state=17;//next state VD;
					
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 17:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,")")==0){// state's work for CFG
						state=18;//next state VD;
					
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 18:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"{")==0){// state's work for CFG
						state=19;//next state VD;
						prod_mem[pn++]=18;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 19:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"}")==0){// state's work for CFG
						state=4;//next state VD;
					
						break;
					}
					else if(strcmp(item,"int")==0){
						state=20;
						prod_mem[pn++]=19;//LocalDeclaration
						prod_mem[pn++]=21;
						prod_mem[pn++]=11;
						break;
					}
					else if(strcmp(item,"float")==0){
						state=20;
						prod_mem[pn++]=19;
						prod_mem[pn++]=21;
						prod_mem[pn++]=12;
						break;
					}
					else if(strcmp(item,"double")==0){
						state=20;
						prod_mem[pn++]=19;
						prod_mem[pn++]=21;
						prod_mem[pn++]=13;
						break;
					}
					else if(strcmp(item,"char")==0){
						state=20;
						prod_mem[pn++]=19;
						prod_mem[pn++]=21;
						prod_mem[pn++]=14;
						break;
					}
					else if(strcmp(item,"String")==0){
						state=20;
						prod_mem[pn++]=19;
						prod_mem[pn++]=21;
						prod_mem[pn++]=15;
						break;
					}
					else if(strcmp(item,"Identifier")||strcmp(item,"if")||strcmp(item,"while")||strcmp(item,"return")){
						state=22;
						get=0;
						prod_mem[pn++]=22;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 20:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"Identifier")==0){// state's work for CFG
						state=21;//next state VD;
			
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 21:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,";")==0){// state's work for CFG
						state=19;//next state VD;
						prod_mem[pn++]=30;	
						break;
					}
					else if(strcmp(item,"=")==0){
						state=25;
						prod_mem[pn++]=29;
						prod_mem[pn++]=34;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 22:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"Identifier")==0){// state's work for CFG
						state=24;//next state VD;
						prod_mem[pn++]=24;
						prod_mem[pn++]=29;
						prod_mem[pn++]=34;
						prod_mem[pn++]=35;
						break;
					}
					else if(strcmp(item,"if")==0){
						state=35;
						prod_mem[pn++]=26;//LocalDeclaration
						prod_mem[pn++]=59;
						prod_mem[pn++]=63;
						break;
					}
					else if(strcmp(item,"while")==0){
						state=30;
						prod_mem[pn++]=27;//LocalDeclaration
						prod_mem[pn++]=60;
						prod_mem[pn++]=64;
						break;
					}
					else if(strcmp(item,"return")==0){
						state=27;
						prod_mem[pn++]=30;
						break;
					}	
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}

			case 24:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"=")==0){// state's work for CFG
						state=25;//next state VD;
						break;
					}
					if(strcmp(item,"(")==0){
						state=27;
						prod_mem[pn++]=58;
						prod_mem[pn++]=60;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}



			case 25:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"Char")==0){// state's work for CFG
						state=26;//next state VD;
						prod_mem[pn++]=35;
						prod_mem[pn++]=36;
						prod_mem[pn++]=41;
						prod_mem[pn++]=46;
						prod_mem[pn++]=56;
						break;
					}
					else if(strcmp(item,"String")==0){
						state=26;
						prod_mem[pn++]=35;
						prod_mem[pn++]=36;
						prod_mem[pn++]=41;
						prod_mem[pn++]=46;
						prod_mem[pn++]=57;
						break;
					}
					else if(strcmp(item,"Identifier")==0){
						state=26;
						prod_mem[pn++]=35;
						prod_mem[pn++]=36;
						prod_mem[pn++]=41;
						prod_mem[pn++]=46;
						prod_mem[pn++]=52;
						break;
					}

					else if(strcmp(item,"Int")==0){
						state=26;
						prod_mem[pn++]=35;
						prod_mem[pn++]=36;
						prod_mem[pn++]=41;
						prod_mem[pn++]=46;
						prod_mem[pn++]=53;
						break;
					}
					else if(strcmp(item,"Float")==0){
						state=26;
						prod_mem[pn++]=35;
						prod_mem[pn++]=36;
						prod_mem[pn++]=41;
						prod_mem[pn++]=46;
						prod_mem[pn++]=54;
						break;
					}
					else if(strcmp(item,"Double")==0){
						state=26;
						prod_mem[pn++]=35;
						prod_mem[pn++]=36;
						prod_mem[pn++]=41;
						prod_mem[pn++]=46;
						prod_mem[pn++]=55;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 26:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"*")==0){// state's work for CFG
						state=25;//next state VD;
						prod_mem[pn++]=47;
						prod_mem[pn++]=49;
						break;
					}
					else if(strcmp(item,"/")==0){
						state=25;
						prod_mem[pn++]=47;
						prod_mem[pn++]=50;
						break;
					}
					else if(strcmp(item,"+")==0){
						state=25;
//						prod_mem[pn++]=48;
						prod_mem[pn++]=43;
						break;
					}
					else if(strcmp(item,"-")==0){
						state=25;
//						prod_mem[pn++]=48;
						prod_mem[pn++]=44;
						break;
					}
					else if(strcmp(item,"<")==0){
						state=25;
						prod_mem[pn++]=37;
						prod_mem[pn++]=39;
						break;
					}
					else if(strcmp(item,">")==0){
						state=25;
						prod_mem[pn++]=37;
						prod_mem[pn++]=40;
						break;
					}
					else if(strcmp(item,";")==0){
						state=19;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 27:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"Identifier")==0){// state's work for CFG
						state=28;//next state VD;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 28:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,")")==0){// state's work for CFG
						state=29;//next state VD;
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 29:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,";")==0){// state's work for CFG
						state=19;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 30://for while loop
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"(")==0){// state's work for CFG
						state=31;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 31:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"Identifier")==0){// state's work for CFG
						state=32;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 32:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,")")==0){// state's work for CFG
						state=33;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 33:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"{")==0){// state's work for CFG
						state=34;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 34:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"}")==0){// state's work for CFG
						state=19;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 35://fot if ... else ...
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"(")==0){// state's work for CFG
						state=36;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 36:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"Identifier")==0){// state's work for CFG
						state=37;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 37:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,")")==0){// state's work for CFG
						state=38;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 38:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"{")==0){// state's work for CFG
						state=39;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 39:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"}")==0){// state's work for CFG
						state=40;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 40:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"else")==0){// state's work for CFG
						state=41;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 41:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"{")==0){// state's work for CFG
						state=42;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}
			case 42:
				isAccept=0;//state attr
				if(strcmp(item,"$")==0){
					if(!isAccept){
						cout<<"error\n";
						isFinish=1;
						isError=1;
						break;
					}
					else {
						cout<<"Finished!!\n";
						//output23();
						isFinish=1;
						break;

					}
				}
				else {
					if(strcmp(item,"}")==0){// state's work for CFG
						state=19;//the end of statement
						break;
					}
					else {
						cout<<"compile error!!\n";
						isFinish=1;
						isError=1;
						break;
					}
				}







		}
	}

}


void output2(){

	ofstream FileOutPut;
	FileOutPut.open(FileNameOut3);
		
	for(int i=0;i<pn;i++){
		
		cout<<prod_mem[i]<<" :"<<CFG[prod_mem[i]].LHS<<" -> ";
		FileOutPut<<prod_mem[i]<<" :"<<CFG[prod_mem[i]].LHS<<" -> ";


		for(int j=0;j<CFG[prod_mem[i]].rNum+1;j++){
			cout<<" "<<CFG[prod_mem[i]].array[j].RHS;
			FileOutPut<<" "<<CFG[prod_mem[i]].array[j].RHS;

		}
		cout<<endl;
	}
	
	FileOutPut.close();


}




bool iN(char *T){

	int l=0;
	
	while(l<NumOfNon){
		
		if(strstr(T,Nonterminal[l])||strstr(Nonterminal[l],T))return true;
		else l++;
	}
	
	return false;
}




int pdmin=-1;

int output3(char *T,int L){
	ofstream FileOutPut;
	FileOutPut.open(FileNameOut4,ios::app);

	L++;
	int memo;
//	cout<<CFG[prod_mem[pdmin+1]].LHS<<" VS "<<T<<endl;
//	FileOutPut<<CFG[prod_mem[pdmin+1]].LHS<<" VS "<<T<<endl;


	if(!iN(T)){
	
		for(int i=0;i<L;i++){cout<<" ";
			FileOutPut<<" ";
		}
		cout<<L<<':'<<T;
		FileOutPut<<L<<':'<<T<<endl;

		cout<<endl;
		return 0;
	}
	else {
		
	
/*			for(int i=0;i<L;i++){cout<<" ";
				FileOutPut<<" ";
			}
			cout<<L<<':'<<T;
			FileOutPut<<L<<':'<<T<<endl;
			cout<<endl;*/
	//	cout<<CFG[prod_mem[pdmin+1]].LHS<<" VS "<<T<<endl;
		if((strcmp(T,CFG[prod_mem[pdmin+1]].LHS)==0||strstr(T,CFG[prod_mem[pdmin+1]].LHS)!=NULL||strstr(CFG[prod_mem[pdmin+1]].LHS,T)!=NULL)&&CFG[prod_mem[pdmin+1]].rNum!=0){
			int n=0;
			pdmin++;
			memo=pdmin;

			for(int i=0;i<L;i++){cout<<" ";
				FileOutPut<<" ";
			}
			cout<<L<<':'<<T;
			FileOutPut<<L<<':'<<T<<endl;
			cout<<endl;




//			if(memo==16)CFG[prod_mem[memo]].rNum++;
//			if(prod_mem[memo]==22)CFG[prod_mem[memo]].rNum++;	
			while(n<CFG[prod_mem[memo]].rNum){
				//cout<<memo;
//				FileOutPut<<memo;
	
				output3(CFG[prod_mem[memo]].array[n].RHS,L);
				n++;
			
			}
			return 0;
		}else{
			//pdmin--;
			return 0;
		}
	}
	
FileOutPut.close();
}



int main(){

	result();
	generator();	
	parser();
	output2();
	if(isError==0){
		output3(CFG[prod_mem[pdmin+1]].LHS,0);
		cout<<"Success!!check output3 for the parse tree~~\n";
	}else cout<<"<ERROR>check output2 for the process~~\n";

	return 0;
}

	
