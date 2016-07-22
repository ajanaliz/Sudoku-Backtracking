#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <list>
#include <limits.h>
#include <sstream>
#include <iomanip>
#include <string>
#include "string.h"
#include "ListNode.h"


int dimension;

bool FindUnassignedLocation(int** grid, int &row, int &col);
bool isSafe(int** grid, int row, int col, int num);

bool SolveSudoku(int** grid)
{
	int row, col;

	if (!FindUnassignedLocation(grid, row, col))
		return true; // solved
	if ((rand() % 2) == 0)
	{
		for (int num = 1; num <= dimension; num++)
		{
			if (isSafe(grid, row, col, num))
			{
				grid[row][col] = num;

				if (SolveSudoku(grid))
					return true;
				//backtrack
				grid[row][col] = 0;
			}
		}
	}
	else
	{
		for (int num = dimension; num >= 1; num--)
		{
			if (isSafe(grid, row, col, num))
			{
				grid[row][col] = num;

				if (SolveSudoku(grid))
					return true;
				//backtrack
				grid[row][col] = 0;
			}
		}
	}
	
	return false; 
}

bool FindUnassignedLocation(int** grid, int &row, int &col)
{
	for (row = 0; row < dimension; row++)
		for (col = 0; col < dimension; col++)
		if (grid[row][col] == 0)
			return true;
	return false;
}

bool UsedInRow(int** grid, int row, int num)
{
	for (int col = 0; col < dimension; col++)
	if (grid[row][col] == num)
		return true;
	return false;
}

bool UsedInCol(int** grid, int col, int num)
{
	for (int row = 0; row < dimension; row++)
	if (grid[row][col] == num)
		return true;
	return false;
}

bool UsedInBox(int** grid, int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < sqrt(dimension); row++)
	for (int col = 0; col < sqrt(dimension); col++)
	if (grid[row + boxStartRow][col + boxStartCol] == num)
		return true;
	return false;
}

bool isSafe(int** grid, int row, int col, int num)
{
	int temp = sqrt(dimension);
	return !UsedInRow(grid, row, num) &&
		!UsedInCol(grid, col, num) &&
		!UsedInBox(grid, row - row % temp, col - col % temp, num);
}

void printGrid(int** grid)
{
	for (int row = 0; row < dimension; row++)
	{
		for (int col = 0; col < dimension; col++)
			printf("%d ", grid[row][col]);
		printf("\n");
	}
}

int estimate_Sudoku(int** grid)
{
	ListNode promChildren;
	int row = 0, col = 0;
	int n = 1, prod = 1, nodeCount = 1;
	while (n != 0 && FindUnassignedLocation(grid, row, col))
	{
		prod *= n;
		nodeCount += (prod* dimension);
		n = 0;
		for (int i = 0; i < dimension; i++)
		{
			if (isSafe(grid,row, col, i))
			{
				n++;
				promChildren.addAppend(i);
			}
		}
		if (n != 0)
		{
			grid[row][col] = promChildren.elementAt(rand() % promChildren.getLength());
			//printGrid(grid);
		}
	}
	return nodeCount;
}

int main()
{

	srand(time(0));
	std::cin >> dimension;
	int** grid = new int*[dimension];
	int** grid1 = new int*[dimension];
	for (int i = 0; i<dimension; i++)
	{
		grid[i] = new int[dimension];
		grid1[i] = new int[dimension];
		for (int j = 0; j<dimension; j++)
		{
			std::string temp;
			std::cin >> temp;
			std::istringstream convertor(temp);
			convertor >> grid[i][j];
			grid1[i][j] = grid[i][j];
		}
	}
	std::cout << "number of nodes estimated using the monte carlo method: " << estimate_Sudoku(grid1) << std::endl;
	if (SolveSudoku(grid) == true)
		printGrid(grid);
	else
		printf("No solution exists");


	delete[] grid;
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}
