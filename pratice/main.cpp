

#include<iostream>

#include "ZipCode.h"

#include<string>



using namespace std;





int main()

{

	int zip;

	string str;

	int code;

	int n=0;

	int x=0;

	cout<<"please enter zipcode(zipcode integer):";

	cin>>zip;

	if(zip>99999){

            cout<<"input error";
            return 0;

	}		

	ZipCode zipcodeint(zip);

	x=zipcodeint.check1();

	if(x==0){
            cout<<"input error";
            return 0;

	}		

	zipcodeint.seperate();

	zipcodeint.encode();

	zipcodeint.display1();

	do{

	cout<<"please enter zipcode(zipcode bar code string):";

	cin>>str;

	}while(str.length()!=25);          //­Y¿é€JŠrŠê€£¬°25digit«h­«·s¿é€J

	

	ZipCode zipcodestr(str);

	zipcodestr.transform();

	

	n=zipcodestr.check2();

	if(n==0){
           cout<<"input error";
           return 0;


	}

	zipcodestr.decode();

	zipcodestr.display2();


	   





	return 0;

}


