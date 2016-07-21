#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include <stdio.h>

int n;
int min = 0x7fffffff;
int arr[10][10];
int chk[10];

void solve(int a, int sum) {
	if (a == n) {							//n���� ��� Ž���ߴٸ�
		if (min > sum)
			min = sum;
		return;
	}
	for (int j = 0; j < n; j++) {
		if (chk[j] == 0) {					//üũ���� ���� ���̶��
			chk[j] = 1;						//üũ
			solve(a + 1, sum + arr[a][j]);	//����
			chk[j] = 0;						//üũ����
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