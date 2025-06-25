//Hamza Malik. All rights reserved!

#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 8

// finds the position of the smallest element in the subarray
// list[first] through list[last].
// Pre: first < last and elements 0 through last of array list are defined.
// Post: Returns the subscript k of the smallest element in the subarray;
// i.e., list[k] <= list[i] for all i in the subarray
int get_min_range (int list[], int first, int last)
{
// Define temporary variables
int i, num, array;
  
/* Define an array composed of the first integer and let x be that integer */
	array = list[first];
	num = first;
	
/* Use a loop to analyze all the numbers in the given array */
for (i = first; i <= last; i++)
		{
/* Use an if statement to compare and sort the numbers */
			if (list[i] < array)
			{
				array = list [i];
				num = i;
			}
		}
return (num);
}

// sorts the data in array list
void
select_sort(int list[], int n)    
{
     int fill,           /* index of first element in unsorted subarray    */
         temp,           /* temporary storage                              */
         index_of_min;   /* subscript of next smallest element             */

     for (fill = 0; fill < n-1; ++fill) {
          /* Find position of smallest element in unsorted subarray */
          index_of_min = get_min_range (list, fill, n-1);

          /* Exchange elements at fill and index_of_min */
          if (fill != index_of_min) {
                temp = list[index_of_min];
                list[index_of_min] = list[fill];
                list[fill] = temp;
          }
     }
}

int 
main (void) {
    int array[] = {67, 98, 23, 11, 47, 13, 94, 58};
    int i;
    
    select_sort (array, ARRAY_SIZE);
    
    for (i=0; i < 8; ++i)
        printf ("%d ", array[i]);
    
    return (0);
}
