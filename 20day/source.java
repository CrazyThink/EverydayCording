import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static int n, m, visit;
	private static int[][] G = new int[200][200];
	private static int[] area = new int[200];
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		n = sc.nextInt();
		m = sc.nextInt();
		
		int from, to;
		
		for(int i = 0; i < m; i++){
			from = sc.nextInt();
			to = sc.nextInt();
			G[from][to] = G[to][from] = 1;
		}
		solve(0, 0);
									//모든 지역을 방문하지 못했으므로
		System.out.println("IMPOSSIBLE");
	}
	
	private static void solve(int a, int deep){
		if(visit == m){				//모든 지역을 방문했다면
			System.out.println("OK");
			System.exit(0); 		//프로그램 종료
		}
		
		area[a] = (deep) % 2 + 1;	//0을 기준으로 같은 깊이는 색이 같고, 깊이가 깊어질 때마다 값을 바꿈
		
		for(int i = 0; i < n; i++)	//지역 개수만큼 반복
			if(G[a][i] == 1 && area[i] == 0){
				visit++;			//방문한 지역 수 증가
				solve(i, deep + 1);	//깊이를 증가시키고 진입
			}
	}	
}