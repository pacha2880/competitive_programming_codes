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
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	string s;
	bool bo = false;
	cin>>s;
	if(!bo)
	for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '=')
			{
				bo = true;
				bool bu = false;
				for(int j = i + 1; j < s.size(); j++)
				{
					if(s[j] != '.')
					{
						cout<<s[j]<<endl;
						bu = true;
						break;
					}
				}
				if(!bu) cout<<"You shall pass!!!\n";
				i = s.size();
			}
		}
		cin>>s;
	if(!bo)
	for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '=')
			{
				bo = true;
				bool bu = false;
				for(int j = i + 1; j < s.size(); j++)
				{
					if(s[j] != '.')
					{
						cout<<s[j]<<endl;
						bu = true;
						break;
					}
				}
				if(!bu) cout<<"You shall pass!!!\n";
				i = s.size();
			}
		}
		cin>>s;
	if(!bo)
	for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '=')
			{
				bo = true;
				bool bu = false;
				for(int j = i + 1; j < s.size(); j++)
				{
					if(s[j] != '.')
					{
						cout<<s[j]<<endl;
						bu = true;
						break;
					}
				}
				if(!bu) cout<<"You shall pass!!!\n";
				i = s.size();
			}
		}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS