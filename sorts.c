/** 
 * sorts.c
 * Compare sorts
 * Added 3 sort algorithms derived from selectionSort
 * Added RankingSort and EcoShellSort
 * by Curcio J Sobrinho (curcio@me.com) for CS50 - 2015
 */ 

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>


/** 
 * pseudo code - buble sort
 * use do.. while
 * initialize	counter	
 * do	
 * {	
 *		set	counter	to	0	
 *		iterate	through	enJre	array	
 * 					if	array[n]	>	array[n+1]	
 *							swap	them	
 *							increment	counter	
 * }	
 * while	(counter	>	0)	
 */
 
void bubleSort(int array[], int n)
{
    // start without 1 
    for (int k = 0; k < n - 1; k++)
    {
        // optimize, check if there are no swaps
        int swaps = 0;
        
        // swap adjacent elements if out of order
        
            // iterate throught the array
            for (int i = 0; i < n - k - 1; i++)
            {
                // check if array[n] and array[n+1] are in order
                if (array[i] > array[i + 1])
                {
                    // they are out of order, swap
                    int tmp = array[i + 1];
                    array[i + 1] = array[i];
                    array[i] = tmp;
                    swaps++;
                }
            }
            
        if (swaps == 0)
            break;
    } 
}

/** 
 * pseudo code - selection sort
 * for	i	=	0	to	n	-	2	
 * min	=	i	
 * for	j	=	i	+	1	to	n	-	1	
 *				if	array[j]	<	array[min]	
 *	 					min	=	j;	
 * if	min	!=	i	
 *	 	swap	array[min]	and	array[i]	
 */
 
void selectionSort(int array[], int n)
{
    // start without 1 
    for (int i = 0; i < n - 1; i++)
    {
        // hold the min e position- remember to skip the first
        int minValue = array[i];
        int minPosition = i;
        
        // look throught unsorted array
        
            // iterate throught the unsorted array
            for (int j = i + 1; j < n ; j++)
            {
                // find the smallest
                if (array[j] < minValue)
                {
                    minValue = array[j];
                    minPosition = j;
                }
            }
            
        //swap
         int tmp = array[i];
         array[i] = minValue;
         array[minPosition] = tmp;
    } 
}

// create by Curcio J Sobrinho - 2015
void EcoSelectionSort(int array[], int n)
{
    // start without 1 
    for (int i = 0; i < n - 1; i++)
    {
        // hold the min e position- remember to skip the first
        int minValue = array[i];
        int minPosition = i;
        
        // look throught unsorted array
        
            // iterate throught the unsorted array
            // we start from both beggining and last index
            for (int j = i + 1, last = n - 1; j < n; j++, last--)
            {
               
                // find the smallest
                if (array[j] < minValue || array[last] < minValue)
                {
                    minValue = array[j];
                    minPosition = j;
                    
                    // find the smallest from backwards
                    if (array[last] < minValue)
                    {
                        minValue = array[last];
                        minPosition = last;
                    }
                }
                
                // if both index meet, let's leave...
                if (j >= last)
                {
                    break;
                }
                
                
            }
            
        //swap
         int tmp = array[i];
         array[i] = minValue;
         array[minPosition] = tmp;
    } 
}

// created by Curcio J Sobrinho - same principle of
// eco but with 4 controls to seach faster
void EcoTurboSelectionSort(int array[], int n)
{
    // start without 1 
    for (int i = 0; i < n - 1; i++)
    {
        // hold the min e position- remember to skip the first
        int minValue = array[i];
        int minPosition = i;
        
        // look throught unsorted array
        
            /** 
             * iterate throught the unsorted array
             * we divide into 4 searches during the same loop
             * ini middle right-middle e last
             * all but ini search backwards
             */
            for (int j = i + 1, last = n - 1, middleRight = n - ((n - i)/ 4) - 1, middle = n - ((n - i)/ 2) - 1; j < n; j++, last--, middleRight--, middle--)
            {
               
                // find the smallest
                if (array[j] < minValue || array[last] < minValue || array[middle] < minValue || array[middleRight] < minValue)
                {
                    minValue = array[j];
                    minPosition = j;
                    
                    // find the smallest from backwards
                    if (array[last] < minValue)
                    {
                        minValue = array[last];
                        minPosition = last;
                    }
                    
                    // find the smallest from midle
                    if (array[middle] < minValue)
                    {
                        minValue = array[middle];
                        minPosition = middle;
                    }
                    
                    // find the smallest from middleright
                    if (array[middleRight] < minValue)
                    {
                        minValue = array[middleRight];
                        minPosition = middleRight;
                    }
                }
                
                // I just need to check if ini is bigger or equals to middle
                // if so, lets leave...
                if (j >= middle)
                {
                    break;
                }
                
                
            }
            
        //swap
         int tmp = array[i];
         array[i] = minValue;
         array[minPosition] = tmp;
    } 
}

