#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using vb = vector<bool>;
using vvl = vector<vl>;

void testCase();
void init();

signed main() {
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

init();
testCase();
return 0;
}

void init() {

}

void testCase() {
ll n, s, k;
cin >> s >> n >> k;

vl nums(k);
for (int i =0;i<k;i++) {
cin >> nums[i];
}

__int128 inf = (__int128)2e9+(ll)100;
auto mul = [&](__int128 x, __int128 y)->ll {
if (x == inf || y == inf) return inf;
return min(x*y, inf);
};

ll ans = 0;

auto lcm = [&](__int128 x, __int128 y) {
if (max(x,y) == inf) return inf;

return min(inf, x/__gcd(x,y) * y);
};

auto f = [&](ll x) {
x = lcm(x, s);
return n/x;
};

for (int i = 1;i<(1<<k);i++) {

ll num = 1;
for (int j = 0;j<k;j++) {
if ((i>>j)&1) {
num = mul(num, nums[j]);
}
}

ll total = f(num);

if (__builtin_popcount(i)&1) {
ans += total;
} else {
ans -= total;
}
}

cout << n/s - ans << "\n";
}