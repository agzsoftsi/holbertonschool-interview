#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
void sum_grids(int grid1[3][3], int grid2[3][3]);
void change_grids(int grid1[3][3]);
int check_grids(int grid1[3][3]);

#endif
