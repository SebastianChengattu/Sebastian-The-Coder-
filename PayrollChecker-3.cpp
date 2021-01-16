//******************************************************************************
// FILE: Lab07.cpp
//
// DESCRIPTION
// Opens a file named "payroll.txt" for reading and reads payroll information
// for one employee. Calculates the employee's paycheck information. Outputs the
// employee paycheck data to a file named "paycheck.txt".
//
// This lab project illustrates the following C++ concepts:
// 1. Functions. Function calls. Pass parameters by-value. Return values.
// 2. Reading from a text file.
// 3. Writing to a text file.
// 4. Formatting output to a text file.
// 5. Writing if, if-else, and if-elseif-elseif... statements.
//
// AUTHOR1: sebastian Chengattu, your ASURITE schengat, schengat@asu.edu
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Spring 2020
// Lab 7, Date/Time: 04/01/2020 11:50 , TA:
// =============================================================================
// TESTING
//
// -----------------------------------------------------------------------------
// TEST CASE 1:
// -----------------------------------------------------------------------------
// Test Input Data (in payroll.txt)
// Simpson Homer
// 15.25 84
// 2
//
// Expected Output:
// -----------------------------
// EMPLOYEE: Simpson, Homer
//
// PAY RATE:           $   15.25
// HOURS:                  84.00
// GROSS PAY:          $ 1311.50
// MED INS DEDUCT:     $  110.13
// 401K DEDUCT:        $   78.69
// FED TAX GROSS PAY:  $ 1122.68
// TAX - FEDERAL:      $   89.48
// TAX - OASDI:        $   69.61
// TAX - MEDICARE:     $   16.28
// TAX - STATE:        $   38.62
// TAX - TOTAL:        $  213.98
// NET PAY:            $  908.70
// -----------------------------
//
// Actual Output:
// ??? copy-and-paste the contents of paycheck.txt here.
//-----------------------------
//EMPLOYEE: Simpson, Homer

//PAY RATE:           $   15.25
//HOURS:                  84.00
//GROSS PAY:          $ 1311.50
//MED INS DEDUCT:     $  110.13
//401K DEDUCT:        $   78.69
//FED TAX GROSS PAY:  $ 1122.68
//TAX - FEDERAL:      $   89.48
//TAX - OASDI:        $   69.61
//TAX - MEDICARE:     $   16.28
//TAX - STATE:        $   38.62
//TAX - TOTAL:        $  213.98
//NET PAY:            $  908.70
//-----------------------------
// Test Results: ??? document whether the program PASSED or FAILED the test case
// PASSED
// -----------------------------------------------------------------------------
// TEST CASE 2:
// -----------------------------------------------------------------------------
// Test Input Data (in payroll.txt)
// Simpson Marg
// 15.26 85
// 2
//
// Expected Output:
// -----------------------------
//EMPLOYEE: Simpson, Marg

//PAY RATE:           $   15.26
//HOURS:                  85.00
//GROSS PAY:          $ 1335.25
//MED INS DEDUCT:     $  110.13
//401K DEDUCT:        $   80.11
//FED TAX GROSS PAY:  $ 1145.01
//TAX - FEDERAL:      $   91.26
//TAX - OASDI:        $   70.99
//TAX - MEDICARE:     $   16.60
//TAX - STATE:        $   39.39
//TAX - TOTAL:        $  218.24
//NET PAY:            $  926.77
//-----------------------------
//
// Actual Output:
// ??? copy-and-paste the contents of paycheck.txt here.
//
// Test Results: ??? document whether the program PASSED or FAILED the test case
// PASSED
// -----------------------------------------------------------------------------
// TEST CASE 3:
// -----------------------------------------------------------------------------
// Test Input Data (in payroll.txt)
// Simpson Bart
// 15.27 86
// 1
//
// Expected Output:
//-----------------------------
//EMPLOYEE: Simpson, Bart

//PAY RATE:           $   15.27
//HOURS:                  86.00
//GROSS PAY:          $ 1359.03
//MED INS DEDUCT:     $   64.97
//401K DEDUCT:        $   81.54
//FED TAX GROSS PAY:  $ 1212.52
//TAX - FEDERAL:      $   96.64
//TAX - OASDI:        $   75.18
//TAX - MEDICARE:     $   17.58
//TAX - STATE:        $   41.71
//TAX - TOTAL:        $  231.11
//NET PAY:            $  981.41
//-----------------------------

