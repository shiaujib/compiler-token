#include"result.cpp"
int cfgi=0;

struct nlist{
	char *LHS;
	bool b;
} N[50],isN[50];
	

struct flist{
	char *s;
	flist *l;
	flist *r;
} F[55];




bool isTer(char *s1){

	int si=0;
	while(si<NumOfNon){
		
		if(strcmp(Nonterminal[si],s1)==0)return false;
		si++;
	}
	return true;
	
}
 
bool Nullable(char *s3){

	int si=0,sj=0,sk=0;
	char c,item[128];
	bool isempty=0;


		//cout<<" "<<item<<" "<<endl;

		if(isTer(s3)){
			//cout<<"@@@@@@";
			return false;
		}
		else {
			//all RHSs for LHS VVVVVVV
			while(true){
				if(strcmp(CFG[si].LHS,s3)==0){
					cout<<"  "<<CFG[si].LHS<<"'s"<<CFG[si].rNum<<endl;
					sj=0;
					if(CFG[si].rNum==0)return true;
					else{
						while(true){
							if(Nullable(CFG[si].array[sj++].RHS)==false)break;
							if(sj==CFG[si].rNum)return true;
				
						}
						si++;
					}
				}else si++;
				
				if(si==cfgi)return false;
					
			}
		}


}


flist *First(char *s3){

	int s=0,si=0,sj=0,sk=0,size=0;
	flist *item = new flist[1];
	flist *tmp,*tail;
	item->s=s3;
	item->l=item->r=NULL;
	tail=item;

	if(isTer(s3)){
		//cout<<"I'm \n";
		return item;
	}
	else {

		while(sk<cfgi){
		//	cout<<"loop in First()~~\n";
			if(strcmp(CFG[sk].LHS,s3)==0){

				if(CFG[sk].rNum!=0){
					//cout<<"got the ter~\n";
					tmp=First(CFG[sk].array[0].RHS);
					tail->r=tmp;
					tmp->l=tail;
					tail=tail->r;
					cout<<"string :"<<tail->s<<endl;
				}else return item->r;
				sk++;
			}else{	
				sk++;
			}

		}
		
		return item->r;
	}

}







void output1(){

	char *tmp,*tmp2;
	int si=0,sk=0;
	bool b;
	ofstream FileOutPut;
	FileOutPut.open(FileNameOut2);

	FileOutPut<<"////////Nullable////////\n\n";
	
	N[si].LHS=CFG[si].LHS;

	b=Nullable(CFG[si].LHS);
	N[si].b=b;


	cout<<CFG[si].LHS<<" "<<b<<endl;
	FileOutPut<<CFG[si].LHS<<" "<<b<<endl;
	tmp=CFG[si].LHS;
	si++;
	while(si<cfgi){
		if(strcmp(tmp,CFG[si].LHS)==0)si++;
		else{
			
			N[si].LHS=CFG[si].LHS;
			cout<<N[si].LHS<<endl;
			b=Nullable(CFG[si].LHS);
			N[si].b=b;
		

			cout<<CFG[si].LHS<<" "<<b<<endl;
			FileOutPut<<CFG[si].LHS<<" "<<b<<endl;
			tmp=CFG[si].LHS;
			si++;
		}
	}
	
	si=0;
	FileOutPut<<"\n\n/////////First()///////\n\n";
	
	F[si].s=CFG[sk].LHS;
	F[si].r=First(F[si].s);
	F[si].l=NULL;

	tmp=F[si].s;

	si++;
	while(sk<cfgi){
		if(strcmp(tmp,CFG[sk].LHS)==0)sk++;
		else{
			F[si].s=CFG[sk].LHS;
			F[si].r=First(F[si].s);
			F[si].l=NULL;
			tmp=F[si].s;
			si++;
			sk++;
		}
		
	}
	
	flist* tmp3;

	for(int i=0;i<si;i++){

		tmp3=&F[i];
		cout<<tmp3->s<<" : ";
		FileOutPut<<tmp3->s<<" : ";
		tmp3=tmp3->r;

		for(;tmp3!=NULL;tmp3=tmp3->r){

			cout<<" "<<tmp3->s;
			FileOutPut<<" "<<tmp3->s;
		}
		cout<<endl;
		FileOutPut<<endl;
	}

	FileOutPut.close();
}








	
int generator(){


	ifstream FileInPut;
	FileInPut.open(FileNameIn2);//grammarSLR.txt

	char ctmp;
	char str[128];//for readline
	int max=0;
	int stri=0;
	int ind=0;
	int ck=0;
	int rhsc=0;
	bool isL=1;


	//construct a CFG table
	while(FileInPut.peek()!=EOF){
		stri=0;
		isL=1;
		ind=0;
		ck=0;
		rhsc=0;
		
		FileInPut.getline(str,128,'\n');	

		while(str[ind]!='\0'){
			ctmp=str[ind++];
			cout<<ctmp;
			if(isL){
				if(ctmp==' '){
					isL=0;
					stri=0;
				}
				else{
					CFG[cfgi].LHS[stri++]=ctmp;
					CFG[cfgi].LHS[stri]='\0';
				}

			}else{
				if(ctmp!=' '){
					ck=1;
					CFG[cfgi].array[rhsc].RHS[stri++]=ctmp;
					CFG[cfgi].array[rhsc].RHS[stri]='\0';

				}
				else if(ck==0){
					CFG[cfgi].rNum=0;
					break;
				}		
				else {
					stri=0;
					rhsc++;
					CFG[cfgi].rNum=rhsc;
				}
			}
		}
		
		if(rhsc==0&&ck==1)CFG[cfgi].rNum=1;
		else if(rhsc>1)CFG[cfgi].rNum++;

		if(cfgi==41||cfgi==19||cfgi==20||cfgi==18||cfgi==21)CFG[cfgi].rNum++;

		//next prod
		cfgi++;
		max=cfgi;		
	}

	cout<<" Hello ~~\n";

	for(int i=0;i<cfgi;i++){
		cout<<CFG[i].rNum<<" "<<CFG[i].LHS<<" -> ";
		for(int j=0;j<CFG[i].rNum;j++){
			cout<<CFG[i].array[j].RHS<<" ";
		}
		cout<<endl;
	}

	output1();

//	result();	
	return 0;
}
