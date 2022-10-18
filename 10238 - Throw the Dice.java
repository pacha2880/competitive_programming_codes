import java.util.*;
import java.math.BigInteger;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			int f = sc.nextInt();
			int n = sc.nextInt();
			int s = sc.nextInt();
			BigInteger dp[][] = new BigInteger[n + 1][s + 1];
			for(int i = 0; i <= n; i++) for(int j = 0; j <= s; j++) dp[i][j] = BigInteger.ZERO;
			dp[0][0] = BigInteger.ONE;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < s; j++)
					for(int k = 1; k <= f; k++)
						if(j + k <= s)
							dp[i + 1][j + k] = dp[i + 1][j + k].add(dp[i][j]);
			System.out.println(dp[n][s] + "/" + BigInteger.valueOf(f).pow(n));
		}
	}
}