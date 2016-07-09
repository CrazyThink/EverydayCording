import java.util.Arrays;
import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	private static final int max = 30;				//�� �ִ밪
	private static int n;							//�� ũ��
	private static int[][] arr = new int[max][max];	//��
	private static int[] x = {-1, 0, 1, 0};
	private static int[] y = {0, -1, 0, 1};
	private static int house = 2;					//�� ��ȣ
	private static int[] size = new int[max];		//�� ũ��
	
	public static void main(String[] args) throws Exception {
		input();									//�Է�
		print();									//ó�� ���� ���
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(arr[i][j] == 1){					//���� �ִٸ�
					move(i,j);						//�̵�
					house++;
			}
		Arrays.sort(size);							//�������� ����
		
		print();									//������ ���� ���
		System.out.println(house-2);				//�� ���� ���
		for(int i = 1; i < house-1; i++)
			System.out.println(size[max-i]);		//�� ũ�� ���
	}
	
	private static void input() throws Exception {	//�Է�
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));
		
		n = sc.nextInt();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				arr[i][j] = sc.nextInt();
	}
	
	private static void print() {					//�迭 ���
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				System.out.print(arr[i][j] + " ");
			System.out.println();
		}
		System.out.println();
	}
	
	private static void move(int a, int b) {		//�̵�
		arr[a][b] = house;							//�� ��ȣ �Է�
		size[house-2]++;							//�� ũ�� ����
		for(int i = 0; i < 4; i++)
			if(safe(a+x[i], b+y[i]) && arr[a+x[i]][b+y[i]]==1)
				move(a+x[i], b+y[i]);				//�����ϰ� ���� �ִٸ� �̵�
	}
	
	private static boolean safe(int a, int b) {		//����Ȯ��
		return a>=0 && a<n && b>=0 && b<n;
	}
}