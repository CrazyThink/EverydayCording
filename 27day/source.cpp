#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include <stdio.h>

int H, W;
int count;

void solve(int h, int w){
	if (H == h && W == w) {									//�����ߴٸ�
		count++;											//ī��Ʈ ����
		return;
	}
	if (h + 1 <= H)											//���� ����
		solve(h + 1, w);
	if (w + 1 <= W && (double)H / W <= (double)h / (w + 1))	//���� ����
		solve(h, w + 1);
}


int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &H);
	scanf("%d", &W);

	solve(0, 0);

	printf("%d\n", count);
}