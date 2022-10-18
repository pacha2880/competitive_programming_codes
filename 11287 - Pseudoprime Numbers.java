import java.util.*;
import java.math.BigInteger;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger a, b;
		while(true)
		{
			a = sc.nextBigInteger();
			b = sc.nextBigInteger();
			if(a.equals(BigInteger.ZERO))
				break;
			if(!a.isProbablePrime(10) && b.modPow(a, a).equals(b))
				System.out.println("yes");
			else
				System.out.println("no");
		}
	}
}