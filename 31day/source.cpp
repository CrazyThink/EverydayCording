#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include <stdio.h>

long long int n;
long long int sum;

void main() {
	freopen("sample.txt", "r", stdin);

	scanf("%lld", &n);

	long long int i;
	for (i = 1; i*i < n; i++)	//n�� ������ ������ �ݺ�
		if (n%i == 0)			//n�� ������
			sum += i + n/i; 
	if (i*i == n)				//n�� �������� ������
		sum += i;				//�� ���� ����

	printf("%lld\n", sum);
}