#include "kdy_sumAlgorithm.h"

void main() {
	kdy_sumAlgorithm A;
	int n;
	clock_t point[4];

	printf("┌──────────────────────────────┐\n");
	printf("│1부터 n까지의 합을 3가지 알고리즘으로 실행시간을 나타냅니다.│\n");
	printf("└──────────────────────────────┘\n");

	printf("\n1. 프로그램의 실제 시간 측정\n");
	for(int i = 1; i <= 50; i+=1){
		point[0] = clock();
		A.kdy_sumAlgotithmA(i);
		point[1] = clock();
		A.kdy_sumAlgotithmB(i);
		point[2] = clock();
		A.kdy_sumAlgotithmC(i);
		point[3] = clock();

		printf("n = %2d 일때\t", i);
		printf("알고리즘A : %.3f\t", (double)(point[1] - point[0]) / CLOCKS_PER_SEC);
		printf("알고리즘B : %.3f\t", (double)(point[2] - point[1]) / CLOCKS_PER_SEC);
		printf("알고리즘C : %.3f\n", (double)(point[3] - point[2]) / CLOCKS_PER_SEC);
	}
}