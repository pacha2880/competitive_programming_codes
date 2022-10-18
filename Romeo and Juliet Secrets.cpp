	#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;z
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
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,nu,tb,ta,con;
	cin>>n;
	string a,b,c,d;
	vector<int> v1,v2;
	while(n--)
	{
		cin>>a>>b>>nu;
		c = a;
		d = b;
		reverse(c.begin(),c.end());
		reverse(d.begin(),d.end());
		v1 = alz(b+'$'+a);
		v2 = alz(d+'$'+c);
		ta = a.size();
		tb = b.size();
		con=0;
		ta = ta + tb + 1;
		for(int i=tb+1;i<=ta-tb;i++)
		{
			if(v1[i]+v2[ta-i+1]>=tb-nu)
				con++;
		}
		cout<<con<<endl;
	}	
	return 0;
}