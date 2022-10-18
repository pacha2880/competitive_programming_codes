#include <bits/stdc++.h>

#define PI                3.14159265358979323846264338327950
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

const int INF = int(1e9 + 7);
typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef complex<double> cd;

vector<cd> fft(vector<cd> a)
{
	int n = a.size();
	if (n == 1) return a;

	vector<cd> y(n);
	double theta = 2.0 * acos(-1) / (double)n;
	cd w = 1, wn = cd( cos(theta), sin(theta) );

	vector<cd> aEven(n/2), aOdd(n/2);

	for (int i = 0; i < n/2; i++)
	{
		aEven[i] = a[2*i];
		aOdd[i] = a[2*i+1];
	}

	vector<cd> yEven = fft(aEven);
	vector<cd> yOdd = fft(aOdd);

	for (int i = 0; i < n/2; i++)
	{
		y[i]     = yEven[i] + w*yOdd[i];
		y[i+n/2] = yEven[i] - w*yOdd[i];

		w *= wn;
	}

	return y;
}

vector<cd> ifft(vector<cd> a)
{
	int n = a.size();
	for (int i = 0; i < n; i++) a[i] = conj(a[i]);

	a = fft(a);

	for (int i = 0; i < n; i++) a[i] = conj(a[i]) / (cd)n;

	return a;
}

vector<cd> fftMul(vector<cd> a, vector<cd> b)
{
	int n = a.size() + b.size();
	while (__builtin_popcount(n) > 1) n += (n & -n);
	while (a.size() < n) a.push_back( 0 );
	while (b.size() < n) b.push_back( 0 );

	a = fft(a);
	b = fft(b);

	for (int i = 0; i < n; i++) a[i] *= b[i];

	a = ifft(a);
	
	return a;
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(n, 0);
    vector<cd> A, B, C;

    A.assign(n, 0);
    B.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
    	if (s[i] == 'a')
    	{
    		A[i] = 1;
    		B[n-1-i] = 1;
    	}
    }
    C = fftMul(A, B);
    for (int i = 1; i < n; i++) v[i] += round( real(C[n-1 + i]) );

    A.assign(n, 0);
    B.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
    	if (s[i] == 'b')
    	{
    		A[i] = 1;
    		B[n-1-i] = 1;
    	}
    }
    C = fftMul(A, B);
    for (int i = 1; i < n; i++) v[i] += round( real(C[n-1 + i]) );

    A.assign(n, 0);
    B.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
    	if (s[i] == 'c')
    	{
    		A[i] = 1;
    		B[n-1-i] = 1;
    	}
    }
    C = fftMul(A, B);
    for (int i = 1; i < n; i++) v[i] += round( real(C[n-1 + i]) );

    int best = 0;
	for (int i = 1; i < n; i++) best = max(best, v[i]);
	cout << best << '\n';
	for (int i = 1; i < n; i++) 
	{
		if (v[i] == best) cout << i << ' ';
	}
	cout << '\n';

    return 0;
}
