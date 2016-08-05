import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static int n;
	private static int[] scale = {1, 3, 9, 27, 81, 243, 729};
	private static int[] chk = new int[8];
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));	

		n = sc.nextInt();
		
		System.out.print(n + " ");							//무게 출력
		solve(n, 0);
	}
	
	private static void solve(int left, int right){
		if(left == right){									//왼쪽과 오른쪽이 같다면
			for(int c = 2; c > 0; c--){						//왼쪽부터 출력
				for(int i = 0; i < 7; i++)
					if(chk[i] == c)							//왼쪽과 오른쪽을 구분하여 출력
						System.out.print(scale[i] + " ");
				if(c == 2)									//왼쪽을 다 출력했다면
					System.out.print("0 ");					//구분 표시
			}
			System.exit(0);									//프로그램 종료
		}
		for(int i = 0; i < 7; i++)
			if(chk[i] == 0){
				chk[i] = 1; solve(left, right + scale[i]);	//오른쪽에 더함
				chk[i] = 2; solve(left + scale[i], right);	//왼쪽에 더함
				chk[i] = 0;									//추를 뺌
			}
	}
}