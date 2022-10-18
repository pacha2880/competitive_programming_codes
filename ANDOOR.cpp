#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long double		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 988244353;
const ll EPS = 1e-9;
const ll PI = acos(-1);
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y) : x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	ll norm() {return hypot(x,y);}
};
point rotate(point p, ll an)
{
	return point(p.x * cos(an) - p.y * sin(an), p.x * sin(an) + p.y * cos(an));
}
ll dist(point a, point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}
pair<ll, vector<pair<ll, int>>> per[1010];
point cir[1010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cas;
	cin>>cas;
	ll w, h;
	cout<<fixed<<setprecision(8);
	while(cas--)
	{
		int n;
		cin>>w>>h>>n;
		fore(i, 0, n)
		{
			cin>>cir[i].x>>cir[i].y>>per[i].f;
			per[i].s.clear();
		}
		ll res = 0, ini, d, an, r, R, an1, an2, ra;
		point dir, ax;
		int coni;
		fore(i, 0, n)
		{
			if(cir[i].y < per[i].f - EPS)
			{
				an = acos(cir[i].y / per[i].f);
				an1 = -PI / 2 - an;
				an2 = -PI / 2 + an;
				per[i].s.pb(mp(an1, 0));
				per[i].s.pb(mp(an2, 1));
			}
			if(fabs(cir[i].y - h) < per[i].f - EPS)
			{
				an = acos((h - cir[i].y) / per[i].f);
				an1 = PI / 2 - an;
				an2 = PI / 2 + an;
				per[i].s.pb(mp(an1, 0));
				if(an2 > PI + EPS)
				{
					per[i].s.pb(mp(-PI, 0));
					per[i].s.pb(mp(an2 - 2 * PI, 1));
				}
				else
					per[i].s.pb(mp(an2, 1));
			}
			if(cir[i].x < per[i].f - EPS)
			{
				an = acos(cir[i].x / per[i].f);
				an1 = PI - an;
				an2 = -PI + an;
				per[i].s.pb(mp(an1, 0));
				per[i].s.pb(mp(-PI, 0));
				per[i].s.pb(mp(an2, 1));
			}
			if(fabs(cir[i].x - w) < per[i].f - EPS)
			{
				an = acos((w - cir[i].x) / per[i].f);
				//cout<<"caca "<<(w - cir[i].x) / per[i].f<<'\n';
				an1 = -an;
				an2 = an;
				per[i].s.pb(mp(an1, 0));
				per[i].s.pb(mp(an2, 1));	
			}
			if(cir[i].y - per[i].f > h - EPS || cir[i].x  - per[i].f > w - EPS)
			{
				per[i].s.pb(mp(-PI, 0));
				continue;
			}
			per[i].s.pb(mp(PI, 1));
			fore(j, i + 1, n)
			{
				d = dist(cir[i], cir[j]);
				r = per[i].f, R = per[j].f;
				if(r > R + EPS)
				{
					if(d + R < r + EPS)
					{
						per[j].s.pb(mp(-PI, 0));
						continue;
					}
				}
				if(R > r + EPS)
				{
					if(d + r < R + EPS)
					{
						per[i].s.pb(mp(-PI, 0));
						break;
					}
				}
				if(d < r + R - EPS)
				{
					an = acos((r * r + d * d - R * R) / (2 * r * d));
					//cout<<"caca:\n";
					//cout<<cir[i].x<<','<<cir[i].y<<' '<<cir[j].x<<','<<cir[j].y<<' '<<an * 180 / PI<<'\n';
					ax = cir[j] - cir[i];
					dir = rotate(ax, -an);
					an1 = atan2(dir.y, dir.x);
					dir = rotate(ax, an);
					an2 = atan2(dir.y, dir.x);
					if(an1 < an2 -EPS)
					{
						per[i].s.pb(mp(an1, 0));
						per[i].s.pb(mp(an2, 1));
					}
					else
					{
						per[i].s.pb(mp(an1, 0));
						per[i].s.pb(mp(-PI, 0));
						per[i].s.pb(mp(an2, 1));	
					}
					an = acos((-r * r + d * d + R * R) / (2 * R * d));
					ax = cir[i] - cir[j];
					dir = rotate(ax, -an);
					an1 = atan2(dir.y, dir.x);
					dir = rotate(ax, an);
					an2 = atan2(dir.y, dir.x);
					if(an1 < an2 - EPS)
					{
						per[j].s.pb(mp(an1, 0));
						per[j].s.pb(mp(an2, 1));
					}
					else
					{
						per[j].s.pb(mp(an1, 0));
						per[j].s.pb(mp(-PI, 0));
						per[j].s.pb(mp(an2, 1));	
					}
				}
			}
			ini = -PI;
			coni = 0;
			sort(all(per[i].s));
			//cout<<"momoi "<<cir[i].x<<' '<<cir[i].y<<'\n';
			ra = 2 * PI * per[i].f;
			fore(j, 0, per[i].s.size())
			{
				//cout<<per[i].s[j].f * 180 / PI<<' '<<per[i].s[j].s<<'\n';
				//cout<<coni<<'\n';
				if(coni != 0)
				{
					//cout<<"aumento "<<(per[i].s[j].f - ini) * per[i].f<<'\n';
					ra -= (per[i].s[j].f - ini) * per[i].f;
				}
				ini = per[i].s[j].f;
				if(per[i].s[j].s == 1)
					coni--;
				else
					coni++;
			}
			res += ra;
			//cout<<"mirra "<<ra<<' '<<res<<'\n';
		}
		cout<<(double)res<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2