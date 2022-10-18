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
bitset<10000000> bi;
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	//2-32 3-20 5-14 7-12
	vector<ll> humbles;
	ll dos, tres, cinco, siete, mul;
	dos = 1;
	for(int i=0;i<33;i++)
	{
		tres = 1;
		mul = dos;
		if(mul>2000000000ll) break;
		for(int j=0;j<21;j++)
		{
			mul=dos*tres;
			if(mul>2000000000ll) break;
			cinco = 1;
			for(int k=0;k<15;k++)
			{
				mul = dos*tres*cinco;
				if(mul>2000000000ll) break;
				siete = 1;
				for(int l=0;l<13;l++)
				{
					mul = dos*tres*cinco*siete;
					if(mul>2000000000ll) break;
					humbles.push_back(mul);
					siete*=7;
				}
				cinco*=5;
			}
			tres*=3;
		}
		dos*=2;
	}
	sort(humbles.begin(),humbles.end());
	int n;
	string t[] = {"th","st","nd","rd","th","th","th","th","th","th"};
	while(cin>>n&&n)
	{
		cout<<"The "<<n<<((n%100<11||n%100>13)?t[n%10]:"th")<<" humble number is "<<humbles[n-1]<<'.'<<'\n';
	}
	return 0;

}