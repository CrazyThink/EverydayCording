import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	public static void main(String[] args)throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));
		
		int n;
		int integer[] = new int[1000001];
		int search;
		int top, bot, mid;
		
		n = sc.nextInt();				//숫자 개수 입력
		
		for(int i = 1; i <= n; i++)
			integer[i] = sc.nextInt();	//정수 입력
		search = sc.nextInt();			//기준 값 입력
		
		top = n+1; bot = 1;				//top을 n+1로 설정해야 모든원소가 k보다 작을 때 n+1에서 끝난다.
		mid = (top + bot) / 2;
		
		while(top != bot) {				//탐색을 마칠때까지
			if (search > integer[mid])
				bot = mid + 1;
			else
				top = mid;				//값이 일치해야하는 것은 아니기 때문에 -1이 없다.
			mid = (top + bot) / 2;
		}
		System.out.printf(mid + " ");
	}
}