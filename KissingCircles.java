// Working program with FastReader 
import java.util.*; 
import java.math.*;
import java.lang.Math;

class Main 
{ 	
	private static BigDecimal sqrt(BigDecimal al)
	{
		return new BigDecimal(Math.sqrt(al.doubleValue()));
	}
	private static BigDecimal hypot(BigDecimal a, BigDecimal b)
	{
		return sqrt(a.multiply(a).add(b.multiply(b)));
	}
	private static BigDecimal sin(BigDecimal al)
	{
		return new BigDecimal(Math.sin(al.doubleValue()));
	}
	private static BigDecimal cos(BigDecimal al)
	{
		return new BigDecimal(Math.cos(al.doubleValue()));
	}
	public static void main(String[] args) 
	{ 
		Scanner sc = new Scanner(System.in);
		BigDecimal R, n, al, x, r, an, ver, zu, pi = new BigDecimal(Math.acos(-1)),
		dos = new BigDecimal("2");
		while(sc.hasNext())
		{
			R = new BigDecimal(sc.next());
			n = new BigDecimal(sc.next());
			if(n.equals(new BigDecimal("1")))
			{
				System.out.println(R.round(new MathContext(10)) + " 0.0000000000 0.0000000000");
				continue;	
			}
			//al = 2 * PI / n;
			al = dos.multiply(pi).divide(n, new MathContext(50));
			x = hypot(R.multiply(sin(al)), R.multiply(cos(al)).subtract(R));
			//long double x = hypot(R * sin(al), R * cos(al) - R); 
			r = x.multiply(R.divide(dos.multiply(R).add(x), new MathContext(50)));
			//long double r = x * R / (2 * R + x);
			an = n.subtract(dos).multiply(pi).divide(dos.multiply(n), new MathContext(50));
			//long double an = (n - 2) * PI / (2 * n);
			ver = sin(an).multiply(r).multiply(R.subtract(r)).subtract(r.multiply(r).multiply(an)).multiply(n);
			//double ver = (sin(an) * r * (R - r) - r * r * an) * n;
			zu = R.multiply(R).multiply(pi).subtract(r.multiply(r).multiply(pi).multiply(n)).subtract(ver);
			//long double zu = (R * R * al / 2 - r * r * (PI - an) - sin(an) * r * (R - r)) * n;
			System.out.println((r.round(new MathContext(20))).toString() + " " + (ver.round(new MathContext(20))).toString() + " " + (zu.round(new MathContext(20)).toString())
				);
		}
	} 
}


