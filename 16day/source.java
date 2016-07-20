import java.util.Scanner;
import java.io.FileInputStream;
public class source {
	
	private static int[] first = {2, 3, 5, 7};	//앞자리
	private static int[] end = {1, 3, 7, 9};	//중간, 뒷자리
	private static int n;
	private static int count;
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		n = sc.nextInt();

		for(int i = 0; i < 4; i++)
			solve(first[i], 1);
		
		System.out.println(count);
	}
	
	private static void solve(int a, int len){
		if(!isprime(a))
			return;		
		if(n == len){						//n의 길이라면
			count++;
			System.out.println(a);			//소수출력
			return;
		}
		for(int i = 0; i < 4; i++)
			solve(a*10+end[i], len+1);
	}
	
	private static boolean isprime(int x){	//소수판별
		for(int j = 2; j*j<=x; j++)
			if(x%j==0)
				return false;
		return true;
	}
}