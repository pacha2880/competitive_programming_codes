import java.util.*;
import java.math.BigInteger;
class Main
{
	static BigInteger pot(BigInteger b, int e)
	{
		BigInteger res = BigInteger.ONE;
		while(e > 0)
		{
			if(e % 2 == 1) res = res.multiply(b);
			b = b.multiply(b);
			e /= 2;
		}
		return res;
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger a = sc.nextBigInteger(), ten = new BigInteger("10"), c;
		int b = sc.nextInt();
		a = pot(a, b);
		String s;
		int k = 0;
		//System.out.println("chacha");
		//System.out.println(a);
		while(a.compareTo(new BigInteger("9")) > 0)
		{
			s = a + "";
			k = 0;
			for(int i = 0; i < s.length(); i++)
			{
				k += s.charAt(i) - '0';
			}
			a = BigInteger.valueOf(k);
			//System.out.println(k);
		}
		System.out.println(a);
	}
}