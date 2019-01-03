#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void shuffle(int deck[][13]);
void deal(const int deck[][13], const char *face[], const char *suit[]);
int main()
{
	const char *s[4] = { "Clubs", "Diamonds", "Hearts", "Spdes" };
	const char *f[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	int d[4][13] = { 0 };
	int counter, a;
	srand(time(NULL));
	shuffle(d);
	deal(d, f, s);
	system("pause");
	return 0;
}
void shuffle(int deck[][13])
{
	int row, column, cards;
	for (cards = 1; cards <= 52; cards++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (deck[row][column] != 0);
		deck[row][column] = cards;
	}
}
void deal(const int deck[][13], const char *face[], const char *suit[])
{
	int cards, row, column,a ,counter,b,column2,row2,cards2,i,j,k,l,count,c=0;
	printf("Please guess the color of the card:1-black, 2-red\n? ");
	scanf_s("%d", &a);
	
	for (cards = 1; cards < 2; cards++)
	{
		for (column = 0; column <= 12; column++)
		{
			for (row = 0; row <= 3; row++)
			{
				if (deck[row][column] == cards)
				{
					printf("%s of %s\n", face[column], suit[row]);
					if ((a == 1 && row == 0) || (a == 1 && row == 3))
					{
						printf("You guess right\n");
					}
					else if ((a == 2 && row == 1) || (a == 2 && row == 2))
					{
						printf("You guess right\n");
					}
					else
					{
						printf("You guess wrong\n");
						c += 1;
					}
					i = column;
					j = row;
					break;
				}
			}
		}
	}
	for (cards = 2; cards < 3; cards++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <= 12; column++)
			{
				if (deck[row][column] == cards)
				{
					printf("Please take a guess about the next card will bigger than this card or smaller than this one:1-bigger, 2-smaller\n?");
					scanf_s("%d", &b);
					printf("%s of %s\n", face[column], suit[row]);
					if ((b == 1 && column > i) ||( b == 1 && column == i && row>j))
					{
						printf("You guess right\n");
						count = 0;
					}
					else if ((b == 2 && column < i) || (b == 2 && column == i && row<j))
					{
						printf("You guess right\n");
						count = 1;
					}
					else
					{
						printf("You guess wrong\n");
						c += 1;
						if (column>i || (column == i&&row>j))
							count = 0;
						if (column < i || (column == i&&row < j))
							count = 1;
					}
					k = column;
					l = row;
				}
			}
		}
	}
	for (cards = 3; cards < 4; cards++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <= 12; column++)
			{
				if (deck[row][column] == cards)
				{
					printf("Please take a guess about the next card will between the two cards or not:1-Yes, 2-No\n?");
					scanf_s("%d", &b);
					printf("%s of %s\n", face[column], suit[row]);
					if ((b == 1 && (i< column && column<k) && count == 0) || (b == 1 && count == 0 && (column == i || column == k) && (row<l&&row>j)) || (b == 1 && (i>column&&column>k)&&count == 1) || (b == 1 && count == 1 && (column == i || column == k) && (row>l&&row<j)))
					{
						printf("You guess right\n");
					}
					else if ((b == 2 && (i<column || column<k) && count == 1) || (b == 2 && count == 1 && (column == i || column == k) && (row<l || row>j)) || (b == 2 && (i>column || column>k) && count == 0) || (b == 2 && count == 0 && (column == i || column == k) && (row>l || row<j)))
					{
						printf("You guess right\n");
					}
					else
					{
						printf("You guess wrong\n");
						c += 1;
					}
				}
			}
		}
	}
	for (cards = 4; cards < 10; cards++)
	{
		for (row2 = 0; row2 <= 3; row2++)
		{
			for (column2 = 0; column2 <= 12; column2++)
			{
				if (deck[row2][column2] == cards)
				{
					printf("\t%s of %s", face[column2], suit[row2]);
					if (cards == 4 || cards == 6)
						printf("\n");
					if (column2 == i || column2 == k || column2 == column){
						//c += 2;
						if (cards == 4){
							c += 3;
						}
						if (cards == 5 || cards == 6){
							c += 2;
						}
						if (cards == 7 || cards==8 || cards==9){
							c += 1;
						}
					}
				}
			}
		}
	}
	printf("\nYou have to drink %d shots\n", c);
}
