#include <stdio.h>

int main()
{
	int i;
	int temp = 0;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	for (i = 0; i < 10; i++)
	{
		int min = 9999;
		int index = 0;
		for (int j = i; j < 10; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index = j;
			}
		}
		if (array[i] > min)
		{
			temp = array[i];
			array[i] = min;
			array[index] = temp;
		}

	}

	for (int i = 0; i < 10; i++)
		printf("%d ", array[i]);


}