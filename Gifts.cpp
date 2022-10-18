#include <bits/stdc++.h>
#define PI 			acos(-1)
#define fi 			(1+sqrt(5))/2
#define Binet(n)	(pow(fi,n)-pow(-fi,-n))/sqrt(5)
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
struct node
{
	vi num;
	map<int,bool> nums;
	void join(node a,node b)
	{
		for(int i=0;i<a.num.size();i++)
			if(!b.nums[a.num[i]])
			{
				b.nums[a.num[i]]=true;
				b.num.push_back(a.num[i]);
			}
		num = b.num;
		nums = b.nums;
	}
};
node T[4*500000];
int A[500000];
void init(int b, int e, int node)
{
	if(b==e)
	{
		T[node].num.clear(); T[node].nums.clear(); T[node].num.push_back(A[e]); T[node].nums[A[e]]=true;
	}
	else
	{
		int mid = (b+e)/2, izq = node*2+1, der= izq+1;
		init(b,mid,izq);
		init(mid+1,e,der);
		T[node].join(T[izq],T[der]);  
	}

}
node query(int b, int e, int nodo, int i, int j)
{
	node t;
	if(j<b||i>e) return t;
	if(i<=b&&j>=e)
		return T[nodo];
	int mid=(b+e)/2, l=nodo*2+1, r=l+1;
	if(i>mid) return query(mid+1,e,r,i,j);
	if(j<=mid) return query(b,mid,l,i,j);
	t.join(query(b,mid,l,i,j),query(mid+1,e,r,i,j));
	return t;

}

int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n, m, l, r, k;
	node t;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		init(0,n-1,0);
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>l>>r>>k;
			t=query(0,n-1,0,l-1,r-1);
			for(int j=0;j<t.num.size();j++)
				cout<<t.num[j]<<' ';
			cout<<endl;
			if(t.num.size()<k) cout<<":("<<endl;
			else
			{
				cout<<t.num[t.num.size()-k]<<endl;
			}
		}
	}
	return 0;
}