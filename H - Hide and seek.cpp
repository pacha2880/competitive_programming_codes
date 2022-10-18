#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
//#define PI                acos(-1)
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define f first
#define s second
#define fore(i, b, e)	  for (int i = b; i < e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const double EPS = 1e-9;
const double PI = acos(-1);
struct point 
{
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y){}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	double operator ^(point p) {return x * p.y - y * p.x;}
	double norm() {return x * x + y * y;}
};

point cen;
point ar[100010], seg[2][100010];
pair<int, int> ari[100010];
int ins[100010];
double an[100010];
bool used[100010];
int ord[100010];
int antimap[100010];
bool comp(int a, int b)
{
	return an[a] < an[b] - EPS;
}
int above(point p) {
	if (p.y == cen.y) return p.x > cen.x;
	return p.y > cen.y;
}
bool ordenCircular(point p, point q) {
	int tmp = above(q) - above(p);
	if (tmp!=0) return tmp > 0;
	return ((p-cen)^(q-cen)) > 0;
}
bool compa(int a, int b) {
	return ordenCircular(ari[a].s == -1? ar[ari[a].f]:seg[ari[a].s][ari[a].f],
			ari[b].s == -1? ar[ari[b].f]:seg[ari[b].s][ari[b].f]);
}
point mira;
struct line
{
	double a, b, c;
	line() {}
	line(point p, point q)
	{
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a * p.x - b * p.y;
	}
};
double det(double a, double b, double c, double d)
{
	return a * d - b * c;
}
point intersect(line a, line b)
{
	double d = -det(a.a, a.b, b.a, b.b);
	//cout<<'#'<<d<<'#';
	return point(det(a.c, a.b, b.c, b.b) / d, det(a.a, a.c, b.a, b.c) / d);
}
double dis(int n)
{
	return (intersect(line(mira, cen), line(seg[0][n], seg[1][n])) - cen).norm();
}
bool iz(point p, int a)
{
	return ((seg[abs(ins[a]-1)][a] - seg[ins[a]][a])^(p - seg[ins[a]][a])) > EPS;
}
struct asd
{
	bool operator() (int a, int b) const
	{
		if(((seg[ins[a]][a] - cen) ^ (seg[ins[b]][b] - cen)) > EPS)
		{
			return !iz(seg[ins[b]][b], a);
		}
		else
		{
			return iz(seg[ins[a]][a], b);
		}
	}
};
void calan(point a, point b, int in)
{
	b = b - a;
	an[in] = atan2(b.y, b.x);
}
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int s,k,w;
	while(cin>>s)
	{
		cin>>k>>w;
		//cout<<k<<'#';
		fore(i, 0, k) cin>>ar[i].x>>ar[i].y;
		fore(i, 0, w) fore(j, 0, 2) cin>>seg[j][i].x>>seg[j][i].y;
		fore(i, 0, s)
		{
			int po = 0;
			cen = ar[i];
			//cout<<"el centro es: "<<cen.x<<' '<<cen.y<<'\n';
			fore(j, 0, k)
			{
				if(j != i)
				{
					ord[po] = po;
					ari[po] = mp(j, -1);
					calan(cen, ar[j], po);
					po++;
				}
			}
			//cout<<k<<' ';
			fore(j, 0, w)
			{
				used[j] = 0;
				ord[po] = po;
				ord[po+1] = po+1;
				ari[po] = mp(j, 0);
				ari[po+1] = mp(j, 1);
				calan(cen, seg[0][j], po);
				calan(cen, seg[1][j], po+1);
				if(((seg[0][j] - cen) ^ (seg[1][j] - cen)) > EPS)
					ins[j] = 0;
				else
					ins[j] = 1;
				po += 2;
			}
			//cout<<po<<' ';
			sort(ord, ord + po, comp);

			set<int, asd> st;
			if(ari[ord[0]].f == -1)
				mira = ar[ari[ord[0]].f];
			else
				mira = seg[ari[ord[0]].s][ari[ord[0]].f];
			fore(i, 0, po)
			{
				if(ari[ord[i]].s != -1 && ins[ari[ord[i]].f] == ari[ord[i]].s)
				{
					used[ari[ord[i]].f] = 1;
					antimap[ari[ord[i]].f] = i;
				}
				if(ari[ord[i]].s != -1 && ins[ari[ord[i]].f] != ari[ord[i]].s && !used[ari[ord[i]].f])
					st.insert(ari[ord[i]].f);
			}
			//cout<<st.size()<<' ';
			int res = 0;
			//cout<<po<<' ';
			/*fore(i, 0, po)
			{
				if(ari[ord[i]].s == -1)
				{
					cout<<ar[ari[ord[i]].f].x<<' '<<ar[ari[ord[i]].f].y<<'\n';
				}
				else
				{
					cout<<seg[ari[ord[i]].s][ari[ord[i]].f].x<<' '<<seg[ari[ord[i]].s][ari[ord[i]].f].y<<'\n';
				}	
			}*/
			fore(i, 0, po)
			{
				if(ari[ord[i]].s == -1)
				{
					mira = ar[ari[ord[i]].f];
					if(st.size() == 0)
						res++;
					else
					{
						//cout<<cen.x<<','<<cen.y;
						//cout<<*st.begin()<<'/';
						if(iz(mira,*st.begin()))
							res++;
					}
				}
				else
				{
					mira = seg[ari[ord[i]].s][ari[ord[i]].f];
					if(ari[ord[i]].s == ins[ari[ord[i]].f])
					{
						st.insert(ari[ord[i]].f);
					}
					else
					{
						//cout<<'@';
						st.erase(ari[ord[i]].f);
					}
				}
				//cout<<st.size()<<'/'<<res<<' ';
			}
			cout<<res<<'\n';
		}
	}
    return 0;
}
// PLUS ULTRA!