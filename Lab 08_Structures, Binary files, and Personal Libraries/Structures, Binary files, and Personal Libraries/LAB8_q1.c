//Hamza Malik 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct address_t
{
	int a, b, c, d;
	char fifth_comp[16];
}
address;
struct address_t file[300];

int
localnet (address file1, address file2)
{
	int network;
	if (file1.a == file2.a && file1.b == file2.b && file1.c != file2.c)
	{
		network = 1;
	}

		else 
		{
			network = 0;
		}
		
return network;
}

int
main (void)
{
	int aa, bb, cc, dd, temp;
	char component_5[16];

FILE *in;
in = fopen("sentinel_file.txt", "r");

int i=0, j=0;

while ((fscanf(in, "%d.%d.%d.%d %s", &aa, &bb, &cc, &dd, &component_5)!=EOF))
{
	file[i].a = aa;
	file[i].b = bb;
	file[i].c = cc;
	file[i].d = dd;
	strncpy(file[i].fifth_comp, component_5, 16);
	i++;
}

i = 0;

for (i = 0; i<11; i++)
{
	for(j = 0; j<11; j++)
	{
		temp = localnet(file[i], file[j]); 
		if (temp == 1)
		{
printf("%s and %s are on the same network\n", file[i].fifth_comp, file[j].fifth_comp); 
		}
	} 
}

printf("\nThese are all the IP Addresses and Nicknames:\n"); 

for (i=0; i<11; ++i)
{
	if(file[i].a != 0)
	{
printf("%d.%d.%d.%d %s\n", file[i].a, file[i].b, file[i].c, file[i].d, file[i].fifth_comp) ;
	} 
		else
		{
		fclose(in); 
		}
} 
}
