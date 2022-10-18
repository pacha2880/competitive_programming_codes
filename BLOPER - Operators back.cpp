#include <bits/stdc++.h>

#define fore(i, b, e)	for(int i = b; i < e; i++)
using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
vector<int> res(1000);
bool go(int su, int n)
{
	if(abs(su) > n * (n + 1) / 2)
		return false;
	if(n == 1)
	{
		if(su == 1)
			return true;
		return false;
	}
	if(go(su - n, n - 1))
	{
		res[n] = 1;
		return true;
	}
	else 
		return go(su + n, n - 1);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, s;
	cin>>n>>s;
	if((n + 1) / 2 % 2 == s % 2 && go(s, n))
	{
		cout<<1;
		fore(i, 2, n + 1)
		{
			if(res[i])
				cout<<"+";
			else cout<<"-";
			cout<<i;
		}
		cout<<'\n';
	}
	else
		cout<<"Impossible\n";
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
