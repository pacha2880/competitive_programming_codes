#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;

typedef long long ll;
const double EPS=1e-7;
vector<int> X,Y;
vector<vector<double> > A;
vector<double> b,c;
double z;
int n,m;
void pivot(int x,int y){
	swap(X[y],Y[x]);
	b[x]/=A[x][y];
	fore(i,0,m)if(i!=y)A[x][i]/=A[x][y];
	A[x][y]=1/A[x][y];
	fore(i,0,n)if(i!=x&&abs(A[i][y])>EPS){
		b[i]-=A[i][y]*b[x];
		fore(j,0,m)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
		A[i][y]=-A[i][y]*A[x][y];
	}
	z+=c[y]*b[x];
	fore(i,0,m)if(i!=y)c[i]-=c[y]*A[x][i];
	c[y]=-c[y]*A[x][y];
}
pair<double,vector<double> > simplex( // maximize c^T x s.t. Ax<=b, x>=0
		vector<vector<double> > _A, vector<double> _b, vector<double> _c){
	// returns pair (maximum value, solution vector)
	A=_A;b=_b;c=_c;
	n=b.size();m=c.size();z=0.;
	X=vector<int>(m);Y=vector<int>(n);
	fore(i,0,m)X[i]=i;
	fore(i,0,n)Y[i]=i+m;
	while(1){
		int x=-1,y=-1;
		double mn=-EPS;
		fore(i,0,n)if(b[i]<mn)mn=b[i],x=i;
		if(x<0)break;
		fore(i,0,m)if(A[x][i]<-EPS){y=i;break;}
		//assert(y>=0); // no solution to Ax<=b
		pivot(x,y);
	}
	while(1){
		double mx=EPS;
		int x=-1,y=-1;
		fore(i,0,m)if(c[i]>mx)mx=c[i],y=i;
		if(y<0)break;
		double mn=1e200;
		fore(i,0,n)if(A[i][y]>EPS&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
		//assert(x>=0); // c^T x is unbounded
		pivot(x,y);
	}
	vector<double> r(m);
	fore(i,0,n)if(Y[i]<m)r[Y[i]]=b[i];
	return mp(z,r);
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	int cas;
	cin>>cas;
	cout<<fixed<<setprecision(7);
	while(cas--) 	
	{
		int ta;
		cin>>ta;
		pair<double, double> ar[ta];
		for(int i = 0; i < ta; i++)
		{
			cin>>ar[i].fst>>ar[i].snd;
		}
		double dist[ta][ta];
		for(int i = 0; i < ta; i++)
			for(int j = 0; j < ta; j++)
				dist[i][j] = dist[j][i] = hypot(ar[i].fst - ar[j].fst, ar[i].snd - ar[j].snd);
		vector<double> _c(ta);
		for(int i = 0; i < ta; i++)
			_c[i] = -1;
		vector<vector<double> > _A;
		vector<double> _b;
		for(int i = 0; i < ta; i++)
		{
			for(int j = i + 2; j < (i == 0?ta-1:ta); j++)
			{
				vector<double> add(ta);
				for(int k = 0; k < ta; k++)
					add[k] = 0;
				add[i] = 1;
				add[j] = 1;
				_A.pb(add);
				_b.pb(dist[i][j]+1e-6);
			}
		}
		for(int i = 0; i < ta; i++)
		{
			vector<double> add(ta);
			for(int j = 0; j < ta; j++)
				add[j] = 0;
			add[i] = -1;
			add[(i+1)%ta] = -1;
			_A.pb(add);
			_b.pb(-dist[i][(i+1)%ta]+1e-6);
		}
		pair<double, vector<double> > res =  simplex(_A, _b, _c);
		for(int i = 0; i < res.snd.size(); i++)
			cout<<res.snd[i]<<'\n';
	}
	return 0;
} 	