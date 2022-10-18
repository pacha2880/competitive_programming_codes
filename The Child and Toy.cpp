#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>	ii;
typedef vector<int>		vi;
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,m,sum=0,a,b;

	cin>>n>>m;
	int pre[n];
	set<int> mp[n];
	for(int i=0;i<n;i++)
		cin>>pre[i];
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		mp[a-1].insert(b-1);
		mp[b-1].insert(a-1);
	}
	set<int>::iterator it,ti;
	int pos=0,sa;
	while(m>0)
	{
		pos%=n;
		sa=0;

		if(mp[pos].size())
		{
			for(it=mp[pos].begin();it!=mp[pos].end();it++)
				sa+=pre[*it];
			if(sa<=pre[pos]*mp[pos].size())
			{
				for(it=mp[pos].begin();it!=mp[pos].end();it++)
					{
						ti = mp[*it].find(pos);
						if(ti!=mp[*it].end())
							{
								m--;
								sum+=pre[*it];
								mp[*it].erase(*ti);
								cout<<*it<<' ';
							}
					}cout<<endl;
				mp[pos].clear();
			}
		}
		pos++;

	}
	cout<<sum;
	return 0;
}