import java.util.*;
import java.math.BigInteger;
public class Enjoy
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger a = sc.nextBigInteger(), b = sc.nextBigInteger();
		BigInteger g = a.gcd(b);
		System.out.println(a.divide(g).add(BigInteger.ONE).multiply(b.divide(g).add(BigInteger.ONE)));
	}
}