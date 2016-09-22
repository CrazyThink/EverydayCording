#include "kdy_poly.h"

void main(){
	printf("\n************* [ 2016년도 2학기 자료구조 실습과제 2 ] *************\n\n");
	printf("                         1. 다항식 계산\n\n");

	kdy_Polynomial a, b, c, d, e;
	a.kdy_read("A"); // 첫 번째 다항식을 입력 받음
	b.kdy_read("B"); // 두 번째 다항식을 입력 받음

	printf("\n******************************************************************\n\n");

	a.kdy_display("    display(A) = ");
	b.kdy_display("    display(B) = ");

	a.kdy_display2("   display2(A) = ");
	b.kdy_display2("   display2(B) = ");
	

	c.kdy_add (a, b);  // 두 다항식의 합 계산
	c.kdy_display2("      A + B  = ");
	c.kdy_trim();
	c.kdy_display2(" Trim(A + B) = ");

	d.kdy_sub (a, b);  // 두 다항식의 차 계산
	d.kdy_display2("      A - B  = ");
	d.kdy_trim();
	d.kdy_display2(" Trim(A - B) = ");

	e.kdy_mult (a, b); // 두 다항식의 곱 계산
	e.kdy_display2("      A * B  = ");
	e.kdy_trim();
	e.kdy_display2(" Trim(A * B) = ");
	 
	getchar();
	getchar();
}