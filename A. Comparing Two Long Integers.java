import java.math.BigInteger;
import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger a = sc.nextBigInteger();
		BigInteger b = sc.nextBigInteger();
		int x = a.compareTo(b);
		if(x > 0)
			System.out.println(">");
		else if(x < 0)
			System.out.println("<");
		else
			System.out.println("=");
	}
}
