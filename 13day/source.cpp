#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include <stdio.h>

int x[4] = {1, 1, 1, 0};
int y[4] = {-1, 0, 1, 1};
int go[19][19];
int win;
int X, Y;
int count;


int main(){
	freopen("sample.txt", "r", stdin);


	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			scanf("%d", &go[i][j]);

	for(int i = 0; i < 19; i++)									//y�� Ž��
		for(int j = 0; j < 19; j++)								//x�� Ž��
			if (go[i][j])										//0�� �ƴ϶��
				for (int k = 0; k < 4; k++)						//4���� Ž��
					if (go[i - y[k]][j - x[k]] != go[i][j]) {	//Ž�� ���� ������ ��ġ�� ���� ���� ���� �������� ���� ��
						for (int tx = 0, ty = 0; go[i][j] == go[i + ty][j + tx]; tx += x[k], ty += y[k])
							count++;							//Ž�� �������� ��ǥ�� �ϳ��� ������Ű�� ���� ���� ������ ���� ī��Ʈ ����
						if (count == 5)							//���� ���� 5����� ��ġ�� �̱䵹�� �����ϰ�, ��� �ݺ����� ��������
							X = j + 1, Y = i + 1, win = go[i][j], i = 20, j = 20, k = 5;
						count = 0;								//������ �ƴ϶�� ī��Ʈ �ʱ�ȭ
					}
	
	if (win)													//�̱䵹�� �ִٸ� �̱䵹�� ��ǥ ���
		printf("%d\n%d %d\n", win, X, Y);
	else														//�ºΰ� ���� �ʾҴٸ� 0���
		printf("%d\n", win);
}