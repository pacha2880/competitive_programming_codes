#include<bits/stdc++.h>
#define f 		first
#define s 		second
#define pb      push_back
#define sz(v) 	(int)v.size()
#define fore(i, b, e)   for(int i = b; i < e; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vii lis(n + 1);
    fore(i, 0, n) cin>>lis[i + 1].f>>lis[i + 1].s;
    vii lisis;
    fore(i, 1, n + 1)
    {
        if(lis[i].f == 0)
        {
            int se = i;
            while(lis[se].s != 0)
                se = lis[se].s;
            lisis.pb({i, se});
        }
    }
    fore(i, 1, sz(lisis))
        lis[lisis[i].f].f = lisis[i - 1].s, lis[lisis[i - 1].s].s = lisis[i].f;
    fore(i, 1, n + 1)
        cout<<lis[i].f<<' '<<lis[i].s<<'\n';
	return 0;
}