import java.util.*;
import java.math.BigInteger;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String a, b;
		while(sc.hasNext())
		{
			a = sc.next();
			b = sc.next();
			boolean bo = true;
			for(int i = min(a); i <= 36; i++)
			{
				for(int j = min(b); j <= 36; j++)
				{
					if((new BigInteger(a, i)).equals(new BigInteger(b, j)))
					{
						System.out.println(a + " (base " + i + ") = " + b + " (base " + j + ")");
						bo = false;
						i = 100;
						j = 100;
					}
				}
			}
			if(bo)
				System.out.println(a + " is not equal to "+ b + " in any base 2..36");
		}
	}
	public static int min(String s)
	{
		int min = 0;
		for(int i = 0; i < s.length(); i++)
		{
			char ch = s.charAt(i);
			min = Math.max(min, (int)(ch >= '0' && ch <= '9' ? (int)(ch - '0') : (int)(ch - 'A' + 10)));
		}
		return Math.max(2, min + 1);
	}
}