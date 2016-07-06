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

	top = n, bot = 1;
	mid = (top + bot) / 2;

	while (search != integer[mid]) {
		if (top - bot < 0) {
			mid = -1;
			break;
		}
		else if (search > integer[mid])
			bot = mid + 1;
		else
			top = mid - 1;
		mid = (top + bot) / 2;
	}
	printf("%d\n", mid);
}