#include "kdy_poly.h"

void main(){
	printf("\n************* [ 2016�⵵ 2�б� �ڷᱸ�� �ǽ����� 2 ] *************\n\n");
	printf("                         1. ���׽� ���\n\n");

	kdy_Polynomial a, b, c, d, e;
	a.kdy_read("A"); // ù ��° ���׽��� �Է� ����
	b.kdy_read("B"); // �� ��° ���׽��� �Է� ����

	printf("\n******************************************************************\n\n");

	a.kdy_display("    display(A) = ");
	b.kdy_display("    display(B) = ");

	a.kdy_display2("   display2(A) = ");
	b.kdy_display2("   display2(B) = ");
	

	c.kdy_add (a, b);  // �� ���׽��� �� ���
	c.kdy_display2("      A + B  = ");
	c.kdy_trim();
	c.kdy_display2(" Trim(A + B) = ");

	d.kdy_sub (a, b);  // �� ���׽��� �� ���
	d.kdy_display2("      A - B  = ");
	d.kdy_trim();
	d.kdy_display2(" Trim(A - B) = ");

	e.kdy_mult (a, b); // �� ���׽��� �� ���
	e.kdy_display2("      A * B  = ");
	e.kdy_trim();
	e.kdy_display2(" Trim(A * B) = ");
	 
	getchar();
	getchar();
}