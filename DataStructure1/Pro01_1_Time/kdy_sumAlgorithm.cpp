#include "kdy_sumAlgorithm.h"

void main() {
	kdy_sumAlgorithm A;
	int n;
	clock_t point[4];

	printf("����������������������������������������������������������������\n");
	printf("��1���� n������ ���� 3���� �˰������� ����ð��� ��Ÿ���ϴ�.��\n");
	printf("����������������������������������������������������������������\n");

	printf("\n1. ���α׷��� ���� �ð� ����\n");
	for(int i = 1; i <= 50; i+=1){
		point[0] = clock();
		A.kdy_sumAlgotithmA(i);
		point[1] = clock();
		A.kdy_sumAlgotithmB(i);
		point[2] = clock();
		A.kdy_sumAlgotithmC(i);
		point[3] = clock();

		printf("n = %2d �϶�\t", i);
		printf("�˰���A : %.3f\t", (double)(point[1] - point[0]) / CLOCKS_PER_SEC);
		printf("�˰���B : %.3f\t", (double)(point[2] - point[1]) / CLOCKS_PER_SEC);
		printf("�˰���C : %.3f\n", (double)(point[3] - point[2]) / CLOCKS_PER_SEC);
	}
}