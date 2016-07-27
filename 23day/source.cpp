#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
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
			if (sum + money[n - i] <= m)				//큰 동전부터 거스름돈을 넘지 않도록 거슬러 준다
				sum += money[n - i], count++, i = 1;	//거슬러 주고, 카운트 증가, 다시 큰 동전부터 반복

	printf("%d\n", count);
}