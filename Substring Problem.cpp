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
	bool ord[3000];
	struct trie
	{
		map<char,trie*> children;
		bool fin;
		vi id;
		trie(): fin(false){};
	};

	trie *root;
	void insertar(string s, int id)
	{
		trie *node = root;
		for(int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			if(node -> children[c] == NULL) node -> children[c] = new trie;
			node = node -> children[c];
		}
		node -> fin = 1;
		node -> id.push_back(id);
	}
	void busqueda(string s)
	{
		trie* node = root;
		for(int i =0; i < s.size(); i++)
		{
			char c = s[i];
			if(node -> children[c] == NULL) { break;}
			node = node -> children[c];
			if(node -> fin)
			{
				for(int i=0;i<node->id.size();i++)
					ord[node -> id[i]] = 1;
				node -> fin = 0;
			}
		}
	}
	int main()
	{
		ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		root = new trie;
		string s,a;
		cin>>s;
		int n;
		cin>>n;
		for(int i = 0; i < n; i++)
		{
			cin>>a;
			insertar(a,i);
		}
		int si = s.size();
		memset(ord,0,sizeof(ord));
		for(int i = 0; i < si; i++)
		{
			busqueda(s.substr(i,si-i));
		}
		for(int i = 0; i < n; i++)
			cout<<(ord[i]?'Y':'N')<<'\n';
		return 0;
	}