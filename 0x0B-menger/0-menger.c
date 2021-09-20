#include "menger.h"
/**
 * menger - function that draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 * If level is lower than 0, your function must do nothing
 */

void menger(int level)
{
	int i, j, high, width, print = 1, size;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			high = i, width = j;
			while (print)
			{
				if (high % 3 == 1 && width % 3 == 1)
				{
					printf(" ");
					break;
				}
				if (high == 0 || width == 0)
				{
					printf("#");
					break;
				}
				high = high / 3;
				width = width / 3;
			}
		}
		printf("\n");
	}
}
