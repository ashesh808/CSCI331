/*
* Description: Test file for CourseRegistration class consiting of several function calls
* Name: Ashesh Nepal
* starID: ta9983ry
* Date: 2nd September, 2022
* Profressor: Jie Meichsner
*/

#include <fstream>
#include <vector>
#include "CourseRegistration.h"

using namespace std;

//Test program to run all the functions 
int main()
{
    int courseid, studentid, credithours;
    string grade;
    vector<CourseRegistration> courseRegisrationGroup;
    char choice = 'y';
    while (choice == 'y' || choice == 'Y')
    {
        cout << "Enter course identifier \n";
        cin >> courseid;
        cout << "Enter student identifier: \n";
        cin >> studentid;
        cout << "Enter Credit hours: \n";
        cin >> credithours;
        cout << "Enter student grade \n";
        cin >> grade;
        CourseRegistration c1(courseid, studentid, credithours, grade);
        courseRegisrationGroup.push_back(c1);
        cout << "Enter another Student?(y/n) ";
        cin >> choice;
    }
    ofstream outfile;
    outfile.open("courseregisrationgroup.txt");
    for (int i = 0; i < courseRegisrationGroup.size(); i++)
    {
        outfile << courseRegisrationGroup[i];
    }
    outfile.close();
    return 0;
} 