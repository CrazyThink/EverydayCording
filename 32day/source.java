import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static int n;
	private static int cnt;

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		n = sc.nextInt();
		
		int i = 1;
		while(cnt != n){			//n번째 소수일때까지
			if(isprime(++i))		//소수라면
				cnt++;				//카운트 증가
		}
		System.out.println(i);
	}
	
	private static boolean isprime(int k){
		for(int i = 2; i*i <= k; i++)
			if(k%i == 0) return false;
		return true;
	}
	
}