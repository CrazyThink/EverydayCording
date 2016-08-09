import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static int n, B, C;
	private static int[] gift = new int[30];
	private static int A = 0x7fffffff;
	private static int min = 0x7fffffff;
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		n = sc.nextInt();
		
		for(int i = 0; i < n; i++)
			gift[i] = sc.nextInt();
		
		solve(0, 0, 0, 0);
		
		System.out.print(A + " " + B + " " + C);
	}
	
	private static void solve(int num, int a, int b, int c){
		if(num < n){
			solve(num + 1, a, b, c + gift[num]);
			solve(num + 1, a, b + gift[num], c);
			solve(num + 1, a + gift[num], b, c);
		}
		else if(a >= b && b >= c && a < A && a - c <= min){
			A = a; B = b; C = c;	//( a >= b >= c ) 이고, 길동이가 최소이고, 길동이와 김삼이의 차가 최소일때 값을 갱신
		}
	}
}