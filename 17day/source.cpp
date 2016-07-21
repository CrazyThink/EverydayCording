#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

int n;
int min = 0x7fffffff;
int arr[10][10];
int chk[10];

void solve(int a, int sum) {
	if (a == n) {							//n개를 모두 탐색했다면
		if (min > sum)
			min = sum;
		return;
	}
	for (int j = 0; j < n; j++) {
		if (chk[j] == 0) {					//체크하지 않은 열이라면
			chk[j] = 1;						//체크
			solve(a + 1, sum + arr[a][j]);	//진입
			chk[j] = 0;						//체크해제
		}
	}
}

int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	solve(0, 0);

	printf("%d\n", min);
}