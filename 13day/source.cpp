#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
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

	for(int i = 0; i < 19; i++)									//y줄 탐색
		for(int j = 0; j < 19; j++)								//x줄 탐색
			if (go[i][j])										//0이 아니라면
				for (int k = 0; k < 4; k++)						//4방향 탐색
					if (go[i - y[k]][j - x[k]] != go[i][j]) {	//탐색 시작 이전의 위치에 같은 색의 돌이 존재하지 않을 때
						for (int tx = 0, ty = 0; go[i][j] == go[i + ty][j + tx]; tx += x[k], ty += y[k])
							count++;							//탐색 방향으로 좌표를 하나씩 증가시키며 같은 돌이 나오는 동안 카운트 증가
						if (count == 5)							//같은 돌이 5개라면 위치와 이긴돌을 저장하고, 모든 반복문을 빠져나감
							X = j + 1, Y = i + 1, win = go[i][j], i = 20, j = 20, k = 5;
						count = 0;								//끝난게 아니라면 카운트 초기화
					}
	
	if (win)													//이긴돌이 있다면 이긴돌과 좌표 출력
		printf("%d\n%d %d\n", win, X, Y);
	else														//승부가 나지 않았다면 0출력
		printf("%d\n", win);
}