// test.cc// Copyright 1997, Gregory A. Riccardi
#include <fstream>
#include <string.h>
#include <iomanip>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"
#include "person.h"

using namespace std;

void testFixText ()
{
	Person person;
	FixedTextBuffer Buff (6);
	
	Person :: InitBuffer (Buff);
	
	//If needed, pad a string with blanks before it is copied to a field
	/*
	strcpy (person.LastName, "Ames      ");
	strcpy (person.FirstName, "Mary      ");
	strcpy (person.Address, "123 Maple      ");
	strcpy (person.City, "Stillwater     ");
	strcpy (person.State, "OK");
	strcpy (person.ZipCode, "74075    ");
	*/
	
	//no padding here. Instead padding is performed in pack operation of FixedTextBuffer class
	strcpy (person.LastName, "Ames");
	strcpy (person.FirstName, "Mary");
	strcpy (person.Address, "123 Maple");
	strcpy (person.City, "Stillwater");
	strcpy (person.State, "OK");
	strcpy (person.ZipCode, "74075");
		
	person . Print (cout);
	person . Pack (Buff);
	Buff . Print (cout);
	ofstream TestOut ("fixtext.dat",ios::out|ios::binary);
	Buff . Write (TestOut);
	TestOut . close ();
	ifstream TestIn ("fixtext.dat", ios::in|ios::binary);
	FixedTextBuffer InBuff (6);
	Person :: InitBuffer (InBuff);
	Buff . Read (TestIn);
	person . Unpack (Buff);
	person . Print (cout);
}

void testLenText ()
{
	cout << "\nTesting LengthTextBuffer"<<endl;
	Person person;
	LengthTextBuffer Buff;
	Person :: InitBuffer (Buff);
	strcpy (person.LastName, "Ames");
	strcpy (person.FirstName, "Mary");
	strcpy (person.Address, "123 Maple");
	strcpy (person.City, "Stillwater");
	strcpy (person.State, "OK");
	strcpy (person.ZipCode, "74075");
	person . Print (cout);
	Buff . Print (cout);
	cout <<"pack person "<<person . Pack (Buff)<<endl;
	Buff . Print (cout);
	ofstream TestOut ("lentext.dat",ios::out|ios::binary);
	Buff . Write (TestOut);
	Buff . Write (TestOut);
	strcpy (person.FirstName, "Dave");
	person.Print (cout);
	person.Pack (Buff);
	Buff . Write (TestOut);
	TestOut . close ();
	ifstream TestIn ("lentext.dat", ios::in|ios::binary);
	LengthTextBuffer InBuff;
	Person :: InitBuffer (InBuff);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
}

void testDelText ()
{
	cout << "\nTesting DelimTextBuffer"<<endl;
	Person person;
	strcpy (person.LastName, "Ames");
	strcpy (person.FirstName, "Mary");
	strcpy (person.Address, "123 Maple");
	strcpy (person.City, "Stillwater");
	strcpy (person.State, "OK");
	strcpy (person.ZipCode, "74075");
	person . Print (cout);
	DelimTextBuffer Buff;
	Person :: InitBuffer (Buff);
	Buff . Print (cout);
	cout <<"pack person "<<person . Pack (Buff)<<endl;
	Buff . Print (cout);
	ofstream TestOut ("deltext.dat",ios::out|ios::binary);
	Buff . Write (TestOut);
	Buff . Write (TestOut);
	strcpy (person.FirstName, "Dave");
	person.Print (cout);
	person.Pack (Buff);
	Buff . Write (TestOut);
	TestOut . close ();
	ifstream TestIn ("deltext.dat", ios::in|ios::binary);
	DelimTextBuffer InBuff;	
	Person :: InitBuffer (InBuff);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
	cout <<"read "<<Buff . Read (TestIn)<<endl;
	cout <<"unpack "<<person . Unpack (Buff)<<endl;
	person . Print (cout);
}

int main()
{
	//testFixText ();
	testLenText ();
	//testDelText ();
	
	return 1;
}
