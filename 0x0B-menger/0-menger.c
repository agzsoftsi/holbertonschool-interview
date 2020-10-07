#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Depth of Menger Sponge to print
 * Return: None
 */

void menger(int level)
{
	int axisX, axisY, d, dim = 1;

	if (level >= 0)
	{
		for (axisX = 0; axisX < level; axisX++)
		{
			dim *= 3;
		}

		for (axisX = 0; axisX < dim; axisX++)
		{
			for (axisY = 0; axisY < dim; axisY++)
			{
				for (d = dim / 3; d > 0; d /= 3)
				{
					if ((axisX % (d * 3)) / d == 1 && (axisY % (d * 3)) / d == 1)
						break;
				}
				if (d)
				{
					printf(" ");
				} else
				{
					printf("#");
				}
			}
			printf("\n");
		}
	}
}
