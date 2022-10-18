#include <bits/stdc++.h>
#define mp					make_pair
#define pb					push_back
#define f 					first
#define s 					second
#define sz(a)				a.size()
#define fore(i, b, e)		for(int i = b; i < e; i++)
#define forn(i, n)			for(int i = 0; i < n; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
using namespace std;
typedef long long 		ll;
const int MOD = 1e9+7;
const double EPS = 1e-9;
typedef complex<double> cd;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    //cout<<"cha "<<result.size()<<'\n';
    return result;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	string a, b;
	vector<int> le, ri;
	while(cin>>a)
	{
		cin>>b;
		reverse(a.begin(), a.end());
		le.resize(a.size());
		ri.resize(b.size());
		vector<int> ress[4], res(a.size() + b.size() - 1, 0);
		string pal = "GATC";
		fore(i, 0, 4)
		{
			fore(j, 0, a.size())
				le[j] = a[j] == pal[i];
			fore(j, 0, b.size())
				ri[j] = b[j] == pal[i];
			//cout<<'\n';
			//cout<<i<<' '<<le.size()<<' '<<ri.size()<<'\n';
			ress[i] = multiply(le, ri);	
			//cout<<ress[i].size()<<'\n';
			//cout<<i<<'\n';
			fore(j, 0, res.size())
			{
				//cout<<ress[i][j]<<' ';
				res[j] += ress[i][j];
			}
			//cout<<'\n';
		}
		pair<int, int> mayo(-1, 0);
		fore(i, 0, res.size())
		{
			//cout<<res[i]<<' ';
			mayo = max(mayo, {res[i], -i});
		}
		//cout<<'\n';
		cout<<mayo.f<<'\n';
		if(mayo.f == 0)
		{
			cout<<"No matches\n";
		}
		else
		{
			reverse(a.begin(), a.end());
			int ind = -mayo.s;
			string s;
			fore(i, 0, b.size())
			s += '0';
			s += a;
			fore(i, 0, b.size())
			s += '0';
			int fro = b.size() + a.size() - 1 - ind;
			int to = b.size() + a.size() - 1 - ind + b.size();
			fore(i, fro, to)
			{
				if(s[i] != b[i - fro] && s[i] != '0')
					s[i] = 'X';
				else
					s[i] = b[i - fro];
			}
			string res;
			fore(i, 0, b.size() + a.size() + b.size())
				if(s[i] != '0')
					res += s[i];
			cout<<res<<'\n';
		}
		cout<<'\n';
	}
	return 0;
}
