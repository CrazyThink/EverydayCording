#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
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

	for (int done = 0; ; time++) {						//치즈가 다 녹을때까지 시간 증가
		for (int i = 0; i < n; i++)						//행 탐색
			for (int j = 0; j < m; j++)					//열 탐색
				if (cheese[i][j] == 1) {				//치즈가 있다면
					done++;								//남은 치즈 개수 증가
					for (int k = 0, count = 0; k < 4; k++) {
						if (cheese[i + y[k]][j + x[k]] == 0 || (cheese[i + y[k]][j + x[k]] > 1 && cheese[i + y[k]][j + x[k]] < time + 2))
							count++;					//외부 공기량 증가
						if (count >= 2) {				//외부 공기가 두 군데 이상 닿는다면
							cheese[i][j] = time + 2;	//치즈를 녹임
							break;
						}
					}
				}
		if (done == 0)	//치즈가 더 이상 남아있지 않다면
			break;		//반복문을 빠져나옴
		done = 0;		//남은 치즈 개수 초기화
	}

	printf("%d\n", time);
}