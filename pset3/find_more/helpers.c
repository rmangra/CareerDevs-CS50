/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

// function prototypes
void merge(int values[], int left, int mid, int right);
void mergeSort(int values[], int left, int right);

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

    // BINARY SEARCH -- O(log n):
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

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // MERGE SORT -- O(n):
    int left = 0;
    int right = n - 1;
    mergeSort(values, left, right);
    return;
}

void merge(int values[], int left, int mid, int right)
{
    int i, j, k;
    // create temporary array
    int temp[left + right + 1];
    // copy data to temporary array
    for (i = left; i <= right; i++) {
        temp[i] = values[i];
    }
    // copy the greater of the two elements of the two sorted halves
    // into the next position of the values array
    for (i = k = left, j = mid + 1; i <= mid && j <= right; k++) {
        if (temp[i] <= temp[j]) {
            values[k] = temp[i];
            i++;
        } else {
            values[k] = temp[j];
            j++;
        }
    }
    // copy any remaining elements
    for (; i <= mid; i++, k++) {
        values[k] = temp[i];
    }
}

void mergeSort(int values[], int left, int right)
{
    int mid;
    if (left < right) {
        // find the middle of the array
        mid = (left + right) / 2;
        // sort left half using recursion
        mergeSort(values, left, mid);
        // sort right half using recursion
        mergeSort(values, mid + 1, right);
        // merge the sorted halves
        merge(values, left, mid, right);
    }
    return;
}