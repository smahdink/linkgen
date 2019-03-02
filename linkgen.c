// In God we trust
// LINKGEN
// Author: Seyed Mahdi Nagavi Kalajahi

#include <stdio.h>

int main(void)
{
	printf("In God we trust\n");
	printf("LINKGEN\n");
	printf("Please replace the number you wanna change in the link with a *\n");

	// gets the link
	char link[300];
	for (int j = 0; j < 300; j++)
	{
		link[j] = '\0';
	}
	printf("LINK (max 300 charachters): ");
	scanf("%s", link);

	// finds the *
	int location;
	for (int i = 0; i < 300; i++)
	{
		if (link[i] == '*')
		{
			location = i;
			break;
		}
		else
		{
			location = -1;
		}
		
	}
	
	// checks if the * is found
	if (location == -1)
	{
		printf("No * found!\n");
		return 1;
	}

	// divides the link into two links before and after *
	// any enhancements appreciated :P
	char before[location + 1];
	char after[300 - location - 1];
	for (int z = 0; z < location + 1; z++)
	{
		before[z] = '\0';
	}
	for (int x = 0; x < 300 - location - 1; x++)
	{
		after[x] = '\0';
	}
	for (int k = 0; k < location; k++)
	{
		before[k] = link[k];
	}
	for (int j = location + 1; j < 300; j++)
	{
		after[j - (location + 1)] = link[j];
	}
	

	// gets range
	printf("Range of *\n");
	int range_min = 0;
	int range_max = 0;

	printf("Min: ");
	scanf("%d", &range_min);

	printf("Max: ");
	scanf("%d", &range_max);

	// create file to store links
	FILE *link_txt = fopen("newlinks", "w");

	// generate new links and write them to the file
	for (int l = range_min; l <= range_max; l++)
	{
		fprintf(link_txt, "%s%02d%s\n", before, l , after);
	}
	fclose(link_txt);


	


}