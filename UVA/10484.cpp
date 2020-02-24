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
#define EPS 1e-9 
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a)) 
#define polar(r,t) ((r)*exp(point(0,(t)))) 
#define angle(v) (atan2((v).Y,(v).X)) 
#define length(v) ((long double)hypot((v).Y,(v).X)) 
#define lengthSqr(v) (dot(v,v)) 
#define dot(a,b) ((conj(a)*(b)).real()) 
#define cross(a,b) ((conj(a)*(b)).imag()) 
#define rotate(v,t) (polar(v,t)) 
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a)) 
#define reflect(p,m) ((conj((p)/(m)))*(m)) 
#define normalize(p) ((p)/length(p)) 
#define same(a,b) (lengthSqr(vec(a,b))<EPS) 
#define mid(a,b) (((a)+(b))/point(2,0)) 
#define perp(a) (point(-(a).Y,(a).X)) 
#define colliner pointOnLine 
enum STATE { IN, OUT, BOUNDRY };

#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define PI acos(-1.)
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
const ld eps = 1e-3;
const int N = 1e3 + 50, M = 4e4 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int prm[101];
vector<int>primes;
void pre() {
	for (int i = 2; i <= 100; i++) {
		if (!prm[i]) {
			primes.emplace_back(i);
			for (int j = i; j <= 100; j += i)
				prm[j] = i;
		}
	}
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(3);
	int n, d;
	pre();
	while (cin >> n >> d&&d) {
		d = abs(d);
		int m = d;
		map<int, int>mp;
		for (int i = 0; i < primes.size(); i++) {
			int p = primes[i];
			int cnt = 0;
			while (m % p == 0)m /= p, cnt++;
			mp[p] = -cnt;
		}
		if (m != 1) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 2; i <= n; i++) {
			int x = i;
			while (prm[x]) {
				int p = prm[x];
				int cnt = 0;
				while (x % p == 0)x /= p, cnt++;
				mp[p] += cnt;
			}
		}
		ll ans = 1;
		for (auto e : mp) {
			if (e.second < 0) {
				ans = 0; break;
			}
			ans *= (e.second + 1);
		}
		cout << ans << endl;
	}
	return 0;

}