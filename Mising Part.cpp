	#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef complex<double> cd;
double mul;
int t;
unsigned int bitReverse(unsigned int n, int logn)
{
	unsigned int res = 0;
	while(logn--)
	{
		res <<= 1;
		res |= (n&1);
		n >>= 1;
	}
	return res;
}
void fft(vector<cd>& v, vector<cd>& par)
{
	if(t == 1) return;
	double theta;
	cd w, wn, u, y;
	double m;
	for(unsigned int i=0;i<t;i++)
		par[i] = v[bitReverse(i,log2(t))];
	for(int i=1;i<t;i*=2)
	{
		m= 2*i;
		theta = 2.0*acos(-1)/m; 
		wn = cd(cos(theta), mul*sin(theta));
		for(int j = 0; j<t;j+=m)
		{
			w = 1;
			for(int k = 0; k < i; k++)
			{	
				u = par[j+k] + w*par[k+j+i];
				y =  par[j+k] - w*par[k+j+i];
				par[j+k] = u;
				par[i+j+k] = y;
				w *= wn;
			}
		}
	}
}
void fftmul(vector<cd>& v,string a, string b, char l, char r)
{
	vector<cd> aa(t,0), bb(t,0),A(t),B(t);
	for(int i=0;i<a.size();i++)
		aa[i] = (a[i]==l);
	for(int i=0;i<b.size();i++)
		bb[i] = (b[i]==r);
	mul = 1;
	fft(aa,A);
	fft(bb,B);
	for(int i=0;i<t;i++)
		aa[i] = A[i]*B[i];
	mul = -1;
	fft(aa,v);
	for(int i =0; i<t;i++)
		v[i]/=t;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	string a,b;
	cin>>a>>b;
	int n, ch = 'a'-'A';
	n = a.size();
	for(int i=0;i<n;i++)
		a[i]+=ch;
	b+=b;
	reverse(b.begin(),b.end());
	string letras = "abcde";
	string ord = "abcde";
	int res = 0;
	t = a.size() + b.size();
	while(__builtin_popcount(t)>1) t+=(t&-t);
	vector<cd> vm(t);
	int mp[5][5][2*n];
	for(int i=0;i<5;i++)
	{
		for(int o = 0; o < 5; o++)
		{
			fftmul(vm,a,b,letras[i],letras[o]);
			for(int k=0;k<2*n;k++)
				mp[letras[i]-'a'][letras[o]-'a'][k] = (int)round(real(vm[n-1+k]));
		}
	}
	int v[2*n];
	do
	{
		memset(v,0,sizeof(v));
		for(int i=0;i<5;i++)
			{
				for(int k = 0;k<2*n;k++)
					v[k]+=mp[letras[i]-'a'][ord[i]-'a'][k];
			}		
		for(int i=0;i<2*n;i++)
			{
				res = max(res,v[i]);
			}

	} while ( next_permutation(ord.begin(), ord.end()) );
	cout<<n-res;
	return 0;
}