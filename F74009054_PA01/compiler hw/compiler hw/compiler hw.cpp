// compiler hw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int id=0,fl=0,sc=0,index;
int flag[20];
int scope[20];
char result_iden[80][30];
char sentence_tok[100][100];  //將式子儲存在2維陣列理 以字元方式儲存 好方便處理 ex; a=6+b  sentence[0][0]='a' sentence[0][1]='='...
char sentence_tokf[100][100];
char type[80][30];
int length[50];
int len;
int tokx,toky;
int sentence_len[20];
char temp[20];
int cha_num[20];

class Lexical_Analyzer
{
public :
    int uqIdi,uqOpi,uqDei,defOpi,defKeyi,cLitteri,comi,comi2;
	int keyflag,oprflag,idflag,floatfl,strfl,charfl,comfl,pcomfl,comfl2,pcomfl2;
    char tmpStr[50],Str[250],mIden[50][20],mOpr[50][20],mDel[50];
    char defKey[80][30],defOprStr[80][30],defOpr[80],defsymbol[80];
    char chOpr[80][30],chIden[80][30],chIdfl[20],chOpfl[80],chDefl[80],chDel[80];
    char Opr[80][30],Con[80][30],Iden[80][30],Key[80][30],sLitter[80][30],cLitter[80][30],comment[80][30],comment2[80][30];
	char Identifier[80][30];
	int i,j,k,ti,oprfl,delfl,keyfl,sLitterfl,cLitterfl,ptfl,tfl,mIdeni,sLitteri,mIdenj,mOpri,mOprj,mDeli,Erri;
    int Opri,Coni,Ideni,Keyi,Deli;
	int line,symbol;
	


    Lexical_Analyzer()
    {
        //strcpy(Str,str);
	
        //Defined Keywords
		symbol=0;
		line=0;
        defKeyi=51;
        strcpy(defKey[0],"int");
        strcpy(defKey[1],"float");
        strcpy(defKey[2],"double");
        strcpy(defKey[3],"long");
        strcpy(defKey[4],"if");
        strcpy(defKey[5],"else");
        strcpy(defKey[6],"while");
        strcpy(defKey[7],"for");
        strcpy(defKey[8],"return");
        strcpy(defKey[9],"goto");
        strcpy(defKey[10],"break");
        strcpy(defKey[11],"char");
        strcpy(defKey[12],"void");
		strcpy(defKey[13],"class");
		strcpy(defKey[14],"public");
		strcpy(defKey[15],"static");
		strcpy(defKey[16],"String");
		strcpy(defKey[17],"abstract");
		strcpy(defKey[18],"case");
		strcpy(defKey[19],"continue");
		strcpy(defKey[20],"enum");
		strcpy(defKey[21],"instanceof");
		strcpy(defKey[22],"new");
		strcpy(defKey[23],"switch");
		strcpy(defKey[24],"transient");
		strcpy(defKey[25],"assert");
		strcpy(defKey[26],"catch");
		strcpy(defKey[27],"extends");
		strcpy(defKey[28],"package");
		strcpy(defKey[29],"short");
		strcpy(defKey[30],"synchronize");
		strcpy(defKey[31],"try");
		strcpy(defKey[32],"boolean");
		strcpy(defKey[33],"final");
		strcpy(defKey[34],"interface");
		strcpy(defKey[35],"private");
		strcpy(defKey[36],"static");
		strcpy(defKey[37],"this");
		strcpy(defKey[38],"do");
		strcpy(defKey[39],"finally");
		strcpy(defKey[40],"implements");
		strcpy(defKey[41],"protected");
		strcpy(defKey[42],"strictfp");
		strcpy(defKey[43],"throw");
		strcpy(defKey[44],"volatile");
		strcpy(defKey[45],"byte");
		strcpy(defKey[46],"const");
		strcpy(defKey[47],"import");
		strcpy(defKey[48],"native");
		strcpy(defKey[49],"super");
		strcpy(defKey[50],"throw");





        //Defined Operators
        defOpi=34;
        strcpy(defOprStr[0],"+");
        strcpy(defOprStr[1],"-");
        strcpy(defOprStr[2],"*");
        strcpy(defOprStr[3],"/");
        strcpy(defOprStr[4],"=");
        strcpy(defOprStr[5],"%");
        strcpy(defOprStr[6],">");
        strcpy(defOprStr[7],"<");
        strcpy(defOprStr[8],"<=");
        strcpy(defOprStr[9],">=");
        strcpy(defOprStr[10],"==");
        strcpy(defOprStr[11],"+=");
        strcpy(defOprStr[12],"-=");
        strcpy(defOprStr[13],"*=");
        strcpy(defOprStr[14],"/=");
        strcpy(defOprStr[15],"%=");
        strcpy(defOprStr[16],"++");
        strcpy(defOprStr[17],"--");
		strcpy(defOprStr[18],"<<");
		strcpy(defOprStr[19],">>");
		strcpy(defOprStr[20],">>>");
		strcpy(defOprStr[21],"!=");
		strcpy(defOprStr[22],"&");
		strcpy(defOprStr[23],"^");
		strcpy(defOprStr[24],"|");
		strcpy(defOprStr[25],"||");
		strcpy(defOprStr[26],"&&");
		strcpy(defOprStr[27],"?");
		strcpy(defOprStr[28],"&=");
		strcpy(defOprStr[29],"^=");
		strcpy(defOprStr[30],"|=");
		strcpy(defOprStr[31],"<<=");
		strcpy(defOprStr[32],">>=");
		strcpy(defOprStr[33],">>>=");
        strcpy(defOpr,"+-/*%=<>");
        strcpy(defsymbol,",;:{}[]()");
    }
	void getstr(char* str)
	{
		strcpy(Str,str);
		line++;
		//cout<<"test "<<Str<<endl;
	}

