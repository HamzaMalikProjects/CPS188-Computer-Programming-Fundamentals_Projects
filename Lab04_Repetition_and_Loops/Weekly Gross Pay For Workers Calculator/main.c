//Hamza Malik. All rights reserved!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void spaces(int space_num, FILE *dW) {
    // Function to add spacing in the report file
    for (int i = 0; i < space_num; i++) {
        fprintf(dW, " ");
    }
}

void spacesC(int space_num) {
    // Function to add spacing in the console
    for (int i = 0; i < space_num; i++) {
        printf(" ");
    }
}

void run() {
    // Initializing variables
    int Employ_num, hrs, shifts;
    double wage, gross_pay;

    int numOfTokens = 0; // Variable to track the number of tokens in each line
    char *end;           // Variable for using strtod function

    FILE *dR, *dW;                 // File pointers
    dR = fopen("L4_data.txt", "r"); // Open file for reading
    dW = fopen("Report.txt", "w");  // Create file for writing

    // Write header to file
    fprintf(dW, "Employee Number          Shifts              Wage        Total Hours Worked        Gross pay\n____________________________________________________________________________________________\n");

    // Print header to console
    printf("Employee Number          Shifts              Wage        Total Hours Worked        Gross pay\n____________________________________________________________________________________________\n");

    while (1) {
        char r[100]; // Buffer to store the line read from the file

        if (fgets(r, 100, dR) == NULL) {
            // Read line from file, break if end of file is reached
            break;
        }

        char *g = strtok(r, " "); // Tokenize the line read from the file

        while (g != NULL) {
            numOfTokens++; // Increment the token count

            if (numOfTokens == 1) {
                // The first token is the employee number
                Employ_num = atoi(g);
            } else if (numOfTokens == 2) {
                // The second token is the number of shifts
                shifts = atoi(g);
            } else if (numOfTokens == 3) {
                // The third token is the wage
                wage = strtod(g, &end);
            }

            if (numOfTokens > 3) {
                // Sum all the tokens after the third token to get the total number of hours worked
                hrs = atoi(g) + hrs;
            }

            g = strtok(NULL, " "); // Get the next token
        }

        // Calculate gross pay based on the number of hours worked
        if (hrs <= 15) {
            gross_pay = wage * hrs;
        } else if ((hrs > 15) && (hrs <= 25)) {
            gross_pay = ((wage * 1.05) * hrs);
        } else if (hrs > 25) {
            gross_pay = ((wage * 1.1) * hrs);
        }

        // Print data to console
        printf("\n");
        spacesC(4);
        printf("%d", Employ_num);
        spacesC(9);
        printf("|");

        spacesC(8);
        printf("%d", shifts);

        if (shifts >= 10) {
            spacesC(9);
        } else if (shifts < 10) {
            spacesC(10);
        }

        printf("|");

        spacesC(6);
        printf("%0.2lf", wage);
        spacesC(6);
        printf("|");

        if (hrs >= 10) {
            spacesC(9);
        } else if (hrs < 10) {
            spacesC(10);
        }

        printf("%d       |       ", hrs);
        printf("%0.2lf\n", gross_pay);

        // Write data to file
        fprintf(dW, "\n");
        spaces(4, dW);
        fprintf(dW, "%d", Employ_num);
        spaces(9, dW);
        fprintf(dW, "|");

        spaces(8, dW);
        fprintf(dW, "%d", shifts);

        if (shifts >= 10) {
            spaces(9, dW);
        } else if (shifts < 10) {
            spaces(10, dW);
        }

        fprintf(dW, "|");

        spaces(6, dW);
        fprintf(dW, "%0.2lf", wage);
        spaces(6, dW);
        fprintf(dW, "|");

        if (hrs >= 10) {
            spaces(9, dW);
        } else if (hrs < 10) {
            spaces(10, dW);
        }

        fprintf(dW, "%d       |       ", hrs);
        fprintf(dW, "%0.2lf\n", gross_pay);

        // Reset variables for the next line of data
        hrs = 0;
        gross_pay = 0;
        Employ_num = 0;
        numOfTokens = 0;
    }

    printf("\n\nSee Report.txt! (In the same directory)");

    fclose(dW); // Close the writing file
    fclose(dR); // Close the reading file
}

int main(void) {
    run();
    return 0;
}
