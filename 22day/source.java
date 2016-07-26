import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static int n;
	private static int count;
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		n = sc.nextInt();
		
		solve(0);

		System.out.println(count);
	}
	
	private static void solve(int now){
		if(n == now){				//도착했다면
			count++;				//카운트 증가
			return;
		}
		for(int i = 1; i <= 2; i++)	//1또는 2만
			if(now + i <= n)		//계단을 넘어가지 않을 때만
				solve(now + i);		//올라감
	}	
}