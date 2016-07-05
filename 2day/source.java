import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	public static void main(String[] args)throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));
		
		int integer;
		integer = sc.nextInt();
		
		for(int i = 1; i <= integer; i++)	//1부터 입력한 숫자까지 반복
			System.out.print( ((i%3==0) ? "X" : i) + " ");
	}
}