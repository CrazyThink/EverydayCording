#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include <stdio.h>

int n, w;
int wi[100], vi[100];
int max;

void solve(int a, int now_wi, int now_vi){
	if (max < now_vi)						//������ �ִ��� ����
		max = now_vi;

	for (int i = a; i < n; i++)				//���� ǰ�� �ߺ��� �Ұ����ϵ���
		if (now_wi + wi[i] <= w)			//���� �̳��� ��
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