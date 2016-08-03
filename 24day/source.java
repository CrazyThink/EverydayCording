import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static int B, n;
	private static int[] play = new int[21];
	private static int max;
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		B = sc.nextInt();
		n = sc.nextInt();
		
		for(int i = 0; i < n; i++)
			play[i] = sc.nextInt();
		
		solve(0, 0);

		System.out.println(max);
	}
	
	private static void solve(int a, int now){
		if(max < now){							//지금이 최대라면 갱신
			max = now;				
		}
		for(int i = a; i < n; i++)				//같은 활동 중복이 불가능하도록 i=a로 설정
			if(now + play[i] <= B)				//예산 이내라면
				solve(a + 1, now + play[i]);	//추가
	}
}