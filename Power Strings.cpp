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
typedef vector<ll>      vll;
vi zal(string a)
{
	int n = a.size();
	vector<int> z(n);
	int right=0, left=0;
	for(int k = 1; k<n;k++)
	{
		if(right<k)
		{
			right=left=k;
			while(right<n && a[right] == a[right-left])
				right++;
			z[k] = right - left;
			right--;
		}
		else
		{
			int k1 = k - left;
			if(z[k1]<right - k + 1)
				z[k] = z[k1];
			else
			{
				left = k;
				while(right<n && a[right] == a[right-left])
					right++;
				z[k] = right - left;
				right--;
			}
		}
	}
	return z;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	string a;
	bool t,tt;
	vector<int> z;
	while(cin>>a&&a!=".")
	{	
		int n = a.size();
		z = zal(a);
		tt = false;
		for(int i=1;i<=n/2;i++)
		{
			t = true;
			for(int j = i; j < n; j += i)
			{
				if(z[j]<i)
				{
					t = false;
					break;
				}
			}
			if(t)
			{
				cout<<n/i<<endl;
				tt = true;
				break;
			}
		}
		if(!tt)
			cout<<1<<endl;

	}
	return 0;
}