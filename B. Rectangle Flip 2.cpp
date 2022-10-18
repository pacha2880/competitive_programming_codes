#include <bits/stdc++.h>


#define pb                push_back

#define all(a)            (a).begin(), (a).end()
#define mem(a,h)          memset(a, (h), sizeof(a))
#define mul(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (ll i = b; i < e; i++)
#define fore(i, b, e)    for (ll i = b; i < e; i++)


using namespace std;



typedef long long  ll;

//typedef tree<vh,null_type,less<vh>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;
#define fi first
#define se second
#define ptr item*
#define __ll128 ll
#define tam 510
#define tamlog 14
const ll INF= 1e18;
const ll MOD= 1e9+7;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

typedef double ldb;
ll suf[tam],pref[tam];
vi V;
ll getquery1(int iz,int der,int riz,int &rder,int hasta)
{
    //<<"1 ";

    ll total=0,m;
    forr(j,iz,der)
    {
        while(riz<rder)
        {
            if (V[j]>V[rder])rder--;
            else break;
        }
        m=(rder-riz);

        total+=m*V[j];
        total+=pref[rder+1];
        total-=pref[hasta+1];

    }

    return total;
}
ll getquery2(int iz,int der,int &riz,int rder,int hasta)
{

    assert(riz<=rder);
    //<<"2 "<<endl;
    //<<"go 2"<<endl;
    //<<iz<<' '<<der<<' '<<riz<<' '<<rder<<' '<<hasta<<endl;
    ll total=0,m;
    for(int j=iz;j>der;j--)
    {
        while(riz<rder)
        {
            if (V[j]>V[riz])riz++;
            else break;
        }
        m=(rder-riz);
        total+=m*V[j];
        //<<m<<' '<<j<<endl;
        if (riz>=1)
        total+=suf[riz-1];
        if (hasta>=1)
        total-=suf[hasta-1];
    }
    //<<"query2 "<<total<<endl;
    return total;
}
ll init(vi &v,int pos,vector<ii> quers)
{
    V=v;
    int m=v.size();
    vi dp,v1,v2;
    vi suf1,suf2;
    forr(i,0,m)
    {
        if (i==pos)
        {
            v1.pb(v[i]);
            v2.pb(v[i]);
            continue;
        }
        if (i<pos)
            v1.pb(v[i]);
        else
            v2.pb(v[i]);
    }
    reverse(all(v2));

    ll antot=0;
    dp=vi(pos+v2.size(),0);

    forr(i,0,v1.size())
        suf1.pb(antot+v1[i]),antot=suf1.back();
    antot=0;
    forr(i,0,v2.size())
        suf2.pb(antot+v2[i]),antot=suf2.back();

    int p2=0;
    ll atot=0;
    forr(i,0,pos+1)
    {
        while(p2<v2.size())
        {
            if (v2[p2]<v1[i])
                p2++;
            else
                break;
        }
            dp[i]=(suf2.size()-p2)*v1[i];
        if (p2>0)
            dp[i]+=suf2[p2-1];
        atot+=v1[i];
    }
    dp[pos]+=atot;//dp[pos]-=v[pos];

//    <<endl;
//    forr(i,0,m)
//    {
//        <<dp[i]<<' ';
//    }
//    <<endl;

    reverse(all(v2));
    p2=0;
    for(int i=v2.size()-1;i>=1;i--)
    {
        //<<v2[i]<<' ';
        while(p2<v1.size())
        {
            if (v1[p2]<v2[i])
                p2++;
            else break;
        }

        dp[i+pos]=(suf1.size()-p2)*v2[i];
        if (p2>0)
            dp[i+pos]+=suf1[p2-1];
    }
//    <<endl;
//    forr(i,0,m)
//    {
//        <<dp[i]<<' ';
//    }
//    <<endl;
    ll total=0;
    forr(i,0,m)
        total+=dp[i];
        //<<total/2<<" tot y pos "<<pos<<endl;
    total/=2;
    ll FINAL=0;

    //<<total<<endl;
    int miiz=0;
    int mider=m-1;
    antot=0;
    forr(i,0,pos)
    {
        suf[i]=antot+v[i];
        antot=suf[i];
    }
    antot=0;
    for(int i=m-1;i>=pos;i--)
        pref[i]=antot+v[i],
        antot=pref[i];
    int pder1,piz1;
    piz1=0,pder1=m-1;

    for(auto par:quers)
    {
        int li=par.fi;
        int ri=par.se;

        assert(li<=ri);
        int K1=abs(li-miiz);
        int K2=abs(ri-mider);
        assert(li<=pos && ri>=pos);

        //<<li<<" "<<ri<<" :-> ";

        pder1=min(pder1,mider);


        total-=getquery1(miiz,li,pos-1,pder1,mider);
        piz1=max(piz1,miiz);


        total-=getquery2(mider,ri,piz1,pos+1,miiz);
        int paux=miiz;

        total+=getquery2(mider,ri,paux,li,miiz);
        //<<total<<endl;
        FINAL+=total;
        miiz=li;
        mider=ri;

    }
    //<<"FINAL ";
    //<<FINAL<<endl;
    return FINAL;
}

