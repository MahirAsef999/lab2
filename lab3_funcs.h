//g++ test.cpp --std=c++11
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

//Three helper functions 
vector<int> GenerateVectorFromInput ();
vector<int> GenerateRandomVector(int size);


/* Print a vector of int to cerr, e.g.,
Current vector: 13 9 23 12 29
*/
void PrintVector (const vector<int> & L);

//Functions to be implemented in lab2 
void Merge (const vector<int> & list1, const vector<int> & list2, vector<int> & result);
void MergeSort (vector<int> & L);
void QuickSort (vector<int> & L, int first, int last);
void KWayMerge_BF (vector<vector<int>> listOfLists, vector<int> & result);
void KWayMerge_DAC (vector<vector<int>> listOfLists, vector<int> & result);
void HybridSort (vector<int> & list, int run_length);
