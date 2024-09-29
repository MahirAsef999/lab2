# lab2

## Goal:

- Implement Merge Sort, QuickSort, K-Way Merging, and a hybrid sorting algorithm.
- Get familiar with using C++ STL vector.

## Starter Code: 

    Download the starter code: 


## Program Execution:

The following example illustrates how your programs should work:
1. Compile and link lab3_funcs.cpp (which implements the required sorting functions and merging functions), lab1_funcs.cpp, and lab3_main.cpp (which run test cases on these functions) to get a lab3.exe file. 
```
$ g++ -std=c++11 lab1_funcs.cpp lab3_funcs.cpp lab3_main.cpp -o lab3.exe 
```

  Or you can simply type 
```
$ make lab3.exe
```

2.  The executable lab3.exe takes one command line argument:

```
   $ ./lab3.exe sorting_alg
```
    It tests the given sorting algorithm using a sequence of test cases given in lab3_main.cpp. 
```
 $ ./lab3.exe mergesort 
   Testing MergeSort using built-in test cases 
   …
```
 

## Details: Implement the following functions in lab3_funcs.cpp: 

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
$ ./lab3.exe mergesort
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
  //Hint: 
 //Brute-and-force method: Below Merge() is the two-way merge function 
            k=listOfLists.size();  
            vector<int> currentList = listOfLists[0] //copy first list to currentList 
             for i=1 to k - 1
                   Merge (listOfLists[i], currentList, output) 
                              //merge i-th list with currentList into output 
                   
                   if (i!=k-1) 
                       //prepare for next iteration 
                       currentList = output   //now output is my currentList 
  
   } 

  
void KWayMerge_DAC (vector<vector<int>> listOfLists, vector<int> & output)
//To be discussed in class 
```

5. Implement an simplified TimSort
```
/* Sort the given list using simplified TimSort 
  First using insertion sort or other sorting algorithm to generate sorted sublists, each of #run_length 
  Then use KWayMerge function to merge these sorted sublists into one sorted list */
void TimSort (vector<int> & list, int run_length)
{
        vector<vector<int>> listOfRuns; 
       // Use/call selection or other sorting algorithm to sort each segment/run of list into sorted order. 
      // For example, if run_length is 100, then in this step, we sort
      //.   list[0…99], list[100…199], list[200…299], … list[len/100*100… len-1] into
      //  ascending order  by calling insertion sort or other sorting algorithm on them one by one, 
       // and then copy data from each sublist into a vector, push the vector into listOfRuns 

       //Note: you can refer to this post about how to extract a subvector: 
      //https://stackoverflow.com/questions/421573/best-way-to-extract-a-subvector-from-a-vector
       //vector<int> sublist (list.begin(), list.begin()+100); //this will copy list[0…99] to sublist 
      //vector<int> sublist2 (list.begin()+100, list.begin()+200); //this will copy list[100…199] to sublist2 


        //Call KWayMerge to merge listOfRuns into one sorted list, write output to back to lis
} 
```
To test TimSort, compile the whole program and then run the following command:
```
$ ./lab3.exe timsort 
```
This will run three test cases, n=20, n=400, n=800 (where run length is set to 5, 50, and 100 respectively). 


## What to submit
  Please submit your lab3_funcs.cpp by deadline to the following submission page: 

https://storm.cis.fordham.edu:8443/web/project/182?current_tab=submit


