import java.util.*;
import java.math.BigInteger;
class Main{

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger n = sc.nextBigInteger(), x = n, six = new BigInteger("6"),
		 mo, one = BigInteger.ONE, ac = BigInteger.ZERO, minus = new BigInteger("-1"),
		 ze = BigInteger.ZERO;
		 ac = six.subtrac(n.mod(six));
		 x = n.add(ac).divide(six);
		 System.out.println(5);
		 System.out.print(x.add(one));
		 System.out.print(" ");
		 System.out.print(x.subtrac(one));
		 System.out.print(" -");
		 System.out.print(x);
		 System.out.print(" -");
		 System.out.print(x);
		 System.out.print(" ");
		 System.out.println(ac.negate());
	}
}