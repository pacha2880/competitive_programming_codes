#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
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
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int tam = 100010;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
double dist(pair<double, double> a, pair<double, double> b)
{
	return hypot(a.f - b.f, a.s - b.s);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	pair<double, pair<double, double>> ar[n];
	fore(i, 0, n) cin>>ar[i].s.f>>ar[i].s.s>>ar[i].f;
	sort(ar, ar + n);
	int mini = 0, maxi = 0, coun = 0;
	double primal = sqrt(2) * 50.0;
	while(maxi < n)
	{
		while(ar[mini].f < ar[maxi].f - primal)
			mini++;
		//cout<<maxi<<' '<<mini<<'\n';
		fore(i, mini, maxi)
		{
			if(dist(ar[i].s, ar[maxi].s) + ar[i].f > ar[maxi].f)
				coun++;
			if(coun > n)
			{
				cout<<"greater\n";
				return 0;
			}
		}
		maxi++;
	}
	cout<<2 * coun<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2