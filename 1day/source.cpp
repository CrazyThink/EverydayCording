#define _CRT_SECURE_NO_WARNINGS //scanf ���� ����
#include<stdio.h>

void main() {
	freopen("sample.txt", "r", stdin);

	int num;		//�Է¹��� ������ ����
	int integer;	//�Էµ� ����
	int max=0;		//�ִ밪
	int count;		//�� ��°���� ����

	scanf("%d", &num);					//���� �� ���� ���� �� �Է�
	for (int i = 0; i < num; i++) {		
		scanf("%d", &integer);			//���� �Է�
		if (max < integer)				//�Է¹��� ���ڰ� �ִ밪���� ũ�ٸ�
			max = integer, count = i+1;	//max�� integer����, count�� �� ��°���� ����
	}
	printf("%d\n%d\n", max, count);		//�ִ밪�� �ִ밪�� ��ġ ���
}