    int IsmIden(char ch)
    {
        return((IsIden(ch)||IsFloat(ch))?1:0);
    }

    int IsIden(char ch)
    {
        return((isalpha(ch)||ch=='_')?1:0);  //但斷是否為變數
    }

    int IsFloat(char ch)
    {
        return((isdigit(ch)||ch=='.')?1:0); //判斷是否為浮點術
    }

    int IsOpr(char ch)
    {
        oprfl=0;
        for(ti=0;ti<18&&!oprfl;ti++)
        {
        if(ch==defOpr[ti])
        {
            oprfl=1;
        }
        }
        return oprfl;
    }

    
    int IsDel(char ch)
    {
        delfl=0;
        for(ti=0;ti<strlen(defsymbol)&&!delfl;ti++)
        {
        if(ch==defsymbol[ti])
        {
            delfl=1;
        }
        }
        return delfl;
    }

    int IsKey(char *str)          //判斷是否為keyword
    {
        keyfl=0;                  //keyflag
        for(ti=0;ti<defKeyi&&!keyfl;ti++)
        {
        if(!strcmp(defKey[ti],str))
        {
            keyfl=1;
        }
        }
        return keyfl;
    }


    void Find()
    {
        i=0;
		comi=0;
		comi2=0;
        cLitteri=0;
        sLitteri=0;
        Erri=0;
        mIdeni=0;
        mIdenj=0;
        mOpri=0;
        mOprj=0;
        mDeli=0;
		keyflag=0;
		oprflag=0;
		idflag=0;
		strfl=0;
		charfl=0;
        while(Str[i]!='\0')
        {
        if(IsmIden(Str[i]))
        {
            while(IsmIden(Str[i]))
            {
            mIden[mIdeni][mIdenj++]=Str[i++]; 
            if(!IsmIden(Str[i]))
            {
                mIden[mIdeni++][mIdenj]='\0';
                mIdenj=0;
            }
            }
        }
        else if(Str[i]=='"')
        {
            sLitterfl=1;
            k=0;
            tmpStr[k++]=Str[i];
			for(j=i+1;j<strlen(Str)&&sLitterfl;j++)            //若出現"XX"代表為字串存入sLitter中
            {
                tmpStr[k++]=Str[j];
                if(Str[j]=='"')
                {
                    tmpStr[k]='\0';
                    strcpy(sLitter[sLitteri++],tmpStr);
					strfl=1;
                    sLitterfl=0;
                    i=j+1;
                }
            }
            if(sLitterfl)                                   //若只有單個"則代表錯誤
            {
                cout<<"Invalid Use of \""<<endl;
                i++;
				strfl=0;
            }
        }
        else if(Str[i]=='\'')
        {
            cLitterfl=0;
            k=0;
            tmpStr[k++]=Str[i];
			for(j=i+1;j<strlen(Str)&&!cLitterfl;j++)
            {
                tmpStr[k++]=Str[j];
                if(Str[j]=='\'')
                {
                    tmpStr[k]='\0';
                    if(strlen(tmpStr)!=3)
                    {
                        cout<<"Invalid Use of \'"<<endl;
                        cLitterfl=1;
                        i++;
                    }
                    else
                    {
		
                        strcpy(cLitter[cLitteri++],tmpStr);
						charfl=1;
                        cLitterfl=1;
                        i=j+1;
                    }
                }
            }
            if(!cLitterfl)
            {
                cout<<"Invalid Use of \'"<<endl;
                cLitterfl=1;
				charfl=0;
                i++;
            }
        }
		else if(Str[i]=='/'&&Str[i+1]=='*')               //在此判斷是否為/*comment*/
        {
            comfl=1;
			pcomfl=1;
            k=0;
            tmpStr[k++]=Str[i];
			for(j=i+1;j<strlen(Str)&&comfl;j++)            //若出現"XX"代表為字串存入sLitter中
            {
                tmpStr[k++]=Str[j];
                if(Str[j]=='/')
                {
                    tmpStr[k]='\0';
                    strcpy(comment[comi++],tmpStr);
                    comfl=0;
                    i=j+1;
                }
            }
            if(comfl)                                   //若只有單個"則代表錯誤
            {
                cout<<"Invalid Use of \""<<endl;
                i++;
				pcomfl=0;
            }
        }
		else if(Str[i]=='/'&&Str[i+1]=='/')               //在此判斷是否為//comment
        {
            comfl2=1;
			pcomfl2=1;
            k=0;
            tmpStr[k++]=Str[i];
			for(j=i+1;j<strlen(Str)&&comfl2;j++)            //若出現"XX"代表為字串存入sLitter中
            {
				tmpStr[k++]=Str[j];
                if(Str[j+1]==' ')
                {
                    tmpStr[k]='\0';
                    strcpy(comment2[comi2++],tmpStr);
                    comfl2=0;
                    i=j+1;
					
                }
				if(comfl2)                                   //若只有單個"則代表錯誤
            {
                cout<<"Invalid Use of \""<<endl;
                i++;
				pcomfl=0;
            }
            }
			
        }
        else if(IsOpr(Str[i]))                      //判斷char是否為operator若是存在mOpr
        {
            while(IsOpr(Str[i]))
            {
				
				mOpr[mOpri][mOprj++]=Str[i++];
            if(!IsOpr(Str[i]))
            {
	
                mOpr[mOpri++][mOprj]='\0';
                mOprj=0;
            }
            }
        }
        else if(IsDel(Str[i]))                    //判斷是否為特殊符號若是存入mDel
        {
            while(IsDel(Str[i]))
            {
				
				mDel[mDeli++]=Str[i++];
            }
            mDel[mDeli]='\0';
        }
      
		 else
        {
            i++;
        }
		
       
		
		 
	   } 
	   

	 
    }////////////////////////////