//
// Actual Output:
// ??? copy-and-paste the contents of paycheck.txt here.
//
// Test Results: ??? document whether the program PASSED or FAILED the test case
//PASSED
//==============================================================================

// Include required header files.
#include<cstdlib>                  // For exit()
#include<fstream>                   // For ifstream, ofstream
#include<iomanip>                  // For setprecision(), setw()
#include<iostream>                  // For endl, fixed
#include<string>                  // For string class

using namespace std;

// This is the percentage rate for calculating the OASDI deduction (this is com-
// monly known as social security). It is 6.2% of the employee's federal taxable
// gross pay.
const double OASDI_RATE =0.062; // define constant OASDI_RATE

// All employees are required to contribute 6.0% of their pretax gross pay to
// the company 401K plan.
const double FOUR01K_RATE = 0.06; // define constant FOUR01k_RATE  6 %

// This is the percentage rate for calculating the medicare deduction. It is
// 1.45% of the employee's federal taxable gross pay.
const double MEDICARE_RATE = 0.0145; // define constant MEDICARE_RATE

// These constants are the monthly costs for each of the medical insurance
// plans. The amount an employee pays depends on his or her medical insurance
// status (see the next group of constants following this group).
const double MED_INS_DEDUCT_EMPL_ONLY = 32.16; //define MED_INS_DEDUCT_EMPL_ONLY
const double MED_INS_DEDUCT_EMPL_ONE = 64.97; // define MED_INS_DEDUCT_EMPL_ONE
const double MED_INS_DEDUCT_FAMILY = 110.13; // define MED_INS_DEDUCT_FAMILY

// These constants match the numbers for the employee's medical insurance status
// that will be in the input file.
const int MED_INS_STATUS_EMPL_ONLY = 0;  // Employee Only
const int MED_INS_STATUS_EMPL_ONE  = 1;  // Employee + One
const int MED_INS_STATUS_FAMILY    = 2;  // Family

//------------------------------------------------------------------------------
// FUNCTION: error_exit()
//
// Called when something "bad" happens. Displays the specified error message
// 'msg' and then terminates the program with an exit code of -1.
//------------------------------------------------------------------------------
void error_exit(string msg)
{
    cout << msg << endl;
    exit(-1);
}

//------------------------------------------------------------------------------
// FUNCTION: calc_gross_pay()
//
// Calculates and returns an employee's gross pay which is based on the number
// of hours worked (in parameter hrs_worked) and the employee's pay rate (in
// parameter pay_rate).
//------------------------------------------------------------------------------
//Implement the pseudocode from the lab project document
double calc_gross_pay(double pay_rate,double hrs_worked)
{
    double gross_pay = 0;

    if(hrs_worked <= 80)
    {
        gross_pay = hrs_worked*pay_rate;
    }
    else
    {
        gross_pay = 80*pay_rate + (hrs_worked - 80)*(1.5*pay_rate);
    }

    return gross_pay;
}

//------------------------------------------------------------------------------
// FUNCTION: calc_med_ins_deduct()
//
// Determines and returns the employee's medical insurance deduction which is
// based on the employee's medical insurance status in parameter med_ins_status.
//------------------------------------------------------------------------------
//Implement the pseudocode from the lab project document
double calc_med_ins_deduct(int med_ins_status)
{
    double med_ins_deduct = 0;

    if(med_ins_status == MED_INS_STATUS_EMPL_ONLY)
    {
        med_ins_deduct = MED_INS_DEDUCT_EMPL_ONLY;
    }
    else if(med_ins_status == MED_INS_STATUS_EMPL_ONE)
    {
        med_ins_deduct = MED_INS_DEDUCT_EMPL_ONE;
    }
    else
    {
        med_ins_deduct= MED_INS_DEDUCT_FAMILY;
    }
    return med_ins_deduct;
}
//------------------------------------------------------------------------------
// FUNCTION: calc_tax_fed()
//
// Calculates and returns the employee's federal income tax which is based on
// his or her federal taxable gross pay (in parameter fed_tax_gross_pay) and the
// federal tax withholding percentage table in the lab project document.
//------------------------------------------------------------------------------
//Implement the pseudocode from the lab project document.
// Hint: see calc_tax_state(). The code you will write for this function is
// similar to the code in that function.
double calc_tax_fed(double fed_tax_gross_pay)
{
    double tax_fed = 0;

    if(fed_tax_gross_pay >= 384.62 && fed_tax_gross_pay < 1413.67)
    {
        tax_fed = 0.0797*fed_tax_gross_pay;
    }
    else if(fed_tax_gross_pay >=1413.67 && fed_tax_gross_pay < 2695.43)
    {
        tax_fed = 0.1275*fed_tax_gross_pay;
    }
    else if(fed_tax_gross_pay >= 2695.43)
    {
        tax_fed = 0.195*fed_tax_gross_pay;
    }
    return tax_fed;

}

