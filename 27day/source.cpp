#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

int H, W;
int count;

void solve(int h, int w){
	if (H == h && W == w) {									//도착했다면
		count++;											//카운트 증가
		return;
	}
	if (h + 1 <= H)											//범위 제한
		solve(h + 1, w);
	if (w + 1 <= W && (double)H / W <= (double)h / (w + 1))	//범위 제한
		solve(h, w + 1);
}


int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &H);
	scanf("%d", &W);

	solve(0, 0);

	printf("%d\n", count);
}