    void Multcheck()
    {
        uqIdi=0;
        uqDei=0;
        uqOpi=0;
        for(i=0;i<20;i++)
        {
        chOpfl[i]=0;
        chIdfl[i]=0;
        chDefl[i]=0;
        }
        for(i=1;i<mIdeni+1;i++)
        {
        if(chIdfl[i-1]==0)
        {
            strcpy(chIden[uqIdi++],mIden[i-1]);
            for(j=i;j<mIdeni;j++)
            {
            if(!strcmp(mIden[j],mIden[i-1]))        //若相等的話不進行字串複製
            {
                chIdfl[j]=1;
            }
            }
        }
        }
        for(i=1;i<mOpri+1;i++)
        {
        if(chOpfl[i-1]==0)
        {
            strcpy(chOpr[uqOpi++],mOpr[i-1]);
            for(j=i;j<mOpri;j++)
            {
            if(!strcmp(mOpr[j],mOpr[i-1]))
            {
                chOpfl[j]=1;
            }
            }
        }
        }
        for(i=1;i<mDeli+1;i++)
        {
        if(chDefl[i-1]==0)
        {
			
            chDel[uqDei++]=mDel[i-1];
            chDel[uqDei]='\0';
            for(j=i;j<mDeli;j++)
            {
            if(mDel[j]==mDel[i-1])
            {
                chDefl[j]=1;
            }
            }
        }
        }
    }

