#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef double       ll;
#define pb                emplace_back
#define mp    make_pair
#define sz(a)   a.size()
#define mods(a, m)   ((a % m + m) % m) 
#define md(a)    mods(a, MOD)
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define f first
#define s second
#define fore(i, b, e)   for (int i = b; i < e; i++)
#define forr(i, b, e)     for (int  i = b; i < e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;
typedef long double       ld;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e20;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);
struct Line {
 mutable ll k, m, p;
 bool operator<(const Line& o) const { return k < o.k; }
 bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
 // (for doubles, use inf = 1/.0, div(a,b) = a/b)
 const ll inf = 1/.0;
 ll div(ll a, ll b) { // floored division
  return a / b; }
 bool isect(iterator x, iterator y) {
  if (y == end()) { x->p = inf; return false; }
  if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
  else x->p = div(y->m - x->m, x->k - y->k);
  return x->p >= y->p;
 }
 void add(ll k, ll m) {
  auto z = insert({k, m, 0}), y = z++, x = y;
  while (isect(y, z)) z = erase(z);
  if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
  while ((y = x) != begin() && (--x)->p >= y->p)
   isect(x, erase(y));
 }
 ll query(ll x) {
  assert(!empty());
  auto l = *lower_bound(x);
  return l.k * x + l.m;
 }
};
double inter(pair<double, double> a, pair<double, double> b)
{
 return (a.s - b.s) / (b.f - a.f);
}

double intery(pair<double, double> a, pair<double, double> b)
{
 double x = (a.s - b.s) / (b.f - a.f);
 return a.f * x + a.s ;
}
pair<double, double> eq[2][1000010], supeq[2][1000010];
pair<double, double> form(double x1, double y1, double x2, double y2)
{
	double m = (y1 - y2) / (x1 - x2);
	return mp(m, -m * x2 + y2);
}
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    freopen("asd.txt","r",stdin);
    //freopen("","w",stdout);
    int n;
    cin>>n;
    double a, b;
    if(n == 1)
     {
      cin>>a>>b;
      cout<<"0\n";
      return 0;
     }
    pair<int, int> ar[n];
    fore(i, 0, n) cin>>ar[i].f>>ar[i].s;
    sort(ar, ar + n);
    vector<pair<double,double>> ve;
    int pra = ar[0].f;

    fore(i, 1, n)
    {
    	if(ar[i].f != pra)
    	{
    		ve.pb(ar[i-1]);
    		pra = ar[i].f;
    	}
    }
    ve.pb(ar[n-1]);
    n = ve.size();
    fore(i, 0, n) ar[i] = ve[i];
    //cout<<'\n';
    //fore(i, 0, n) cout<<ar[i].f<<' '<<ar[i].s<<'\n';
    fore(i, 0, n)
    {
     a = ar[i].f;
     b = ar[i].s;
     b = 1/ b;
     eq[0][i] = mp(-b, a * b);
     eq[1][i] = mp(b, -a * b);
    }
    supeq[0][0] = eq[0][0];
    supeq[1][n-1] = eq[1][n-1];
    LineContainer lin, lan;
    double lo, hi, mid;
    double aa, bb;

    //fore(i, 0, n) cout<<eq[0][i].f<<','<<eq[0][i].s<<' '<<eq[1][i].f<<','<<eq[1][i].s<<'\n';
    lin.add(eq[0][0].f, eq[0][0].s);
    lan.add(eq[1][n-1].f, eq[1][n-1].s);
    ll res = -1e20;
    //cout<<"challa\n";
    fore(i, 1, n)
    {
    	a = intery(supeq[0][i-1], eq[1][i]);
    	b = inter(supeq[0][i-1], eq[1][i]);
    	supeq[0][i] = mp(min(supeq[0][i-1].f, eq[0][i].f), a - b * min(supeq[0][i-1].f, eq[0][i].f));
    	a = intery(supeq[1][n - i], eq[0][n - i - 1]);
    	b = inter(supeq[1][n - i], eq[0][n - i - 1]);
    	supeq[1][n - i - 1] = mp(max(supeq[1][n - i].f, eq[1][n - i - 1].f), a - b * max(supeq[1][n - i].f, eq[1][n - i - 1].f));
    }
    double mami = -1e7;

    fore(i, 1, n)
    {
		 lo = ar[0].f, hi = ar[n-1].f;
		 //cout<<"chancho\n";
		 fore(j, 0, 100)
		 {
			  mid = (lo + hi) / 2;
		      //cout<<lo<<' '<<hi<<'\n';
		      //cout<<lin.query(mid)<<' '<<eq[1][i].f * mid + eq[1][i].s<<' '<<mid<<'\n';
			  if(lin.query(mid) > supeq[1][i].f * mid + supeq[1][i].s)
			   lo = mid;
			  else
			   hi = mid;
		 }
		 //cout<<'\n';
		// cout<<mid<<'\n';
		 mami = max(mami, mid);
		 res = max(res, lin.query(mid));
		 lo = ar[0].f, hi = ar[n-1].f;
		 fore(j, 0, 100)
		 {
			  mid = (lo + hi) / 2;
			  if(lin.query(mid) > eq[1][i].f * mid + eq[1][i].s)
			   lo = mid;
			  else
			   hi = mid;
		 }
	     lin.add(eq[0][i].f, -mid * eq[0][i].f + lin.query(mid));
		 lo = ar[0].f, hi = ar[n-1].f;
		 fore(j, 0, 100)
		 {
			  mid = (lo + hi) / 2;
			  if(lan.query(mid) < supeq[0][n-i-1].f * mid + supeq[0][n-i-1].s)
			   lo = mid;
			  else
			   hi = mid;
		 }
		 mami = max(mami, mid);
		 res = max(res, lan.query(mid));

		 lo = ar[0].f, hi = ar[n-1].f;
		 fore(j, 0, 100)
		 {
			  mid = (lo + hi) / 2;
			  if(lan.query(mid) < eq[0][n-i-1].f * mid + eq[0][n-i-1].s)
			   lo = mid;
			  else
			   hi = mid;
		 }
		 lan.add(eq[1][n-i-1].f, -mid * eq[1][n-i-1].f + lan.query(mid));

		
    }
cout<<ar[0].f<<' '<<ar[n-1].f<<' '<<mami<<'\n';
    cout<<fixed<<setprecision(7)<<-res<<'\n';
    return 0;
}
// PLUS ULTRA!