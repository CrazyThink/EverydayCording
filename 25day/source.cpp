#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

int n, w;
int wi[100], vi[100];
int max;

void solve(int a, int now_wi, int now_vi){
	if (max < now_vi)						//지금이 최대라면 갱신
		max = now_vi;

	for (int i = a; i < n; i++)				//같은 품목 중복이 불가능하도록
		if (now_wi + wi[i] <= w)			//무게 이내일 때
			solve(a + 1, now_wi + wi[i], now_vi + vi[i]);
}


int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &n);
	scanf("%d", &w);

	for (int i = 0; i < n; i++) {
		scanf("%d", &wi[i]);
		scanf("%d", &vi[i]);
	}
	solve(0, 0, 0);

	printf("%d\n", max);
}