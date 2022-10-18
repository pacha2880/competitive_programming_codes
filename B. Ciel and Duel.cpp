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
	int n,m,a;
	cin>>n>>m;
	vi atk, def;
	int mine[m];
	bool mar[1000];
	mem(mar,0);
	string s;
	while(n--)
	{
		cin>>s>>a;
		if(s == "ATK")
			atk.pb(a);
		else
			def.pb(a);
	}
	for(int i = 0; i< m; i++)
		cin>>mine[i];
	sort(mine, mine + m);
	sort(all(def));
	sort(all(atk));
	int bo = true;
	int res = 0, ap=0;
	for(int i = 0; i < def.size(); i++)
	{
		if(ap == m) {bo = false; break;}
		if(mine[ap] > def[i])
		{
			mar[ap] = 1;
		}
		else
			i--;
		ap++;

	}
	if(bo)
	{
		bool te = true;
		if(m>n)
		{
			int posi = m-1;
			for(int i = atk.size()-1; i > -1; i--)
			{
				while(mar[posi])
					posi--;
				if(atk[i]>mine[posi])
				{
					te = false;
					break;
				}
				posi--;
			}
			if(te){
		for(int i = 0; i < m; i++)
			if(!mar[i])
				res += mine[i];
		for(int i = 0; i < atk.size(); i++)
			res -= atk[i];}
		}
	}

	ap = 0;
	int po = 0;
	for(int i = m-1; i > -1; i--)
	{
		if(po == atk.size()) break;
		if(mine[i] > atk[po])
			ap += mine[i] - atk[po];
		else
			break;
		po++;
	}
	//cout<<res<<' '<<ap<<endl;
	cout<<max(res,ap);
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS