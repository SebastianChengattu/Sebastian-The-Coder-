/**************************************************************************************************
// FILE: Lab03.cpp
//
// OBJECTIVES
// After completing this lab project, the student should be able to:
//
// 1. Define and use local variables of the int, double, and string data types.
// 2. Use cout to display string literals and variables.
// 3. Use cin to read values from the keyboard into variables.
// 4. Use the arithmetic operators.
// 5. Call math functions from the C++ Standard Library.
// 6. Write a function definition, call functions, pass arguments, and return values.
// 7. Define and use named constants.
//
// AUTHORS
// Sebastian Benny Chengattu
// ID:1210640571
// schengat@asu.edu
// COURSE INFO
// CSE100 Principles of Programming with C++, Spring 2020
// Lab Project 1 Date/Time January 29th, 2020 / 11:50am-12:40pm TA's: Yixing LI
// DUE: Febuary 15th 2020
//--------------------------------------------------------------------------------------------------
*/



// TESTING SECTION
//
// --------------------------------------------------------------------------------------------
// TEST CASE 1
// --------------------------------------------------------------------------------------------
// DESCRIPTION:
// Tests that the program computes and displays the correct lucky number.
//
// TEST CASE INPUT DATA:
// Customer name    = Wilma
// Birthdate month  = 3
// Birthdate day    = 13
// Birthdate year   = 1970
// Height in inches = 80
// Weight in lbs    = 120
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Wilma, your lucky number is 5. Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// ??? Document the observed output, i.e., what message did your program output? ???
//
// TEST CASE RESULT:
// ??? If the output from your program matches the expected output, then write PASSED here to
// indicate that your program passed the test case. If the output from your program does not
// match the expected output then find the bug(s) and correct them. If you cannot find the
// bug(s) andcorrect them, then write FAILED here to indicate that your program did not pass
// the test case. ???
//
// --------------------------------------------------------------------------------------------
// TEST CASE 2
// --------------------------------------------------------------------------------------------
// ??? Document your second test case here, using the same format as Test Case 1. ???
//
// --------------------------------------------------------------------------------------------
// TEST CASE 3
// --------------------------------------------------------------------------------------------
// ??? Document your third test case here, using the same format as Test Cases 1 and 2. ???
//**************************************************************************************************

// Include the necessary header files.

#include <cmath>     // For pow() and sqrt()
#include <iostream>  // For cin, cout, endl
#include <string>    // For string class

using namespace std;

// Define a named constant CM_PER_INCH which is a double and is equivalent to 2.54.
// Read about named constants in Chapter 3 section 3.5 of your textbook.
#define CM_PER_INCH 2.54

// Define a named constant LB_PER_KG which is a double and is equivalent to 2.20462262.
#define LB_PER_KG 2.20462262

//--------------------------------------------------------------------------------------------------
// FUNCTION: calc_lucky()
//
// DESCRIPTION
// Calculates the person's lucky number using Zelda's way cool formula.
//
// REMARKS
// I prefix the names of my parameters with a 'p' character so that when reading through the code
// if I see a variable name starting with 'p' I know it is a function parameter.
//--------------------------------------------------------------------------------------------------
int calc_lucky(int pDate, double pHeight, int pMonth, double pWeight, int pYear)
{
    // Define an int variable named 'term1' and assign to term1 the result of evaluating:
    //
    //     100 x pMonth^2
    //
    // Note: Remember, C++ does not have an exponentiation operator. To calculate pMonth^2 you can
    // either write pMonth * pMonth or call pow(pMonth, 2).
    //
    //     pow(static_cast<double>(pMonth), 2)
    int term1= 100 * pow(static_cast<double>(pMonth), 2);

    // Define an int variable named 'term2' and assign to it: 10 x pDate^3. Note: if you use
    // the pow() function to calculate pDate^3 you will need to typecast the result of evaluating
    // 10 x pDate^3 to an int in order to assign it to term2. This is done using the static_cast<>
    // operator.
    int term2= 10 * pow(static_cast<double>(pMonth), 2);

    // Define an int variable named 'term3' and assign (term1 + term2) / pYear to it. Note: the
    // division of term1 + term2 by pYear is to be performed as integer division.
    int term3= (term1+ term2)/pYear ;

    // Define a double variable named 'term4' and assign to it: pWeight^6 / pHeight. Note: this
    // division is to be performed as floating-point division. If you use the pow() function to
    // compute pWeight^6, it will return a double so the division will naturally be performed
    // as floating point division.
    double term4 = pow((pWeight), 6)/pHeight;

    // Calculate and return the lucky number using term3, term4, and the lucky number formula.
    // Note: you need to typecast term3 + sqrt(term) to an int before performing the modulus by
    // 10 operation (% is not defined on floating point data values).
    int lucky = static_cast<int>(term3 + sqrt(term4))%10 + 1; //typecast_to_int(term3 + √term4) modulus 10 + 1 ;

    return lucky;
}

