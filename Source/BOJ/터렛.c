#include <stdio.h>
#include <math.h>

int main()
{
	int x1 = -1, y1 = -1; // 1��° ��ǥ 
	int x2 = -1, y2 = -1; // 2���� ��ǥ
	int r1 = -1, r2 = -1;	// �� ���� ������
	int result = 0; // ���
	double d = 0; // �� ���� ������ �Ÿ�
	int T;	 // �׽�Ʈ���̽�

	scanf(" %d", &T);

	for (; 0 < T; T--)
	{
		scanf(" %d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		if (d == 0)
			if (r1 == r2)
				result = -1;
			else
				result = 0;
		else
			if (abs(r1 - r2) < d && d < r1 + r2)
				result = 2;
			else if (abs(r1 - r2) == d || (r1 + r2) == d)
				result = 1;
			else
				result = 0;

		printf("%d \n", result);
	}

	return 0;
}