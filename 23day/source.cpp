#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include <stdio.h>

int m, n;
int money[10];
int sum, count;

int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &m);
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
			scanf("%d", &money[i]);

		for (int i = 1; i <= n; i++)
			if (sum + money[n - i] <= m)				//ū �������� �Ž������� ���� �ʵ��� �Ž��� �ش�
				sum += money[n - i], count++, i = 1;	//�Ž��� �ְ�, ī��Ʈ ����, �ٽ� ū �������� �ݺ�

	printf("%d\n", count);
}