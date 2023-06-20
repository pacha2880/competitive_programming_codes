#include <bits/stdc++.h>
#define mp					make_pair
#define pb					push_back
#define f 					first
#define s 					second
#define int                 ll
#define sz(a)				a.size()
#define fore(i, b, e)		for(int i = b; i < e; i++)
#define forn(i, n)			for(int i = 0; i < n; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
using namespace std;
typedef long long 		ll;
typedef vector<int> vi;
const int MOD = 1e9+7;
const double EPS = 1e-9;
const int tam = 100010;

class LimitedMemorySeries1{
    public:
    long long getSum(int n, int x0, int a, int b, vi qs)
    {
        int m = sz(qs);
        vi res(m), ls(m), rs(m, MOD - 1);
        int rus = 0;
        bool bo = true;
        fore(i, 0, m) qs[i]++;
        while(true)
        {
            map<int, vi> mids;
            map<int, int> canti;
            fore(i, 0, m)
            {
                // cout<<ls[i]<<' '<<rs[i]<<'\n';
                if(ls[i] <= rs[i])
                    mids[ls[i] + rs[i] >> 1].pb(i);
            }
            if(mids.empty()) break;
            int ax = x0;
            fore(i, 0, n)
            {
                auto it = mids.lower_bound(ax);
                if(it != mids.end())
                    canti[it->f]++;
                ax = (ax * a + b) % MOD;
            }
            int can = 0;
            for(auto cat : canti)
            {
                can += cat.s;
                for(int y : mids[cat.f])
                    if(can >= qs[y])
                        res[y] = cat.f, rs[y] = cat.f - 1;
                    else
                        ls[y] = cat.f + 1;
            }
        }
        fore(i, 0, m) rus += res[i];
        return rus;
    }
};

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
    int n, x0, a, b;
    cin>>n>>x0>>a>>b;
    vi q({4854010,3139503,1855546,219904,846357,2624639,891260,217467,4940091,4802760,2424821,424076, 3848272,2062765,2922407,4850301,1279972,4929307,2035456,3562859,1749594,4089499,3797495,1013980, 1650805,1245213,3020379,4661668,427170,1176815,292944,2435328,420809,4170355,2635197,3940607, 4311718,2098572,4868054,30319,4588969,1460677,1335028,3921495,3621970,4459335,966000,3686977, 2316560,1634961,2280624,1940395,3321546,3168811,1856547,3859093,4340475,1382782,3482928,2517843, 185008,1135373,2821050,3260484,4821220,1700954,3243343,2183615,394339,2630121,1811267,1060542, 3898314,892312,2015580,11161,4965095,2128470,2320933,1095881,3938450,1887098,975426,2098073,3300937, 1145560,2894728,1026181,3259403,4509345,3610224,3584456,1877483,2665752,2243671,616205,504849,3068426, 1471925,4144568});
    LimitedMemorySeries1 asd;
    cout<<asd.getSum(n, x0, a, b, q)<<'\n';
	return 0;
}
