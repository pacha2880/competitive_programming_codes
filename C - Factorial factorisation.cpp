#include <bits/stdc++.h>
#define f 		first
#define s 		second
#define pb push_back

using namespace std;

typedef long long ll;

bitset<10000> bi;
vector<int> pri, pric;

void criba()
{
	bi.set();
	for(int i = 2; i <  10000; i++)
		if(bi[i])
		{
			for(int j = i + i; j < 10000; j += i)
				bi[j] = 0;
			pri.pb(i);
			pric.pb(i*i);
		}
}

int pria[10000];
map<int,int> torial[1010];


vector<int> facto(map<int,int> facs, bool ulti = false)
{
	//cout<<1;
	vector<int> res;
	int misi = 1000000000;
		int ari = (facs.rbegin() -> f);
		//cout<<ari<<'\n';
		for(;true;ari++)
		{
			vector<int> a, b;
			map<int,int> ax = facs;
			//cout<<2;
			bool bo = false;
			for(map<int,int>::iterator it = torial[ari].begin(); it != torial[ari].end(); it++)
			{
				ax[it->f] -= it->s;
				if(ax[it->f] < 0)
				{
					bo = true;
					break;
				}
				if(ax[it->f] == 0)
					ax.erase(it->f);
			}
			if(bo) break;
			if(ax.empty())
			{
				if(ulti)
					return res;
				a.pb(ari);
				return a;
			}
			else
			{
				a = facto(ax);
				b = facto(torial[ari]);
				if(a.size() == 0 || b.size() == 0)
				{
					continue;
				}
				for(int i = 0; i < b.size(); i++)
					a.pb(b[i]);
			}
			if(a.size() < misi)
			{
				misi = a.size();
				res = a;
			}
		}
	return res;
}

int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	criba();
	for(int i = 2; i < 1010; i++)
	{
		torial[i] = torial[i-1];
		int ax = i;
		for(int j = 0; pri[j] <= ax; j++)
		{
			while(ax % pri[j] == 0)
			{
				torial[i][pri[j]]++;
				ax /= pri[j];
			}
		}
	}
	vector<int> res = facto(torial[n], true);
	if(res.size() == 1)
	sort(res.begin(), res.end());
	if(res.size() == 0)
		cout<<"No solution\n";
	else
	{
		cout<<n<<"! = ";
		for(int i = 0; i < res.size(); i++)
		{
			if(i > 0) cout<<" * ";
			cout<<res[i]<<'!';
		}
		cout<<'\n';
	}
	return 0;
}