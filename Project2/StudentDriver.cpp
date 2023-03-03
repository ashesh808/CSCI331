/*
 * Description: Test file for Student class consiting of several function calls
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 2nd September, 2022
 * Profressor: Jie Meichsner
 */

#include <fstream>
#include <vector>
#include <iomanip>
#include "iobuffer.h"
#include "fixfld.h"
 #include "length.h"
#include "Student.h"
#include "buffile.h"
using namespace std;


Student JohnAmes;
Student AlanMason;
Student GARiccardi;
Student Padded;

template <class IOB>
void testBuffer (IOB & Buff, char * myfile)
{
	Student student;
	int result;
	int recaddr1, recaddr2, recaddr3, recaddr4;

	// Test writing
	//Buff . Print (cout);
	BufferFile TestOut (Buff);
	//result = TestOut . Create (myfile,ios::in|ios::out);
	//cout << "create file "<<result<<endl;
	//if (!result)
	//{
		//cout << "Unable to create file "<<myfile<<endl;
		result = TestOut . Open (myfile, ios::in|ios::out);
		cout << "open file "<<result<<endl;
		if (!result)
		{
			cout << "Unable to open file "<<myfile<<endl;
			return;
		}
	//}
	JohnAmes . Pack (Buff);
	//Buff . Print (cout);
	recaddr1 = TestOut . Write ();
	cout << "write at "<<recaddr1<<endl;
	AlanMason. Pack (Buff);
	//Buff . Print (cout);
	recaddr2 = TestOut . Write ();
	cout << "write at "<<recaddr2<<endl;
	GARiccardi . Pack (Buff);
	recaddr3 = TestOut . Write ();
	cout << "write at "<<recaddr3<<endl;
	GARiccardi.Pack (Buff);
	recaddr4 = TestOut . Write ();
	cout << "write at "<<recaddr4<<endl;
	TestOut . Close ();

	// test reading
	BufferFile TestIn (Buff);
	TestIn . Open (myfile, ios::in);
	//result = TestIn . ReadHeader ();
	//cout <<"read header "<<result<<endl;
	TestIn . Read (recaddr3);
	student . Unpack (Buff);
	student . Print (cout, "First record:");
	TestIn . Read (recaddr2);
	student . Unpack (Buff);
	student . Print (cout, "Second record:");
	TestIn . Read (recaddr1);
	student . Unpack (Buff);
	student . Print (cout, "Third record");
	TestIn . Read (recaddr4);
	student . Unpack (Buff);
	student . Print (cout, "Fourth record");
	result = TestIn . Read (recaddr4*2);
	if (result!= -1) cout<<"Read past end of file! Error."<<endl;
	else cout <<"Read past end of file failed! Correct."<<endl;
}

void InitPerson()
{
	cout << "Initializing 3 Persons" <<endl;
    strcpy (JohnAmes.identifier, "1234555");
	strcpy (JohnAmes.lname, "Ames");
	strcpy (JohnAmes.fname, "John");
	strcpy (JohnAmes.address, "123 Maple");
	strcpy (JohnAmes.dateofenrollment, "08/23/22");
	strcpy (JohnAmes.creditHoursCompleted, "74");
    JohnAmes . Print (cout);

    strcpy (AlanMason.identifier, "42141241");
	strcpy (AlanMason.lname, "Mason");
	strcpy (AlanMason.fname, "Alan");
	strcpy (AlanMason.address, "90 Eastgate");
    strcpy (AlanMason.dateofenrollment, "12/42/90");
    strcpy (AlanMason.creditHoursCompleted, "90");
    AlanMason . Print (cout);

	strcpy (GARiccardi.identifier, "8888888888");
    strcpy (GARiccardi.lname, "Riccardi");
	strcpy (GARiccardi.fname, "Gregory");
	strcpy (GARiccardi.address, "2006 W Randolph");
    strcpy (GARiccardi.dateofenrollment, "12/23/02");
	strcpy (GARiccardi.creditHoursCompleted, "100");
	GARiccardi . Print (cout);

    strcpy (Padded.identifier, "8888888888");
	strcpy (Padded.lname, "Riccardi");
	strcpy (Padded.fname, "Gregory");
	strcpy (Padded.address, "2006 W Randolph");
    strcpy (Padded.dateofenrollment, "12/23/02");
	strcpy (Padded.creditHoursCompleted, "100");
}

void testFixedField ()
{
	cout <<"Testing Fixed Field Buffer"<<endl;
	FixedFieldBuffer Buff (6);
	Student :: InitBuffer (Buff);
	testBuffer (Buff, "fixfile.dat");
}

void testLength ()
{
	cout << "\nTesting LengthTextBuffer"<<endl;
	LengthFieldBuffer Buff;
	Student :: InitBuffer (Buff);
	testBuffer (Buff, "lenfile.dat");
}

void testDelim ()
{
	cout << "\nTesting DelimTextBuffer"<<endl;
	DelimFieldBuffer::SetDefaultDelim ('|');
	DelimFieldBuffer Buff;
	Student :: InitBuffer (Buff);
	testBuffer (Buff, "delfile.dat");
}

int main(int argc, char ** argv)
{
	InitPerson();
	testFixedField ();
	testLength ();
	testDelim ();
}