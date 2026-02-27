#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAXLEN 27

int ROW, COL, ROWS, COLS;
int EASY_COUNT;
bool vis[MAXLEN][MAXLEN];//Initialize checkerboard
void init_board(char arr[MAXLEN][MAXLEN], int rows, int cols, char set);//Print board
void Display_board(char arr[MAXLEN][MAXLEN], int row, int col);
void set_mine(char mine[MAXLEN][MAXLEN], int row, int col);
void find_mine(char mine[MAXLEN][MAXLEN], char show[MAXLEN][MAXLEN], int row, int col);//mark
void sign_show(char show[MAXLEN][MAXLEN], int row, int col);//delete the flag place
void del_sign_show(char show[MAXLEN][MAXLEN], int row, int col);

void game()
{
	char mine[MAXLEN][MAXLEN] = { 0 };
	char show[MAXLEN][MAXLEN] = { 0 };
	//Initialize checkerboard
	init_board(mine, ROWS, COLS, 'O');
	init_board(show, ROWS, COLS, ' ');
	//set mine
	set_mine(mine, ROW, COL);
	Display_board(show, ROW, COL);//print the board

	find_mine(mine, show, ROW, COL);//fine mine
}

void init_board(char arr[MAXLEN][MAXLEN], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;//Initialize the chessboard, making sure that each cell of the chessboard is in the same initial state
		}
	}
}


void Display_board(char arr[MAXLEN][MAXLEN], int row, int col)//Used to print unmarked checkerboard
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)//Center row and column markers
	{
		if (i == 0) {
			printf("    ");
			continue;
		}
		if (i < 10) printf(" %d  ", i);
		else printf(" %d ", i);
	}
	printf("\n");
	for (i = 0; i <= col; i++)
	{
		if (i == 0) {
			printf("   |");
			continue;
		}
		printf("---");
		if (i <= col)
		{
			printf("|");
		}
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %c ", i + 'A' - 1);//ASCII code value of the corresponding letter
		printf("|");
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j <= col)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row)
		{
			for (j = 0; j <= col; j++)
			{
				if (j == 0) {
					printf("   |");
					continue;
				}
				printf("---");
				if (j <= col)
				{
					printf("|");
				}
			}
		}
		if (i != row)printf("\n");
	}
	for (i = 0; i <= col; i++)
	{
		if (i == 0) {
			printf("   |");
			continue;
		}
		printf("---");
		if (i <= col)
		{
			printf("|");
		}
	}
	printf("\n");
	printf("=======================================\n");
}

void Display_board_show(char arr[MAXLEN][MAXLEN], int row, int col)//Print the board that has been marked
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		if (i == 0) {
			printf("    ");
			continue;
		}
		if (i < 10) printf(" %d  ", i);
		else printf(" %d ", i);
	}
	printf("\n");
	for (i = 0; i <= col; i++)
	{
		if (i == 0) {
			printf("   |");
			continue;
		}
		printf("---");
		if (i <= col)
		{
			printf("|");
		}
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %c ", i + 'A' - 1);
		printf("|");
		for (j = 1; j <= col; j++)
		{
			if (!vis[i][j]) printf(" %c ", arr[i][j]);//Print out the contents of a grid
			else printf(" X ");
			if (j <= col)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row)
		{
			for (j = 0; j <= col; j++)
			{
				if (j == 0) {
					printf("   |");
					continue;
				}
				printf("---");
				if (j <= col)
				{
					printf("|");
				}
			}
		}
		if (i != row)printf("\n");
	}
	for (i = 0; i <= col; i++)
	{
		if (i == 0) {
			printf("   |");
			continue;
		}
		printf("---");
		if (i <= col)
		{
			printf("|");
		}
	}
	printf("\n");
	printf("=======================================\n");
}


void set_mine(char mine[MAXLEN][MAXLEN], int row, int col)//set mine
{
	int count = EASY_COUNT;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;//Generate random numbers
		y = rand() % col + 1;
		if (mine[x][y] == 'O')
		{
			mine[x][y] = 'X';
			vis[x][y] = 1;
			count--;
		}
	}
}


