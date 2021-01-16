/***********************************************************************************************

FILE: Lab02.cpp
//
// DESCRIPTION
/
//
//AUTHOR'S
// Sebastian Benny Chengattu
// ID:1210640571
// schengat@asu.edu
// COURSE INFO
// CSE100 Principles of Programming with C++, Spring 2020
// Lab Project 1 Date/Time Febuary 5th, 2020 / 11:50am-12:40pm TA's: Yixing LI
// DUE: Febuary 8th 2020
//**************************************************************************************************
 -------------------------------------------------------------------------------------------------
// TESTING
//
// Test Case 1
// -----------
//
// Test 1 Case Results: Passed
//
// Test Case 2
// -----------
// ...
//
// Test Case 3
// -----------
// ...
//**************************************************************************************************/



#include <iostream>
#include <math.h>
#include <iomanip>
//#include directives

using namespace std;

#define NUM_STUDENTS 3


int main()
{
    //const int NUM_STUDENTS = 3 ; //with this the variable will remain as a constant and unchanged


    cout<<"Description: Tests that the program computes and displays correct exam average and standard deviation."<<endl<< endl <<endl ;
    cout<<"Input Data:"<<endl;
    // in this we will be defining 3 integer variables to stor the exams scores
    //for the 3 students
    int exam_homer;
    int exam_lisa;
    int exam_ralph;

    // we will then declare and define three variables for each function.
    double exam_avg;
    double exam_variance;
    double exam_stddev;


    // prompts the each student to enter their respective scores

    //Homers
    cout<< "Enter exam score for Homer: ";
    cin >> exam_homer;
    //cout<< endl;
    //Lisa
    cout<< "Enter exam score for Lisa: ";
    cin >> exam_lisa;
    //cout<< endl;
    //Ralph
    cout<< "Enter exam score for Ralph: ";
    cin >> exam_ralph;
    //cout<< endl;

    //above the statement that displays the real numbers
    cout << fixed << setprecision(2);
    // in the next series of tasks calculate the exam average, sample
    //standard deviation and the variance.

    //Exam Average
    exam_avg = (exam_homer+exam_lisa+exam_ralph)/static_cast<double>(NUM_STUDENTS);

    //Exam Variance
    exam_variance= (pow(exam_homer-exam_avg,2) +pow(exam_lisa-exam_avg,2) + pow(exam_ralph-exam_avg,2))/(NUM_STUDENTS-1);

    //Exam Sample Standard Deviation
    exam_stddev = sqrt(exam_variance);


    // OutPut the exam average standard deviation

    cout<<endl<<"Expected Output: "<< endl;
    cout<< "The exam average score is:     "<< exam_avg<<"\%"<< endl;
    cout<< "The exam standard deviation is: "<< exam_stddev<< endl;


    return 0;
}
