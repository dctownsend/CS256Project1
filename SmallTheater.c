/*
 ============================================================================
 Name        : SmallTheater.c
 Author      : Dakota Townsend
 Version     :
 Description : movie theater
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int showMenu();
void showSeats();
void seats(double[], int);
const int rows = 15;
const int columns = 30;
char map[rows][columns];


void seats(double rowPrice[], int row)
{

	printf("Please enter a ticket price for each row.\n");

	for(int i = 0 ; i < row; i++)
	{
		printf("Row #%d: ", i+1);
		rowPrice[i] = getchar( );
	}
}


void showSeats() {
	printf("\tSeats\n");
	printf("    1 2 3 4 5 6 7 8 9 10 11 12 13 "
			"14 15 16 17 18 19 20 21 22 "
			"23 24 25 26 27 28 29 30\n");
	for(int count = 0; count < 15; count++) {
		printf("\nRow %d", count+1);
		for(int count2 = 0; count2 < 30; count2++) {
			printf(" %c", map[count][count2]);
		}
	}
}

int showMenu(){
	int menuChoice;
	printf(" \tMAIN MENU\n");
	printf(" 1. Purchase a Ticket.\n");
	printf(" 2. View Seat Prices.\n");
	printf(" 3. View Available Seats.\n");
	printf(" 4. View Ticket Sales.\n");
	printf(" 5. Quit the program.\n");
	printf("_____________________\n\n");
	printf("Please enter your choice: ");
	scanf("%f", menuChoice);
	return menuChoice;

  }

int main() {

	const int numRows = 15;
	double prices[numRows];
	char selection;
	int row2, column2;
	const TAKEN = '*';
	const EMPTY = '#';


	printf("\t*********************************************************");
	printf("\n*");
	printf("\t*	Welcome to The our small town Theater	*");
	printf("\n*");
	printf("\t*********************************************************");
	printf("");
	printf("\n");

	for(int i= 0;i<rows;i++)//initiating array
		{
			for (int j=0;j<columns;j++)
			{
				map[i][j]=EMPTY;
			}
		}

		showSeats();
		printf("\n");
	    seats(prices, 15); //ask user to enter price of each row

	    selection = showMenu();
		do  {

			switch(selection){
			case 1:
				printf("please enter a row number and a seat number: ");
				printf("row number: ");
				scanf("%d", row2);
				printf("seat number: ");
				scanf("%d", column2);
				printf("");

				if(map[row2][column2] == TAKEN)
				{
					printf("This seat is taken! Try another one. \n");
					continue; // start the loop again
				}
				else  // and if it is - sell the ticket
					map[row2][column2]=TAKEN;
				// Add the next loop to immediately see the effects:
				for (int i = 0; i < rows; i++){
					for(int j = 0; j < columns; j++){
						printf("%s", map[i][j]);
					}
					printf("");
				} break;

			case 2:
				for(int count = 0; count < rows; count++){
				printf("the price of row %d: ", count+1);
				printf("%s", prices[count]);
				} break;
			case 3:
				printf("view available seats\n\n");
				showSeats();
				break;
			case 4:
				printf("view seat sales\n\n");
				break;
			case 5:
				printf("quit");
				break;
			default: printf("error: invalid input.\n");
  }
} while(selection != 5);
		return 0;
}