static int get_mine_count(char mine[MAXLEN][MAXLEN], int x, int y)//Check the number of mines around the input coordinates
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == 'X')
			{
				count++;
			}
		}
	}
	return count;
}
void spread_mine(char mine[MAXLEN][MAXLEN], char show[MAXLEN][MAXLEN], int x, int y)//展开非雷区
{
	int i = 0;
	int j = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (i >= 1 && i <= ROW && j >= 1 && j <= COL)
			{
				if (get_mine_count(mine, i, j) == 0 && show[i][j] == ' ')
				{
					show[i][j] = 'O';
					spread_mine(mine, show, i, j);
				}
				else if (get_mine_count(mine, i, j) != 0 && show[i][j] == ' ')
				{
					int count = get_mine_count(mine, i, j);
					show[i][j] = count + '0';
				}
			}
		}
	}
}
int is_win(char mine[MAXLEN][MAXLEN], char show[MAXLEN][MAXLEN], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (mine[i][j] != 'X' && show[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
void sign_show(char show[MAXLEN][MAXLEN])//mark
{
	int x = 0;
	char c;
	int y = 0;
	printf("Select the coordinates you want to mark:>");
	while (1)
	{
		getchar();
		scanf("%c %d", &c, &y);
		x = c - 'A' + 1;
		if (show[x][y] == ' ')
		{
			show[x][y] = 'F';
			break;
		}
		else
		{
			printf("Input error, please re-enter");
		}
	}
}
void del_sign_show(char show[MAXLEN][MAXLEN])//delete
{
	int x = 0;
	char c;
	int y = 0;
	printf("Select the coordinates where you want to remove the tag:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		getchar();
		scanf("%c %d", &c, &y);
		x = c - 'A' + 1;
		if (show[x][y] == 'F')
		{
			show[x][y] = ' ';
			break;
		}
		else
		{
			printf("Input error, please re-enter");
		}
	}
}
void find_mine(char mine[MAXLEN][MAXLEN], char show[MAXLEN][MAXLEN], int row, int col)
{
	int x = 0;
	int y = 0;
	char c;
	while (1)
	{
		printf("Please enter the coordinates of mine clearance (input 0, 0 is marked, input 0, 1 is unmarked):>");
		getchar();
		scanf("%c %d", &c, &y);
		if (c >= 'A' && c <= 'Z') x = c - 'A' + 1;
		if (c == '0') x = 0;
		if (show[x][y] != ' ')
		{
			printf("This coordinate has been scanned, please re-enter\n");
			continue;
		}
		else if ((x<1 || x>row || y<1 || y>col) && (x != 0 && y != 0) && (x != 0 && y != 1)) {
			printf("Coordinates are wrong, please re-enter\n");
			continue;
		}
		else if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == 'X')//fine a mine
			{
				printf("I'm sorry you got blown up\n");
				Display_board_show(show, ROW, COL);
				system("pause");
				system("cls");
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				if (count + '0' == '0')
				{
					show[x][y] = 'O';
					spread_mine(mine, show, x, y);//Unfold non-minefield
				}
				else
				{
					show[x][y] = count + '0';
				}
				Display_board(show, ROW, COL);
			}
		}
		else if (x == 0 && y == 0)//The marking operation is performed when the input coordinates are two zeros
		{
			sign_show(show);//Marked coordinate
			Display_board(show, ROW, COL);
		}
		else if (x == 0 && y == 1)//The marking operation is performed when the input coordinates are two zeros
		{
			del_sign_show(show);//delete the mark
			Display_board(show, ROW, COL);
		}
		else
		{
			printf("Input coordinates are out of minefield range, please re-enter\n");
		}
		if (is_win(mine, show, row, col) == 1)
		{
			printf("Congratulations. Mine clearance\n");
			Display_board(mine, ROW, COL);
		}
	}
}


int main() {
	int x;
	srand((unsigned int)time(NULL));//Make sure the sequence of random numbers generated is different each time you run the program
	while (1) {
		printf("Welcome to the minesweeper! \n");
		printf("Please select your difficulty:\n");
		printf("\t1:Beginner 8x8 grid with 10 mines\n");
		printf("\t2:Middle 16x16 grid with 40 mines\n");
		printf("\t3:Expert 24x24 mesh with 99 mines\n");
		printf("\t0.exit the game\n");
		printf("Please choose:>");
		scanf("%d", &x);
		if (x == 0)
		{
			printf("Goodbye!\n");
			break;
		}
		if (x == 1)
		{
			ROW = 8;
			COL = 8;
			ROWS = ROW + 2;
			COLS = COL + 2;
			EASY_COUNT = 10;
			game();
		}
		if (x == 2)
		{
			ROW = 16;
			COL = 16;
			ROWS = ROW + 2;
			COLS = COL + 2;
			EASY_COUNT = 40;
			game();
		}
		if (x == 3)
		{
			ROW = 24;
			COL = 24;
			ROWS = ROW + 2;
			COLS = COL + 2;
			EASY_COUNT = 99;
			game();
		}
	}

	return 0;
}