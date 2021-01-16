/*-------------------------------------------------------------------------
// AUTHOR: Sebastian Chengattu
// FILENAME: Lab10.cpp
// SPECIFICATION: For  this  lab,  you  will  create  a  basic  array  of  numbers,
// fill  in  the  elements  of the  array  by prompting the user for input, sort the
// elements of array and display the sorted elements to the user.
// FOR: CSE 100- Lab #10
// TIME SPENT: 3 hours
//----------------------------------------------------------------------*/

#include <iostream>


using namespace std;


int main()
{
    // ============================================================
    // Declare some variables. You might need
    //
    // - an integer for the array size,
    // - a int for the exchange element, and
    // - a cin for requesting input
    //
    // -->
    int array_Size;
    int exchange_Element;



    // ============================================================
    // Request array size from the user
    //
    // - Print this message "How many elements in the array?"
    // - Request an integer from the user using cin  and save it
    //
    // -->
    cout << "How many elements in the array?\n";
    cin >> array_Size;
    // Declare a int array by the size you received above
    // -->

    int array[array_Size];

    // ============================================================
    // Fill in the Array

    int numOfElements = -1; // having this would never satisfy code?

    for (int i = 0; i < array_Size; i++)
    {
        // Display the message: "Please enter the next value:"
        // -->
        cout << "Please enter the next value: ";
        // Request the next element (int) from the user,
        // save it to the ith element of the array
        // -->
        cin >> array[i];
    }


    // ============================================================
    // Sort the array's elements in increasing order
    //
    // Here we will use Selection Sort like algorithm.
    int temp; // declared temporary for the function that will be used in the if
    // The first for loop iterates all elements as element_i
    for (int i = 0; i < array_Size; i++)
    {
        // The second for loop finds the right position of element_i
        for (int j = i + 1; j < array_Size; j++)
        {
            // Compare ith value and jth value,
            //
            // - If array[i] >= array[j], swap these two values
            //
            // For example, let array[i] = 10, array[j] = 20, to swap
            // array[i] and array[j] means array[i] will become 20
            // and array[j] will have 10.
            //
            // To swap the values in two position, you would need an
            // extra variable to temporarily hold the value. For example,
            //
            //     temp = array[i];
            //     array[i] = array[j];
            //     array[j] = temp;
            //
            // -->
            if(array[i] >= array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }


        }
    }


    // ============================================================
    // Display the sorted array on the same line

    cout << "The array after sorting" << endl;

    for (int i = 0; i < array_Size; i++)
    {
        // Print ith element, do NOT include line break
        // -->
        if(i != array_Size + numOfElements){
            cout << array[i] << ", ";
        }
        else{
            cout << array[i] << "\n";
        }

    }

    // Print a line break
    // -->
    cout << "\n" ;

    // ============================================================
    // Remove the minimum in the sorted array
    //
    // As our array is sorted in the increasing order, to remove the
    // minimum, we just remove the first element in the array. It is like
    // shifting the array to the left by one element.

    // Because we are doing shifting, in each iteration, we use two
    // values, one at index i, the other at index i+1.
    // To prevent us from going over the boundary of array, the following
    // offset variable should be set as the correct value.
    int offset = 1;

    // In this for loop, we move the element at i + 1 to the position i
    for (int i = 0; i < array_Size - offset; i++) //if you substract offest i
    {
        // Move array[i + 1] to array[i]
        array[i] = array[i + 1];
    }

    // The last element will be set as zero. Remember the greatest index
    // should be array's length - 1.
    // -->
    array[array_Size - offset] = 0;

    // ============================================================
    // Display the Array after removing the first element

    cout << "The array with the minimum removed" << endl;

    for (int i = 0; i < array_Size; i++)
    {
        // Print ith element, do NOT include line break
        // -->
        if(i != array_Size - 1){
            cout << array[i] << ", ";
        }
        else{
            cout << array[i];
        }
    }

    // Print a line break
    // -->
    cout << " \n";

    // ============================================================
    // Search for an element and remove it

    // Ask the user which element to remove
    cout << "Enter the value to search and remove:" << endl;
    // Use cin to get a value for search
    // int valueToRemove =
    int valueToRemove;
    cin >> valueToRemove;
    // To search, we can iterate all values, record the index of target (t),
    // and then shift to the left values from t to the end.
    bool isFound = false; // writing boolean doesnt declare it but bool does
    for (int i = 0; i < array_Size; i++)
    {
        // if ith element == valueToRemove,
        //     Set a flag isFound
        //
        if(array[i] == valueToRemove){
           isFound = true;
        // if isFound,
        //     if i + 1 is available
        //         move element i + 1 to index i
        //     if i + 1 is not available
        //         set element i as zero
        if(isFound){

            if(i + 1 < array_Size ){
                array[i] = array [i+1];
            }
            else{
                array[i] = 0;
            }
        }
        }


    }

    if (isFound)
    {
        cout << "Search element found"<< endl;
    }
    else
    {
        cout << "Search element NOT found" << endl;
    }


    // ============================================================
    // Display the final array

    cout << "\nThe final array" << endl;

    for (int i = 0; i < array_Size; i++)
    {
        // Print ith element, do NOT include line break
        // -->
        cout<< array[i] <<", ";
    }

    // Print a line break
    // -->
    cout << " \n";

    return 0;

}
