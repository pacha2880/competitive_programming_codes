// https://codeforces.com/contest/442/problem/E
// Codeforces Round 253 (Div. 1)
// E. Gena and Second Distance
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC optimization ("O2")
// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct pt{
    double x, y;
    pt(){}
    pt(double x, double y) : x(x), y(y){}
    pt operator -(pt & p){return {x - p.x, y - p.y};}
    double norm() {return hypot(x, y);}
    double normsq() {return x * x + y * y;}
};
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int w, h, n;
    cin>>w>>h>>n;
    vector<pt> pots(n);
    fore(i, 0, n) cin>>pots[i].x>>pots[i].y;
    pt esq[4] = {{w, h}, {w, 0}, {0, h}, {0, 0}};
    auto cana = [&](double r, double an1, double an2, pt po)
    {
        double x1 = r * cos(an1) + po.x, y1 = r * sin(an1) + po.y, x2 = r * cos(an2) + po.x, y2 = r * sin(an2) + po.y;
        if(x1 > -EPS && x1 < w + EPS && y1 > -EPS && y1 < h + EPS || x2 > -EPS && x2 < w + EPS && y2 > -EPS && y2 < h + EPS)
            return 1;
        fore(i, 0, 4)
        {
            pt dir = esq[i] - po;
            double an = atan2(dir.y, dir.x);
            if(dir.norm() > r - EPS && an > an1 - EPS && an < an2 + EPS)
                return 1;
        }
        return 0;
    };
    auto can = [&](int cual, double r)
    {
        vector<pair<double, int>> sweep;
        int cuanta_maldad = 0;
        cout<<"@@@@\n";
        cout<<r<<'\n';
        cout<<cual<<'\n';
        cout<<pots[cual].x<<' '<<pots[cual].y<<'\n';
        double lasu = -PI;
        fore(i, 0, n)
            if(i != cual)
            {
                if(pots[i].x == pots[cual].x && pots[i].y == pots[cual].y)
                {
                    cout<<i<<'\n';
                    fore(j, 0, n)
                    {
                        if(j != cual && j != i)
                            if((pots[i] - pots[j]).norm() < r)
                                return false;
                    }
                    return true;
                }
                pt res = pots[i] - pots[cual];
                if(res.norm() > 2 * r + EPS) continue;
                double alf = atan2(res.y, res.x);
                double bet = acos(res.norm() / r / 2);
                if(alf - bet < -PI)
                    cuanta_maldad++, sweep.pb({alf + bet + EPS, -1}), sweep.pb({alf - bet + 2 * PI - EPS, 1}),
                    lasu = max(lasu, sweep.back().f);
                else if(alf + bet > PI)
                    cuanta_maldad++, sweep.pb({alf + bet - 2 * PI + EPS, -1}), sweep.pb({alf - bet - EPS, 1}),
                    lasu = max(lasu,);
                else
                    sweep.pb({alf - bet - EPS, 1}), sweep.pb({alf + bet + EPS, -1});
            }
        cout<<sz(sweep)<<'\n';
        sort(all(sweep));
        if(cuanta_maldad > 0)
            lasu = sweep.back();
        for(auto cat : sweep)
        {
            cout<<'$'<<cat.f * 180 / PI<<' '<<lasu * 180 / PI<<' '<<cat.s<<'\n';
            cout<<cuanta_maldad<<'\n';
            if(cat.f - lasu > EPS && cuanta_maldad == 1 && cana(r, lasu, cat.f, pots[cual]))
                return true;
            cuanta_maldad += cat.s;
            lasu = cat.f;
        }
        return false;
    };
    double rusa = 0;
    shuffle(all(pots), rng);
    fore(i, 0, n)
    {
        cout<<i<<"#################3\n";
        cout<<pots[i].x<<' '<<pots[i].y<<'\n';
        double minu = MOD;
        fore(j, 0, n) if(j != i) minu = min(minu, (pots[i] - pots[j]).norm() / 2);
        cout<<minu<<'\n';
        rusa = max(rusa, minu);
        cout<<rusa<<'\n';
        if(can(i, rusa))
        {
            double hi = 2e6;
            fore(asd, 0, 50)
            {
                double mid = (rusa + hi) / 2;
                if(can(i, mid))
                    rusa = mid;
                else
                    hi = mid;
            }
        }
        cout<<pots[i].x<<' '<<pots[i].y<<' '<<rusa<<'\n';
    }
    cout<<rusa<<'\n';
	return 0;

}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// efe no más.
// Si no vá por todo, andá pa' allá bobo.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better
