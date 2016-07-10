#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include <stdio.h>

int cols[9];			//�� �˻�
int up[18];				//������ �밢�� �˻�
int down[18];			//������ �밢�� �˻�
int n;
int count;

void solve(int row) {
	if (n == row) {		//������ �࿡ ���� �����ٸ�
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