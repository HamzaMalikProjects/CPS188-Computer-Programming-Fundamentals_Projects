//Hamza Malik. All rights reserved!
#include <stdio.h>									
#include <math.h>
#include <ctype.h>


int main(void){
	
	//printf("1  ");
		
	int rows;
	int num=1;
	
	printf("How many rows for Pascal's Triangle?  ");
	scanf("%d", &rows);
	
	for(int i=0;i<rows;i++){
		
		//printf("1  ");
		
		for(int x=0; x<=i;x++){
			
			if((x==0)||(i==0)){
				num=1;
			}else{
				num=num*(i-x+1)/x;				//Formula for entry
				
			}
			printf("  %d  ", num);
			//printf("*");
			
		}//2
		printf("\n");
		
	}//1
	
	
	
}