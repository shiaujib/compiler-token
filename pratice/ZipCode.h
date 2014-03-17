

#include<iostream>

#ifndef ZIPCODE_H

#define ZIPCODE_H
using namespace std;


class ZipCode{

public:

	ZipCode(int);

	ZipCode(string);

    void setcode(int);

	void setcode2(string);

	void seperate();    //±N¿é€Jinteger©î¶}€À§OŠs€J°}ŠC

	void encode();

	void decode();

	void transform();   //change string into integer

	int check1();

	int check2();       //ÀË¬dinput string¬O§_Š³»~

	void display1();   //¿é¥Xzipcode integerÂà¬° barcode stringµ²ªG

	void display2();   //¿é¥Xbarcode stringÂà¬°zipcode integerµ²ªG

		

private:

	int Code1;

	string Code2;

	int array1[5];      //¥ÎšÓŠs©ñ©îžÑ«áªºŒÆŠr

	int array2[30];     //±Ncode2¥ÑstringÂàŠ^intŠsŠbarray2žÌ

	int enzipcode[30];     //Šs©ñincode«áªº­È

	int dezipcode[5];      //ŠbŠ¹Šs©ñžÑœX«áªºcode

	int flag;         //¥ÎšÓÀËŽú¬O§_¥X²{«DªkŒÆŠr

	



};

#endif
