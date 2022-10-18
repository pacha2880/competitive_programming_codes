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
vi alz(string s)
{
	int n = s.size();
	vi v(n);
	int left = 0, right = 0;
	for(int k = 1; k < n; k++)
	{
		if(right < k)
		{
			left = right = k;
			while(right < n && s[right] == s[right-left])
				right++;
			v[k] = right - left;
			right--;
		}
		else
		{
			int k1 = k - left;
			if(k + v[k1] < right)
				v[k] = v[k1];
			else
			{
				left = k;
				while(right < n && s[right] == s[right - left])
					right++;
				v[k] = right - left;
				right--;
			}
		}
	}
	return v;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	string s,t;
	cin>>s>>t;
	vi v = alz(t + "$" + s);
	int n = s.size() + t.size() + 1;
	ll ar[n + n], su[n+n];
	mem(su,0);
	mem(ar,-1);
	int tam = t.size();
	ll sum = 0, add = 0, ap = 1, ep = 0;
	for(int i = tam + 1; i < n; i++)
	{
		if(v[i] == tam)
		{
			ar[i+tam-1] = ap;
		}
		add = (ar[i]==-1?add:ar[i]);
		sum += add;
		sum%=MOD;
		ap++;
		ap += sum;
		ap %=MOD;
		//cout<<"ap: "<<ap<<" add: "<<add<<" sum: "<<sum<<endl;
	}
	cout<<sum<<endl;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS