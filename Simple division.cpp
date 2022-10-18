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
int gcd(int a, int b) {return b==0? a:gcd(b,a%b);}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	vi vi;
	int a;
	while(cin>>a&&a)
	{
		vi.clear();
		vi.push_back(a);
		while(cin>>a&&a)
			vi.push_back(a);
		a=0;
		for(int i=0;i<vi.size()-1;i++)
			for(int j=i+1;j<vi.size();j++)
				a=gcd(a,vi[i]-vi[j]);
		cout<<abs(a)<<endl;
	}
	return 0;
}