#include<bits/stdc++.h>
#define int     long long
#define f 		first
#define s 		second
#define pb      push_back
#define index   int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define sz(v) 	(int)v.size()
#define fore(i, b, e)   for(int i = b; i < e; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int tam = 200010;

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin>>n>>k;
    if(n * (n - 1) / 2 < k) 
    {
        cout<<"Impossible\n";
        return 0;
    }
    int cono = 0;
    int nono = 0, cuana = 1;
    while(nono <= k)
    {
        cono++;
        nono += cuana, cuana++;
        cout<<"(";
    }
    cuana--;
    nono -= cuana;
    // cout<<nono<<' '<<k<<'\n';
    k -= nono;
    while(cuana)
    {
        cuana--;
        cout<<")";
        if(cuana)
        while(cuana <= k)
        {
            cono++;
            k -= cuana;
            cout<<"()";
            // cout<<cono<<' '<<cuana<<' '<<k<<'\n';
            // return 0;
        }
    }
    while(cono < n)
        cout<<"()", cono++;
    cout<<'\n';
	return 0;
}