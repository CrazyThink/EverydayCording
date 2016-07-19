#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

int now, goal;
int count;


int main(){
	freopen("sample.txt", "r", stdin);

	scanf("%d", &now);
	scanf("%d", &goal);

	while (now != goal) {
		if (goal - now >= 8)
			now += 10;
		else if (goal - now >= 3)
			now += 5;
		else if (goal - now > 0)
			now += 1;

		else if (goal - now <= -8)
			now -= 10;
		else if (goal - now <= -3)
			now -= 5;
		else if (goal - now < 0)
			now -= 1;

		count++;
	}
	printf("%d\n", count);
}