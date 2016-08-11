import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static int n;
	private static int[] num = new int[81];

	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		n = sc.nextInt();
		
		solve(1);
	}
	
	private static void solve(int k){
		if(k > n){									//n자리의 수열이라면
			for(int i=1; i <= n; i++)  System.out.print(num[i]);	//출력
			System.exit(0);							//종료
		}
		for(int i = 1; i <= 3; i++){				//1부터 3까지의 수만
			num[k] = i;
			if(good(k)) solve(k+1);					//좋은 수열이라면 다음으로
			num[k] = 0;
		}
	}
	
	private static boolean good(int k){
		int a;
		for(int i = k-1, j = k; i > 0; i -= 2, j -= 1){
			for(a = i; a < j; a++)					//검사
				if(num[a] != num[a + j - i])		//다르다면
					break;
			if(a == j) return false;				//반복하는 동안 다르지 않았다면
		}
		return true;
	}
}