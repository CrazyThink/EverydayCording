#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

char a[1000];		//최대1000자의 문자열을 입력받는 배열
int b[50];			//알파벳을 저장할 변수

void main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int count = 0;
		int c = 0;			//홀수 알파벳 여부 판단
		memset(a, 0, 1000);	//a배열을 전부 0으로 초기화
		memset(b, 0, 200);	//b배열을 전부 0으로 초기화
		scanf("%s", a);
		for (int i = 0; a[i]; i++) {
			if (a[i] >= 'a') a[i] -= 32;//소문자를 대문자로
			b[a[i] - 'A']++;			//해당 알파벳의 개수 증가
		}
		for (int i = 0; i<50; i++) {
			count += b[i] / 2;			//알파벳의 개수 증가
			if (b[i] % 2 == 1) c = 1;	//홀수 개수인 알파벳이 하나라도 있다면
		}
		printf("%d\n", count * 2 + c);
	}
}