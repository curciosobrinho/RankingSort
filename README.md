# RankingSort

Really fast sorting algorithm for small arrays.<br>
<br>
Take a look at the other sorting algorithms like EcoSelection sort inside the code to better understand this one.
<br>
:)
<br>
The idea is to open the mind about the options inside loops.
Why use only 1 value of the array at a time? Why not compare more than one?

I hope that this implementation shows that it is worth to think about it.

# Background reason
We all know that O(n^2) sorting algorithms like insertion or selection sort are not the best options for big arrays.

The new algotrithm as implemented is faster than insertion sort.

The Ranking sort uses the core idea of selection sort but uses the min e max each iteration, going from 0 - mid and final - mid inside the same loop. When they meet, stop the iteration and the unsorted array is sorted.

EcoShellSort (I am still working on this one) is a modified implementation of shellSort using the size of the array as a parameter to set the gap (I am still testing to check when and how to make it better). As it uses the same principle of insertion sort to sort the small chunks, I am tweaking the size of the chunk to improve speedy. It seems to be working.
<br>
:)

<br>
The above code (sorts.c) shows the difference in time  - microseconds - (I know that we must NOT use time to measure, but as they will ALL run with the same array and in the same machine  - your machine - I think we can try)

Take a look at some speed benchmarks<br>
<br>
Array size = 50<br>
BubleSort - Time : 15 us<br>
SelectionSort - Time : 9 us<br>
InsertionSort - Time : 7 us<br>
ShellSort -  Time : 6 us<br>
MergeSort -  Time : 123 us<br>
// bellow are mine<br>
EcoSelectionSort - Time : 7 us<br>
EcoTurboSelectionSort - Time : 8 us<br>
EcoPowerSelectionSort - Time : 9 us<br>
RankingSort - Time : 6 us<br>
EcoShellSort - Time : 5 us<br>
<br>
<br>
Array size = 100<br>
BubleSort - Time : 44 us<br>
SelectionSort - Time : 28 us<br>
InsertionSort - Time : 19 us<br>
ShellSort -  Time : 14 us<br>
MergeSort -  Time : 150 us<br>
// bellow are mine<br>
EcoSelectionSort - Time : 23 us<br>
EcoTurboSelectionSort - Time : 21 us<br>
EcoPowerSelectionSort - Time : 23 us<br>
RankingSort - Time : 15 us<br>
EcoShellSort - Time : 12 us<br>
<br>
<br>
Array size = 1000<br>
BubleSort - Time : 2839 us<br>
SelectionSort - Time : 1715 us<br>
InsertionSort - Time : 979 us<br>
ShellSort -  Time : 156 us<br>
MergeSort -  Time : 304 us<br>
// bellow are mine<br>
EcoSelectionSort - Time : 999 us<br>
EcoTurboSelectionSort - Time : 845 us<br>
EcoPowerSelectionSort - Time : 799 us<br>
RankingSort - Time : 642 us<br>
EcoShellSort - Time : 137 us<br>
<br>
<br>
Array size = 10000<br>
BubleSort - Time : 294167 us<br>
SelectionSort - Time : 136732 us<br>
InsertionSort - Time : 90682 us<br>
ShellSort -  Time : 1881 us<br>
MergeSort -  Time : 2243 us<br>
// bellow are mine<br>
EcoSelectionSort - Time : 90063 us<br>
EcoTurboSelectionSort - Time : 65995 us<br>
EcoPowerSelectionSort - Time : 68592 us<br>
RankingSort - Time : 59071 us<br>
EcoShellSort - Time : 1832 us<br>
<br>
<br>
Array size = 100000<br>
BubleSort - Time : 33071597 us<br>
SelectionSort - Time : 14116509 us<br>
InsertionSort - Time : 8419908 us<br>
ShellSort -  Time : 30218 us<br>
MergeSort -  Time : 28247 us<br>
// bellow are mine<br>
EcoSelectionSort - Time : 8386055 us<br>
EcoTurboSelectionSort - Time : 6415782 us<br>
EcoPowerSelectionSort - Time : 6295024 us<br>
RankingSort - Time : 5709083 us<br>
EcoShellSort - Time : 26694 us<br>


# How to run
If you use clang to compile just:<br>
clang -o sorts sorts.c

Or use your prefered compiler.
