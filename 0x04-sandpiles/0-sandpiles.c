#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: sandpiles stable
 * @grid2: sandpiles stable
 * Return: void function
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	sum_grids(grid1, grid2);

	while (!check_grids(grid1))
	{
		print_grid(grid1);
		change_grids(grid1);
	}

}


/**
 * sum_grids - computes the sum of two sandpiles
 * @grid1: sandpiles stable
 * @grid2: sandpiles stable
 * Return: void function
 */
void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}


/**
 * check_grids - computes the sum of two sandpiles
 * @grid1: sandpiles stable
 * Return: void function
 */
int check_grids(int grid1[3][3])
{

	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				return (0);
	return (1);
}

/**
 * print_grid - computes the sum of two sandpiles
 * @grid: sandpiles stable
 * Return: void function
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * change_grids - computes the sum of two sandpiles
 * @grid1: sandpiles stable
 * Return: void function
 */
void change_grids(int grid1[3][3])
{
	int i;
	int j;
	int new_grid[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			new_grid[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					new_grid[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					new_grid[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					new_grid[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					new_grid[i][j + 1] += 1;
			}
		}
	}

	sum_grids(grid1, new_grid);
}
