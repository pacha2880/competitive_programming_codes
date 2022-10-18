import java.util.*;
import java.math.BigDecimal;
class Main
{

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger a;
		BigInteger cero = new BigInteger("0");
		BigInteger diesite = BigInteger.valueOf(17);
		while(true)
		{
			a = sc.nextBigInteger();
			if(a.equals(cero)) break;
			// if(a.comparteTo(one) == 0) iguales
			// if(a.comparteTo(one) < 0) a es menor
			// if(a.comparteTo(one) > 0) a es mayor
			if(a.mod(diesite).equals(cero))
				System.out.println(1);
			else
				System.out.println(0);
		}
	}
}