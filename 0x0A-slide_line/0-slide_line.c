#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
	int *mplace_here = NULL;
	int *mleft = NULL;
	int *mright = NULL;

	if (direction == SLIDE_LEFT)
	{
		mplace_here = line;
		mleft = mplace_here;

		while (mleft < line + (size - 1))
		{
			while (*mleft == 0 && mleft < line + (size - 1))
			{
				mleft++;
			}
			mright = mleft + 1;
			while (mright < line + (size))
			{
				if (*mright == *mleft)
				{
					*mplace_here = *mleft * 2;
					if (mplace_here != mleft)
					{
						*mleft = 0;
					}
					*mright = 0;
					mplace_here++;
					break;
				}
				else
				{
					mright++;
				}
			}
			mleft++;
		}
		if (*(line + size - 1) && !*mplace_here)
		{
			*mplace_here = *(line + size - 1);
			*(line + size - 1) = 0;
		}
	}
	return (1);
}