//------------------------------------------------------------------------------
// FUNCTION: calc_tax_state()
//
// Calculates and returns the employee's state income tax which is based on his
// or her federal taxable gross pay (in parameter fed_tax_gross_pay) and the
// state tax withholding percentage table in the lab project document.
//------------------------------------------------------------------------------
double calc_tax_state(double fed_tax_gross_pay)
{
    double tax_state = 0;
    if (fed_tax_gross_pay < 961.54) {
        tax_state = fed_tax_gross_pay * 0.0119;
    } else if (fed_tax_gross_pay < 2145.66) {
        tax_state = fed_tax_gross_pay * 0.0344;
    } else {
        tax_state = fed_tax_gross_pay * 0.0774;
    }
    return tax_state;
}

//------------------------------------------------------------------------------
// FUNCTION: open_input_file()
//
// Opens the file named by filename for reading. If the file cannot be opened
// then call error_exit() to terminate the program.
//------------------------------------------------------------------------------
void open_input_file(ifstream& fin, string filename)
{
    // Pass the C-string inside of filename to fin.open() to open the file.
    fin.open(filename.c_str());

    // If the file could not be opened (most likely because it does not exist),
    // then the ifstream variable fin will be false. So, if fin is false, we
    // call the  error_exit() function to terminate the program.
    if (!fin) {
        error_exit("Could not open input file for reading.");
    }
}

//------------------------------------------------------------------------------
// FUNCTION: open_output_file()
//
// Opens the file named by filename for writing. If the file cannot be opened
// then call error_exit() to terminate the program.
//------------------------------------------------------------------------------
void open_output_file(ofstream& fout, string filename)
{
    // Pass the C-string inside of filename to fout.open() to open the file.
    fout.open(filename.c_str());

    // If the file could not be opened then the ofstream variable fout will be
    // false. So, if fout is false, we call the error_exit() function to
    // terminate the program.
    if (!fout) {
        error_exit("Could not open output file for writing.");
    }
}

