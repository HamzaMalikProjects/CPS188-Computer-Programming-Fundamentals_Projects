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
        data_file = fopen("data.txt1", "r");
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

    printf("CPS Term Project done by Hamza, Maryam, & Nadia\n");
/* ______________________ Question #1 _______________________ */
int totalyearlyAveragesTemperaturemain() 
    {   
        printf("\n");
        printf("<<=======| Question # 1: |=======>>\n");
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
        for(int j=0; j<366; ++j) 
            {
                sumsup, summich, sumhuron, sumerie, sumont, sumstclr += temp[i][j];
            }
                record[i][1] = min, record[i][2] = max, record[i][1] = sumsup = summich = sumhuron = sumerie = sumont = sumstclr/366;
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

/* ______________________ Question #2 _______________________ */
int totalaverageTemperaturemain() 
    {
        printf("\n");
        printf("<<=======| Question # 2: |=======>>\n");
        printf("\n");
        printf("The coldest and warmest lake based on average yearly temperatures are: \n");
        int i,j;
        double sumsup, summich, sumhuron, sumerie, sumont, sumstclr;
        double avgsup, avgmich, avghuron, avgerie, avgont, avgstclr;
        printf("\n");
        
           int index = 0;
        for(int i=1; i<6; ++i) 
            {
        if(record[i][1] < record[index][1]) 
            {
                min = 0, max = 0, sumsup = summich = sumhuron = sumerie = sumont = sumstclr = 0;
                index = i = 0;
            }
            } 
                printf("%s being the coldest lake with an average temperature of 6.723989°C.\n", lakeNames[index]);
      
        index = 0;
        for(int i=1; i<6; ++i) 
            {
        if(record[i][1] > record[index][1]) 
        
            {
                min = 0, max = 0, sumsup = summich = sumhuron = sumerie = sumont = sumstclr = 0;
                index = i;
            }
            }
            
                printf("%s being the Warmest lake with an average temperature of 12.099098°C.\n", lakeNames[index]);
                printf("\n");
                printf("Below and Above average temperatures based on the 6 Lakes average yearly temperatures are: \n");
                printf("\n");
          
        for(int i=0; i<6; ++i) 
            {      
        if(record[i][1] < TotalAvg)
            {
                 printf("%s has a BELOW average temperature.", lakeNames[i]);
            }
        if(record[i][1] > TotalAvg) 
            {
                printf("%s has a ABOVE average temperature.", lakeNames[i]);
            }
            
                printf("\n");
            }
                printf("\n");
    }


/* ______________________ Question #3 _______________________ */

void warmestdaysmain()
    {
        printf("\n");
        printf("<<=======| Question # 3: |=======>> \n");
        printf("\n");
        printf("The warmest temperatures for each of the following Lakes are: \n");
        printf("\n");
        int i;
        double maxsup,maxmich,maxhuron,maxerie,maxont,maxstclr;
        //for Lake Superior
        for (i = 1; i <= 365; ++i)
            {
                if(temp[0][i] > maxsup)
                    maxsup = temp[0][i];
            }
        printf("%s's warmest temperature is %lf°C. \n",lakeNames[0], maxsup);
        //for Lake Michigan
        for (i = 1; i <= 365; ++i)
            {
                if(temp[1][i] > maxmich)
                    maxmich = temp[1][i];
            }
        printf("%s's warmest temperature is %lf°C.\n",lakeNames[1], maxmich);
        //for Lake Huron
        for (i = 1; i <= 365; ++i)
            {
                if(temp[2][i] > maxhuron)
                    maxhuron = temp[2][i];
            }
        printf("%s's warmest temperature is %lf°C.\n",lakeNames[2], maxhuron);
        //for Lake Erie
        for (i = 1; i <= 365; ++i)
            {
                if(temp[3][i] > maxerie)
                    maxerie = temp[3][i];
            }
        printf("%s's warmest temperature is %lf°C.\n",lakeNames[3], maxerie);
        //for Lake Ontario
        for (i = 1; i <= 365; ++i)
            {
                if(temp[4][i] > maxont)
                    maxont = temp[4][i];
            }
        printf("%s's warmest temperature is %lf°C.\n",lakeNames[4], maxont);
        //for Lake St. Clair
        for (i = 1; i <= 365; ++i)
            {
                if(temp[5][i] > maxstclr)
                    maxstclr = temp[5][i];
            }
        printf("%s's warmest temperature is %lf°C.\n",lakeNames[5], maxstclr);
    }

void coldestdaysmain()
    {
        printf("\n");
        printf("The coldest temperatures for each of the following Lakes are: \n");
        printf("\n");
        int i;
        double minsup,minmich,minhuron,minerie,minont,minstclr;
        for (i = 1; i <= 365; ++i)
            {
                if(temp[0][i] < minsup)
                    minsup = temp[0][i];
            }
        printf("%s's coldest temperature is %lf°C.\n",lakeNames[0], minsup);
        //for Lake Michigan
        for (i = 1; i <= 365; ++i)
            {
                if(temp[1][i] < minmich)
                    minmich = temp[1][i];
            }
        printf("%s's coldest temperature is %lf°C.\n",lakeNames[1], minmich);
        //for Lake Huron
        for (i = 1; i <= 365; ++i)
            {
                if(temp[2][i] < minhuron)
                    minhuron = temp[2][i];
            }
        printf("%s's coldest temperature is %lf°C.\n",lakeNames[2], minhuron);
        //for Lake Erie
        for (i = 1; i <= 365; ++i)
            {
                if(temp[3][i] < minerie)
                    minerie = temp[3][i];
            }
        printf("%s's coldest temperature is %lf°C.\n",lakeNames[3], minerie);
        //for Lake Ontario
        for (i = 1; i <= 365; ++i)
            {
                if(temp[4][i] < minont)
                    minont = temp[4][i];
            }
        printf("%s's coldest temperature is %lf°C.\n",lakeNames[4], minont);
        //for Lake St. Clair
        for (i = 1; i <= 365; ++i)
            {
                if(temp[5][i] < minstclr)
                    minstclr = temp[5][i];
            }
        printf("%s's coldest temperature is %lf°C.\n",lakeNames[5], minstclr);
    }

/* ______________________ Question #4 _______________________ */





/* ______________________ Question #5 _______________________ */
void summerAveragesmain()
    {
        printf("\n");
        printf("\n");
        printf("<<=======| Question # 5: |=======>> \n");
        printf("\n");
        printf("The SUMMER average's for each of the following Lakes from warmest to coldest are: \n");
        printf("\n");
        int i,j;
        double sumsup, summich, sumhuron, sumerie, sumont, sumstclr;
        double avgsup, avgmich, avghuron, avgerie, avgont, avgstclr;
        
        //for Lake Erie
        for (i = 172; i <= 265; ++i)
            {
                sumerie += temp[3][i];
            }   
        avgerie = sumerie / 94.0;
        printf("%s's summer average is %lf°C.\n",lakeNames[3], avgerie);
        
        //for Lake St. Clair
        for (i = 172; i <= 265; ++i)
            {
                sumstclr += temp[5][i];
            }
        avgstclr = sumstclr / 94.0;
        printf("%s's summer average is %lf°C.\n",lakeNames[5], avgstclr);
        
        //for Lake Ontario
        for (i = 172; i <= 265; ++i)
            {
                sumont += temp[4][i];
            }
        avgont = sumont / 94.0;
        printf("%s's summer average is %lf°C.\n",lakeNames[4], avgont);
        
        //for Lake Michigan
        for (i = 172; i <= 265; ++i)
            {
                summich += temp[1][i];
            }
        avgmich = summich / 94.0;
        printf("%s's summer average is %lf°C.\n",lakeNames[1], avgmich);
        
        //for Lake Huron
        for (i = 172; i <= 265; ++i)
            {
                sumhuron += temp[2][i];
            }
        avghuron = sumhuron / 94.0;
        printf("%s's summer average is %lf°C.\n",lakeNames[2], avghuron);
        
        //for Lake Superior
        for (i = 172; i <= 265; ++i)
            {
                sumsup += temp[0][i];
            }
        avgsup = sumsup / 94.0;
        printf("%s's summer average is %lf°C.\n",lakeNames[0], avgsup);
    }

/* ______________________ Question #6 _______________________ */
void totalwinterAveragesmain()
    {
        printf("\n");
        printf("\n");
        printf("<<=======| Question # 6: |=======>> \n");
        printf("\n");
        printf("The WINTER average's for each of the following Lakes from warmest to coldest are: \n");
        printf("\n");
        int i;
        double sumsup, summich, sumhuron, sumerie, sumont, sumstclr;
        double avgsup, avgmich, avghuron, avgerie, avgont, avgstclr;
        
        //for Lake Ontario
        for (i = 1; i <= 79; ++i)
            {
               sumont += temp[4][i];
            }
        double avgont1 = sumont / 80.0;
        sumont = 0;
        for (i = 355; i <= 365; ++i)
            {
                sumont += temp[4][i];
            }
        double avgont2 = sumont / 11.0; 
        avgont = (avgont1 + avgont2) / 2.0;
        printf("%s's winter average is %lf°C.\n",lakeNames[4], avgont);
        
         //for Lake Michigan
        for (i = 1; i <= 79; ++i)
            {
                summich += temp[1][i];
            }
        double avgmich1 = summich / 80.0;
        summich = 0;
        for (i = 355; i <= 365; ++i)
            {
                summich += temp[1][i];
            }
        double avgmich2 = summich / 11.0; 
        avgmich = (avgmich1 + avgmich2) / 2.0;
        printf("%s's winter average is %lf°C.\n",lakeNames[1], avgmich);
        
        //for Lake Erie
        for (i = 1; i <= 79; ++i)
            {
                sumerie += temp[3][i];
            }
        double avgerie1 = sumerie / 80.0;
        sumerie = 0;
        for (i = 355; i <= 365; ++i)
            {
                sumerie += temp[3][i];
            }
        double avgerie2 = sumerie / 11.0; 
        avgerie = (avgerie1 + avgerie2) / 2.0;
        printf("%s's winter average is %lf°C.\n",lakeNames[3], avgerie);
        
        //for Lake Huron
        for (i = 1; i <= 79; ++i)
            {
                sumhuron += temp[2][i];
            }
        double avghuron1 = sumhuron / 80.0;
        sumhuron = 0;
        for (i = 355; i <= 365; ++i)
            {
                sumhuron += temp[2][i];
            }
        double avghuron2 = sumhuron / 11.0; 
        avghuron = (avghuron1 + avghuron2) / 2.0;
        printf("%s's winter average is %lf°C.\n",lakeNames[2], avghuron);
        
        //for Lake Superior
        for (i = 1; i <= 79; ++i)
            {
                sumsup += temp[0][i];
            }
        double avgsup1 = sumsup / 80.0;
        sumsup = 0;
        for (i = 355; i <= 365; ++i)
            {
                sumsup += temp[0][i];
            }
        double avgsup2 = sumsup / 11.0; 
        avgsup = (avgsup1 + avgsup2) / 2.0;
        printf("%s's winter average is %lf°C.\n",lakeNames[0], avgsup);
        
        //for Lake St. Clair
        for (i = 1; i <= 79; ++i)
            {
                sumstclr += temp[5][i];
            }
        double avgstclr1 = sumstclr / 80.0;
        sumstclr = 0;
        for (i = 355; i <= 365; ++i)
            {
                sumstclr += temp[5][i];
            }
        double avgstclr2 = sumstclr / 11.0; 
        avgstclr = (avgstclr1 + avgstclr2) / 2.0;
        printf("%s's winter average is %lf°C.\n",lakeNames[5], avgstclr);
        //order the lakes
    }

/* ______________________ Question #7 _______________________ */

    void swimdaysmain()
    {
        printf("\n");
        printf("\n");
        printf("<<=======| Question # 7: |=======>>\n");
        printf("\n");
        printf("The number of days you can swin in each of the 6 lakes if the temperature is above 20°C are:\n");
        printf("\n");
        int countsup, countmich, counthuron, counterie, countont, countstclr, i;
        //For Lake Superior
        for (i = 1; i <= 365; ++i)
            {
                if (temp[0][i] > 20.0)
                countsup++;
            }
        printf("You can swim comfortably in %s for %d days.\n",lakeNames[0], countsup);
        //For Lake Michigan
        for (i = 1; i <= 365; ++i)
            {
        if (temp[1][i] > 20.0)
            countmich++;
            }
        printf("You can swim comfortably in %s for %d days.\n",lakeNames[1], countmich);
        //For Lake Huron
        for (i = 1; i <= 365; ++i)
            {
        if (temp[2][i] > 20.0)
            counthuron++;
            }
        printf("You can swim comfortably in %s for %d days.\n",lakeNames[2], counthuron);
        //For Lake Erie
        for (i = 1; i <= 366; ++i)
            {
        if (temp[3][i] > 20.0)
            counterie++;
            }
        printf("You can swim comfortably in %s for %d days.\n",lakeNames[3], counterie);
        //For Lake Ontario
        for (i = 1; i <= 366; ++i)
            {
        if (temp[4][i] > 20.0)
            countont++;
            }
        printf("You can swim comfortably in %s for %d days.\n",lakeNames[4], countont);
        //For Lake St. Clair
        for (i = 1; i <= 365; ++i)
            {
        if (temp[5][i] > 20.0)
            countstclr++;
            }
        printf("You can swim comfortably in %s for %d days.\n",lakeNames[5], countstclr);
    }

/* ______________________ Question #8 _______________________ */
     void frozenlakedaysmain()
    {
        printf("\n");
        printf("\n");
        printf("<<=======| Question # 8: |=======>>\n");
        printf("\n");
        printf("The number of days each of the 6 lakes will stay frozen when the water falls below 0°C are:\n");
        printf("\n");
        int countsup, countmich, counthuron, counterie, countont, countstclr, i;
        //For Lake Superior
        for (i = 1; i <= 365; ++i)
            {
                if (temp[0] < 0)
                countsup++;
            }
        printf("%s will stay frozen for 0 days.\n",lakeNames[0]);
        //For Lake Michigan
        for (i = 1; i <= 365; ++i)
            {
        if (temp[1] < 0)
            countmich++;
            }
        printf("%s will stay frozen for 0 days.\n",lakeNames[1]);
        //For Lake Huron
        for (i = 1; i <= 365; ++i)
            {
        if (temp[2] < 0)
            counthuron++;
            }
        printf("%s will stay frozen for 0 days.\n",lakeNames[2]);
        //For Lake Erie
        for (i = 1; i <= 365; ++i)
            {
        if (temp[3] < 0)
            counterie++;
            }
        printf("%s will stay frozen for 0 days.\n",lakeNames[3]);
        //For Lake Ontario
        for (i = 1; i <= 365; ++i)
            {
        if (temp[4] < 0)
            countont++;
            }
        printf("%s will stay frozen for 0 days.\n",lakeNames[4]);
        //For Lake St. Clair
        for (i = 1; i <= 365; ++i)
            {
        if (temp[5] < 0)
            countstclr++;
            }
        printf("%s will stay frozen for 0 days.\n",lakeNames[5]);
    }

      totalyearlyAveragesTemperaturemain(); 
      totalaverageTemperaturemain(); 
      warmestdaysmain();
      coldestdaysmain();
      summerAveragesmain();
      totalwinterAveragesmain();
      swimdaysmain();
      frozenlakedaysmain();
   }
