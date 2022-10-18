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
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("asd1.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	ll su[31];
	int con[31];
	mem(su, 0);
	ll a;
	char ch;
	ll pot[32];
	pot[0] = 1;
	for(int i = 1; i < 32; i++)
		pot[i] = pot[i-1] * 2;
	ll sut;
	map<ll,int> ma[31];
	map<ll,int>::iterator it;
	int cont;
	int fi = 0;
	while(n--)
	{
		cont=0;
		cin>>ch>>a;
		sut = 0;
		if(ch == '+')
		{
			fi++;
			int pos = 0;
			while(pot[pos+1] <= a)
			{
				pos++;
			}
			//cout<<0;
			ma[pos][a]++;
			su[pos]+=a;

		}
		else
		{
			fi--;
			int pos = 0;
			while(pot[pos+1] <= a)
			{
				pos++;
			}
			ma[pos][a]--;
			if(ma[pos][a] == 0)
				ma[pos].erase(a);
			su[pos]-=a;
		}
		//cout<<1;
		bool ant = false;
		for(int i = 0; i < 31; i++)
		{
			if(ma[i].size() > 0)
			{
				it = ma[i].begin();
				if(it != ma[i].end())
				{
					if(sut * 2 < it->f && ant)
						cont++;
					ant = true;
				}
			}
			sut += su[i];
		}
		cout<<(fi>1?fi - 1 - cont:0)<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2