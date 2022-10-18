#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
pair<double, double	> ara[100010], arb[100010];
double dis(pair<double, double> a, pair<double, double> b)
{
	return hypot(a.f - b.f, a.s - b.s);
}
pair<double, double> trans(pair<double, double> a, pair<double, double> b, double fra)
{
	//cout<<"# "<<(b.f - a.f) * fra<<'\n';
	return mp(a.f + (b.f - a.f) * fra, a.s + (b.s - a.s) * fra);
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	fore(i, 0, n) cin>>ara[i].f>>ara[i].s;
	int m;
	cin>>m;
	fore(i, 0, m) cin>>arb[i].f>>arb[i].s;
	double mindis = dis(ara[0], arb[0]), fra;
	double acua = 0, acub = 0;
	ld a, b, c, d;
	int inb = 1;
	pair<double, double> prea = ara[0], preb = arb[0], uxu;
	fore(i, 1, n)
	{
		while(inb < m && acua + dis(prea, ara[i]) > EPS + acub + dis(preb, arb[inb]))
		{
			acub += dis(preb, arb[inb]);
			preb = arb[inb];
			inb++;
			//cout<<inb<<'\n';
		}
		if(inb == m) break;
		a = acub + dis(preb, arb[inb]) - acua - dis(prea, ara[i]);
		fra = (dis(preb, arb[inb]) - a) * 1.0 / (dis(preb, arb[inb]));
		cout<<i<<' '<<inb<<' '<<' '<<fra<<' '<<dis(trans(preb, arb[inb], fra), ara[i])<<'\n';
		uxu = trans(preb, arb[inb], fra);
		cout<<uxu.f<<' '<<uxu.s<<' '<<ara[i].f<<' '<<ara[i].s<<'\n';
		mindis = min(mindis, dis(trans(preb, arb[inb], fra), ara[i]));
		acua += dis(prea, ara[i]);
		prea = ara[i];
	}
	cout<<"preoo\n";
	cout<<mindis<<'\n';
	int ina = 1;
	cout<<'\n';
	prea = ara[0], preb = arb[0];
	acua = 0;
	acub = 0;
	fore(i, 1, m)
	{
		while(ina < n && acub + dis(preb, arb[i]) > acua + dis(prea, ara[ina]) + EPS)
		{
			acua += dis(prea, ara[ina]);
			prea = ara[ina];
			ina++;
		}
		if(ina == n) break;
		a = acua + dis(prea, ara[ina]) - acub - dis(preb, arb[i]);
		fra = (dis(prea, ara[ina]) - a) * 1.0 / (dis(prea, ara[ina]));
		cout<<i<<' '<<inb<<' '<<fra<<' '<<dis(trans(preb, arb[inb], fra), ara[i])<<'\n';
		mindis = min(mindis, dis(trans(prea, ara[ina], fra), arb[i]));
		acub += dis(preb, arb[i]);
		preb = arb[i];
	}
	cout<<fixed<<setprecision(5)<<mindis<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2