import java.util.*;
import java.math.BigDecimal;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigDecimal a, b;
		int n = sc.nextInt();
		for(int i = 0; i < n; i++)
		{
			String s;
			a = new BigDecimal("0");
			while(true)
			{
				s = sc.next();
				if(s.equals("0")) break;
				b = new BigDecimal(s);
				a = a.add(b);
			}
			System.out.println(prune(a));
		}
	}
	public static String prune(BigDecimal a)
	{
		String s = a.toString();
		int po = s.length() - 1;
		while(s.charAt(po) == '0')
			po--;
		if(s.charAt(po) == '.')
			po--;
		String neo = "";
		for(int i = 0; i <= po; i++)
			neo += s.charAt(i);
		return neo;
	}
}