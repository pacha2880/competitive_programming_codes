#include <bits/stdc++.h>
#define PI 			acos(-1)
//#define mp			make_pair
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
map<char,int> mp;
map<int,char> mpp;
int cowDec(string cow){
	int pot = 1,res=0;
	for(int i=cow.size()-1;i>-1;i--){
		res+=mp[cow[i]]*pot;
		pot*=4;
	}
	return res;
}
string decCow(int dec){
	string res="";
	while(dec>0){
		res= mpp[dec%4]+res;
		dec/=4;
	}
	return res;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	mp['V']=0;
	mpp[0]='V';
	mp['U']=1;
	mpp[1]='U';
	mp['C']=2;
	mpp[2]='C';
	mp['D']=3;
	mpp[3]='D';
	string a,b;
	char ch;
	int n,x,y;
	cin>>n;
	cout<<"COWCULATIONS OUTPUT"<<endl;
	while(n--){
		cin>>a>>b;
		x=cowDec(a);
		y=cowDec(b);
		for (int i = 0; i < 3; ++i)
		{
			cin>>ch;
			switch(ch){
				case 'A': y+=x; break;
				case 'R': y/=4; break;
				case 'L': y*=4;
			}
		}
		a=decCow(y);
		while(a.size()<8){
			a='V'+a;
		}
		cin>>b;
		cout<<(a==b?"YES":"NO")<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}