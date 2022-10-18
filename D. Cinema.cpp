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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, a, can;
	set<int> st;
	cin>>n>>k;
	fore(i, 0, k) {cin>>a; st.insert(a);}
	cin>>can;
	int poso[can], suri[can], maxo = 0, ce, cana, pio;
	string s;

	fore(i, 0, can)
	{
		ce = 0;
		poso[i] = suri[i] = 0;
		cin>>s;
		cin>>cana;
		fore(j, 0, cana)
		{
			cin>>pio;
			//cout<<pio<<','<<st.count(pio)<<' ';
			poso[i] += st.count(pio);
			if(pio == 0)
				ce++;
		}
		suri[i] = max(k - n + cana, poso[i]);
		maxo = max(maxo, suri[i]);
		poso[i] = min(k, poso[i] + ce);
	}
	map<int, int> maxe[2];
	maxe[0][0] = poso[0];
	maxe[1][can-1] = poso[can-1];
	fore(i, 1, can)
	{
		maxe[0][i] = max(maxe[0][i - 1], poso[i]);
		maxe[1][can - i - 1] = max(maxe[1][can - i], poso[can - i - 1]);
	}
	//cout<<"maxo "<<maxo<<' '<<maxe<<'\n';
	fore(i, 0, can)
	{
		//cout<<suri[i]<<' '<<poso[i]<<' ';
		if(suri[i] >= max(maxe[0][i-1], maxe[1][i+1]))
			cout<<0<<'\n';
		else if(poso[i] >= maxo)
			cout<<2<<'\n';
		else
			cout<<1<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2