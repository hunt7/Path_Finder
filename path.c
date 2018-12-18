#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void size_of_grid(int *row, int *column)
{
	int sign,
		total = 0;

	FILE *fr = fopen("grid.txt","r");		//opening file for reading characters
	while((sign = getc(fr)) != EOF)			//read while not end-of-file
		(sign != '\n') ? total++ : (*row)++;

	(*column) = total/(*row);
	
	fclose(fr);								//always need to close file and initialize to NULL
	fr = NULL;
}


void load_matrix(int *row, int *column, char *arr[])
{
	int sign,
		i = 0,
		j = 0;

	arr[i] = (char *) malloc((*column) * sizeof(char));		//allocing memory for array of pointers

	FILE *fr = fopen("grid.txt","r");
	while((sign = getc(fr)) != EOF)
		{
			if(sign != '\n')
			{	
				(*(*(arr + i) + j++)) = sign;
			}
			else
				{
					arr[++i] = (char *) malloc((*column) * sizeof(char));
					j = 0;
				}
		}
}

void print_matrix(int *row, int *column, char *arr[])
{
	for(int i = 0; i < (*row); i++)
	{
		for(int j = 0; j < (*column); j++)
			printf("%c", *(*(arr + i) + j));
		putchar('\n');
	}
}


int main()									//main program
{
	char sign;
	int row = 0, column = 0;
	int size;
	char *arr[size];

	while(scanf("%c",&sign) == 1)			//while we will type signs to run functions
		{
			if(sign == 'q')	
				return 0;					//quit the program
			else if(sign == 'l')
			{
				size_of_grid(&row, &column);
				load_matrix(&row, &column,&*arr);
			}
			else if(sign == 'p')
				print_matrix(&row, &column, &*arr);
		}

}