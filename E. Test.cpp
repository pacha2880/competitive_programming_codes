	#include <bits/stdc++.h>
	#define pb 		push_back
	#define f 		first
	#define s 		second

	using namespace std;

	typedef long long ll;


	
	vector<int> alz(string s)
	{
		int n = s.size();
		vector<int> z(n, 0);
		for(int i = 1, l = 0, r = 0; i < n; i++)
		{
			if(i <= r)
				z[i] = min(r - i + 1, z[i-l]);
			while(i + z[i] < n && s[z[i]] == s[i + z[i]])
				z[i]++;
			if(r < i + z[i] - 1)
				l = i, r = i + z[i] - 1;
		}
		return z;
	}
	int main()
	{
		ios::sync_with_stdio(0); cin.tie(0);
		//freopen("asd.txt", "r", stdin);
		string ar[3];
		cin>>ar[0]>>ar[1]>>ar[2];
		int ta = ar[0].size() + ar[1].size() + ar[2].size();
		int res = ta;
		int a = ar[0].size(), b = ar[1].size(), c = ar[2].size();
		string neo;
		int per[] = {0, 1, 2};
		vector<int> z;
		//cout<<ar[0].size()<<'\n';
		do
		{
			z = alz(ar[per[1]] + "$" + ar[per[0]]);
			int mi = 0;
			int ta = ar[per[1]].size() + 1 + ar[per[0]].size();
			bool ins = false;
			for(int i = ar[per[1]].size()+1; i < ta; i++)
			{
				if(z[i] == ar[per[1]].size())
				{
					ins = true;
					break;
				}
				if(z[i] + i == ta)
				{
					mi = z[i];
					break;
				}
			}
			if(ins)
				neo = ar[per[0]];
			else
				neo = ar[per[0]].substr(0, ar[per[0]].size() - mi) + ar[per[1]];
			ins = false;
			z = alz(ar[per[2]] + "$" + neo);
			ta = ar[per[2]].size() + 1 + neo.size();
			mi = 0;
			for(int i = ar[per[2]].size() + 1; i < ta; i++)
			{
				if(z[i] == ar[per[2]].size())
				{
					ins = true;
					break;
				}
				if(z[i] + i == ta)
				{
					mi = z[i];
					break;
				}
			}
			if(ins)
			{
				res = min(res, (int)neo.size());
			}
			else
				res = min(res, (int)neo.size() + (int)ar[per[2]].size() - mi);
			//cout<<per[0]<<' '<<per[1]<<' '<<per[2]<<' '<<res<<'\n';
		}
		while(next_permutation(per, per + 3));
		cout<<res<<'\n';
		return 0;
	}