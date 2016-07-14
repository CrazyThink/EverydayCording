import java.util.Scanner;
import java.io.FileInputStream;
public class source {
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));
		
		int n;
		int count = 0;

		n = sc.nextInt();
		
		for(int i = 1, end1 = n/2; i <= end1; i++)
			for(int j = i, k, end2 = (n-i)/2; j <= end2; j++){
				k = n - i - j;
				if(i + j > k) count++;
			}
		
		System.out.println(count);
	}
}