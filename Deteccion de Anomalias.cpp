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
int T[400004];
void update(int b, int e, int nodo, int pos, int val)
{
	if(pos>e||pos<b) return;
	if(b==e) {T[nodo]+=val; return;}
	int mid=(b+e)/2,l=nodo*2+1,r=l+1;
	update(b,mid,l,pos,val);
	update(mid+1,e,r,pos,val);
	T[nodo]=T[r]+T[l];

}

int query(int b,int e, int nodo, int i, int j)
{
	if(i>e||j<b) return 0;
	if(b>=i&&e<=j) return T[nodo];
	int mid=(b+e)/2,l=nodo*2+1,r=l+1;
	if(j<=mid) return query(b,mid,l,i,j);
	if(i>mid) return query(mid+1,e,r,i,j);
	return query(b,mid,l,i,j)+query(mid+1,e,r,i,j);
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	map<string,int> mp;
	int a=1,n,q;
	cin>>n>>q;
	int peq[n];
	string t;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(mp[t])
		{
			peq[i]=mp[t]-1;
		}
		else
		{
			mp[t]=a;
			peq[i]=a-1;
			a++;
		}
	}
	memset(T,0,sizeof(T));
	pair<int,pair<int, int> > pa[q];
	int sum[q],ind[n];
	memset(ind,-1,sizeof(ind));
	for(int i=0;i<q;i++)
	{
		cin>>pa[i].second.first>>pa[i].first;
		pa[i].second.first--;
		pa[i].first--;
		pa[i].second.second=i;
	}
	sort(pa,pa+q);
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(ind[peq[i]]!=-1)
			update(0,n-1,0,ind[peq[i]],-1);
		ind[peq[i]]=i;
		update(0,n-1,0,i,1);
		while(c<q&& pa[c].first==i)
		{
			sum[pa[c].second.second]=query(0,n-1,0,pa[c].second.first,pa[c].first);
			c++;
		}

	}

		
	for(int i=0;i<q;i++) cout<<sum[i]<<'\n';

	return 0;
}