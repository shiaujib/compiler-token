

#include<iostream>

#include<string>

#include "ZipCode.h"

using namespace std;





ZipCode::ZipCode(int code1){



		setcode(code1);

	}



ZipCode::ZipCode(string code2){

		setcode2(code2);

	}



void ZipCode::setcode(int code1){

		Code1=code1;

	}



void ZipCode::setcode2(string code2){

		Code2=code2;

	

}

void ZipCode::seperate(){

	for(int i=0;i<4;i++) array1[i]=0;

	for(int i=4;i>=0;i--){

		array1[i]=Code1%10;

		Code1/=10;

	}

}

void ZipCode::encode(){

	int n=0;

	for(int i=0;i<25;i++) enzipcode[i]=0;

	  for(int i=0;i<5;i++){

		switch(array1[i])                 //³ožÌ±Narray1ªºŒÆŠršú¥XšÓ€ÀªRencode

		{

		case 9:enzipcode[n]=1;

			enzipcode[n+1]=0;

			enzipcode[n+2]=1;

			enzipcode[n+3]=0;

			enzipcode[n+4]=0;

			n+=5;

			break;

		case 8:enzipcode[n]=1;

			enzipcode[n+1]=0;

			enzipcode[n+2]=0;

			enzipcode[n+3]=1;

			enzipcode[n+4]=0;

			n+=5;

			break;

		case 7:enzipcode[n]=1;

			enzipcode[n+1]=0;

			enzipcode[n+2]=0;

			enzipcode[n+3]=0;

			enzipcode[n+4]=1;

			n+=5;

			break;

		case 6:enzipcode[n]=0;

			enzipcode[n+1]=1;

			enzipcode[n+2]=1;

			enzipcode[n+3]=0;

			enzipcode[n+4]=0;

			n+=5;

			break;

		case 5:enzipcode[n]=0;

			enzipcode[n+1]=1;

			enzipcode[n+2]=0;

			enzipcode[n+3]=1;

			enzipcode[n+4]=0;

			n+=5;

			break;

		case 4:enzipcode[n]=0;

			enzipcode[n+1]=1;

			enzipcode[n+2]=0;

			enzipcode[n+3]=0;

			enzipcode[n+4]=1;

			n+=5;

			break;

		case 3:enzipcode[n]=0;

			enzipcode[n+1]=0;

			enzipcode[n+2]=1;

			enzipcode[n+3]=1;

			enzipcode[n+4]=0;

			n+=5;

			break;

		case 2:enzipcode[n]=0;

			enzipcode[n+1]=0;

			enzipcode[n+2]=1;

			enzipcode[n+3]=0;

			enzipcode[n+4]=1;

			n+=5;

			break;

		case 1:enzipcode[n]=0;

			enzipcode[n+1]=0;

			enzipcode[n+2]=0;

			enzipcode[n+3]=1;

			enzipcode[n+4]=1;

			n+=5;

			break;

		case 0:enzipcode[n]=1;

			enzipcode[n+1]=1;

			enzipcode[n+2]=0;

			enzipcode[n+3]=0;

			enzipcode[n+4]=0;

			n+=5;

			break;

		default:flag=1;     //¥ÎšÓÀËŽú¬O§_¥X²{¥H€WŒÆŠr¥H¥~ªºŒÆ

			break;

		}



	}

}

		

		

void ZipCode::decode(){

	int n=0;

	for(int i=0;i<5;i++) dezipcode[i]=0;  //±N°}ŠC²MªÅ

	for(int i=0;i<25;i++){

		if(i%5==0) array2[i]*=7;

		else if(i%5==1) array2[i]*=4; 

		else if(i%5==2) array2[i]*=2; 

		else if(i%5==3) array2[i]*=1; 

		else if(i%5==4) array2[i]*=0; 

	

		

	}



	for(int i=0;i<25;i++){                //±N5­Ó¬°€@²Õarray2¬Û¥[«áŠs€Jdezipcode

            

		dezipcode[n]+=array2[i];

		if(dezipcode[n]>10) {

			dezipcode[n]=0;

		

		}

		if(i%5==4) n++;                   //5­Óarray2¬Û¥[«án+1

		

		}

}



void ZipCode::transform(){                       //Šb³ožÌ±NŠrŠêÂàŠšŒÆŠrŠs€Jarray€€€è«Kdecode

	int index;

	for(int i=0;i<=30;i++) array2[i]=0;          //¥ý±N°}ŠC³£¬°0¥H€è«KÀËŽú¬O§_Š³Šh¥XŠì€ž

	for(index=0; index<25; index++){

     array2[index] = Code2[index]-'0';            // ±N ascii ÂàŒÆŠr

    }

}



int ZipCode::check1(){

	if(flag==1){

		cout<<"input error please try again:";     //¥X²{«DªkŠr€žŠ^³ø¿ù»~

		return 0;

	}

	return 1;

}



int ZipCode::check2(){

	int z=0;

	if(array2[0]!=1&&array2[24]!=1){                        //·í¶}ÀY©Îµ²§ÀšÃ«D1«hŠ^³ø¿ù»~

		cout<<"input code error please check again(¶}ÀYµ²§À»Ý¬°1)"<<endl;

		return 0;

	}

	for(int i=0;i<25;i++){                                   //·íinput string¥X²{0,1¥H¥~ªºŒÆ«hŠ^³ø¿ù»~

		if(array2[i]>1){

			cout<<"input code error please try again(¥u¥i¿é€J0,1)"<<endl;

			return 0;

			break;

		}

		z+=array2[i];

		if(z>2) {

			cout<<"input code error please try again(€@²Õ¶W¹Lšâ­Ó1)"<<endl; //input string€£¥i¥X²{¶W¹L2­Ó1

			return 0;

		}

		if(i%5==4&&z<2){

			cout<<"input code error please try again(€@²Õ€£š¬šâ­Ó1)"<<endl;

			return 0;

		}

		if(i%5==4) z=0;

	}

	return 1;

}

void ZipCode::display1(){

	cout<<"the bar code string is:";

	for(int i=0;i<25;i++){

		cout<<enzipcode[i];

	}

	cout<<endl;

}

void ZipCode::display2(){

	cout<<"the decode integer is:";

	for(int i=0;i<5;i++){

	cout<<dezipcode[i];

	}
        cout<<endl;

	

}







		

		

		
