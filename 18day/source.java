import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static int n, M;
	private static int[] A = new int[100];
	private static int[] m = new int[100];
	private static int min = 0x7fffffff;
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		n = sc.nextInt();
		M = sc.nextInt();

		for(int i = 0; i < n; i++)
			A[i] = sc.nextInt();
		for(int i = 0; i < n; i++)
			m[i] = sc.nextInt();
		
		for(int i = 0; i < n; i++)
			solve(i, A[i], m[i]);
		
		System.out.println(min);
	}
	
	private static void solve(int a, int sum_A, int sum_m){
		if(sum_A >= M){			//필요한 메모리 이상을 확보했다면
			if(min > sum_m)		//비용이 최소라면
				min = sum_m;	//최솟값을 갱신
			return;
		}
		for(int i = a + 1; i < n; i++)
			solve(i, sum_A + A[i], sum_m + m[i]);
	}
}