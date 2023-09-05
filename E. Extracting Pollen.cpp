#include <iostream>
using namespace std;
int f[1000001];
int sd[1000001];
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
int main() {
	int ans, s, v, n, k, mx;
	mx = 0;
	// ios_base::sync_with_stdio(0); cin.tie(0);

	// cin >> n >> k;
    n = in();
    k = in();
	// scanf("%d %d", &n,&k);
	for(int i = 0; i < n; ++i) {
		// cin >> v;
        v = in();
		// scanf("%d", &v);
		mx = max(mx, v);
		f[v]++;
	}
	for(int i = 1; i <= mx; ++i)
		sd[i] = sd[i/10] + i%10;
	ans = 0;
	for(int v = mx; v > 0; v--) {
		if(v > 0 ) {
			s = sd[v];
			f[v-s] += f[v];
			if(k > f[v])
				k -= f[v];
			else {
				ans = s;
				k = 0;
				break;
			}
		}
	}
	cout << ans << '\n';
	// printf("%d\n", ans);
	return 0;
}