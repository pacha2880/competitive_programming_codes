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
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int c[24];
	for(int i=0;i<24;i++)
		cin>>c[i];
	if((c[23]==c[21]&&c[23]==c[22]&&c[23]==c[20]&&c[4]==c[5]&&c[4]==c[6]&&c[4]==c[7]&&
	((c[8]==c[9]&&c[8]==c[17]&&c[8]==c[19]&&c[0]==c[1]&&c[0]==c[16]&&c[0]==c[18]&&c[2]==c[3]&&c[2]==c[14]&&c[2]==c[12]&&c[10]==c[11]&&c[10]==c[13]&&c[10]==c[15])||
	(c[0]==c[1]&&c[0]==c[13]&&c[0]==c[15]&&c[12]==c[14]&&c[12]==c[8]&&c[12]==c[9]&&c[10]==c[11]&&c[10]==c[18]&&c[10]==c[16]&&c[17]==c[19]&&c[17]==c[2]&&c[17]==c[3])))||
	(c[0]==c[1]&&c[0]==c[2]&&c[3]==c[0]&&c[8]==c[9]&&c[9]==c[10]&&c[10]==c[11]&&
	((c[12]==c[13]&&c[13]==c[22]&&c[22]==c[23]&&c[4]==c[5]&&c[5]==c[14]&&c[14]==c[15]&&c[6]==c[7]&&c[7]==c[16]&&c[16]==c[17]&&c[18]==c[19]&&c[19]==c[21]&&c[21]==c[20])||
	(c[21]==c[20]&&c[20]==c[14]&&c[14]==c[15]&&c[12]==c[13]&&c[13]==c[6]&&c[6]==c[7]&&c[4]==c[5]&&c[5]==c[18]&&c[18]==c[19]&&c[16]==c[17]&&c[17]==c[22]&&c[22]==c[23])))||
	(c[16]==c[17]&&c[17]==c[18]&&c[18]==c[19]&&c[12]==c[13]&&c[13]==c[14]&&c[14]==c[15]&&
	((c[1]==c[3]&&c[3]==c[23]&&c[23]==c[21]&&c[22]==c[20]&&c[20]==c[10]&&c[10]==c[8]&&c[4]==c[6]&&c[6]==c[11]&&c[11]==c[9]&&c[0]==c[2]&&c[2]==c[7]&&c[7]==c[5])||
	(c[0]==c[2]&&c[2]==c[20]&&c[20]==c[22]&&c[21]==c[23]&&c[23]==c[9]&&c[9]==c[11]&&c[8]==c[10]&&c[10]==c[7]&&c[7]==c[5]&&c[4]==c[6]&&c[6]==c[3]&&c[3]==c[1]))))
		cout<<"YES";
	else
		cout<<"NO";

	return 0;
}