// created by Curcio J Sobrinho - same principle of
// eco but with 2 places (min and max) and 2 controls to seach faster
void RankingSort(int array[], int n)
{
    // start from beggining and from the end 
    for (int i = 0, lastIndex = (n - 1); i < n ; i++, lastIndex--)
    {
        
        // watch out for even or odd sizes of arrays
        if (n % 2 == 0)
        {
            if ( i >= lastIndex)
            {
                break;
            }
        
        }
        else
        {
            if ( i + 1 > lastIndex)
            {
                break;
            }
        }
        
        
        // hold the min e position
        int minValue = array[i];
        int minPosition = i;
        
        
        // hold the sec e position
        int maxValue = array[lastIndex];
        int maxPosition = lastIndex;

        // look throught unsorted array
        
            /** 
             * iterate throught the unsorted array
             * we divide into 2 searches during the same loop
             * ini and last - search backwards
             */
            // esse ok for (int j = i + 1; j <= lastIndex; j++)
            for (int j = i + 1, last = lastIndex - 1; j <= lastIndex; j++, last--)
            {
                
                 // find the smallest
                if (array[j] < minValue || array[last] < minValue)
                {
                    minValue = array[j];
                    minPosition = j;
                    
                    if (array[last] < minValue)
                    {
                        minValue = array[last];
                        minPosition = last;
                    }

                }
                
                 // find the largest
                if (array[j] > maxValue || array[last] > maxValue)
                {
                    maxValue = array[j];
                    maxPosition = j;
                    
                    if (array[last] > maxValue)
                    {
                        maxValue = array[last];
                        maxPosition = last;
                    }
                }
                
                // when they meet, leave...
                if (j >= last)
                {
                    break;
                }
    
            }
           
        //swap
        if (minPosition != i)
        {
            int tmp = array[i];
            array[i] = minValue;
            array[minPosition] = tmp;
            
        }
         
        if (maxPosition != lastIndex)
        {
            int tmpMax = array[lastIndex];
            array[lastIndex] = maxValue;
            array[maxPosition] = tmpMax;
 
        } 
     
    } 
}

// created by Curcio J Sobrinho - same principle of
// eco but with 8 controls to seach faster
void EcoPowerSelectionSort(int array[], int n)
{
    // start without 1 
    for (int i = 0; i < n - 1; i++)
    {
        // hold the min e position- remember to skip the first
        int minValue = array[i];
        int minPosition = i;
        
        // look throught unsorted array
        
            /** 
             * iterate throught the unsorted array
             * we divide into 8 searches during the same loop
             * j to last, each takes care of 1/8 of the array
             * all but ini search backwards
             */
            for (int j = i + 1, last = n - 1, seventhRight = n - ( (n - i)/ 8) - 1, sixthRight = n - (2 * (n - i)/ 8) - 1, fifthRight = n - (3 * (n - i)/ 8) - 1, middle = n - ((n - i)/ 2) - 1,  thirdRight = n - (5 * (n - i)/ 8) - 1, secondRight = n - (6 * (n - i)/ 8) - 1; j < n; j++, last--, seventhRight--, sixthRight--, fifthRight--, middle--, thirdRight--, secondRight--)
            {
               
                // find the smallest
                if (array[j] < minValue || array[last] < minValue || array[seventhRight] < minValue || array[sixthRight] < minValue || array[fifthRight] < minValue || array[middle] < minValue || array[thirdRight] < minValue || array[secondRight] < minValue)
                {
                    minValue = array[j];
                    minPosition = j;
                    
                    // find the smallest from backwards
                    if (array[last] < minValue)
                    {
                        minValue = array[last];
                        minPosition = last;
                    }
                    
                    // find the smallest from seventhRight
                    if (array[seventhRight] < minValue)
                    {
                        minValue = array[seventhRight];
                        minPosition = seventhRight;
                    }
                    
                    // find the smallest from sixthRight
                    if (array[sixthRight] < minValue)
                    {
                        minValue = array[sixthRight];
                        minPosition = sixthRight;
                    }
                    
                    // find the smallest from fifthRight
                    if (array[fifthRight] < minValue)
                    {
                        minValue = array[fifthRight];
                        minPosition = fifthRight;
                    }
                    
                    // find the smallest from middle
                    if (array[middle] < minValue)
                    {
                        minValue = array[middle];
                        minPosition = middle;
                    }
                    
                    // find the smallest from thirdRight
                    if (array[thirdRight] < minValue)
                    {
                        minValue = array[thirdRight];
                        minPosition = thirdRight;
                    }
                    
                    // find the smallest from secondRight
                    if (array[secondRight] < minValue)
                    {
                        minValue = array[secondRight];
                        minPosition = secondRight;
                    }
                }
                
                // I just need to check if ini is bigger or equals to secondRight
                // if so, lets leave...
                if (j >= secondRight)
                {
                    break;
                }
                
                
            }
            
        //swap
         int tmp = array[i];
         array[i] = minValue;
         array[minPosition] = tmp;
    } 
}

/** 
 * pseudo code - insertion sort
 *  
 * 	for	i	=	0	to	n	-	1	
 *		element	=	array[i]	
 *		j	=	i	
 *		while	(j	>	0	and	array[j	-	1]	>	element)	
 *	 					array[j]	=	array[j	-	1]	
 *	 					j	=	j	-	1	
 *		array[j]	=	element	
 */
 
void insertionSort(int array[], int n)
{
    // go to final, otherwise miss the last one
    for (int i = 0; i < n ; i++)
    {
        // hold the value and position
        int value = array[i];
        int position = i;
        
        // look throught unsorted array
        
            // iterate throught the unsorted array
            while (position > 0 && array[position -1] > value)
            {
                array[position] = array[position - 1];
                position--;
            }
            
        array[position] = value;
    } 
}

/** 
 * pseudo code - merge sort
 *  
 * 	If	n	<	2	
 * Return.	
 * Else	
 * Sort	left	half	of	elements.	
 * Sort	right	half	of	elements.	
 * Merge	sorted	halves.	
  * 
  * sort	(int	array[],	int	start,	int	end)	
 * {	
 * 			if	(end	>	start)	
 * {	
 * 					int	middle	=	(start	+	end)	/	2;	
 * 	 	sort(array,	start,	middle);	
 * 	 	sort(array,	middle	+	1,	end);	
 * 	 	merge(array,	start,	middle,	middle	+	1,	end);	
 * }	
 * }	
 */

void merge(int vec[], int vecSize) {
  int mid;
  int i, j, k;
  int* tmp;
 
  tmp = (int*) malloc(vecSize * sizeof(int));
  if (tmp == NULL) {
    exit(1);
  }
 
  mid = vecSize / 2;
 
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < vecSize) {
    if (vec[i] <= vec[j]) {
      tmp[k] = vec[i++];
    }
    else {
      tmp[k] = vec[j++];
    }
    ++k;
  }
 
  if (i == mid) {
    while (j < vecSize) {
      tmp[k++] = vec[j++];
    }
  }
  else {
    while (i < mid) {
      tmp[k++] = vec[i++];
 
    }
  }
 
  for (i = 0; i < vecSize; ++i) {
    vec[i] = tmp[i];
  }
 
  free(tmp);
}
 
void mergeSort(int vec[], int vecSize) {
  int mid;
 
  if (vecSize > 1) {
    mid = vecSize / 2;
    mergeSort(vec, mid);
    mergeSort(vec + mid, vecSize - mid);
    merge(vec, vecSize);
  }
}

// added ShellSort
void shellSort(int vet[], int size)
{
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    }
}

// I am just tweaking the shellSort...
// Just trying to see if we can improve it
void EcoShellSort(int vet[], int size)
{
    int i, pos, value, control;
    int gap = 1;
    
    control = 3;
    
    // the size of the array is bigger than 1000
    // lets increase the control
    if (size > 1000)
    control = log10(size) + 1;
    
    while(gap < size) {
        gap = control * gap + 1;
    }
    while ( gap > 1) {
    
        gap /= control;
        
        for(i = gap; i < size; i++) {
        
            value = vet[i];
            pos = i - gap;
            
            while (pos >= 0 && value < vet[pos]) {
                vet [pos + gap] = vet[pos];
                pos -= gap;
            }
            vet [pos + gap] = value;
            
        }
 
    }
}

// helper function to create random array inputs
void createRandomArrayInput(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
    }
}

// helper function to measure time in microseconds
// I know about O(...) notation but I needed something
double time_diff(struct timeval x , struct timeval y)
{
    double x_ms , y_ms , diff;
     
    x_ms = (double)x.tv_sec * 1000000 + (double)x.tv_usec;
    y_ms = (double)y.tv_sec * 1000000 + (double)y.tv_usec;
     
    diff = (double)y_ms - (double)x_ms;
     
    return diff;
}

int main(void)
{
   // get the size to create array
   printf("Array size = ");
   int size = 0;
   scanf("%d", &size);
   
   // fill the array with random numbers
   int ar[size];
   createRandomArrayInput(ar, size);

   // let's copy the array to ensure everyone gets the same later
   int unsorted[size];
   
   // change to 1 to debug (it's faster than gdb everytime - :) )
   int debug = 0;
   
   if (debug > 0)
   {
    //dummy to test
    ar[0] = 9;
    ar[1] = 9;
    ar[2] = 2;
    ar[3] = 4;
    ar[4] = 5;
    ar[5] = 6;
    ar[6] = 1;
    ar[7] = 8;
    ar[8] = 2;
    ar[9] = 4;
   }
   
   for (int i = 0; i < size; i++)
   {
      unsorted[i] = ar[i];
   }
   
   // to time them n microseconds (μs)
   struct timeval before, after;
   
   gettimeofday(&before, NULL);
   bubleSort(ar, size);
   gettimeofday(&after, NULL);
   printf("BubleSort - Time : %.0lf us\n", time_diff(before, after));
     
   // return to the unsorted - same to all
   for (int i = 0; i < size; i++)
   {
      ar[i] = unsorted[i];
   }
   
   // if you want to create random array
   // other than use the same first just uncomment bellow
   // repete to others as well
   // createRandomArrayInput(ar,size);
   
   gettimeofday(&before, NULL);
   selectionSort(ar, size);
   gettimeofday(&after, NULL);
   printf("SelectionSort - Time : %.0lf us\n", time_diff(before, after));
   
   // return to unsorted - same to all
   for (int i = 0; i < size; i++)
   {
      ar[i] = unsorted[i];
   }
   
   gettimeofday(&before, NULL);
   insertionSort(ar, size);
   gettimeofday(&after, NULL);
   printf("InsertionSort - Time : %.0lf us\n", time_diff(before, after));
   
   // return to unsorted - same to all
   for (int i = 0; i < size; i++)
   {
      ar[i] = unsorted[i];
   }
   
   gettimeofday(&before, NULL);
   shellSort(ar, size);
   gettimeofday(&after, NULL);
   printf("ShellSort -  Time : %.0lf us\n", time_diff(before, after));
 
   // return to unsorted - same to all
   for (int i = 0; i < size; i++)
   {
      ar[i] = unsorted[i];
   }
   
   gettimeofday(&before, NULL);
   mergeSort(ar, size);
   gettimeofday(&after, NULL);
   printf("MergeSort -  Time : %.0lf us\n", time_diff(before, after));
 
   /** 
    * all below are my creations to test the backwards
    * search in the for loops, they've proved to be faster
    * for arrays bigger than 500 better 
    * the best option for O(n^2) kind sorting algorithms
    * See implementations for more info
    */
    
   // return to first unsorted -same to all
   for (int i = 0; i < size; i++)
   {
      ar[i] = unsorted[i];
   }
   
   gettimeofday(&before, NULL);
   EcoSelectionSort(ar, size);
   gettimeofday(&after, NULL);
   printf("EcoSelectionSort - Time : %.0lf us\n", time_diff(before, after));
   
   // return to unsorted - same to all
   for (int i = 0; i < size; i++)
   {
      ar[i] = unsorted[i];
   } 
   
   gettimeofday(&before, NULL);
   EcoTurboSelectionSort(ar, size);
   gettimeofday(&after, NULL);
   printf("EcoTurboSelectionSort - Time : %.0lf us\n", time_diff(before, after));
     
   // return to unsorted - same to all
   for (int i = 0; i < size; i++)
   {
      ar[i] = unsorted[i];
   }

   gettimeofday(&before, NULL);
   EcoPowerSelectionSort(ar, size);
   gettimeofday(&after, NULL);
   printf("EcoPowerSelectionSort - Time : %.0lf us\n", time_diff(before, after));
   
   // return to unsorted - same to all
   for (int i = 0; i < size; i++)
   {
      ar[i] = unsorted[i];
   }
   gettimeofday(&before, NULL);
   RankingSort(ar, size);
   gettimeofday(&after, NULL);
   printf("RankingSort - Time : %.0lf us\n", time_diff(before, after));
   
   // return to unsorted - same to all
   for (int i = 0; i < size; i++)
   {
      ar[i] = unsorted[i];
   }

   if (debug > 0)
   {
        // if you want to print to test
        printf("before ar[]=");
        for (int i = 0; i < size; i++)
        {   
            printf(" %i,", ar[i]);
        }
        printf("\n"); 
   }
   
   gettimeofday(&before, NULL);
   EcoShellSort(ar, size);
   gettimeofday(&after, NULL);
   printf("EcoShellSort - Time : %.0lf us\n", time_diff(before, after));
   
   if (debug > 0)
   {
        // comented - just to check if working
        printf("after ar[]=");
        for (int i = 0; i < size; i++)
        {   
            printf(" %i,", ar[i]);
        }
        printf("\n");
   }
  
   return 0;
}
