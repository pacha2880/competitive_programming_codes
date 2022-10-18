
import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
public class A
{
	static class FastReader 
	{ 
		BufferedReader br; 
		StringTokenizer st; 

		public FastReader() 
		{ 
			br = new BufferedReader(new
					InputStreamReader(System.in)); 
		} 

		String next() 
		{ 
			while (st == null || !st.hasMoreElements()) 
			{ 
				try
				{ 
					st = new StringTokenizer(br.readLine()); 
				} 
				catch (IOException e) 
				{ 
					e.printStackTrace(); 
				} 
			} 
			return st.nextToken(); 
		} 

		int nextInt() 
		{ 
			return Integer.parseInt(next()); 
		} 

		long nextLong() 
		{ 
			return Long.parseLong(next()); 
		} 

		double nextDouble() 
		{ 
			return Double.parseDouble(next()); 
		} 

		String nextLine() 
		{ 
			String str = ""; 
			try
			{ 
				str = br.readLine(); 
			} 
			catch (IOException e) 
			{ 
				e.printStackTrace(); 
			} 
			return str; 
		} 
	} 

	public static void main(String[] args)
	{
		FastReader sc = new FastReader();
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
			long sa = 0;
			int to = 0, co = 0;
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