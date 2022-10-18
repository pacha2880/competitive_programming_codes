#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define MOD1		998244353
#define EPS			1e-9
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	n /= 2;
	ii ar[n];
	for(int i = 0; i < n; i++)
	{
		cin>>ar[i].f>>ar[i].s;
		if(ar[i].f > ar[i].s)
			swap(ar[i].f, ar[i].s);
	}
	sort(ar, ar + n);
	int li = 0, ld = 0, poi = 0, pod = n-1;
	ii res[n];
	for(int i = 0; i < n-1; i++)
	{
		if(ar[i].f < li && ar[i].f < ld)
		{
			cout<<-1;
			return 0;
		}
		if(ar[i].f >= li)
		{
			li = ar[i].s;
			res[poi] = ar[i];
			poi++;
		}
		else
		{
			res[pod] = mp(ar[i].s, ar[i].f);
			pod--;
			ld = ar[i].s;
		}
	}

	if(ar[n-1].f < li && ar[n-1].f < ld)
	{
		cout<<-1;
	}
	else
	{
		if(ar[n-1].f >= li && ar[n-1].s >=ld)
		{
			res[poi] = ar[n-1];
		}
		else if(ar[n-1].f >= ld && ar[n-1].s >= li)
		{
			res[poi] = mp(ar[n-1].s,ar[n-1].f);
		}
		else if(ar[n-1].s <= li && ar[n-1].f >= ld)
		{
			res[poi] = mp(ar[n-1].s,ar[n-1].f);
		}
		else if(ar[n-1].f >= li && ar[n-1].s <= ld)
		{
			res[poi] = ar[n-1];
		}
		else
		{
			cout<<-1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(i > 0) cout<<' ';
		cout<<res[i].f<<' '<<res[i].s;
	}
	return 0

	;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS