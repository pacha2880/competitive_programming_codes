	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>
	#define PI 				acos(-1)
	#define mp				make_pair
	#define pb				push_back
	#define all(a)			(a).begin(), (a).end()
	#define sz(a)			a.size()
	#define srt(a)			sort(all(a))
	#define mem(a, h)		memset(a, (h), sizeof(a))
	#define F 				first
	#define S 				second
	#define MOD1			998244353
	#define forr(i, b, e)	for(int i = b; i < e; i++)
	#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
	int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

	using namespace std;
	using namespace __gnu_pbds;

	typedef long long 		ll;
	typedef unsigned long long 		ull;
	typedef pair<int, int>  ii;
	typedef vector<int>     vi;
	typedef vector<ii>      vii;
	typedef vector<ll>      vll;
	typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
	//find_by_order kth largest  order_of_key <
	const int tam = 100010;
	const int MOD = 1e9+7;
	const double EPS = 1e-9;
	vector<int> v[tam];
	vector<int> T[tam*4];
	void init(int nodo,int i,int j)
	{
		if (i==j)
		{
			sort(v[i].begin(),v[i].end());
			T[nodo]=v[i];
			return;
		}
		int mid=(i+j)/2, newnodo=(nodo*2);
		vector<int> v1,v2,ans;
		init(newnodo,i, mid);v1=T[newnodo];
		init(newnodo+1,mid+1,j);v2=T[newnodo+1];
		int posi,posj;
		posi=posj=0;
		while(posi<v1.size()|| posj<v2.size())
		{
			if (posi<v1.size() && posj<v2.size())
			{
				if (v1[posi]<v2[posj])
					ans.pb(v1[posi]),posi++;
				else
					ans.pb(v2[posj]),posj++;
			}
			else if (posi<v1.size())
				ans.pb(v1[posi]),posi++;
			else
				ans.pb(v2[posj]),posj++;
		}
		T[nodo]=ans;
	}
	int val[tam],n;
	int todos(int nodo,int hasta)
	{
		vector<int>::iterator ite=upper_bound(T[nodo].begin(),T[nodo].end(),hasta);
		if (ite==T[nodo].begin())return 0;
		ite--;
		return ite-T[nodo].begin()+1;
	}
	int ask(int nodo,int i,int j,int l,int r,ii rag)
	{
		if (j<l|| i>r)return 0;
		int mid=(i+j)/2,newnodo=(nodo*2);
		if (i>=l && j<=r)
		{
			int ans=0;
			if (rag.F<=rag.S)
			{
				ans+=todos(nodo,rag.S);
				ans-=todos(nodo,rag.F-1);
			}
			else
			{
				ans+=todos(nodo,n);
				ans-=todos(nodo,rag.F-1);
				ans+=todos(nodo,rag.S);
			}
			return ans;
		}
		return ask(newnodo, i, mid, l, r, rag)+
				ask(newnodo +1 , mid+1 , j, l, r, rag);
	}

	int main()
	{

		//if (lower_bound(g.begin(),g.end(),3)==g.end())<<"nice\n";
		ios::sync_with_stdio(0); cin.tie(0);
		cin>>n;
		int valor;
		forr(i,1,n+1)
		{
			cin>>valor;
			val[i]=valor;
			v[valor].pb(i);
			v[i].pb(valor);
		}
		init(1,1,n);
		ll tot=0;
		forr(i,1,n+1)
		{
			int n1,n2;
			n1=i,n2=val[i];
			if (n1>n2)swap(n1,n2);
			if (n2-1==n1 || (n1==1 && n2==n))
				continue;
			//<<n1<<' '<<n2<<endl;
			ii rag1,rag2;
			rag1=mp((n1)%n+1,((n2-1-1)%n+n)%n+1);
			//swap(rag1.F,rag1.S);
			rag2=mp(((n2+1-1)%n+n)%n+1,((n1-1-1)%n+n)%n+1);
			//if (rag1.F>rag1.S && rag2.F> rag2.S)continue;
			if (rag1.F>rag1.S)
				swap(rag1,rag2);
			//<<endl;
			//tot=0;
			tot+=ask(1,1,n,rag1.F,rag1.S,rag2);
			/*<<tot<<' ';
			<<i<<" "<<val[i]<<endl;
			<<rag1.F<<" "<<rag1.S<<" ";
			<<rag2.F<<" "<<rag2.S<<endl;*/
		}
		cout<<tot/2<<"\n";
		return 0;
	}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2