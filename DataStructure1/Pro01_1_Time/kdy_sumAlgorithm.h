#include <stdio.h>
#include <time.h>
#include <windows.h>

class kdy_sumAlgorithm {
public:
	int kdy_sumAlgotithmA(int n) {		//sum=n(n+1)/2 공식사용
		Sleep(1);
		return n*(n + 1) / 2;
	}

	int kdy_sumAlgotithmB(int n) {		//sum=1+2+...+n
		int sum = 0;
		for (int i = 1; i <= n; i++){
			sum += i;
			Sleep(1);
		}
		return sum;
	}

	int kdy_sumAlgotithmC(int n) {		//sum=0+(1)+(1+1)+(1+1+1)+...+(1+1+...+1)
		int sum = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++){
				sum += 1;
				Sleep(1);
			}
		return sum;
	}
};