//Hamza Malik. All rights reserved!

#include <stdio.h>
#include <ctype.h>
#include <string.h>



void reverse(char str_input[], int length, int start, char reversed[]){
	//char temp;
	
	if(0<=(length)){
		
		//printf(".%d..%d\n", start, length);   //Debugg checking indexes
		
		reversed[start]=str_input[length];
		
		reverse(str_input, --length, ++start, reversed);
		
	}	
	
}


void strip(char str_input[], int length, char stripped[]){
	
	//char *ptr;
	//printf("%d", length);
	for(int i=0;i<length;i++){
		
		
		if((isdigit(str_input[i]))||(isalpha(str_input[i]))){
			char c = str_input[i];
			//printf("%d", i);
			
			if(isupper(c)){
				c=tolower(c);
				//printf("debugg");
			}	
					stripped[strlen(stripped)]=c;			
		}
		
		
		
	}
	//ptr=str_input;
	
	printf("The Stripped String is: %s\n", stripped);
	
	
}


int main(void){

	//Initlizaing Variables
	char stripped[100], str_input[100], reversed[100], reversed_stripped[100];
	int length;
	int start=0;
	int count;
	//ptr=str_input;
	
	//Initilizaing arrays as empty instead of null characters
	for(int i=0;i<100;i++){
		stripped[i]='\0';
		str_input[i]='\0';
		reversed[i]='\0';
		reversed_stripped[i]='\0';
	}
	
	
	printf("Enter A string:   ");
	gets(str_input);									//Gets string inpput for string 

	length=strlen(str_input);	
	
	strip(str_input, length, stripped);						//STrips orignal string
	
	reverse(str_input, length-1, start,  reversed);						//Reverses orignal string
	
	printf("The Reversed String is %s\n", reversed);
	
	strip(reversed, length, reversed_stripped);						//Strips reveresd string
	
	//printf("\nThe Reversed String stripped is %s\n", reversed);
	//printf("\n%s", stripped);
	
	
	//Checks if string is palindrome by checking if each index is equal, if it is then add one to count, if count is equal to the length of the array then it means each letter is the same
	
	for(int i=0; i<(length-1);i++){
		
		if(stripped[i]==reversed_stripped[i]){
			count=count+1;
		}
		
	}//For
	if(count==(length-1)){
		printf("The String is a palindrome");
	}
}//End of main
