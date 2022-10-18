#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>
 #include <queue>
 #include <vector>
 #include <map>
 #include <string> 
 #include <cmath> 
 #include <sstream>
 #define min(a, b) ((a) < (b) ? (a) : (b))
 #define max(a, b) ((a) > (b) ? (a) : (b))
 #define abs(a) ((a) < 0 ? (-1 * (a)) : (a))
 template<class T>
 inline void swap(T &a, T &b)
 {
     T tmp = a;a = b;b = tmp;
 }
 inline void read(long long &x)
 {
     x = 0;char ch = getchar(), c = ch;
     while(ch < '0' || ch > '9') c = ch, ch = getchar();
     while(ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
     if(c == '-') x = -x;
 }
 const long long INF = 0x3f3f3f3f;
 
 long long pow(long long a, long long b, long long mod)
 {
     long long r = 1, base = a % mod;
     for(;b;b >>= 1)
     {
         if(b & 1) r *= base, r %= mod;
         base *= base, base %= mod;
     }
     return r; 
 }
 void exgcd(long long a, long long b, long long &x, long long &y)
 {
     if(!b)x = 1, y = 0;
     else exgcd(b, a%b, y, x), y -= (a / b) * x;
 }
 long long ni(long long x, long long mod)
 {
     long long inv, y; exgcd(x, mod, inv, y);
     inv = (inv % mod + mod) % mod;
     if(!inv) inv = mod;
     return inv; 
 }
 int tiaoshi;
 long long calc(long long n, long long p, long long pt)
 {
     if(n == 0) return 1;
     long long ans = 1;
     for(long long i = 1;i <= pt;++ i) if(i % p) ans *= i, ans %= pt;
     ans = pow(ans, n/pt, pt);
     for(long long i = 1;i <= n%pt;++ i) 
         if(i % p) 
             ans *= i, ans %= pt;
     return ans * calc(n/p, p, pt) % pt;
 }
 long long C(long long n, long long m, long long p, long long pt)
 {
     if(n < m || n < 0 || m < 0) return 0;
     long long cnt = 0;
     for(long long i = n;i;i /= p) cnt += i/p;
     for(long long i = m;i;i /= p) cnt -= i/p;
     for(long long i = n - m;i;i /= p) cnt -= i/p;
     return pow(p, cnt, pt) * calc(n, p, pt) % pt * ni(calc(m, p, pt), pt) % pt * ni(calc(n - m, p, pt), pt) % pt;
 } 
 long long exlucas(long long n, long long m, long long mod)
 {
     long long tmp2 = mod, ans = 0;
     for(long long i = 2;i <= mod;++ i)
         if(tmp2 % i == 0)
         {
             long long pt = 1;
             while(tmp2 % i == 0)  tmp2 /= i, pt *= i;
             long long tmp3 = C(n, m, i, pt);
             ans += tmp3 * (mod/pt) % mod * ni(mod/pt, pt) % mod;
             ans %= mod;
         }
     return ans;
 }
 long long n,m,p;
 int main()
 {
	freopen("qwe.txt", "r", stdin);
	freopen("asd1.txt", "w", stdout);
 	while(1){
     read(n), read(m), read(p);
     printf("%lld\n", exlucas(n, m, p)); 
     if(n == 10) return 0;;
 	}
     return 0;
 }