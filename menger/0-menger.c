#include "menger.h"
#include <math.h>

/**
 * is_empty - Checks if a position should be empty in a Menger sponge
 * @x: X coordinate
 * @y: Y coordinate
 *
 * Return: 1 if position is empty, 0 if filled
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
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
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
