#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<chrono>
#include<unordered_map>
#include<random>
#include<complex> 
using namespace std;
typedef complex<long double> point;
#define vec(a,b) ((b)-(a))
#define X real()
#define Y imag()
#define length(v) ((long double)hypot((v).Y,(v).X))
#define cross(a,b) ((conj(a)*(b)).imag())
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#ifndef ONLINE_JUDGE
int __builtin_popcount(int mask) {
	int cnt = 0;
	for (int i = 0; i < 23; i++)
		if (mask & (1 << i)) ++cnt;
	return cnt;
}
#endif
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ld eps = 1e-9;
const int N = 1e3 + 50, M = 1e5 + 10, mod = 1e9+7;
ll gcd(ll a, ll b) {  return b ?gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }

int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	int n;
	while (cin >> n&&n) {
		int mx=1e9, my=1e9, mz=1e9, Mx=0, My=0, Mz=0;
		for (int i = 0; i < n; i++) {
			int x, y, z, d;
			cin >> x >> y >> z>>d;
			mx = min(mx, x+d);
			my = min(my, y+d);
			mz = min(mz, z+d);
			Mx = max(Mx, x);
			My = max(My, y);
			Mz = max(Mz, z);
		}
		ll ans = 0;
		if (Mx > mx || My > my || Mz > mx)ans = 0;
		else ans = 1LL * (mx - Mx) * (My - my) * (Mz - mz);
		cout <<ans << endl;
	}
	return 0;

}