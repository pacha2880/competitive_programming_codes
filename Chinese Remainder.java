import java.util.*;
import java.math.BigInteger
;
class Main
{
	static BigInteger x, y, g;
	static void extendedEuclid(BigInteger a, BigInteger b)
	{
		if(b.equals(BigInteger.ZERO))
		{
			x = BigInteger.ONE;
			y = BigInteger.ONE;
			g = a;
			return;
		}
		extendedEuclid(b, a.mod(b));
		BigInteger x1 = y;
		y = x.subtract(a.divide(b).multiply(y));
		x = x1;
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int cas = sc.nextInt();
		BigInteger a, b, c, d, mul, res, bb, dd;
		while(cas > 0)
		{
			cas--;
			a = sc.nextBigInteger();
			b = sc.nextBigInteger();
			bb = b;
			c = sc.nextBigInteger();
			d = sc.nextBigInteger();
			dd = d;
			extendedEuclid(b, d);
			mul = b.divide(g).multiply(d);
			b = b.divide(g);
			d = d.divide(g);
			res = a.multiply(d.multiply(y)).add(c.multiply(b.multiply(x))).mod(mul);
			if(res.mod(bb).equals(a) && res.mod(dd).equals(c))
				System.out.println(res+ " " + mul);
			else
				System.out.println("no solution");
		}
	}
}