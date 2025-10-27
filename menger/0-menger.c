#include "menger.h"
#include <math.h>

/**
 * is_empty - Determines if a coordinate position should be empty
 * The function checks if both x and y coordinates have the middle digit (1)
 * in base 3 representation at any level, which means the position is empty.
 *
 * @x: X coordinate of the position to check
 * @y: Y coordinate of the position to check
 *
 * Return: 1 if position should be empty, 0 if it should be filled
 */
static int is_empty(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}
	return (0);
}

/**
 * menger - Prints a 2D Menger Sponge fractal of the specified level
 * This function draws a Menger sponge pattern where each level N is a 3x3
 * grid of level N-1 sponges, except for the center which is empty.
 *
 * @level: The recursion level of the Menger Sponge (0 being a single #)
 */
void menger(int level)
{
	int i, j, size;

	if (level < 0)
		return;

	if (level == 0)
	{
		printf("#\n");
		return;
	}

	size = (int)pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (is_empty(i, j))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}