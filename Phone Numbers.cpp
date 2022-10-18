#include <bits/stdc++.h>
#define PI 			acos(-1)
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
ll pot(ll b,int e){
	if(e==0) return 1ll;
	return pot(b*b,e/2)*(e&1?b:1ll);
}
map<string,vector<pair<ll,bool> > > mp;
void add(string key,ll num, bool un){
	bool el=true;
	ll lon = pot(10ll,log10(num) +1);
	for(int i=0;i<mp[key].size();i++){
		if(mp[key][i].first>=num){
			if((mp[key][i].first-num)%(un?lon/10:lon)==0){
				el=false;
				break;
			}
		}
		else
		{
			if((num-mp[key][i].first)%(pot(10ll,log10(mp[key][i].first)+1))==0){
				mp[key][i].first=-1;
			}
		}
	}
	vector<pair<ll,bool> > ne;
	for(int i=0;i<mp[key].size();i++){
		if(mp[key][i].first!=-1)
			ne.push_back(make_pair(mp[key][i].first,mp[key][i].second));
	}
	mp[key]=ne;
	if(el)
		mp[key].push_back(make_pair(num,un));
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,m,e;
	string name,num;
	bool bol;
	cin>>n;
	while(n--){
		cin>>name>>m;
		while(m--){
			cin>>num;
			bol=false;
			e=atoll(num.c_str());
			if(log10(e)+1<num.size()){
				e+=pot(10ll,num.size());
				bol=true;
			}
			add(name,e,bol);
		}
	}

	stringstream ss;
	map<string,vector<pair<ll,bool> > >::iterator it;
	cout<<mp.size()<<endl;
	for(it=mp.begin();it!=mp.end();it++){
		cout<<it->first<<' '<<it->second.size()<<' ';
		for(int i=0;i<it->second.size();i++)
		{
			if(i>0) cout<<' ';
			if(it->second[i].second){
				stringstream ss;
				ss << it->second[i].first;
				string str = ss.str();
				cout<<str.substr(1);
			}
			else
				cout<<it->second[i].first; 
		}
		cout<<endl;
	}
	return 0;
}