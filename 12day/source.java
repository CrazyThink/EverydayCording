import java.util.Scanner;
import java.io.FileInputStream;
public class source {
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));
		
		int[][] pond = new int[100][100];
		int n, m, w, h;
		int sum;
		int max = 0;

		n = sc.nextInt();
		m = sc.nextInt();
		w = sc.nextInt();
		h = sc.nextInt();
		
		
		for (int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				pond[i][j] = sc.nextInt();
		
		
		for(int a = 0; a < n - w + 1; a++)			//������ Ž�� ��������
			for (int i = 0; i < m - h + 1; i++) {	//������ Ž�� ��������
				sum = 0;
				for(int b = 0; b < w; b++)			//������ Ž�� �� ����
					for (int j = 0; j < h; j++)		//������ Ž�� �� ����
						sum += pond[a + b][i + j];
				if (sum > max) max = sum;
			}
		
		System.out.println(max);
	}
}