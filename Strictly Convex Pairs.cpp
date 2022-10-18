#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
struct point
{	
	ll x, y;
	point() {}
	point(ll x, ll y) : x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
	ll operator *(point p) {return x * p.x + y * p.y;}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) > 0;}
	ll norm() {return x * x + y * y;}

};
ll sig(ll a)
{
	return a == 0 ? 0 : (a < 0 ? -1 : 1);
}

bool inslog(vector<point> &pol, point p)
{
	int lo = 1, hi = pol.size() - 1, mid;
	if(p.left(pol[0], pol[1]) || p.left(pol[hi], pol[0])) return false;
	while(lo < hi - 1)
	{
		mid = (lo + hi) / 2;
		if(p.left(pol[0], pol[mid]))
			hi = mid;
		else
			lo = mid;
	}
	return p.left(pol[hi], pol[lo]);
}
ll dis(point a, point b)
{
	return (a - b).norm();
}
point epi;
bool comp(point a, point b)
{
	a = a - epi, b = b - epi;
	ll cro = a ^ b;
	if(cro == 0)
		return a.norm() < b.norm();
	return cro > 0;
}
vector<point> pol;
vector<point> ins, outs;
ll in, out;
int n, m;
bool comi(int ind, int a, int b)
{
	ll cro = (pol[b] - outs[ind]) ^ (pol[a] - outs[ind]);
	if(cro > 0) return true;
	if(cro < 0) return false;
	return (pol[a] - outs[ind]).norm() < (pol[b] - outs[ind]).norm();
}
bool comd(int ind, int a, int b)
{
	ll cro = (pol[b] - outs[ind]) ^ (pol[a] - outs[ind]);
	if(cro < 0) return true;
	if(cro > 0) return false;
	return (pol[a] - outs[ind]).norm() < (pol[b] - outs[ind]).norm();
}
int bini(int ind, int ti)
{
	int lo = 0, hi = n - 1, mid, res = 0, raca;
	if(ti == 0)
	{
		
		if(((pol[0] - outs[ind]) ^ (pol[1] - outs[ind])) > 0)
		{
			//cout<<outs[ind].x<<' '<<outs[ind].y<<"  S\n";
			while(lo < hi)
			{
				mid = (lo + hi) / 2;
				//cout<<mid<<' '<<pol[mid+1].left(outs[ind], pol[0])<<'\n';
				if(((pol[mid] - outs[ind]) ^ (pol[mid + 1] - outs[ind])) >= 0 && pol[mid+1].left(outs[ind], pol[0]))
				{
					lo = mid + 1;
					if(comi(ind, mid + 1, res))
						res = mid + 1;
				}
				else
				{
					hi = mid - 1;
					if(comi(ind, mid, res))
						res = mid;
				}
			}
		}
		else if(((pol[0] - outs[ind]) ^ (pol[n-1] - outs[ind])) > 0)
		{
			//res = n-1;
			//cout<<outs[ind].x<<' '<<outs[ind].y<<"  E\n";
			while(lo < hi)
			{
				mid = (lo + hi) / 2;
				//cout<<mid<<'\n';
				if(((pol[mid + 1] - outs[ind]) ^ (pol[mid] - outs[ind])) > 0 && pol[mid].left(outs[ind], pol[0]))
				{
					hi = mid - 1;
					if(comi(ind, mid, res))
						res = mid;
				}
				else
				{
					lo = mid + 1;
					if(comi(ind, mid + 1, res))
						res = mid + 1;
				}
			}
		}
		else
		{
			if(((pol[0] - outs[ind]) ^ (pol[1] - outs[ind])) == 0)
				return 1;
			if(((pol[0] - outs[ind]) ^ (pol[n-1] - outs[ind])) == 0)
				return 0;
			return 0;
		}
	}
	else
	{
		if(((pol[0] - outs[ind]) ^ (pol[1] - outs[ind])) < 0)
		{
			//cout<<outs[ind].x<<' '<<outs[ind].y<<"  P\n";
			while(lo < hi)
			{
				mid = (lo + hi) / 2;
				//cout<<mid<<'\n';
				if(((pol[mid] - outs[ind]) ^ (pol[mid + 1] - outs[ind])) < 0 && pol[0].left(outs[ind], pol[mid + 1]))
				{
					lo = mid + 1;
					if(comd(ind, mid + 1, res))
						res = mid + 1;
				}
				else
				{
					hi = mid - 1;
					if(comd(ind, mid, res))
						res = mid;
				}
			}
		}
		else if(((pol[0] - outs[ind]) ^ (pol[n-1] - outs[ind])) < 0)
		{
			//res = n-1;
			//cout<<outs[ind].x<<' '<<outs[ind].y<<"  F\n";
			while(lo < hi)
			{
				mid = (lo + hi) / 2;
				//cout<<mid<<'\n';
				if(((pol[mid + 1] - outs[ind]) ^ (pol[mid] - outs[ind])) <=	0 && pol[0].left(outs[ind], pol[mid]))
				{
					hi = mid - 1;
					if(comd(ind, mid, res))
						res = mid;
				}
				else
				{
					lo = mid + 1;
					if(comd(ind, mid + 1, res))
						res = mid + 1;
				}
			}
		}
		else
		{
			if(((pol[0] - outs[ind]) ^ (pol[1] - outs[ind])) == 0)
				return 0;
			if(((pol[0] - outs[ind]) ^ (pol[n-1] - outs[ind])) == 0)
				return n-1;
			return 0;
		}
	}
	return res;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n>>m;
	pol.resize(n);
	fore(i, 0, n) cin>>pol[i].x>>pol[i].y;
	reverse(pol.begin(), pol.end());
	point p;
	fore(i, 0, m) 
	{
		cin>>p.x>>p.y;
		if(inslog(pol, p))
			ins.pb(p);
		else
			outs.pb(p);
	}
	reverse(pol.begin(), pol.end());
	in = ins.size(), out = outs.size();
	//cout<<"sdfa   "<<in<<' '<<out<<'\n';
	ll res = in * (in - 1) / 2;
	//cout<<"caca"<<res<<'\n';
	int ind;
	vector<point> gru[2][n];
	int cha;
	int a, b;
	fore(i, 0, out)
	{
		a = bini(i, 0), b = bini(i, 1);
		//cout<<outs[i].x<<','<<outs[i].y<<' '<<pol[a].x<<'|'<<pol[a].y<<' '<<pol[b].x<<'/'<<pol[b].y<<'\n';
		gru[0][a].pb(outs[i]);
		gru[1][b].pb(outs[i]);
	}
	fore(i, 0, n)
	{
		epi = pol[i];
		fore(j, 0, 2) sort(gru[j][i].begin(), gru[j][i].end(), comp);
		/*cout<<"grupo de: "<<pol[i].x<<','<<pol[i].y<<'\n';
		fore(j, 0, 2)
		{
			fore(k, 0, gru[j][i].size())
			{
				cout<<gru[j][i][k].x<<','<<gru[j][i][k].y<<' ';
			}
			cout<<'\n';
		}*/
	}
	int sas, coc, inda, indb, indc;
	ll ax;
	ll can = 0, sav;
	fore(i, 0, out)
	{
		if(outs[i].left(pol[0], pol[n-1]))
		{
			//cout<<outs[i].x<<','<<outs[i].y<<'\n';
			can++;	
		}
	}
	///cout<<can<<'\n';
	fore(i, 0, n)
	{
		sav = can;
		ind = 0;
		fore(j, 0, gru[0][i].size())
		{
			while(ind < gru[1][i].size() && !gru[1][i][ind].left(gru[0][i][j], pol[i]))
			{
				ind++;
				can--;
			}
			res += can;
			can++;
		}
		can = sav + gru[0][i].size() - gru[1][i].size();
	}
	cout<<res<<'\n';
	return 0;
}
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2