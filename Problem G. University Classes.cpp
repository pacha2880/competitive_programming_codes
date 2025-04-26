#include<bits/stdc++.h>
#define f 		first
#define s 		second
#define fore(i, b, e)   for(int i = b; i < e; i++)

using namespace std;

typedef vector<int> vi;

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	vi asd(7);
	fore(i, 0, n)
	{
		string s;
		cin>>s;
		fore(i, 0, 7)
			asd[i] += s[i] == '1';
	}
	int ma = 0;
	fore(i, 0, 7) ma = max(ma, asd[i]);
	cout<<ma<<'\n';
	return 0;
}