import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static int n;
	private static String star = "";

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		n = sc.nextInt();
		
		f(n);
	}
	
	private static void f(int n){
		if(n > 0){
			f(n-1);
			star += "*";
			System.out.println(star);
		}
	}
}