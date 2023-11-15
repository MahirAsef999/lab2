//g++ test.cpp --std=c++11
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void SelectionSort(vector<int> & L);

// recursive selection sort
void SelectionSort(vector<int> & list, int left, int right) ;

// iterative bubble sort
void BubbleSort(vector<int> & L);

// recursive bubble sort
void BubbleSortRec(vector<int> & list, int left, int right);

// binary search a list
int BinarySearch(const vector<int> & list, int target, int left, int right);

//Functions from lab1

vector<int> GenerateVectorFromInput ();
vector<int> GenerateRandomVector(int size);



/* Print a vector of int to cerr, e.g.,
Current vector: 13 9 23 12 29
*/
void PrintVector (const vector<int> & L);


//new functions to write for lab3

void Merge (const vector<int> & list1, const vector<int> & list2, vector<int> & result);
void MergeSort (vector<int> & L);
void QuickSort (vector<int> & L, int first, int last);
void KWayMerge_BF (vector<vector<int>> listOfLists, vector<int> & result);
void KWayMerge_DAC (vector<vector<int>> listOfLists, vector<int> & result);
void TimSort (vector<int> & list, int run_length);
