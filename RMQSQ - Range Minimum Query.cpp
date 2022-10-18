#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define aint(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(aint(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,nuint_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 1000010;
const int logTam = 21;

int n; 
int ar[tam], table[logTam][tam];
void inispar()
{
	fore(i, 0, n) table[0][i] = ar[i];
	for(int k = 0; (1 << k) < n; k++)
		for(int i = 0; i + (1 << k) < n; i++)
			table[k + 1][i] = min(table[k][i], table[k][i + (1 << k)]);
}
int query(int b, int e)
{
	int lev = 31 - __builtin_clz(e - b + 1);	
	return min(table[lev][b], table[lev][e - (1 << lev) + 1]);	
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n;
	fore(i, 0, n) cin>>ar[i];
	inispar();
	int q;
	cin>>q;
	int a, b;
	while(q--)
	{
		cin>>a>>b;
		cout<<query(a, b)<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (int vs int?) ARRAY OUT OF BOUNDSS2