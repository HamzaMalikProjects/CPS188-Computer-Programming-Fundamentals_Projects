// This is number 9 using the 2019 data
#include<stdio.h>
#include <stdlib.h>
//Stores the names of the 6 lakes
char * lakeNames[6] = {"Lake Superior","Lake Michigan","Lake Huron","Lake Erie","Lake Ontario","Lake St.Clair"};
int i,j;
double arrSum (double arr[i]);
void timeConv(int x);
double min,max;
//Holds averages for the 6 lakes
double temp[6][365], record[6][9], TotalAvg, min, max;
char names[6] = {'s', 'm', 'h', 'e', 'o', 'z'};

int main(void)
   {
       //Validates file data type and links it to the code
        FILE *data_file;
        int year, index = 0, i = 0, month = 0, day=0;
        //Set to open file named data.txt
        data_file = fopen("data.txt2", "r");
        while(day!= 365)
            {
                //Stores each of the values
                fscanf(data_file,("%d %d %lf %lf %lf %lf %lf %lf"),&year, &day,&temp[0][i],&temp[1][i],&temp[2][i],&temp[3][i],&temp[4][i],&temp[5][i]);
                ++i;
            } 
        // Checks for file data.txt, if its not found or cannot be opened then display error message and exits
        if (data_file == NULL)
            {
                // Displays error message and exits
                puts("Error: Your file could not open, please try again");
                exit(0);
                ++i;
            }
/* ______________________ Question #9 _______________________ */
//Uses same code from question 1 but uses the 2019 data and outputs average according to it.
int totalyearlyAveragesTemperaturemain() 
    {   
        printf("<<=======| Question # 9: |=======>>\n");
        printf("\n");
        printf("The average temperatures for each of the following 6 Lakes are: \n");
        printf("\n");
        
        int i,j;
        double sumsup, summich, sumhuron, sumerie, sumont, sumstclr;
        double avgsup, avgmich, avghuron, avgerie, avgont, avgstclr;
        double min,max;
        
        for(int i=0; i<6; ++i) 
            {
                min = 0, max = 0, sumsup = summich = sumhuron = sumerie = sumont = sumstclr = 0;
        for(int j=0; j<365; ++j) 
            {
                sumsup, summich, sumhuron, sumerie, sumont, sumstclr += temp[i][j];
            }
                record[i][1] = min, record[i][2] = max, record[i][1] = sumsup = summich = sumhuron = sumerie = sumont = sumstclr/365;
            }
        for(int i=0; i<6; ++i)
            {
                //Average temperature for each of the following lakes
                TotalAvg += record[i][1];
                printf("%s being %lf°C.\n",lakeNames[i],record[i][1]);
            }
        for(int i=0; i<6; ++i)
            {  
                //Yearly Average for all 6 lakes
                TotalAvg = TotalAvg/6;
                printf("\nThe YEARLY average temperature of all the 6 Lakes combined is %lf°C.\n", TotalAvg);
                printf("\n");
                break;
            }
    }
totalyearlyAveragesTemperaturemain(); 
}