//------------------------------------------------------------------------------
// FUNCTION: main()
//
// This is the starting point of execution.
//------------------------------------------------------------------------------
int main()
{
    // Define an ifstream object named 'fin' to read from the input file. Then
    // call open_input_file() passing "payroll.txt" as the name of the file to
    // be opened. If the file could not be opened for reading, then open_input_
    // file() will not return.
    ifstream fin;

    open_input_file(fin, "payroll.txt");

    // Read the employee's last and first names from the input file into string
    // objects/variables named last_name and first_name, which must be defined.
    string first_name, last_name;
    fin >> last_name >> first_name;

    // Read the employee's pay rate from the input file into double variable
    // pay_rate, which must be defined.
    double pay_rate;
    fin >> pay_rate;

    // Read the employee's hours worked from the input file into double variable
    // hrs_worked, which must be defined.
    double hrs_worked;
    fin>>hrs_worked;

    // Read the employee's medical insurance status from the input file into int
    // variable med_ins_status, which must be defined.
    int med_ins_status;
    fin>>med_ins_status;

    // Close the input file because we're done reading from it.
    fin.close();

    // Call calc_gross_pay() to calculate the employee's gross pay. The input
    // params are pay_rate and hrs_worked. The return value is assigned to vari-
    // able gross_pay which must be defined as a double.
    double gross_pay = calc_gross_pay(pay_rate, hrs_worked);

    // Calculate the employee's mandatory contribution to his/her 401k. This is
    // gross_pay multiplied by the 401K rate. Assign the result to variable
    // four01k_deduct which must be defined as a double.
    double four01k_deduct = gross_pay*FOUR01K_RATE;

    // Call calc_med_ins_deduct() to determine the employee's medical insurance
    // deduction which is based on the employee's medical insurance status
    // stored in med_ins_status. The return value is assigned to variable
    // med_ins_deduct which must be defined as a double.
    double med_ins_deduct = calc_med_ins_deduct(med_ins_status);

    // Calculate the employee's federal taxable gross pay which is gross_pay
    // minus the deductions for medical insurance and 401K. Assign the result
    // to variable fed_tax_gross_pay which must be defined as a double.
    double fed_tax_gross_pay = gross_pay - med_ins_deduct - four01k_deduct;

    // Call calc_tax_fed() to calculate the employee's federal income tax. The
    // input parameter is fed_tax_gross_pay and the returned value is assigned to
    // variable tax_fed which must be defined as a double.
    double tax_fed = calc_tax_fed(fed_tax_gross_pay);

    // Calculate the amount withheld for OASDI and store in tax_oasdi, which
    // must be defined as a double.
    double tax_oasdi = fed_tax_gross_pay * OASDI_RATE;

    // Calculate the amount withheld for medicare and store in tax_medicare,
    // which must be defined as a double.
    double tax_medicare= fed_tax_gross_pay * MEDICARE_RATE;

    // Call calc_tax_state() to determine the employee's state tax deduction. The
    // input parameter is fed_tax_gross_pay and the returned value is assigned to
    // variable tax_state which must be defined as a double.
    double tax_state = calc_tax_state(fed_tax_gross_pay);

    // Calculate the employee's total tax which is the sum of his/her federal
    // tax, OASDI tax, medicare tax, and state tax. Assign the sum to tax_total,
    // which must be defined as a double.
    double tax_total = tax_fed + tax_oasdi + tax_medicare + tax_state;

    // Calculate the employee's net pay which is federal taxable gross pay minus
    // total_tax. Assign the sum to net_pay, which must be defined as a double.
    double net_pay = fed_tax_gross_pay - tax_total;

    // Define an ofstream object named 'fout' to write to the output file. Then
    // call open_output_file() passing "paycheck.txt" as the name of the file to
    // be opened. If the file could not be opened for writing, then open_output_
    // file() will not return.
    ofstream fout;

    open_output_file(fout, "paycheck.txt");

    // Configure fout so real numbers will be printed in fixed notation with two
    // digits after the decimal point.
    fout<< setprecision(2)<<fixed;

    // Configure fout so the numbers will be printed right-justified in their
    // respective fields.
    fout<<right;

    // Output the employee paycheck. All numerical values are output in a field
    // of width 8.
    fout << "-----------------------------"    << endl;
    fout << "EMPLOYEE: " << last_name << ", "  << first_name << endl << endl;
    fout << "PAY RATE:           $" << setw(8) << pay_rate << endl;
    fout << "HOURS:               " << setw(8) << hrs_worked << endl;
    fout << "GROSS PAY:          $" << setw(8) << gross_pay << endl;
    fout << "MED INS DEDUCT:     $" << setw(8) << med_ins_deduct << endl;
    fout << "401K DEDUCT:        $" << setw(8) << four01k_deduct << endl;
    fout << "FED TAX GROSS PAY:  $" << setw(8) << fed_tax_gross_pay << endl;
    fout << "TAX - FEDERAL:      $" << setw(8) << tax_fed << endl;
    fout << "TAX - OASDI:        $" << setw(8) << tax_oasdi << endl;
    fout << "TAX - MEDICARE:     $" << setw(8) << tax_medicare << endl;
    fout << "TAX - STATE:        $" << setw(8) << tax_state << endl;
    fout << "TAX - TOTAL:        $" << setw(8) << tax_total << endl;
    fout << "NET PAY:            $" << setw(8) << net_pay << endl;
    fout << "-----------------------------"    << endl;

    // Close the output file by calling the close() function on fout.
    fout.close();

    // Return 0 from main() to indicate to the OS that the program terminated normally.
    return 0;
}
