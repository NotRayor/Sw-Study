#include <stdio.h>
#include <string.h>

int main()
{
	char week[10];
	int x, y; // x¿ù yÀÏ
	int day = 0;

	scanf("%d %d", &x, &y);

	for (int i = 1; i < x; i++)
	{
		switch (i)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			day += 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day += 30;
			break;
		case 2:
			day += 28;
			break;
		default:
			day += 0;
		}
	}
	day += y;
	day %= 7;

	switch (day)
	{
	case 0:
		strcpy(week, "SUN");
		break;
	case 1:
		strcpy(week, "MON");
		break;
	case 2:
		strcpy(week, "TUE");
		break;
	case 3:
		strcpy(week, "WED");
		break;
	case 4:
		strcpy(week, "THU");
		break;
	case 5:
		strcpy(week, "FRI");
		break;
	case 6:
		strcpy(week, "SAT");
		break;
	}

	printf("%s", week);
}