#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

int pond[100];
int n, w;
int sum;
int max;

int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &n);
	scanf("%d", &w);
	
	for (int i = 0; i < n; i++) 
		scanf("%d", &pond[i]);
	
	for (int i = 0; i < n - w + 1; i++) {
		sum = 0;
		for (int j = 0; j < w; j++)
			sum += pond[i + j];
		if (sum > max) max = sum;
	}

	printf("%d\n", max);
}