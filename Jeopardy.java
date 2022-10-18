import java.util.*;
import java.math.BigInteger;
class Jeopardy
{
	BigInteger cero = new BigInteger("0");
	BigInteger uno = new BigInteger("1");
	BigInteger dos = new BigInteger("2");
	public static void main(String[] args)
	{
		Jeopardy m = new Jeopardy();
		m.solve();
	}
	void solve()
	{
		Scanner sc = new Scanner(System.in);
		BigInteger x = sc.nextBigInteger(), N = x, K = uno, nn, kk;
		BigInteger[] fo = {uno, uno}, 
		last = new BigInteger[350], neo = new BigInteger[350];
		for(int i = 0; i < 350; i++)
			last[i] = BigInteger.valueOf(i + 1);
		for(BigInteger i = dos; cal(i.add(i).subtract(uno), i).compareTo(x) < 0; i = i.add(uno))
		{
			BigInteger lo = uno, hi = uno, mid, res = uno;
			while(cal(hi.add(i), i).compareTo(x) < 0)
				hi = hi.multiply(dos);
			while(lo.compareTo(hi) <= 0)
			{
				mid = lo.add(hi).divide(dos);
				if(cal(i.add(mid), i).compareTo(x) >= 0)
				{
					res = mid; hi = mid.subtract(uno);
				}
				else
					lo = mid.add(uno);
			}
			if(cal(i.add(res), i).equals(x))
			{
				nn = i.add(res);
				kk = i;
				if(nn.compareTo(N) < 0)
				{
					N = nn;
					K = kk;
				}
			}
			last = neo;
		}
		if(x.equals(uno))
			System.out.println("0 0");

		System.out.println(N + " " + K);
	}
	BigInteger cal(BigInteger n, BigInteger k)
	{
		BigInteger bino = uno;
		for(BigInteger i = cero; i.compareTo(k) < 0; i = i.add(uno))
			bino = bino.multiply(n.subtract(i));
		for(int i = 2; BigInteger.valueOf(i).compareTo(k) <= 0; i++)
			bino = bino.divide(BigInteger.valueOf(i));
		return bino;
	}
}