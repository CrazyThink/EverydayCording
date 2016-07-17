import java.util.Scanner;
import java.io.FileInputStream;
public class source {
	
	private static int[][] road = new int[11][11];
	private static int n, m;
	private static int start, end, value;
	private static int sum;
	private static int min = 0x7fffffff;
	private static int[] chk = new int[11];
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		n = sc.nextInt();
		m = sc.nextInt();

		for(int i = 0; i < m; i++){
			start = sc.nextInt();
			end = sc.nextInt();
			value = sc.nextInt();
			road[start][end] = road[end][start] = value;
		}
		solve(1);

		System.out.println(min==0x7fffffff ? "‐1" : min);
	}
	
	private static void solve(int a){
		if(a == n){
			if(min > sum) min = sum;
			return;
		}
		
		for(int i = 2; i <= n; i++)
			if(road[a][i] != 0 && chk[i] == 0){
				sum += road[a][i]; chk[i] = 1;
				solve(i);
				sum -= road[a][i]; chk[i] = 0;
			}
	}
}