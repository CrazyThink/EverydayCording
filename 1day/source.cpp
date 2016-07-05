#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include<stdio.h>

void main() {
	freopen("sample.txt", "r", stdin);

	int num;		//입력받을 숫자의 개수
	int integer;	//입력된 숫자
	int max=0;		//최대값
	int count;		//몇 번째인지 저장

	scanf("%d", &num);					//숫자 몇 개를 비교할 지 입력
	for (int i = 0; i < num; i++) {		
		scanf("%d", &integer);			//숫자 입력
		if (max < integer)				//입력받은 숫자가 최대값보다 크다면
			max = integer, count = i+1;	//max에 integer저장, count에 몇 번째인지 저장
	}
	printf("%d\n%d\n", max, count);		//최대값과 최대값의 위치 출력
}