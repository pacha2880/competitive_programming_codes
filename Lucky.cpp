#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>	ii;
typedef vector<int>		vi;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,d,s,sum;
	cin>>n;
	stringstream ss;
	while(n--){
		cin>>s;
		vector<pair<int,int> > ve(s);
		for(int i=0;i<s;i++)
		{
			ve[i].first= 0;
			ve[i].second = i+1;
		}
		for(int i=0;i<s;i++){
			cin>>d;
			ve[d-1].first++;
		}
		vector<int> v;
		sort(ve.begin(),ve.end());
		sum=0;
		for(int i=0;i<s;i++){
			if(ve[i].first>0){
				sum+=ve[i].first;
				if(sum>s/2) break;
				v.push_back(ve[i].second);
			}
		}
		sort(v.begin(),v.end());
		cout<<v.size()<<'\n';
		for(int i=0;i<v.size();i++){
			if(i>0) cout<<' ';
			cout<<v[i];
		}
		cout<<'\n';
	}
	return 0;
}