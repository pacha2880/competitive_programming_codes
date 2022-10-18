#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD1			998244353
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
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
//find_by_order kth largest  order_of_key <
//const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;

const int tam = 100010;
const int INF = 555555;

pair<ii, ii> T[4 * tam];
int lazy[4*tam];

void init(int b, int e, int nodo)
{
	int L = 2*nodo + 1, R = L+1, mid = (b + e) / 2;
	if (b == e)
	{
		T[nodo] = mp( mp(INF, tam-1), mp(-INF, tam-1) );
		return;	
	}
	init(b, mid, L);
	init(mid+1, e, R);
	T[nodo] = mp( min(T[L].f, T[R].f), max(T[L].s, T[R].s) );
}

void propagate(int b, int e, int nodo)
{
	int L = 2*nodo + 1, R = L+1, mid = (b + e) / 2;
	if (lazy[nodo] > 0)
	{
		T[nodo].f.f += lazy[nodo];
		T[nodo].s.f += lazy[nodo];
	}
	if (b != e)
	{
		lazy[L] += lazy[nodo];
		lazy[R] += lazy[nodo];
	}
	lazy[nodo] = 0;
}

void update(int b, int e, int nodo, int i, int j, int valMin, int valMax, bool rep)
{
	int L = 2*nodo + 1, R = L+1, mid = (b + e) / 2;
	propagate(b, e, nodo);
	if (i > j) return;
	if (b <= i && j <= e)
	{
		if (rep)
			T[nodo] = mp( mp(valMin, b), mp(valMax, b) );
		else
		{
			lazy[nodo] += valMin;
			propagate(b, e, nodo);
		}
		return;
	}
	if (j < b || e < i) return;
	update(b, mid, L, i, j, valMin, valMax, rep);
	update(mid+1, e, R, i, j, valMin, valMax, rep);
	T[nodo] = mp( min(T[L].f, T[R].f), max(T[L].s, T[R].s) );
}

int query(int b, int e, int nodo, int pos)
{
	int L = 2*nodo + 1, R = L+1, mid = (b + e) / 2;
	propagate(b, e, nodo);
	if (pos < b || e < pos) return -1;
	if (b == e) return T[nodo].f.f;
	int rL, rR;
	rL = query(b, mid, L, pos);
	rR = query(mid+1, e, R, pos);
	if (rL == -1) return rR;
	else return rR;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin >> n;
	init(1, n, 0);
	int sz = 0, nxt = 0;
	fore(ite, 0, n)
	{
		char c;
		cin >> c;
		if (c == 'F')
		{
			sz++;
			nxt++;
			update(1, n, 0, nxt, nxt, sz, sz, true);
		}
		if (c == 'B')
		{
			sz++;
			nxt++;
			update(1, n, 0, 1, n, 1, 1, false);
			update(1, n, 0, nxt, nxt, sz, sz, true);
		}
		if (c == 'O')
		{
			int i;
			cin >> i;
			int minPos = T[0].f.s;
			int maxPos = T[0].s.s;
			int actPos = query(1, n, 0, i);
			cout << "queue Size = " << sz << endl;
			cout << "act pos of " << i << " = " << actPos << endl << endl;
			if (actPos < sz - actPos)
			{
				// SALEN LOS DE LA PARTE TRASERA
				int A = actPos-1;
				if (minPos <= i)
					update(1, n, 0, minPos, i, sz-A, sz-A, false );
				if (minPos > i)
				{
					update(1, n, 0, 1, i, sz-A, sz-A, false);
					update(1, n, 0, minPos, n, sz-A, sz-A, false);
				}
			}
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2