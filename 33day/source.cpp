#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include <stdio.h>

int n;

void solve(int n) {
	if (n % 10 != 0)			//����� ���� 0�� �ƴ� ��
		printf("%d", n % 10);	//���
	if (n != 0)					//���� ���� �ƴ϶��
		solve(n / 10);
}

void main() {
	freopen("sample.txt", "r", stdin);

	scanf("%d", &n);

	solve(n);
	printf("\n");
}