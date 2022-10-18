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
vi primos;
bitset<100000> bi;
void criba(){
	bi.set();
	for(int i=2;i<100000;i++){
		if(bi[i]){
			for(int j=i+i;j<100000;j+=i)
				bi[j]=0;
			primos.push_back(i);
		}
	}
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	criba();
	bitset<200000> bis;
	bis.set();
	for(int i=0;i<primos.size()-1;i++)
		for(int j=i+1;j<primos.size();j++)
			bis[primos[i]+primos[j]]=0;
	int prs[100002];
	prs[0]=0;
	for(int i=1;i<=100001;i++){
		prs[i]=prs[i-1]+(bis[i]?0:1);
	}
	int n,a,b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		if(a==0) cout<<prs[b]<<'\n';
		else
			cout<<prs[b]-prs[a-1]<<'\n';
	}
	return 0;
}