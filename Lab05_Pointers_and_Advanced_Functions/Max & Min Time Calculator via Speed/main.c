#include <stdio.h>
#include <math.h>

/* The first function tells the time it takes to get to the Moon */
void
time1 (double s1, double *x1, double *x2) 
{
	double distance_min, distance_max;
	distance_min = 363104;
	distance_max = 405696;
	*x1 = distance_min / s1; 
	*x2 = distance_max / s1; 
}

/* The second function tells the time it takes to get to the Mars */
void
time2 (double s2, double *y1, double *y2)
{
	double distance_min, distance_max;
	distance_min = 54600000;
	distance_max = 401000000;
	*y1 = distance_min / s2; 
	*y2 = distance_max / s2; 
}

/* The Third function tells the time it takes to get to the Venus */
void
time3 (double s3, double *z1, double *z2)
{
	double distance_min, distance_max;
	distance_min = 38000000;
	distance_max = 261000000;
	*z1 = distance_min / s3; 
	*z2 = distance_max / s3; 
}

// The main body of the code
int 
main (void)
{
int num;
double s1, s2, s3, x1, x2, y1, y2, z1, z2;

// Create a loop for the destinations
for (num = 4; num <= 4; num++)
{
// Ask the user to choose the destination and use if statements to execute the operation
	printf ("\nPlease enter '1' to travel to the moon: \nPlease enter '2' to travel to mars: \nPlease enter '3' to travel to venus: \nPlease enter '4' to exit the program: \n"); 
	scanf ("%d", &num);
	
// Ask the user for the travelling speed, introduce the function, and print the results
	if (num == 1)
	{
		printf ("\nPlease enter the traveling speed (in km/h): \n");
		scanf ("%lf", &s1);
		time1 (s1, &x1, &x2);
		printf ("\nTherefore the maximum time will be %0.2lf hours \nand the minimum time will be %0.2lf hours\n", x2, x1);
	}
	
// Ask the user for the travelling speed, introduce the function, and print the results
	else if (num == 2)
	{
		printf ("\nPlease enter the traveling speed (in km/h): \n");
		scanf ("%lf", &s2);
		time2 (s2, &y1, &y2);
		printf ("\nTherefore the maximum time will be %0.2lf hours \nand the minimum time will be %0.2lf hours\n", y2, y1);
	}
	
// Ask the user for the travelling speed, introduce the function, and print the results
	else if (num == 3)
	{
		printf ("\nPlease enter the traveling speed (in km/h): \n");
		scanf ("%lf", &s3);
		time3 (s3, &z1, &z2);
		printf ("\nTherefore the maximum time will be %0.2lf hours \nand the minimum time will be %0.2lf hours\n", z2, z1);
	}

// If the user chooses to exit the program print text
	else if (num == 4)
	{
		printf ("\nYou have exited the program");
	}
}
	
return (0);
}