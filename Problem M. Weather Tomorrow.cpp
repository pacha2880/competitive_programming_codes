#include<bits/stdc++.h>
#define f 		first
#define s 		second
#define sz(v) 	(int)v.size()
#define fore(i, b, e)   for(int i = b; i < e; i++)

using namespace std;
typedef vector<int> vi;

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    set<int> delta;
    int las, x;
    cin>>las;
    fore(i, 1, n)
    {
        cin>>x;
        delta.insert(x - las);
        las = x;
    }
    if(sz(delta) == 1)
        cout<<las + *delta.begin()<<'\n';
    else
        cout<<las<<'\n';
	return 0;
}