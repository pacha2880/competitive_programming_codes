import java.util.Scanner;
public class Main
{

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] ar = new int[2 * n];
		long su = 0;
		for(int i = 0; i < n; i++)
		{
			ar[i] = sc.nextInt();
			ar[i + n] = ar[i];
			su += ar[i];
		}
		if(su % 2 == 1)
			System.out.println("N");
		else
		{
			su /= 2;
			long sa = 0, to = 0, co = 0;
			// cout<<su<<'\n';
			for(int i = 0; i < n; i++)
			{
				while(to < 2 * n && sa < su)
					sa += ar[to++];
				// cout<<i<<' '<<to<<' '<<sa<<'\n';
				if(sa == su)
					co++;
				sa -= ar[i];
			}
			if(co >= 3)	
				System.out.println("Y");
			else
				System.out.println("N");
		}
	}
}