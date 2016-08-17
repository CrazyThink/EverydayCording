#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

int n;

void solve(int n) {
	if (n % 10 != 0)			//출력할 수가 0이 아닐 때
		printf("%d", n % 10);	//출력
	if (n != 0)					//아직 끝이 아니라면
		solve(n / 10);
}

void main() {
	freopen("sample.txt", "r", stdin);

	scanf("%d", &n);

	solve(n);
	printf("\n");
}