    void Outcome()
    {
		
        Opri=0;
        Ideni=0;
        Coni=0;
        Keyi=0;
        for(i=0;i<uqIdi;i++)
        {
        if(IsIden(chIden[i][0]))
        {
            if(IsKey(chIden[i]))
            {
				cout<<"         "<<symbol<<" "<<"<Keywords>:"<<setw(10)<<chIden[i]<<endl;
		
	
            }
            else
            {
            ptfl=1;
            for(j=0;j<strlen(chIden[i])&&ptfl;j++)
            {
                if(chIden[i][j]=='.')
                {
				
                 
					cout<<"         "<<symbol<<" "<<"<Special identifier> : "<<setw(10)<<chIden[i]<<endl;
                    ptfl=0;
                }
            }
            if(ptfl)                                        //若非keywords和非法用法則是indentifier
            {
				
				
				strcpy(Identifier[id++],chIden[i]);
				strcpy(type[fl++],chIden[i-1]);
				scope[sc++]=symbol;
				
				cout<<"         "<<symbol<<" <Identifier>: "<<setw(8)<<chIden[i]<<endl;
				
				//cout<<" answer"<<chIden[i-1];
				//cout<<"         "<<symbol<<" <Identifier>: "<<setw(8)<<Identifier[id]<<"id ="<<id<<endl;
              
            }
            }
        }
        else
        {
            tfl=1;
            ptfl=0;
            for(j=0;j<strlen(chIden[i])&&tfl;j++)
            {
            if(IsIden(chIden[i][j]))
            {
				cout<<"         "<<symbol<<" <ERROR> : "<<chIden[i]<<endl;
               
                tfl=0;
            }
            else if(chIden[i][j]=='.')
            {
                if(ptfl)
                {
					cout<<"         "<<symbol<<" <ERROR> : "<<chIden[i]<<endl;
                
                    tfl=0;
                }
                if(!ptfl)
                {
                    ptfl=1;
                }
            }
            }
			floatfl=0;
			for(j=0;j<strlen(chIden[i]);j++){                //利用floatfl判斷數是否為浮點術若是則印出float若否則印出integer
				if(chIden[i][j]=='.'){
					floatfl=1;
					cout<<"         "<<symbol<<" "<<"<float>: "<<setw(10)<<chIden[i]<<endl;
					break;
				}
			}
				if(tfl&&!floatfl){
		    	cout<<"         "<<symbol<<" "<<"<integer>: "<<setw(10)<<chIden[i]<<endl;
			
            }
			
        }
        }
        for(i=0;i<uqOpi;i++)
        {
        tfl=1;
        for(j=0;j<defOpi&&tfl;j++)
        {
            if(!strcmp(chOpr[i],defOprStr[j]))
            {
				cout<<"         "<<symbol<<" "<<"<Operator>: "<<setw(10)<<chOpr[i]<<endl;
			    strcpy(Opr[Opri++],chOpr[i]);
				tfl=0;
            }
        }
        if(tfl)
        {
            cout<<"error   "<<endl;
        }
        }
		for(i=0;i<sLitteri;i++)
        {
			if(strfl){
			cout<<"         "<<symbol<<" "<<"<String>:    ";
			puts(sLitter[i]);
			}
		}
		for(i=0;i<cLitteri;i++)
        {
			if(charfl){
			cout<<"         "<<symbol<<" "<<"<char>:    ";
			puts(cLitter[i]);
			}
		}
	    sLitteri=0;

			
		for(i=0;i<uqDei;i++)
        {
        tfl=1;
        for(j=0;j<uqDei&&tfl;j++)
        {
			if(chDel[i]=='{'){                  //這邊判斷上scope數量
					symbol++;
					}
				if(chDel[i]=='}'){
					symbol--;
					}
           
				cout<<"         "<<symbol<<" "<<"<Special Symbol>: "<<setw(10)<<chDel[i]<<endl;
			    strcpy(Opr[Opri++],chOpr[i]);
				tfl=0;
            }
		}
	for(i=0;i<comi;i++){
	if(pcomfl){
			cout<<"         "<<symbol<<" "<<"<comment>: ";
			puts(comment[i]);
			}
	}
	for(i=0;i<comi2;i++){
	if(pcomfl2){
			cout<<"comment: ";
			puts(comment2[i]);
			}
	}
    }

