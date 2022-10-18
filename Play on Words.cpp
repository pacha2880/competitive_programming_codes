	#include <bits/stdc++.h>
	#define PI 			acos(-1)
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
	bool visited[26];
	map<int,map<int,bool> > mp;
	void dfs(int nodo)
	{
		if(visited[nodo]) return;
			visited[nodo] = true;
		map<int,bool>::iterator it;
		for(it=mp[nodo].begin();it!=mp[nodo].end();it++)
		{
			dfs(it->first);
		}
	}
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		int n,m,ax = 'a',let[52],b,e;
		char ch1,ch2;
		bool t;
		string s;
		set<int>::iterator it;
		cin>>n;
		while(n--)
		{
			set<int> st;
			mem(let,0);
			mem(visited,0);
			mp.clear();
			cin>>m;
			for(int i=0;i<m;i++)
			{
				cin>>s;
				ch1 = s[0]-'a';
				ch2 = s[s.size()-1]-'a';
				let[ch1]++;
				let[ch2+26]++;
				mp[ch1][ch2]=1;
				mp[ch2][ch1]=1;
				st.insert(ch1);
				st.insert(ch2);
			}
			dfs(*st.begin());
			t = true;
			for(it=st.begin();it!=st.end();it++)
			{
				if(!visited[*it])
				{
					t = false;
					break;
				}
			}
			if(t)
			{
				b = e = 0;
				for(int i = 0; i < 26; i++)
				{
					if(let[i]==let[i+26]-1)
						b++;
					else
						if(let[i]-1==let[i+26])
							e++;
						else
							if(let[i]!=let[i+26])
							{
								t = false;
								break;
							}
				}
				if(t)
				{
					if(b==e&&(b==0||b==1))
						cout<<"Ordering is possible.\n";
					else
						cout<<"The door cannot be opened."<<'\n';
				}
				else
					cout<<"The door cannot be opened."<<'\n';
			}
			else
				cout<<"The door cannot be opened."<<'\n';
		}
		return 0;
	}