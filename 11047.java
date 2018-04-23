import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n,k;
		int res,cnt;
		res = cnt = 0;
		n = sc.nextInt();
		k = sc.nextInt();
		int arr[] = new int[n+1];
		for(int i=1;i<=n;i++)
		{
			arr[i] = sc.nextInt();
		}
		
		cnt = k/arr[1];
		for(int i=2;i<=n;i++)
		{
			int ratio = arr[i] / arr[i-1];
			if(cnt % ratio != 0) // ¾È³ª´µ¾î ¶³¾îÁö¸é
				res += cnt%ratio;
			cnt = cnt / ratio;
		}
		res += cnt;
		System.out.println(res);
	}
}