	void display(){
		if(line<10)
		cout<<" "<<"Line  "<<setw(1)<<line<<" "<<symbol<<"  "<<Str<<endl;
		else cout<<" "<<"Line "<<setw(1)<<line<<" "<<symbol<<"  "<<Str<<endl;
	
		
	}
	
	void display2(){
		for(int i=0;i<id;i++){
			cout<<"identifier  "<<Identifier[i]<<endl;
		}
	}
	
	
	void build_symbol_table(){
		index=0;
		int repeat_fl[20];
		memset(repeat_fl,0,sizeof(repeat_fl)); 
		for(int i=1;i<id;i++)
			for(int j=0;j<i;j++){
				if(strcmp(Identifier[i],Identifier[j])==0)
					repeat_fl[i]=1;
			
		
		}
		for(int i=0;i<id;i++){
			if(repeat_fl[i]==0)
				strcpy(result_iden[index++],Identifier[i]);
		}

		




	}
	
void save_sentence(){
	int a=0;
	int opfl=0;
	toky=0;
	while(Str[a]!='\0'){
		a++;
	}
	length[len]=a;
	
	for(int n=0;n<length[len];n++){
		if(Str[n]=='=')
			opfl=1;
		}
	if(opfl==1){
	
			for(int m=0;m<length[len]-2;m++){
				sentence_tok[tokx][toky++]=Str[m];

			}
			sentence_len[tokx]=toky;
		
		
			tokx++;
			
	}
	len++;
	/*while(Str[i]!='\0'){
		cout<<"111111111";
		if(Str[i]=='='){
			do{
			     cout<<"222222222";
				 sentence_tok[tokx][toky++]=Str[i-1];
				 i++;
			}while(Str[i]!='\0');
		}
		else{
			i++;
		}
		} */
	
	
}
			
		
void build_qua(){
	fstream file2;
	file2.open("output2.txt",ios::out);
	if(!file2){
		 perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
   }
	int cha;
	int qindex=0;
	int tmpindex=0;
	int k;
	int flc=0;
	/////////////////////////
	char* reg[]={"reg0","reg1","reg2","reg3","reg4","reg5","reg6","reg7","reg8","reg9","reg10","reg11","reg12","reg13","reg14","reg15","reg16","reg17","reg18"};
	const int ss = 30;
	char cr[ss];
	int lr[ss];
	int rr[ss];
	int cc=0;
	memset(sentence_tokf,-1,sizeof(sentence_tokf)); //設初始值為-1
	for(int i=0;i<tokx;i++){          //清除空白
		cha=0;
		for(int j=0;j<sentence_len[i];j++){
			if(sentence_tok[i][j]!=' '){
				sentence_tokf[i][cha++]=sentence_tok[i][j];
			}
				

		}
		file2<<endl;
		cha_num[i]=cha;
	}
   int reg_index=0 ,op_index=0;
   for(int i=0;i<tokx;i++)         
		for(int j=2;j<cha_num[i];j++){
			if(sentence_tokf[i][j]=='='){
				temp[qindex++]=sentence_tokf[i][j+1];

		/*		cr[op_index++] =sentence_tokf[i][j];//op memo
				cr[op_index] ='\0';//op memo
			    lr[op_index-1]=reg_index++;*/

				file2<<sentence_tokf[i][j]<<setw(10)<<sentence_tokf[i][j+1]<<setw(10)<<"       "<<setw(10)<<reg[reg_index++]<<endl;
				k=j+2;
			if(k==cha_num[i]){                              //查看數字右邊是否有運算子 若有則進入流程2
				file2<<sentence_tokf[i][j]<<setw(10)<<reg[reg_index-1]<<setw(10)<<"       "<<setw(10)<<reg[reg_index++]<<endl; tmpindex++;
				file2<<sentence_tokf[i][j]<<setw(10)<<reg[reg_index-1]<<setw(10)<<"       "<<setw(10)<<reg[reg_index++]<<endl; tmpindex++;
				file2<<sentence_tokf[i][j]<<setw(10)<<reg[reg_index-1]<<setw(10)<<"       "<<setw(10)<<reg[reg_index++]<<endl; tmpindex++;
				file2<<sentence_tokf[i][j]<<setw(10)<<reg[reg_index-1]<<setw(10)<<"       "<<setw(10)<<sentence_tokf[i][j-1]<<endl; 
			}
			else if(k!=cha_num[i]){     //數字後面仍有運算符
				j++;
				for(int k=j;k+2<cha_num[i];k++){
					char tt=sentence_tokf[i][k+1];
					if(tt!='+'&&tt!='-'&&tt!='*'&&tt!='/'){
						file2<<'='<<setw(10)<<tt<<setw(10)<<"       "<<setw(10)<<reg[reg_index++]<<endl;

					}else if(tt=='+'||tt=='-'){                                    //First
						cr[op_index++]=tt;//memo + -
						//cout<<tt<<"@@"<<op_index-1;
						cr[op_index] ='\0';//op memo
						lr[op_index-1]=reg_index-1;//alloc reg for left of +|-


						if(sentence_tokf[i][k+3]=='*'||sentence_tokf[i][k+3]=='/'){//Second
							rr[op_index++]=3+reg_index++;//alloc reg for right of +|-
							//cout<<tt<<"@@"<<op_index-1;
						}else{
							rr[op_index++]=1+reg_index++;//alloc reg for right of +|-
							//cout<<tt<<"@@"<<op_index-1;
							file2<<'='<<setw(10)<<sentence_tokf[i][k+2]<<setw(10)<<"       "<<setw(10)<<reg[reg_index++]<<endl;
							
						}

					}else if(tt=='*'||tt=='/'){                                    //First
						cr[op_index++]=tt;//memo * /

						//cout<<tt<<"@@"<<op_index-1;
						cr[op_index] ='\0';//op memo
						lr[op_index-1]=reg_index-1;//alloc reg for left of *|/

						if(sentence_tokf[i][k+3]=='+'||sentence_tokf[i][k+3]=='-'){//Second
							rr[op_index++]=1+reg_index++;//alloc reg for right of *|/
						}else{
							rr[op_index++]=1+reg_index++;//alloc reg for right of *|/
							file2<<'='<<setw(10)<<sentence_tokf[i][k+2]<<setw(10)<<"       "<<setw(10)<<reg[reg_index++]<<endl;
						}
					}
					

				}
				if(cc==0)file2<<cr[0]<<setw(10)<<reg[lr[0]]<<setw(10)<<reg[rr[1]]<<setw(10)<<reg[rr[1]]<<endl;
				if(cc==1)file2<<cr[4]<<setw(10)<<reg[lr[4]]<<setw(10)<<reg[rr[3]]<<setw(10)<<reg[rr[3]]<<endl;
				if(cc==1)file2<<cr[2]<<setw(10)<<reg[lr[2]]<<setw(10)<<reg[rr[3]]<<setw(10)<<reg[rr[3]]<<endl;
				cc++;






				

			}
			}
			

		}

	
}
			
					
					
				
	

};

int main(int argc, char argv[])
{
Lexical_Analyzer oblex;
fstream file;
int size=0;
char file_name[40],ch;
char mystring[220]={0};
cout<<"       Please Enter File name :    ";
//gets(file_name);
file.open("D:\data.txt",ios::in);
if(!file)
{
 perror("Error while opening the file.\n");
 exit(EXIT_FAILURE);
}
else
{
    
  
  do{
	  file.getline(mystring,sizeof(mystring));
	  oblex.getstr(mystring);
	  oblex.save_sentence();
	  oblex.display();
      oblex.Find();
      oblex.Multcheck();
      oblex.Outcome();


 
  }while(!file.eof());
  	
}
oblex.build_symbol_table();
oblex.build_qua();
file.close();
fstream fp;
fp.open("output1.txt",ios::out);
for(int i=0;i<index;i++)
		fp<<"id  "<<result_iden[i]<<"   "<<type[i]<<"  "<<scope[i]<<endl;



system("PAUSE");
}