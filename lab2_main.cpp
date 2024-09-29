//g++ test.cpp --std=c++11
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstring>
#include "lab2_funcs.h"
using namespace std;



/* Calling the given sort_func on input a[left...right],
 and compare the sorting result with output
*/
int Test(vector<int> a, vector<int> output,
       std::function<void (vector<int>&, int, int)> sort_func, int left, int right);

/* Calling the given sort_func on input a,
and compare the sorting result with output
 */
int Test(vector<int> a, vector<int> output,
        std::function<void (vector<int>&)> sort_func);

/* Testing sort_func with several test cases */
bool TestSortingWholeList(std::function<void (vector<int>&)> sort_func);
/* Testing sort_func with several test cases */
bool TestSortingSubList(std::function<void (vector<int>&, int, int)> sort_func);

//Test TimSort using randomly generated vectors of varying lengths
int TestHybridSort();

int main(int argc, char ** argv)
{
  vector<int> list;
  bool passed=true;

  if (argc!=2) {
     cout <<"Usage: ./lab2.exe  sorting_alg \n";
     return 1;
  }

  cout <<"Testing "<<argv[1] <<" with builtin testcases"<<endl;

   if (!strcmp(argv[1], "mergesort")){
        cout <<"Testing Mergesort \n";
  	    passed =  TestSortingWholeList(MergeSort);
  } else if (!strcmp(argv[1], "quicksort")){
          cout <<"Testing quicksort \n";
  	      //passed = TestSortingWholeList(QuickSort);
          passed = TestSortingSubList(QuickSort);
  } else if (!strcmp(argv[1], "hybridsort")){
          cout <<"Testing hybridsort\n";
          passed = TestHybridSort ();

  }

  if (passed)
         return 0;  //Unix's convenction: a program exits/return code 0 indicates succecess
  else
         return 1;

}

/* This function goes through a set of test cases, calling sort_func with the input and see if it generates
   desired/correct output */
bool TestSortingWholeList(std::function<void (vector<int>&)> sort_func)
{
   int passed=0;
   /* Test case: sort an empty list */
   vector <int> input;
   vector <int> output;
   passed += Test(input, output, sort_func);

   /* Test case: sort one element list */
   input={3};
   output={3};
   passed+=Test(input, output, sort_func);

   /* Test case: sort two element list */
   input={10,3};
   output={3,10};
   passed+=Test(input, output, sort_func);

   /* Test three elements list, without duplicate */
   input={10,3,4};
   output={3,4,10};
   passed+=Test(input, output, sort_func);

   /* Test three elements list, with duplicate */
   input={10,3,4,3};
   output={3, 3,4,10};
   passed+=Test(input, output, sort_func);

   /* Test with a long, randomly generated list */

   if (passed!=4){
     cout <<"Passed "<<passed<<" testcases\n";
      return false;
   }
   else
   {
     cout <<"Passed all testcases\n";
      return true;
   }
 }

//Testing sort functions that takes the first&last indices (i.e., left/right indices)
bool TestSortingSubList(std::function<void (vector<int>&, int, int)> sort_func)
{
    int passed=0;


    /* Test case: sort an empty list */
    vector <int> input;
    vector <int> output;
    passed += Test(input, output, sort_func, 0, input.size()-1);

    /* Test case: sort one element list */
    input={3};
    output={3};
    passed+=Test(input, output, sort_func, 0, input.size()-1);

    /* Test case: sort two element list */
    input={10,3};
    output={3,10};
    passed+=Test(input, output, sort_func, 0, input.size()-1);

    /* Test three elements list, without duplicate */
    input={10,3,4};
    output={3,4,10};
    passed+=Test(input, output, sort_func, 0, input.size()-1);

    /* Test three elements list, with duplicate */
    input={10,3,4,3};
    output={3, 3,4,10};
    passed+=Test(input, output, sort_func, 0, input.size()-1);


    /* Test case where we sort a sublist by passing left, and right indices */
   input={10,3,4,3};
   output={3,4,10,3};
   passed+=Test(input, output, sort_func, 0, 2);

   input={10,3,4,3};
   output={10,3,3,4};
   passed+=Test(input, output, sort_func, 1, 3);

   if (passed!=7){
	    cout <<"Passed "<<passed<<" testcases\n";
      return false;
   }
   else
   {
	    cout <<"Passed all testcases\n";
      return true;
   }

}

/* Run one input/output testcase with sort_func, allow sorting partial list */
int Test (vector<int> a, vector<int> output, std::function<void (vector<int>&)> sort_func)
{
   cout <<"Input:";
   PrintVector(a);
   cout <<endl;

   sort_func(a);

   cout <<"Output:";
   PrintVector(a);
   cout <<endl;

   // Does sorting result match with expected output?
   if (a==output)
   {
      cout<<"Pass testing\n";
      return 1;
   }
   else
   {
     cout <<"Does not pass testing\n";
     return 0;
   }

}

/* Run one input/output testcase with sort_func, allow sorting partial list */
int Test (vector<int> a, vector<int> output, std::function<void (vector<int>&, int, int)> sort_func,
		int left, int right)
{
   cout <<"Input:";
   PrintVector(a);
   cout <<endl;

   sort_func(a, left, right);

   cout <<"Output:";
   PrintVector(a);
   cout <<endl;

   // Does sorting result match with expected output?
   if (a==output)
   {
      cout<<"Pass testing\n";
      return 1;
   }
   else
   {
     cout <<"Does not pass testing\n";
     return 0;
   }

}


//Test HybridSort using randomly generated vectors of varying lengths
int TestHybridSort()
{

  vector<int> input = GenerateRandomVector (20);
  cout <<"Input:";
  PrintVector (input);

  vector<int> correct_output = input;
  sort (correct_output.begin(),correct_output.end());
  cout <<"Correct output";
  PrintVector(correct_output);

  HybridSort (input, 5);
  if (input!=correct_output)
  {
    cout <<"Failed n=20 test case\n";
    return 0;
  }

  input = GenerateRandomVector (400);
  cout <<"Input:";
  PrintVector (input);

  correct_output = input;
  sort (correct_output.begin(),correct_output.end());

  HybridSort (input, 50);
  if (input!=correct_output)
  {
    cout <<"Failed n=400 test case\n";
    return 0;
  }

  input = GenerateRandomVector (800);
  cout <<"Input:";
  PrintVector (input);

  correct_output = input;
  sort (correct_output.begin(),correct_output.end());

  HybridSort (input, 100);
  if (input!=correct_output)
  {
    cout <<"Failed n=800 test case\n";
    return 0;
  }

  //passed all three testcases
  return 1;


}
