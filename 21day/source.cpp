#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

int n;
int integer[100];
int sum, max;

int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
			scanf("%d", &integer[i]);

	for(int i = 0; i < n; i++)			//탐색 시작지점
		for (int j = i; j < n; j++) {	//탐색 종료지점
			sum = 0;
			for (int k = i; k <= j; k++)//합 구간
				sum += integer[k];
			if (sum > max)	max = sum;	//최댓값이면 갱신
		}

	printf("%d\n", max);
}