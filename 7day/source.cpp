#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

int cols[9];			//열 검사
int up[18];				//오르막 대각선 검사
int down[18];			//내리막 대각선 검사
int n;
int count;

void solve(int row) {
	if (n == row) {		//마지막 행에 퀸을 세웠다면
		count++;
		return;
	}
	for (int col = 0; col < n; col++)
		if (!cols[col] && !up[col + row] && !down[n + col - row]) {
			cols[col] = up[col + row] = down[n + col - row] = 1;
			solve(row + 1);
			cols[col] = up[col + row] = down[n + col - row] = 0;
		}
}

int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &n);
	solve(0);
	printf("%d\n", count);
}