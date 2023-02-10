/*
 * Description: Test file for Student class consiting of several function calls
 * Name: Ashesh Nepal
 * starID: ta9983ry
 * Date: 2nd September, 2022
 * Profressor: Jie Meichsner
 */

#include <fstream>
#include <vector>
#include "Student.h"
using namespace std;

// Test program to run all the functions
int main()
{
    int identifier, creditHoursCompleted;
    string fname, lname, address;
    Date dateofenrollment;
    vector<Student> studentGroup;
    char choice = 'y';
    while (choice == 'y' || choice == 'Y')
    {
        cout << "Enter student identifier \n";
        cin >> identifier;
        cout << "Enter student name:(firstname lastname) \n";
        cin >> fname >> lname;
        cout << "Enter Student address: \n";
        cin >> address;
        cout << "Enter date of enrollment:(mm dd yy) \n";
        cin >> dateofenrollment;
        cout << "Enter the number of credit hours completed by the student: \n";
        cin >> creditHoursCompleted;
        Student s1(identifier, fname, lname, address, dateofenrollment, creditHoursCompleted);
        studentGroup.push_back(s1);
        cout << "Enter another Student?(y/n) ";
        cin >> choice;
    }
    ofstream outfile;
    outfile.open("student.txt");
    for (int i = 0; i < studentGroup.size(); i++)
    {
        cout << "Added student : " << studentGroup[i].getIdentifier();
        outfile << studentGroup[i];
    }
    outfile.close();
    return 0;
}