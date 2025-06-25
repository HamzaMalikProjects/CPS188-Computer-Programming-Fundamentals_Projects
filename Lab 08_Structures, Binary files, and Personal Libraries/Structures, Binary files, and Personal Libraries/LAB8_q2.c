// Hamza Malik 

#include <stdio.h>
#include "mylibrary.h"

struct results
{
	int ans1, ans2, ans3, ans4, ans5;
};

int
main (void)
{
	
double matrix[10][10];
int i, j;

FILE *in;
in=fopen("array_file.txt", "r");

for (i=0; i<10; i++)
for (j=0; j<10; j++)
fscanf (in, "%lf", &matrix[i][j]);
fclose(in);

for (i=0; i<10; i++)
{
	for (j=0; j<10; j++)
	{
		printf ("%.2lf", matrix[i][j]);
		printf ("\n");
	}
}

double sum_of_diag;
sum_of_diag = sumdiag(10, matrix); 
printf ("\n%.2lf", sum_of_diag);

double total_sum;
total_sum = sumall(10, matrix); 
printf ("\n%.2lf", total_sum);

double average_right;
average_right = avright(matrix); 
printf ("\n%.2lf", average_right);

double sum_corners;
sum_corners = corners(matrix); 
printf ("\n%.2lf", sum_corners);

double large_antidiag;
large_antidiag = largeanti(matrix); 
printf ("\n%.2lf", large_antidiag);

FILE *bin;
bin = fopen("results.bin", "wb");

double ans[5] = {sum_of_diag, total_sum, average_right, sum_corners, large_antidiag};
fwrite(ans, sizeof (double), 5, bin); 
fclose(bin);

bin = fopen("results.bin", "rb");
double results[5];

fread(results, sizeof (double), 5, bin);
printf("\nThe sum of the main diagonal is %.1lf\n", results[0]);
printf("The total sum of all the elements is %.1lf\n", results[1]);
printf("The average of the last (rightmost) column is %.1lf\n", results[2]); 
printf("The sum of the four corners is %.1lf\n", results[3]);
printf("The largest number in the anti-diagonal is %.1lf\n", results[4]);
}
