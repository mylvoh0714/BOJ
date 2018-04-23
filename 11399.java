import java.util.*;

public class Main {
	public static void main(String[] args) {
		int sum, res;
		sum = res = 0;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		for(int i=0;i<n;i++) {
			sum += arr[i];
			res += sum;
		}
		System.out.println(res);
	}
}
