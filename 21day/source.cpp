#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include <stdio.h>

int n;
int integer[100];
int sum, max;

int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
			scanf("%d", &integer[i]);

	for(int i = 0; i < n; i++)			//Ž�� ��������
		for (int j = i; j < n; j++) {	//Ž�� ��������
			sum = 0;
			for (int k = i; k <= j; k++)//�� ����
				sum += integer[k];
			if (sum > max)	max = sum;	//�ִ��̸� ����
		}

	printf("%d\n", max);
}