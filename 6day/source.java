import java.util.Arrays;
import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static final int max = 30;				//굴 최대값
	private static int n;							//굴 크기
	private static int[][] arr = new int[max][max];	//굴
	private static int[] x = {-1, 0, 1, 0};
	private static int[] y = {0, -1, 0, 1};
	private static int house = 2;					//집 번호
	private static int[] size = new int[max];		//집 크기
	
	public static void main(String[] args) throws Exception {
		input();									//입력
		print();									//처음 상태 출력
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(arr[i][j] == 1){					//집이 있다면
					move(i,j);						//이동
					house++;
			}
		Arrays.sort(size);							//오름차순 정렬
		
		print();									//마지막 상태 출력
		System.out.println(house-2);				//집 개수 출력
		for(int i = 1; i < house-1; i++)
			System.out.println(size[max-i]);		//집 크기 출력
	}
	
	private static void input() throws Exception {	//입력
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));
		
		n = sc.nextInt();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				arr[i][j] = sc.nextInt();
	}
	
	private static void print() {					//배열 출력
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				System.out.print(arr[i][j] + " ");
			System.out.println();
		}
		System.out.println();
	}
	
	private static void move(int a, int b) {		//이동
		arr[a][b] = house;							//집 번호 입력
		size[house-2]++;							//집 크기 증가
		for(int i = 0; i < 4; i++)
			if(safe(a+x[i], b+y[i]) && arr[a+x[i]][b+y[i]]==1)
				move(a+x[i], b+y[i]);				//안전하고 집이 있다면 이동
	}
	
	private static boolean safe(int a, int b) {		//안전확인
		return a>=0 && a<n && b>=0 && b<n;
	}
}