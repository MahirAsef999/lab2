# lab2

## Goal:

- Implement Merge Sort, QuickSort, K-Way Merging, and a hybrid sorting algorithm.
- Get familiar with using C++ STL vector.

## Starter Code: 

Download the starter code as a zip file and unzip it to get the whole directory of starter code. 


## Program Execution:

The following example illustrates how your programs should work:
1. Compile and link lab2_funcs.cpp (which implements the required sorting functions and merging functions) and lab3_main.cpp (which run test cases on these functions) to get a lab2.exe file. 
```
$ g++ -std=c++11  lab2_funcs.cpp lab2_main.cpp -o lab2.exe 
```

  Or you can simply type 
```
$ make lab2.exe
```

2.  The executable lab3.exe takes one command line argument:

```
   $ ./lab2.exe sorting_alg
```
    It tests the given sorting algorithm using a sequence of test cases given in lab3_main.cpp. 
```
 $ ./lab2.exe mergesort 
   Testing MergeSort using built-in test cases 
   …
```
 

## Details: Implement the following functions in lab2_funcs.cpp: 

1. (Two-way) Merge function.

```
 /*pre-condition: v1, v2 are two sorted vectors (in ascending order). 
 Result might or might not be empty (i.e., you need to clear it)
 post-condition: vector result stores values from v1 and v2, in ascending order*/
void Merge (const vector<int> & v1, const vector<int> & v2, vector<int> & result)
```

2. Implement and test MergeSort function. Note, you will use the Merge() function implemented in step 1. 
```
void MergeSort(vector<int> & L)
```
After you have implement this function, test this function  by compile your program and run the following command:

```
$ ./lab2.exe mergesort
```
   Testing MergeSort using built-in test cases 
    …

3. Implement and test QuickSort function.   
```
void QuickSort(vector<int> & list, int left, int right)
```
4. KWay Merge functions:  implement two version of KWayMerge function, one divide-and-conquer algorithm (as to be studied in class), another one follows brute-and-force way (see hints below).
```
  /* Given a vector of sorted vector, merge them all into one sorted vector 
  @param listOfLists: a vector of sorted vector of ints
  @param output: the merged sorted list 
   @pre-condition: listOfLists contains a number of sorted vector
   @post-condition: all ints are merged and saved into output, in ascending order 
  */
void KWayMerge_BF (vector<vector<int>> listOfLists, vector<int> & output)  
{
  
} 

  
void KWayMerge_DAC (vector<vector<int>> listOfLists, vector<int> & output)
 
```

5. Implement a hybrid sorting algorithm 
```
/* Sort the given list with a hybrid sorting algorithm 
  First using quicksort to generate sorted sublists, each of #run_length 
  Then use KWayMerge function to merge these sorted sublists into one sorted list */
void HybridSort (vector<int> & list, int segment_length)
{
        vector<vector<int>> listOfRuns; 
        // Break input list into multiple sublists each of length given by run_length
        // Call Quicksort to sort each segment of the input list into order  
        // For example, if segment_length is 100, then in this step, we sort
        //    list[0…99], list[100…199], list[200…299], … list[len/100*100… len-1] into
        //  ascending order.

        // Copy out each segment into a new vector, push the vector into listOfRuns 

        //Note: you can refer to this post about how to extract a subvector: 
        //https://stackoverflow.com/questions/421573/best-way-to-extract-a-subvector-from-a-vector
       //vector<int> sublist (list.begin(), list.begin()+100); //this will copy list[0…99] to sublist 
        //vector<int> sublist2 (list.begin()+100, list.begin()+200); //this will copy list[100…199] to sublist2 


        //Call KWayMerge to merge listOfRuns into one sorted list, write output to back to list
} 
```
To test HybridSort, compile the whole program and then run the following command:
```
$ ./lab2.exe hybridsort 
```
This will run three test cases, n=20, n=400, n=800 (where run length is set to 5, 50, and 100 respectively). 


## What to submit
  Please submit your lab2_funcs.cpp by deadline to the following submission page: 
[autograder site][(https://storm.cis.fordham.edu:8443/web/project/2261)]