//--------------------------------------------------------------------------------------------------
// FUNCTION: convert_inch_to_cm()
//
// DESCRIPTION
// Converts inches to centimeters.
//
// REMARK
// Make sure to use the named constant CM_PER_INCH in your conversion expression.
//--------------------------------------------------------------------------------------------------
double convert_inch_to_cm(double pInches)
{
    // Implement the pseudocode.
    return pInches*CM_PER_INCH;
}

//--------------------------------------------------------------------------------------------------
// FUNCTION: convert_lb_to_kg()
//
// DESCRIPTION
// Converts pounds to kilograms.
//
// REMARK
// Make sure to use the named constant LB_TO_KG in your conversion expression.
//--------------------------------------------------------------------------------------------------
double convert_lb_to_kg(double pLbs)
{
    return pLbs / LB_PER_KG;
}

//--------------------------------------------------------------------------------------------------
// FUNCTION: get_int()
//
// DESCRIPTION
// Display the prompt string pPrompt, read an int from the keyboard, and return the int.
// See Get.cpp in the BB Source Code page.
//--------------------------------------------------------------------------------------------------
int get_int(string pPrompt)
{
    cout << pPrompt;
    int n;
    cin >> n;
    return n;
}

//--------------------------------------------------------------------------------------------------
// FUNCTION: get_string()
//
// DESCRIPTION
// Display the prompt string pPrompt, read a string from the keyboard, and return the string.
// See Get.cpp in the BB Source Code page.
//--------------------------------------------------------------------------------------------------
string get_string(string pPrompt)
{
    string s;
    cout << pPrompt;
    cin >> s;
    return s;
}

//--------------------------------------------------------------------------------------------------
// FUNCTION: main()
//--------------------------------------------------------------------------------------------------
int main()
{
    // Display "Zelda's Lucky Number Calculator" and send two endl's to cout.
    cout << "Zelda's Lucky Number Calculator"<<endl<< endl;

    // Call get_string() asking for the customer's first name. Assign the return value to a string
    // variable named 'name' (note: you have to define 'name' as a string).
    string name = get_string("What is your name? ");

    // Call get_int() asking for the month of the customer's birthdate. Assign the return value to an
    // int variable named 'month' (which must be defined as an int).
    int month = get_int("In what month were you born? ");

    // Call get_int() asking for the date of the customer's birthdate. Assign the return value to an
    // int variable named 'date' (which must be defined as an int).
    int date = get_int("What was the date? ");

    // Call get_int() asking for the year of the customer's birthdate. Assign the return value to an
    // int variable named 'year' (which must be defined as an int).
    int year = get_int("What was the year (yyyy)? ");

    // Call get_int() asking for the customer's height in inches and assign the returned value
    // to an int variable named 'heightInch' (which must be defined as an int).
    int heightInch = get_int("What is your height (inches)? ");

    // Call get_int() asking for the customer's weight in lbs and assign the returned value to
    // an int variable named 'weightLb' (which must be defined as an int).
    int weightLb = get_int("What is your weight(lbs)? ");

    // Call convert_inch_to_cm() passing heightInch as the parameter and assigning the return value
    // to a double variable named 'heightCm' (which must be defined as a double).
    double heightCm = convert_inch_to_cm(heightInch);

    // Call convert_lb_to_kg() passing weightLb as the parameter and assigning the return value to
    // a double variable named 'weightKg' (which must be defined as a double).
    double weightKg = convert_lb_to_kg(weightLb);

    // Call calc_lucky() passing date, heightCm, month, weightKg, and year as parameters. Assign the
    // returned value to an int variable named 'lucky' (which must be defined as an int).
    int lucky = calc_lucky(date, heightCm, month, weightKg, year);

    // Display the  customer's name, lucky number, and other required output and return from main().
    cout << name << ", your lucky number is " << lucky << ". Thank you, that will be $25." << endl;

    return 0;
}
