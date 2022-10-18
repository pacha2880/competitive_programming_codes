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
int bit[100005], n;
void update(int pos, int val)
{
	pos++;
	while(pos <= n+1)
	{
		bit[pos] += val;
		pos += (pos & -pos);
	}
}
int query(int pos)
{
	pos++;
	int res = 0;
	while(pos > 0)
	{
		res += bit[pos];
		pos -= (pos & -pos);
	}
	return res;
}
vi alz(string s)
{
	vi res(n,0);
	res[0] = n;
	int left=0, right=0;
	for(int k = 1; k < n; k++)
	{
		if(right < k)
		{
			left = right = k;
			while(right < n && s[right] == s[right - left])
				right++;
			res[k] = right - left;
			right--;
		}
		else
		{
			int k1 = k - left;
			if(res[k1] + k < right)
				res[k] = res[k1];
			else
			{
				left = k;
				while(right < n && s[right] == s[right - left])
					right++;
				res[k] = right - left;
				right--;
			}
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	mem(bit,0);
	string s;
	cin>>s;
	n = s.size();
	vi v = alz(s);
	update(n,1);
	for(int i = 1; i < n; i++)
	{
		if(v[i] > 0)
			update(v[i], 1);
	}
	int con =0;
	for(int i = n-1; i>-1; i--)
	{
		//cout<<v[i]<<endl;
		if(i + v[i] == n)
			con++;
	}
	cout<<con<<endl;
	for(int i = n-1; i>-1; i--)
	{
		//cout<<v[i]<<endl;
		if(i + v[i] == n)
			cout<<v[i]<<' '<<query(n) - query(n-i-1)<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS