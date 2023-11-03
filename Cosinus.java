import java.util.*;
import java.math.BigInteger;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for(int asd = 0; asd < n; asd++)
    {
        String s = sc.next();
        // System.out.println(s);
        // split s by '.'
        String[] arr = s.split("\\.");
        // for(int i = 0; i < arr.length; i++)
        // {
        //     System.out.println(arr[i]);
        // }
        // System.out.println(arr.length);
        BigInteger lef, nov = new BigInteger("90");
        if(arr.length == 1)
        {
            lef = new BigInteger(s);
        }
        else
        {
            lef = new BigInteger(arr[0]);
            BigInteger rig = new BigInteger(arr[1]);
            BigInteger poto = new BigInteger("10").pow(arr[1].length());
            lef = lef.multiply(poto).add(rig);
            nov = nov.multiply(poto);
        }
        BigInteger gcd = lef.gcd(nov);
        lef = lef.divide(gcd);
        nov = nov.divide(gcd);
        // System.out.println(gcd);
        // System.out.println(lef);
        // System.out.println(nov);
        if(!lef.mod(new BigInteger("2")).equals(BigInteger.ZERO))
        {
            System.out.println(nov);
        }
        else
        {
            double lef1 = lef.doubleValue() * gcd.doubleValue();
            double mina = 1000000;
            int res = 1;
            double PI = Math.acos(-1);
            for(int i = 2; i < 1000000; i++)
            {
                if(Math.abs(Math.cos(lef1 * i * PI / 180)) < mina - 0.000001)
                {
                    mina = Math.abs(Math.cos(lef1 * i * PI / 180));
                    res = i;
                }
            }
            System.out.println(res);
        }
    }
  }
}