#include <stdio.h>
#define MAX_DEGREE 80

class kdy_Polynomial {
	int degree;					//����
	float coef[MAX_DEGREE];		//���
public:
	kdy_Polynomial() : coef() { degree = 0; }	//��� �ʱ�ȭ

	void kdy_read(char *str=" Poly = "){		//���� ����
		printf("���׽� %s�� �ְ����� �Է� : ", str);
		scanf("%d", &degree);
		printf("�� ���� ����� �Է��Ͻÿ� (�� %d��): ", degree+1);
		for(int i = 0; i <= degree; i++)
			scanf("%f", coef + i);
	}

	void kdy_display(char *str=" Poly = "){		//���� �� ǥ�ù��
		printf("%s", str);
		for(int i = 0; i < degree; i++)
			printf("(%.2f x^%d) + ", coef[i], degree - i);
		printf("(%.2f)\n", coef[degree]);
	}

	void kdy_display2(char *str=" Poly = "){	//���� �� ǥ�ù��
		printf("%s", str);

		for(int i = 0; i < degree; i++){
			if(coef[i] != 0 || i == 0){
				if(coef[i] == -1)				//����� -1 �϶�
					printf("- x^%d ",  degree-i);
				else if(coef[i] == 1)			//����� 1 �϶�
					printf(" x^%d ",  degree-i);
				else if(coef[i] < 0)			//����� ���� �϶�
					printf("-%5.2f x^%d ", -coef[i], degree-i);
				else							//����� ��� �϶�
					printf("%5.2f x^%d ", coef[i], degree-i);
			}
			if(coef[i + 1] > 0)
					printf("+");				//��� �϶� ��ȣ ǥ��
		}
		if(coef[degree] < 0)					//���� �϶�
			printf("-%5.2f\n", -coef[degree]);
		else if(coef[degree] > 0)				//��� �϶�
			printf("%5.2f\n", coef[degree]);
		else if(degree == 0)					//0 �϶�
			printf(" 0.00\n");
		else									//0 �϶�
			printf("\n");
	}

	void kdy_trim(){							//�ְ������� 0���� ������ ����
		int temp = 0;
		bool flag = false;
		for(int i = 0; i <= degree; i++){
			if(coef[i] != 0 && flag == false)	//0�� �ƴҶ��� ������ ����
				temp = i, flag = true;
			coef[i-temp] = coef[i];			//��� �̵�
		}
		this -> degree -= temp;					//���� ����
		if(flag == false)						//��� ���� 0�̶��
			kdy_isZero();						//������ 0����
	}

	void kdy_add(kdy_Polynomial a, kdy_Polynomial b){	//��
		if(a.degree > b.degree){
			*this = a;
			for(int i = 0; i <= b.degree; i++)
				coef[i + degree - b.degree] += b.coef[i];
		}
		else{
			*this = b;
			for(int i = 0; i <= a.degree; i++)
				coef[i + degree - a.degree] += a.coef[i];
		}
	}

	void kdy_sub(kdy_Polynomial a, kdy_Polynomial b){	//��
		if(a.degree >= b.degree){
			*this = a;
			for(int i = 0; i <= b.degree; i++)
				coef[i + degree - b.degree] -= b.coef[i];
		}
		else{
			*this = b;
			for(int i = 0; i <= a.degree; i++)
				coef[i + degree - a.degree] -= a.coef[i];
			kdy_negate();
		}
	}

	void kdy_mult(kdy_Polynomial a, kdy_Polynomial b){	//��
		this -> degree = a.degree + b.degree;
		for(int i = 0; i <= a.degree; i++)
			for(int j = 0; j <= b.degree; j++)
				coef[i + j] += a.coef[i] * b.coef[j];
	}

	bool kdy_isZero() { return degree = 0; }			//������ 0���� �˻�
	void kdy_negate(){									//���׽� ��ȣ ����
		for(int i = 0; i < degree; i++)
			coef[i] = -coef[i];
	}
};