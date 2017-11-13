/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Check if search value is positive
    if (value < 0) {
        return false;
    }
    // Check if array contains any elements
    if (n < 0) {
        return false;
    }

    // BINARY SEARCH --- O(log n):
    // initialize variables to hold array values
    int left = 0;
    int right = n - 1;
    // while loop that contains binary search algorithm
    while (left <= right) {
        // initialize a variable to find the middle of the array
        int mid = (left + right) / 2;
        // if the middle value of the array equivalent to the search value, return true
        if (values[mid] == value) {
            return true;
        // if search value is lower, set right bound to mid - 1, search left
        } else if (value < values[mid]) {
            right = mid - 1;
        // if search valude is higher, set left bound to mid + 1, search right
        } else {
            left = mid + 1;
        }
    }
    return false;
}

/*  // LINEAR SEARCH --- O(n)
    // Used as test case before implementing more efficient search
    for (int j = 0; j < n; j++) {
        if (values[j] == value) {
            return true;
            break;
        }
    }
        return false;
}
*/

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) {

    // BUBBLE SORT --- O(n^2):
    // initialize a boolean value to false since array is not sorted
    bool isSorted = 0;
    // while loop containing sort algorithm which runs as long as array is unsorted
    while (!isSorted) {
        //sets boolean to true
        isSorted = 1;
        // iterate over the values in the array
        for (int j = 0; j < n - 1; j++) {
        // compare adjacent elements
            if (values[j] > values[j + 1]) {
            // initalize a variable that will temporarily hold array value
            int swap = values[j];
            // swap elements that are in the wrong order
            values[j] = values[j + 1];
            values[j + 1] = swap;
            // boolean is set to false since array had to be sorted
            isSorted = 0;
            }
        }
    }
    return;
}
