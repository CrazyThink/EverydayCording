#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include <stdio.h>

int n, m;
int cheese[100][100];
int time;
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &n);
	scanf("%d", &m);

	for(int i = 0; i < n; i++ )
		for (int j = 0; j < m; j++)
			scanf("%d", &cheese[i][j]);

	for (int done = 0; ; time++) {						//ġ� �� ���������� �ð� ����
		for (int i = 0; i < n; i++)						//�� Ž��
			for (int j = 0; j < m; j++)					//�� Ž��
				if (cheese[i][j] == 1) {				//ġ� �ִٸ�
					done++;								//���� ġ�� ���� ����
					for (int k = 0, count = 0; k < 4; k++) {
						if (cheese[i + y[k]][j + x[k]] == 0 || (cheese[i + y[k]][j + x[k]] > 1 && cheese[i + y[k]][j + x[k]] < time + 2))
							count++;					//�ܺ� ���ⷮ ����
						if (count >= 2) {				//�ܺ� ���Ⱑ �� ���� �̻� ��´ٸ�
							cheese[i][j] = time + 2;	//ġ� ����
							break;
						}
					}
				}
		if (done == 0)	//ġ� �� �̻� �������� �ʴٸ�
			break;		//�ݺ����� ��������
		done = 0;		//���� ġ�� ���� �ʱ�ȭ
	}

	printf("%d\n", time);
}