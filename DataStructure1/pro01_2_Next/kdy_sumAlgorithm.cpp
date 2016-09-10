#include "kdy_sumAlgorithm.h"

void main() {
	kdy_sumAlgorithm A;
	int n;
	clock_t point[3];

	printf("┌──────────────────────────────┐\n");
	printf("│1부터 n까지의 합을 3가지 알고리즘으로 실행시간을 나타냅니다.│\n");
	printf("└──────────────────────────────┘\n");

	printf("\n2. 시간 복잡도가 다른 두 알고리즘의 비교\n");
	for(int i = 10; i <= 500; i+=10){
		point[0] = clock();
		A.kdy_sumAlgotithmA(i);
		point[1] = clock();
		A.kdy_sumAlgotithmB(i);
		point[2] = clock();

		printf("n = %3d 일때\t", i);
		printf("알고리즘A : %.3f\t", (double)(point[1] - point[0]) / CLOCKS_PER_SEC);
		printf("알고리즘B : %.3f\n", (double)(point[2] - point[1]) / CLOCKS_PER_SEC);
	}
}