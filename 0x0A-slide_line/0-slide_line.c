#include "slide_line.h"

/**
 * go_left - pushes line left
 * @line: list of integers
 * @size: size of list
 */
void go_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (line[i] == 0 && line[j] != 0)
			{
				line[i] = line[j];
				line[j] = 0;
				i--;
				break;
			}
			if (line[i] == line[j] && line[i] != 0)
			{
				line[i] *= 2;
				line[j] = 0;
				break;
			}
			else if (line[j] != 0 && line[i + 1] == 0)
			{
				line[i + 1] = line[j];
				line[j] = 0;
				break;
			}
		}
	}
}

/**
 * go_right - pushes line right
 * @line: list of integers
 * @size: size of list
 */
void go_right(int *line, size_t size)
{
	size_t i, j;

	for (i = 1; i <= size; i++)
	{
		for (j = i + 1; j <= size; j++)
		{
			if (line[size - i] == 0 && line[size - j] != 0)
			{
				line[size - i] = line[size - j];
				line[size - j] = 0;
				i--;
				break;
			}
			if (line[size - i] == line[size - j] && line[size - i] != 0)
			{
				line[size - i] *= 2;
				line[size - j] = 0;
				break;
			}
			else if (line[size - j] != 0 && line[size - (i + 1)] == 0)
			{
				line[size - (i + 1)] = line[size - j];
				line[size - j] = 0;
				break;
			}
		}
	}
}
/**
 * slide_line - slides line to left or right
 * @line: list of numbers to slide
 * @size: size of list
 * @direction: direction to slide
 *
 * Return: 1 if successful or 0 if fails
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || !size)
		return (0);
	if (direction == 76)
		go_left(line, size);
	else if (direction == 82)
		go_right(line, size);
	else
		return (0);
	return (1);
}
