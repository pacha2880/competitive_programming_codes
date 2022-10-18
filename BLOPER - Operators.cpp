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
bitset<125250 * 5> bi[1000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, s;
	cin>>n>>s;
	int ta = n * (n + 1) + 1, off = n * (n + 1) / 2;
	if(s + off < 0)
	{
		cout<<"Impossible\n";
		return 0;
	}
	bi[n][s + off] = 1;
	for(int i = n - 1; i > 0; i--)
		bi[i] = (bi[i + 1] << (i + 1)) | (bi[i + 1] >> (i + 1));
	// if(n == 500) return 0;
	if(bi[1][off + 1])
	{
		cout<<1;
		int su = off + 1;
		fore(i, 2, n + 1)
		{
			if(bi[i][su + i])
			{
				su += i;
				cout<<"+";
			}
			else
			{
				su -= i;
				cout<<"-";
			}
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
