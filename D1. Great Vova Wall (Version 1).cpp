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
	ll a,b,c;
	vll num;
	bool be = true;
	int prev =-1,can=0;
	
	stack<ll> st;
	
	for(int i = 0; i<n; i++)
	{
		cin>>a;
		if(be)
		{
			can++;
			prev = a&1;
			be=false;
		}
		else
		{
			if(a&1 == prev)
				can++;
			else
			{
				num.pb(can*(prev?-1:1));
				can=1;
			}

			prev = a&1;
		}
	}
	num.pb(can*(prev?-1:1));
	st.push(num[0]);
	for(int i = 1; i<num.size(); i++)
	{
		if(num[i]%2ll==0ll)
		{
			b = st.top() + num[i] *(st.top()*num[i]>0ll? 1:-1);
			st.pop();
			st.push(b);
		}
		else
		{
			if(st.top()%2ll == 0ll)
			{
				b = st.top()*(st.top()*num[i]>0ll? 1:-1) + num[i];
				st.pop();
				st.push(b);
			}
			else	
			{
				if(st.top()*num[i]>0ll)
				{
					b = st.top() + num[i];
					st.pop();
					st.push(b);
				}
				else
					st.push(num[i]);
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
			if(b%2ll==0ll)
			{
				b = st.top() + b *(st.top()*b>0ll? 1:-1);
				st.pop();
				st.push(b);
			}
			else
			{
				if(st.top()%2ll == 0ll)
				{
					b = st.top()*(st.top()*b>0ll? 1:-1) + num[i];
					st.pop();
					st.push(b);
				}
				else
				{
					st.push(b);
					break;
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