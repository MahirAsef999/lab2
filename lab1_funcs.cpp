/* Project Description: sorting algorithms
Author: Son Tung (Bill) Do
Last modification time: Sep 15, 2021
Known bugs:
*/
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>


using namespace std;


// iterative selection sort

void SelectionSort(vector<int> & L) {
    for (int i = 0; i < L.size()-1; i++) {
        int min = i; // index of smallest element of this loop

        for (int j = i + 1; j < L.size(); j++) {
            if (L[j] < L[min])
                  min = j;
        }

        if (i!=min) //if min is i, no need to swap
          swap(L[i], L[min]); // swap smallest element of this loop to the front
    }
}

// recursive selection sort
void SelectionSort(vector<int> & list, int left, int right) {
    if (left < right) { // if left == right, function does nothing -> base case
        int min = left;
        for (int i = left + 1; i <= right; i++) {
            if (list[i] < list[min])
                min = i;
        }

        if (left!=min)
          swap(list[left], list[min]); // swap min element with first element
        SelectionSort(list, left + 1, right); // sort the rest of the list
    }
}

// iterative bubble sort
void BubbleSort(vector<int> & L) {
    if (L.size() > 0) {
        for (int i = L.size()-1; i > 0; i--) {
            // bubble up one element each loop run
            for (int j = 0; j < i; j++) {
                if (L[j] > L[j+1])
                    swap(L[j], L[j+1]);
            }
        }
    }
}

// recursive bubble sort
void BubbleSortRec(vector<int> & list, int left, int right) {
    if (left < right) { // if left == right, function does nothing -> base case
        for (int i = left; i < right; i++) {
            if (list[i] > list[i+1])
                swap(list[i], list[i+1]);
        }
        BubbleSortRec(list, left, right - 1);
    }
}

// linear search a list
int LinearSearch(const vector<int> & list, int target) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == target)
            return i;
    }
    return -1;
}

// binary search a list
int BinarySearch(const vector<int> & list, int target, int left, int right) {
    if (left <= right) {
        // check if list of more than 1 element is sorted
        if (left < right) {
            for (int i = left; i < right; i++) {
                if (list[i] > list[i+1])
                    return -2; // return -2 if not sorted
            }
        }
        // general case
        int mid = (left + right) / 2; // index of middle element
        if (list[mid] == target)
             return mid;
        else if (target < list[mid])
            return BinarySearch(list, target, left, mid - 1);
        else if (target > list[mid])
            return BinarySearch(list, target, mid + 1, right);
    }
    return -1;
}
