#include "kdy_sumAlgorithm.h"

void main() {
	kdy_sumAlgorithm A;
	int n;
	clock_t point[3];

	printf("����������������������������������������������������������������\n");
	printf("��1���� n������ ���� 3���� �˰������� ����ð��� ��Ÿ���ϴ�.��\n");
	printf("����������������������������������������������������������������\n");

	printf("\n2. �ð� ���⵵�� �ٸ� �� �˰����� ��\n");
	for(int i = 10; i <= 500; i+=10){
		point[0] = clock();
		A.kdy_sumAlgotithmA(i);
		point[1] = clock();
		A.kdy_sumAlgotithmB(i);
		point[2] = clock();

		printf("n = %3d �϶�\t", i);
		printf("�˰���A : %.3f\t", (double)(point[1] - point[0]) / CLOCKS_PER_SEC);
		printf("�˰���B : %.3f\n", (double)(point[2] - point[1]) / CLOCKS_PER_SEC);
	}
}