/*
 * Description: Test file for CourseRegistration class consiting of several function calls
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 2nd March, 2023
 * Profressor: Jie Meichsner
 */

#include <fstream>
#include <vector>
#include <iomanip>
#include "iobuffer.h"
#include "fixfld.h"
#include "length.h"
#include "buffile.h"
#include "CourseRegistration.h"
using namespace std;

CourseRegistration test1;
CourseRegistration test2;
CourseRegistration test3;
CourseRegistration Padded;

template <class IOB>
void testBuffer(IOB &Buff, char *myfile)
{
    CourseRegistration student;
    int result;
    int recaddr1, recaddr2, recaddr3, recaddr4;

    // Test writing
    // Buff . Print (cout);
    BufferFile TestOut(Buff);
    // result = TestOut . Create (myfile,ios::in|ios::out);
    // cout << "create file "<<result<<endl;
    // if (!result)
    //{
    // cout << "Unable to create file "<<myfile<<endl;
    result = TestOut.Open(myfile, ios::in | ios::out);
    cout << "open file " << result << endl;
    if (!result)
    {
        cout << "Unable to open file " << myfile << endl;
        return;
    }
    //}
    test1.Pack(Buff);
    // Buff . Print (cout);
    recaddr1 = TestOut.Write();
    cout << "write at " << recaddr1 << endl;
    test2.Pack(Buff);
    // Buff . Print (cout);
    recaddr2 = TestOut.Write();
    cout << "write at " << recaddr2 << endl;
    test3.Pack(Buff);
    recaddr3 = TestOut.Write();
    cout << "write at " << recaddr3 << endl;
    test3.Pack(Buff);
    recaddr4 = TestOut.Write();
    cout << "write at " << recaddr4 << endl;
    TestOut.Close();

    // test reading
    BufferFile TestIn(Buff);
    TestIn.Open(myfile, ios::in);
    // result = TestIn . ReadHeader ();
    // cout <<"read header "<<result<<endl;
    TestIn.Read(recaddr3);
    student.Unpack(Buff);
    student.Print(cout, "First record:");
    TestIn.Read(recaddr2);
    student.Unpack(Buff);
    student.Print(cout, "Second record:");
    TestIn.Read(recaddr1);
    student.Unpack(Buff);
    student.Print(cout, "Third record");
    TestIn.Read(recaddr4);
    student.Unpack(Buff);
    student.Print(cout, "Fourth record");
    result = TestIn.Read(recaddr4 * 2);
    if (result != -1)
        cout << "Read past end of file! Error." << endl;
    else
        cout << "Read past end of file failed! Correct." << endl;
}

void InitPerson()
{
    cout << "Initializing 3 Persons" << endl;
    strcpy(test1.courseId_, "1234555");
    strcpy(test1.studentId_, "898989");
    strcpy(test1.creditHours_, "30");
    strcpy(test1.grade_, "A");
    test1.Print(cout);

    strcpy(test2.courseId_, "768375402");
    strcpy(test2.studentId_, "253253");
    strcpy(test2.creditHours_, "20");
    strcpy(test2.grade_, "B");
    test2.Print(cout);

    strcpy(test3.courseId_, "78787");
    strcpy(test3.studentId_, "88888");
    strcpy(test3.creditHours_, "50");
    strcpy(test3.grade_, "C");
    test3.Print(cout);

    strcpy(Padded.courseId_, "78787");
    strcpy(Padded.studentId_, "88888");
    strcpy(Padded.creditHours_, "50");
    strcpy(Padded.grade_, "C");
}

void testFixedField()
{
    cout << "Testing Fixed Field Buffer" << endl;
    FixedFieldBuffer Buff(4);
    CourseRegistration ::InitBuffer(Buff);
    testBuffer(Buff, "fixfile.dat");
}

void testLength()
{
    cout << "\nTesting LengthTextBuffer" << endl;
    LengthFieldBuffer Buff;
    CourseRegistration ::InitBuffer(Buff);
    testBuffer(Buff, "lenfile.dat");
}

void testDelim()
{
    cout << "\nTesting DelimTextBuffer" << endl;
    DelimFieldBuffer::SetDefaultDelim('|');
    DelimFieldBuffer Buff;
    CourseRegistration ::InitBuffer(Buff);
    testBuffer(Buff, "delfile.dat");
}

int main(int argc, char **argv)
{
    InitPerson();
    testFixedField();
    testLength();
    testDelim();
}