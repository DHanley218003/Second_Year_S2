/*
 * main.cpp
 * A program for allocating seats on a 17 seat aircraft
 *  Created on: Jan 20, 2016
 *      Author: A00218003
 */
//What os is used? Used to determine screen clear command
#ifdef __linux__
	bool os = true;
#else
	bool os = false;
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
bool occ_seats[17]; // used to determine if a seat is occupied
int seats[17][4]; // used for price calculation, if seat is reserved and seat class.

void Reset(bool x[17], int y[17][4]);
void ShowSeats(bool s[]);
void ClearScreen();

int main()
{
	int menu = -1;
	while(true)
	{
		ClearScreen();
		printf("Please select an option:\n1: print map of seats\n2: print seat details\n3: add a passenger\n4: remove a passenger\n5: reset seats\n0: exit program\n");
		scanf("%d", &menu);
		if(menu == 0)
			break;
		else if(menu == 1)
			ShowSeats(occ_seats);
		else if(menu == 5)
			Reset(occ_seats, seats);
	}
	return 0;
}

void Reset(bool x[17], int y[17][4])
{
	// resets boolean array to determine if a seat is occupied
	for(int i = 0;i < 16; i++)
	{
		x[i] = 0;
	}
	// Resets 2d array of: seat number, reservation flag, seat class(0,1,2)
	for(int i = 0;i < 16; i++)
	{
		for(int j = 1; j < 3; j++)
		{
			if(j == 2)//last int in array used to determine seat class
			{
				if(i > 13)// first class
					y[i][j] = 2;
				else if(i > 10)// business class
					y[i][j] = 1;
				else// economy class
					y[i][j] = 0;
			}
			else
				y[i][j] = 0;
		}
		y[i][0] = i;
	}
	printf("Seats reset.\n");
}

void ShowSeats(bool s[])
{
	ClearScreen();
	int ncount = 0;//used for seat numbering
	int scount = 0;
	for(int i = 0; i < 9; i++)
	{
		if(i % 2)//print numbers or blocks?
		{
			for(int j = 0; j < 4; j++)//blocks
			{
				if(j == 2)// tab to create aisle
					printf("\t");
				if(!(s[scount]))//if a seat is occupied
					printf("%c ", 219);
				scount++;
			}
		}
		else
		{
			for(int j = 0; j < 4; j++)//numbers
			{
				if(j == 2)// tab to create aisle
					printf("\t");
				printf("%d ",ncount);
				ncount++;
			}
			
		}
		printf("\n");
	}
	for(int j = 0; j < 4; j++)// Prints last row of blocks
	{
		if(j == 2)// tab to create aisle
			printf("\t");
		if(!(s[scount]))//if a seat is occupied
			printf("%c ", 219);
		scount++;
	}
	printf("\nEnter a number to continue\n");
	std::cin >> ncount;//rather than system("pause");, which would crash in linux
}

/*void ShowDetails(int s[17][3])
{
	ClearScreen();
	for(int i = 0; i < 17; i++)
	{

	}

	printf("\nEnter a number to continue\n");
	std::cin >> count;//rather than system("pause");, which would crash in linux
}*/

void ClearScreen()
{
	if(os)//if linux
		system("clear");
	else//windows
		system("cls");
}
