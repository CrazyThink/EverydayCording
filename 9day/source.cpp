#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

int integer;
int max;
int row, col;

int main(){
	freopen("sample.txt", "r", stdin);

	for(int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &integer);
			if (integer > max)
				max = integer, row = i + 1, col = j + 1;
		}

	printf("%d\n%d %d\n", max, row, col);
}