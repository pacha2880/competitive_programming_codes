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
#define EPS			1e-9
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n,ma=0;;
	cin>>n;
	ll a,c;
	pair<ll,ll> b;
	vector<pair<ll,ll>> num;
	bool be = true;
	int can=0,prev;
	
	stack<pair<ll,ll>> st;
	
	for(int i = 0; i<n; i++)
	{
		cin>>a;
		if(be)
		{
			can++;
			prev = a;
			be=false;
		}
		else
		{

			if(a == prev)
				can++;
			else
			{
				num.pb(mp(can,prev));
				can=1;
			}

			prev = a;
		}
	}
	num.pb(mp(can,prev));
	st.push(num[0]);
	for(int i = 1; i<num.size(); i++)
	{
		//cout<<"w";
		if(num[i].f%2ll==0ll && st.top().s >=num[i].s)
		{
			b = mp(st.top().f + num[i].f *(st.top().f*num[i].f>0ll? 1:-1),st.top().s);
			st.pop();
			st.push(b);//cout<<1;
		}
		else
		{
			if(st.top().f%2ll == 0ll && num[i].s >= st.top().s)
			{
				b = mp( st.top().f*(st.top().f*num[i].f>0ll? 1:-1) + num[i].f, num[i].s);
				st.pop();
				st.push(b);//cout<<2;
			}
			else	
			{
				if(st.top().s ==num[i].s)
				{
					b = mp( st.top().f + num[i].f, num[i].s);
					st.pop();
					st.push(b);//cout<<3.1;
				}
				else
					{st.push(num[i]);//cout<<3;
					}
			}
		}
		while(true)
		{
			b = st.top();
			st.pop();
			if(st.empty())
			{
				st.push(b); 
				break;
			}
			if(b.f%2ll==0ll && st.top().s >= b.s)
			{
				b = mp(st.top().f + b.f *(st.top().f*b.f>0ll? 1:-1), st.top().s);
				st.pop();
				st.push(b);//cout<<4;
			}
			else
			{
				if(st.top().f%2ll == 0ll && b.s >= st.top().s)
				{
					b = mp(st.top().f*(st.top().f*b.f>0ll? 1:-1) + b.f, b.s);
					st.pop();
					st.push(b);//cout<<5;
				}
				else
				{
					if(st.top().s ==b.s)
					{
						b = mp( st.top().f+b.f, b.s);
						st.pop();
						st.push(b);//cout<<3.2;
					}
					else
					{
						st.push(b);// cout<<6;
						break;
					}
				}
			}

		}
	}
	st.pop();
	if(st.empty())
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS