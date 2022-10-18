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
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		int n,m,a,b,lo,hi,res,mid;
		cin>>n;
		while(n--)
		{
			cin>>m;
			pair<int,int> arr[m];
			int cor[m];
			for(int i=0;i<m;i++)
			{
				cin>>a;
				a--;
				arr[i].f=i;
				cor[a]=i;
			}
			for(int i=0;i<m;i++)
			{
				cin>>a;
				a--;
				arr[i].s = cor[a];
			}
			vector<int> v;
			v.push_back(arr[0].s);
			for(int i = 1; i < m; i++)
			{
				if(arr[i].s>v[v.size()-1])
				{
					v.push_back(arr[i].s);
					continue;
				}
				hi = v.size()-1,lo = 0;
				while(lo<=hi)
				{
					mid = (lo + hi) / 2;
					if(v[mid] >= arr[i].s)
					{
						hi = mid - 1;
						res = mid;
					}
					else
					{
						lo = mid + 1;
					}
				}
				v[res] = arr[i].s;
			}
			cout<<v.size()<<endl;
		}
		return 0;
	}