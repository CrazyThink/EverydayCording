import java.util.Scanner;
import java.io.FileInputStream;
public class source {

	public static void main(String[] args)throws Exception {
		Scanner sc = new Scanner(new FileInputStream("sample.txt"));
		
		int n;
		int integer[] = new int[1000001];
		int search;
		int top, bot, mid;
		
		n = sc.nextInt();				//���� ���� �Է�
		
		for(int i = 1; i <= n; i++)
			integer[i] = sc.nextInt();	//���� �Է�
		search = sc.nextInt();			//���� �� �Է�
		
		top = n+1; bot = 1;				//top�� n+1�� �����ؾ� �����Ұ� k���� ���� �� n+1���� ������.
		mid = (top + bot) / 2;
		
		while(top != bot) {				//Ž���� ��ĥ������
			if (search > integer[mid])
				bot = mid + 1;
			else
				top = mid;				//���� ��ġ�ؾ��ϴ� ���� �ƴϱ� ������ -1�� ����.
			mid = (top + bot) / 2;
		}
		System.out.printf(mid + " ");
	}
}