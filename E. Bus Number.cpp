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
		typedef unsigned long long 		ull;
		typedef pair<int, int>  ii;
		typedef vector<int>     vi;
		typedef vector<ii>      vii;
		typedef vector<ll>      vll;
		ll res=0;
		map<string,bool> visited;
		void bfs(int ar[],int siz)
		{
			string st = "";
			for(int i = 0;i<10;i++)
				st+=ar[i];
			if(visited[st]) return;
			visited[st] = 1;
			map<long double,int> ma;
			for(int i = 2;i<=siz;i++)
				ma[i]++;
			for(int i = 0;i<10;i++)
			{
				if(ar[i]>1)
				{
					ar[i]--;
					bfs(ar,siz-1);
					ar[i]++;
					for(int j = 2;j<=ar[i];j++)
						ma[j]--;
				}
			}
			long double re = 1;
			map<long double,int>::iterator it;
			if(ar[0]>0)
			{
				ma[siz]--;
				ma[siz-ar[0]]++;
			}
			for(it = ma.begin();it!=ma.end();it++)
			{
				if(it->second<0)
				{
					for(int i = 0;i>it->second;i--)
						re/=it->first;
				}
				if(it->second>0)
				{
					for(int i = 0; i<it->second;i++)
						re*=it->first;
				}
			}
			res+=re;
		}
		int main()
		{
			//ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			string s;
			cin>>s;
			int ar[10];
			char ch = '0';
			mem(ar,0);
			for(int i = 0; i < s.size(); i++)
			{
				ar[s[i]-ch]++;
			}
			cout<<endl;
			bfs(ar,s.size());
			cout<<res;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS