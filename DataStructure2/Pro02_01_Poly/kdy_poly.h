#include <stdio.h>
#define MAX_DEGREE 80

class kdy_Polynomial {
	int degree;					//차수
	float coef[MAX_DEGREE];		//계수
public:
	kdy_Polynomial() : coef() { degree = 0; }	//멤버 초기화

	void kdy_read(char *str=" Poly = "){		//값을 읽음
		printf("다항식 %s의 최고차수 입력 : ", str);
		scanf("%d", &degree);
		printf("각 항의 계수를 입력하시오 (총 %d개): ", degree+1);
		for(int i = 0; i <= degree; i++)
			scanf("%f", coef + i);
	}

	void kdy_display(char *str=" Poly = "){		//편집 전 표시방식
		printf("%s", str);
		for(int i = 0; i < degree; i++)
			printf("(%.2f x^%d) + ", coef[i], degree - i);
		printf("(%.2f)\n", coef[degree]);
	}

	void kdy_display2(char *str=" Poly = "){	//편집 후 표시방식
		printf("%s", str);

		for(int i = 0; i < degree; i++){
			if(coef[i] != 0 || i == 0){
				if(coef[i] == -1)				//계수가 -1 일때
					printf("- x^%d ",  degree-i);
				else if(coef[i] == 1)			//계수가 1 일때
					printf(" x^%d ",  degree-i);
				else if(coef[i] < 0)			//계수가 음수 일때
					printf("-%5.2f x^%d ", -coef[i], degree-i);
				else							//계수가 양수 일때
					printf("%5.2f x^%d ", coef[i], degree-i);
			}
			if(coef[i + 1] > 0)
					printf("+");				//양수 일때 부호 표시
		}
		if(coef[degree] < 0)					//음수 일때
			printf("-%5.2f\n", -coef[degree]);
		else if(coef[degree] > 0)				//양수 일때
			printf("%5.2f\n", coef[degree]);
		else if(degree == 0)					//0 일때
			printf(" 0.00\n");
		else									//0 일때
			printf("\n");
	}

	void kdy_trim(){							//최고차수를 0으로 만들지 않음
		int temp = 0;
		bool flag = false;
		for(int i = 0; i <= degree; i++){
			if(coef[i] != 0 && flag == false)	//0이 아닐때의 차수를 저장
				temp = i, flag = true;
			coef[i-temp] = coef[i];			//계수 이동
		}
		this -> degree -= temp;					//차수 변경
		if(flag == false)						//모든 항이 0이라면
			kdy_isZero();						//차수를 0으로
	}

	void kdy_add(kdy_Polynomial a, kdy_Polynomial b){	//합
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

	void kdy_sub(kdy_Polynomial a, kdy_Polynomial b){	//차
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

	void kdy_mult(kdy_Polynomial a, kdy_Polynomial b){	//곱
		this -> degree = a.degree + b.degree;
		for(int i = 0; i <= a.degree; i++)
			for(int j = 0; j <= b.degree; j++)
				coef[i + j] += a.coef[i] * b.coef[j];
	}

	bool kdy_isZero() { return degree = 0; }			//차수가 0인지 검사
	void kdy_negate(){									//다항식 부호 반전
		for(int i = 0; i < degree; i++)
			coef[i] = -coef[i];
	}
};