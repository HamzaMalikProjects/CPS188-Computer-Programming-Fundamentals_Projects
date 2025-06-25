#include <stdio.h>
#include <math.h>

// Create a function that will organize the three integers 
// The function uses if statements and pointers to organize the results
// Each scenario is examined, comparing the three numbers to determine the ascending order

void
order (int n1, int n2, int n3, int *result1, int *result2, int *result3)
{

	if (n1 < n2 && n1 < n3)
		*result1 = n1;
	
		else if (n2 < n1 && n2 < n3)
			*result1 = n2;
			
				else if (n3 < n1 && n3 < n2)
					*result1 = n3;
					
	if (n1 > n2 && n1 > n3)
		*result3 = n1;
	
		else if (n2 > n1 && n2 > n3)
			*result3 = n2;
			
				else if (n3 > n1 && n3 > n2)
					*result3 = n3;
					
	if (n1 != *result1 && n1 != *result3)
		*result2 = n1;
	
		else if (n2 != *result1 && n2 != *result3)
			*result2 = n2;
			
				else if (n3 != *result1 && n3 != *result3)
					*result2 = n3;
	
}

// Then the main body is created and the variables are defined 

int 
main (void)
{
int x, y, z, result1, result2, result3;

// Ask the user to input the three numbers 

	printf ("\nEnter the first random integer: ");
	scanf ("%d", &x);
	
	printf ("Enter the second random integer: ");
	scanf ("%d", &y);
	
	printf ("Enter the third random integer: ");
	scanf ("%d", &z);
	
// Introduce the function in the main body

	order (x, y, z, &result1, &result2, &result3);
	
// Print the results in order

	printf ("\nThe ascending order of the entered integers is %d, %d, %d", result1, result2, result3);
	

return (0);
}