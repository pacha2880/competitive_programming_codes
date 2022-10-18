import java.util.*;
import java.math.BigInteger;

class Main 
{
	static String tobin(BigInteger x)
	{
		BigInteger zero = new BigInteger("0"), two = new BigInteger("2");
		String res = "";
		if(x.equals(zero))
			res = "0";
		while(x.compareTo(zero) > 0)
		{
			if(x.mod(two).equals(zero))
				res += '0';
			else 
				res += '1';
			x = x.divide(two);
		}
		String aux = "";
		for(int i = res.length() - 1; i > -1; i--)
			aux += res.charAt(i);
		return aux;
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int n = 0;
		for(int i = 0; i < s.length(); i++)
		{
			n *= 2;
			if(s.charAt(i) == '1')
				n++;
		}
		BigInteger a, b, zero = new BigInteger("0"), one = new BigInteger("1"), two = new BigInteger("2");
		String c, d, e;
		for(int k = 0; k < n; k++)
		{
			e = sc.next();
			c = sc.next();
			d = sc.next();
			a = b = zero;
			if(e.equals("10"))
			{
				if(c.length() < d.length() || c.length() == d.length() && c.compareTo(d) < 0)
				{
					String aum = "1";
					for(int j = 0; j < (d.length() - c.length()); j++)
						aum += '0';
					c = aum + c;
				}
			}
			for(int i = 0; i < c.length(); i++)
			{
				a = a.multiply(two);
				if(c.charAt(i) == '1')
					a = a.add(one);
			}
			for(int i = 0; i < d.length(); i++)
			{
				b = b.multiply(two);
				if(d.charAt(i) == '1')
					b = b.add(one);
			}
			if(e.equals("0"))
			{
				if(a.compareTo(b) > 0)
					System.out.println(1);
				else
					System.out.println(0);
			}
			if(e.equals("1"))
			{
				System.out.println(tobin(a.add(b)));
			}
			if(e.equals("10"))
				System.out.println(tobin(a.subtract(b)));
			if(e.equals("11"))
				System.out.println(tobin(a.multiply(b)));
			if(e.equals("100"))
			{
				if(b.equals(zero))
					System.out.println("0 0");
				else
					System.out.println(tobin(a.divide(b)) + " " + tobin(a.mod(b)));
			}
		}
	}
}