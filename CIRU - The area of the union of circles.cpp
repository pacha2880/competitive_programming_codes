#include<bits/stdc++.h>
#define ll int
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define per(i,a,b) for(ll i=(ll)a;i>(ll)b;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;

inline double sq(double a){ return a*a;};
inline double parg(double d){
	if(d>=pii){
		d-=pii;
	}
	return d;
}

bool inter(int i, int j, vector<double>& x, vector<double>& y ,vector<double>& r){
	double d = sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]));
	if(d > r[i] + r[j] || abs(r[i] - r[j]) >= d){
		return false;
	}
	return true;
}

void quadratic(double a,double b,double c,double& x1,double& x2){
	x1 = (-b-sqrt(sq(b)-4*a*c))/(2*a);
	x2 = (-b+sqrt(sq(b)-4*a*c))/(2*a);
}

void lyx(double a,double b,double c,double& x, double& y){
	if(b){
		y=(c-a*x)/b;
	}
}

bool lcf(double x,double y,double r,double a,double b, double c,vector<double>& ans){
	double x1,x2,y1,y2;
	if(b)
	{
		quadratic(1+sq(a/b),-2*x-2*(a/b)*(c/b-y),sq(x)+sq(c/b-y)-sq(r),x1,x2);
		lyx(a,b,c,x1,y1);
		lyx(a,b,c,x2,y2);
		ans = {x1,y1,x2,y2};
	}
	else{
		quadratic(1,-2*y,sq(y)+sq(c/a-x)-sq(r),y1,y2);
		x1=c/a;
		ans={x1,y1,x1,y2};
	}
	return true;
}

inline double gth(double x,double y){
	if(x>0.0&&y==0.0){ return 0.0;}
	if(x>0.0&&y>0.0){ return atan(y/x);}
	if(x==0.0&&y>0){ return pi/2.0;}
	if(x<0.0&&y>0.0){ return pi-atan(abs(y/x));}
	if(x<0.0&&y==0.0){ return pi;}
	if(x<0.0&&y<0.0){ return pi+atan(abs(y/x));}
	if(x==0.0&&y<0.0){ return 1.5*pi;}
	if(x>0.0&&y<0.0){ return pii-atan(abs(y/x));}
	return 0.0;
}

inline double f1(double x,double y, double r, double theta){
	return r*(x*sin(theta))+ sq(r)*(theta+sin(theta)*cos(theta))*0.5;
}

double f(int n, vector<double> x, vector<double> y, vector<double> r){
	double ans;
	rep(i,0,n){
		vector<pair<double, double>> iPnts{};
		rep(j, 0, n){
			if(i != j && inter(i, j, x, y, r)){
				vector<double> ans(4, 0.0);
				lcf(x[i], y[i], r[i], 2 * (x[j] - x[i]), 2 * (y[j] - y[i])
					, sq(r[i]) - sq(r[j]) + sq(x[j]) - sq(x[i]) + sq(y[j]) - sq(y[i]), ans);
				double theta1 = gth(ans[0] - x[i], ans[1] - y[i]), theta2 = gth(ans[2] - x[i], ans[3] - y[i]);
				if(theta1>theta2){ swap(theta1,theta2);}

				if(sq(x[j]-x[i]-r[i]*cos((theta1+theta2)/2.0))+sq(y[j]-y[i]-r[i]*sin((theta1+theta2)/2.0))<sq(r[j])){
					iPnts.pb({theta1,theta2});
				}
				else{
					if(sq(x[j]-x[i]-r[i]*cos(parg((theta1+theta2)/2.0+pi)))+sq(y[j]-y[i]-r[i]*sin(parg((theta1+theta2)/2.0+pi)))<sq(r[j])){
						iPnts.pb({theta2,pii});
						iPnts.pb({0.0,theta1});
					}
				}
			}
		}
		if(iPnts.size()==0){
			ans+=pi*sq(r[i]);
		}
		else{
			sort(full(iPnts));
			double theta1=iPnts[0].F,theta2=iPnts[0].S;
			vector<pair<double,double>> intlims{{0.0,theta1}};

			rep(j,0,iPnts.size()){
				while(j<iPnts.size()&&theta2>=iPnts[j].F){
					theta2=max(iPnts[j].S,theta2);
					j++;
				}
				if(j<iPnts.size()){
					intlims.pb({theta2,iPnts[j].F});
					theta1=iPnts[j].F;
					theta2=iPnts[j].S;
				}
			}
			intlims.pb({theta2,pii});

			rep(j,0,intlims.size()){
				if(!(intlims[j].F==0.0&&intlims[j].S==pii)&&(intlims[j].F!=intlims[j].S)){
					ans+=(f1(x[i],y[i],r[i],intlims[j].S)-f1(x[i],y[i],r[i],intlims[j].F));
				}
			}
		}
	}
	return ans;
}

inline bool f4(int j,int i,vector<double>& x,vector<double>& y,vector<double>& r){
	return (j!=i && (sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]))+r[j])<=r[i])? true:false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<double> xp(n,0.0),yp(n,0.0),rp(n,0.0),x{},y{},r{};
	rep(i,0,n){
		cin>>xp[i]>>yp[i]>>rp[i];
		rp[i]=abs(rp[i]);
	}

	vector<bool> in(n,true);
	rep(i,0,n){
		rep(j,0,n){
			if(in[i]&&f4(j,i,xp,yp,rp)){
				in[j]=false;
			}
		}
	}
	rep(i,0,n){
		if(in[i]){
			x.pb(xp[i]);
			y.pb(yp[i]);
			r.pb(rp[i]);
		}
	}
	cout<<fixed<<setprecision(3)<<f(x.size(),x,y,r)<<"\n";
	return 0;
}