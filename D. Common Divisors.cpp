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
vi alz(string a)
{
	int n = a.size();
	vi res(n);
	int left=0,right=0;
	for(int k=1;k<n;k++)
	{
		if(right<k)
		{
			right=left=k;
			while(right<n&&a[right]==a[right-left])
				right++;
			res[k] = right - left;
			right--;
		}
		else
		{
			int k1 = k - left;
			if(res[k1]< right - k + 1)
				res[k] = res[k1];
			else
			{
				left=k;
				while(right<n&&a[right] == a[right-left])
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
	string a, b;
	int res=0;
	bool bo;
	cin>>a>>b;
	if(a.size() > b.size());
	swap(a,b);
	int n = a.size(), m = b.size();
	vi v = alz(a+b);
	for(int i = 1; i <= a.size(); i++)
	{
		if(n % i == 0 && m % i == 0)
		{
			bo = true;
			for(int j = n + m - i; j > 0; j-= i)
			{
				if(v[j] < i)
				{
					bo = false;
					break;
				}
			}
			if(bo) res++;
		}
	}
	cout<<res;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS