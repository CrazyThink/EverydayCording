#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

char a[1000];		//�ִ�1000���� ���ڿ��� �Է¹޴� �迭
int b[50];			//���ĺ��� ������ ����

void main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int count = 0;
		int c = 0;			//Ȧ�� ���ĺ� ���� �Ǵ�
		memset(a, 0, 1000);	//a�迭�� ���� 0���� �ʱ�ȭ
		memset(b, 0, 200);	//b�迭�� ���� 0���� �ʱ�ȭ
		scanf("%s", a);
		for (int i = 0; a[i]; i++) {
			if (a[i] >= 'a') a[i] -= 32;//�ҹ��ڸ� �빮�ڷ�
			b[a[i] - 'A']++;			//�ش� ���ĺ��� ���� ����
		}
		for (int i = 0; i<50; i++) {
			count += b[i] / 2;			//���ĺ��� ���� ����
			if (b[i] % 2 == 1) c = 1;	//Ȧ�� ������ ���ĺ��� �ϳ��� �ִٸ�
		}
		printf("%d\n", count * 2 + c);
	}
}