int N, M;
ll res[tam * tam];
int sum[tam][tam], tab[tam][tam];
ll hola(int x, int y)
{
	tab[x][y] = 1;
	fore(i, 0, N)
		sum[i + 1][y] = sum[i][y] + tab[i][y];
	int fro = y, to = y;
	while(fro > 0 && tab[x][fro -1] == 1)
		fro--;
	while(to < M - 1 && tab[x][to + 1] == 1)
		to++;
	int ta = to - fro + 1, al = x;
	while(al < N- 1 && tab[al + 1][y] == 1)
		al++;
	vi ron(ta);
	ron[y - fro] = al - x + 1;
	// <<'@'<<al<<' '<<x<<'\n';
	int ax = al;
	fore(i, y + 1, to + 1)
	{
		while(sum[al + 1][i] - sum[x][i] < al + 1 - x)
			al--;
		ron[i - fro] = al - x + 1;
	}
	al = ax;
	for(int i = y - 1; i >= fro; i--)
	{
		while(sum[al + 1][i] - sum[x][i] < al + 1 - x)
			al--;
		ron[i - fro] = al - x + 1;
	}
	al = x;
	while(al > 0 && tab[al - 1][y] == 1)
		al--;
	// <<"&"<<al<<' '<<x<<'\n';
	vector<int> ran(ta);
	ran[y - fro] = x - al + 1;
	ax = al;
	fore(i, y + 1, to + 1)
	{
		while(sum[x + 1][i] - sum[al][i] < x + 1 - al)
			al++;
		ran[i - fro] = x - al + 1;
	}
	al = ax;
	for(int i = y - 1; i >= fro; i--)
	{
		while(sum[x + 1][i] - sum[al][i] < x + 1 - al)
			al++;
		ran[i - fro] = x - al + 1;
	}
	al = ax;
	vii que(x - al + 1);
	int b = 0, e = ran.size() - 1;
	// assert(0);
	fore(i, 1, x - al + 2)
	{
		while(ran[b] < i)
			b++;
		while(ran[e] < i)
			e--;
		que[i - 1] = {b, e};
	}
	// <<"%"<<x<<' '<<y<<'\n';
	// fore(i, 0, n)
	// {
	// 	fore(j, 0, m)
	// 	{
	// 		if(i == x && j == y)
	// 			<<"#";
	// 		else
	// 			<<tab[i][j];
	// 	}
	// 	<<'\n';
	// }
	// for(int x : ran)
	// 	<<x<<' ';
	// <<'\n';
	// for(int x : ron)
	// 	<<x<<' ';
	// <<'\n';
	// <<fro<<'|'<<to<<'\n';
	// <<y - fro<<'\n';
	// for(ii cat : que)
	// 	<<cat.f<<','<<cat.s<<' ';
	// <<'\n';
	return init(ron, y - fro, que);
}
ii ar[510 * 510];
#define f fi
#define s se
int main()
{
	 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	cin>>N>>M;
	fore(i, 0, N* M)
	{
		cin>>ar[N* M- i - 1].f>>ar[N* M - i - 1].s;
		ar[N * M - i - 1].f--;ar[N * M - i - 1].s--;
	}
	res[N * M - 1] = 0;ll ras=0;
	fore(i, 0, N * M - 1)
	{
		// <<"query "<<i<<' '<<ar[i].f + 1<<' '<<ar[i].s + 1<<'\n';
		// <<"&&\n";
		res[N * M - i - 2] = hola(ar[i].f, ar[i].s)+ras;
		ras=res[N * M - i - 2];
	}
	fore(i, 0, N* M)
		cout<<res[i]<<'\n';
	return 0;
}