#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define f first
#define s second
#define fore(i, b, e)	  for (int i = b; i < e; i++)
#define forr(i, b, e)	  for (int i = b; i < e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const double EPS = 1e-9;
const double PI = acos(-1);
#define tam 1030
bitset<10000> bi;
vector<int> pri, pric;
void criba()
{
	bi.set();
	fore(i, 2, 10000)
	{
		//cout<<i<<'\n';
		if(bi[i])
		{
			for(int j = i; j < 10000; j+=i)
			{
				//cout<<j<<' ';
				bi[j] = 0;
			}
			pri.pb(i);
			pric.pb(i * i);
		}
	}
}
vector<int> facto(int n)
{
	vector<int> res;
	for(int i = 0; pric[i] <= n; i++)
	{
		if(n % pri[i] == 0)
		{
			res.pb(pri[i]);
			while(n % pri[i] == 0)
				n /= pri[i];
		}
	}
	if(n > 1)
		res.pb(n);
	return res;
}
ll sf(ll n, ll b)
{
	if(n<0) return 0;
	return (1 + (b + 1) * n + b * n * (n - 1) / 2) % INF;
}
int f(ll b, ll e, ll n, ll nu, ll toto)
{
	//cout<<b<<' '<<e<<'\n';
	ll res = e - b, divi, su = e * (e + 1) / 2 - b * (b + 1) / 2 ;
	vector<int> fac = facto(nu);
	int ta = fac.size(), mas = 1 << ta;
	ll le, ri;
	//cout<<nu<<'\n';
	//cout<<"chichi"<<mas<<'\n';
	fore(i, 1, mas)
	{
		divi = 1;
		fore(j, 0, ta)
		{
			if(i & (1<<j))
				divi *= fac[j];
		}
		//cout<<"chim"<<divi<<'\n';
		le = b / divi;
		ri = e / divi;
		//cout<<res<<' '<<ri<<' '<<le<<'#';
		if((((int)__builtin_popcount(i)) & 1) > 0)
		{
			res = ((res - (ri - le)) % INF + INF) % INF;
			su = ((su - divi * (ri * (ri + 1) / 2 - le * (le + 1) / 2 )) % INF + INF) % INF;
		}
		else
		{
			res = ((res + (ri - le)) % INF + INF) % INF;
			su = ((su + divi * (ri * (ri + 1) / 2 - le * (le + 1) / 2 )) % INF + INF) % INF;
		}
	}
	//cout<<res<<' '<<su<<' '<<'$'<<toto<<' '<<nu<<' ';
	return ((toto - nu) * (n * res % INF - su) % INF + INF) % INF;
}
int main()
{
    //std::ios::sync_with_stdio(false); cin.tie(0);
    criba();
    ll n, m, l, r;
    cin>>n>>m>>l>>r;
    ll resa = ((n-1) * m + (m-1) * n) % INF, resu = 0;
    if(l > 1) resa = 0;
    ll lo, hi, mid, res, ab, ar;
    l *= l;
    ll ex, raza = 0;
    r *= r;
    fore(i, 1, n)
    {
    	
    	//cout<<i<<'\n';;
    	lo = 1, hi = m-1, res = 0;
    	while(lo <= hi)
    	{
    		mid = (lo + hi) / 2;
    		if(mid * mid + (ll) i * i < l)
    			res = mid, lo = mid +1;
    		else
    			hi = mid -1;
    	}
    	ab = res;

    	lo = 1, hi = m-1, res = 0;
    	while(lo <= hi)
    	{
    		mid = (lo + hi) / 2;
    		if(mid * mid + (ll) i * i <= r)
    			res = mid, lo = mid +1;
    		else
    			hi = mid -1;
    	}
    	ar = res;
    	//cout<<i<<'\n';
    	//cout<<ar<<' '<<ab<<' '<<resu<<' '<<f(ab, ar, m -1, i)<<'\n';
    	//cout<<i<<' ';
    	ex = f(ab, ar, m, i, n);
    	if(ex < 0) ex += INF;
    	//cout<<ex<<'\n';
    	resu = (resu + ex) % INF;
    	//cout<<"chocolate "<<i<<' '<<resu<<' '<<raza<<'\n';
    }
    //cout<<resu<<' '<<resa<<' ';
    cout<<(2 * resu + resa)%INF<<'\n';
    return 0;
}
// PLUS ULTRA!