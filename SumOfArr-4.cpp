/*-------------------------------------------------------------------------
// AUTHOR: Sebastian Chengattu.
// FILENAME: main.cpp
// SPECIFICATION: create basic array and fill in the array by getting
// user input also calculating the sum of the arrays
// FOR: CSE 100- Lab #9
// TIME SPENT: 4 hours
//-----------------------------------------------------------*/

#include <iostream>

using namespace std;

int main()
{
    // ========== Declaring variables ==========

    // An integer for the array size.
    // -->
    int array_Size;


    // A double for the current element.
    // -->
    double curr_element;

    // A double for the sum of elements.
    // -->
    double sum_element;



    // ========== Request Array size from user ==========

    // Print this message "How many elements in the array?"
    // -->
    cout<<"How many elements in the array? ";


    // Request an integer from the user using cin
    // and store the inputted value in the integer declared above.
    // -->
    cin>> array_Size;

    // ========== Declare the array ==========

    // Declare a new array of size equal to the size requested
    // -->
    int integerArray [array_Size];

    // For reference, the following is an EXAMPLE declaration of an

    // integer array of a fixed size. DO NOT USE THIS ARRAY.
    // int[] integerArray = new int[25];


    // ========== Fill in the array ==========

     for(int i = 0; i < array_Size; i++)
        {

        // Display the message: "Please enter the next value."
        // -->
        cout<<"Please enter the next value.";

        // Request the next element (double) from the user using cin.
        // -->
        cin>> curr_element;

        // Store this element at the ith position of the array
        // -->
        integerArray[i]= curr_element;
      }


    // ========== Display and sum the array's elements ==========

    // Construct a for loop that runs backwards through the array,
    // starting at the last element and ending at the first.

     for (int i = array_Size-1 ; i >=0; i--)
        {

        // Inside this for loop, print the ith element of the array
        // and a tab, with NO newline characters.
        // -->
        if (i== 8)
        cout << "\n"<<integerArray[i] <<" ";
        else
        cout << integerArray[i] <<" ";

        // If this element is the 8th one on its line, print a
        // newline character to advance to the next line.
        // Also inside this for loop, add the value of the ith
        // element to the current value of the double for the sum
        // of elements.
        // -->
        sum_element += integerArray[i];

    }


    // ========== Display the sum ==========

    // Print the following message to the user, preceded by a
    // newline character.
    // "The sum of the array's elements is: <sum>"
    // -->
    cout<< "\n The sum of the array's element is: " << sum_element;

        return 0;

} // Close the main function.
