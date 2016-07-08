#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

int integer[1000001];

int main(){
	freopen("sample.txt", "r", stdin);

	int n;
	int search;
	int top, bot, mid;

	scanf("%d", &n);
	for (int i = 1; i<= n; i++)
		scanf("%d", &integer[i]);
	scanf("%d", &search);

	top = n+1, bot = 1;
	mid = (top + bot) / 2;
	
	while (top != bot) {
		if (search >= integer[mid]) //lower bound와의 차이점
			bot = mid + 1;
		else
			top = mid;
		mid = (top + bot) / 2;
	}
	printf("%d\n", mid);
}