#define _CRT_SECURE_NO_WARNINGS //scanf 오류 제거
#include <stdio.h>

long long int n;
long long int sum;

void main() {
	freopen("sample.txt", "r", stdin);

	scanf("%lld", &n);

	long long int i;
	for (i = 1; i*i < n; i++)	//n의 제곱근 전까지 반복
		if (n%i == 0)			//n의 약수라면
			sum += i + n/i; 
	if (i*i == n)				//n의 제곱근이 약수라면
		sum += i;				//한 번만 더함

	printf("%lld\n", sum);
}