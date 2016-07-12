import java.util.Scanner;
import java.io.FileInputStream;
public class source {
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));
		
		int n;
		int sum = 0;

		n = sc.nextInt();
		
		for(int i = 1; i <= n; i++)
			if( n % i == 0 )
				sum += i;
		
		System.out.println(sum);
	}
}