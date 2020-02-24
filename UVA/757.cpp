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
int n, h;
int f[N];// fish
int d[N];// dec
int t[N];//travel time
int vid;
int vis[N][20 * 60];
int dp[N][20 * 60];
int solve(int ind, int cur) {
	//cout << ind << " " << cur << endl;
	if (cur >= h)
		return 0;
	if (ind == n)
		return 0;
	int& ret = dp[ind][cur];
	if (vis[ind][cur] == vid)
		return ret;
	vis[ind][cur] = vid;
	ret = 0;
	int add = 0, x = f[ind];
	do {
		ret = max(ret, solve(ind + 1, cur + t[ind]) + add);
		cur += 5;
		add += x;
		x = max(0, x - d[ind]);
	} while (cur + t[ind] <= h);
	if (cur <= h) {
		while (cur + 5 <= h)cur += 5, add += x, x = max(0, x - d[ind]);
		ret = max(ret, add);
	}
	return ret;
}
vector<int>ans;
void build(int ind, int cur) {
	if (ind == n)
		return;
	int ret = dp[ind][cur];
	int x = (h - cur - t[ind]) / 5;
	while (cur + t[ind] + 5 * x > h)--x;
	int y = f[ind];
	int x2 = cur, op2 = 0;
	while (x2 + 5 <= h)
		op2 += y, y = max(0, y - d[ind]), x2 += 5;
	vector<int>op;
	int add = 0;
	y = f[ind];
	if (ret == op2) { x = -1; ans.push_back(x2 - cur); }
	if (x < 0) {
		while (ans.size() < n)ans.emplace_back(0);
		return;
	}
	for (int i = 0; i <= x; i++) {
		op.push_back(dp[ind + 1][cur + t[ind] + i * 5] + add);
		add += y;
		y = max(0, y - d[ind]);
	}
	for (int i = x; i > -1; --i) {
		if (op[i] == ret) {
			ans.push_back(i * 5);
			build(ind + 1, cur + t[ind] + i * 5);
			return;
		}
	}
	return;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(3);
	bool ok = 0;
	while (cin>>n&&n){
		if (ok)cout << endl;
		ok = 1;
		cin >> h; h *= 60;
		for (int i = 0; i < n; i++)
			cin >> f[i];
		for (int i = 0; i < n; i++)
			cin >> d[i];
		for (int i = 0; i < n - 1; i++)
			cin >> t[i], t[i] *= 5;
		vid++;
		t[n - 1] = 0;
		ans.clear();
		int x = solve(0, 0);
		build(0, 0);
		for (int i = 0; i < ans.size(); i++) {
			if (i)cout << ", ";
			cout << ans[i];
		}
		cout << "\nNumber of fish expected: "<<x<<"\n";
	}
	return 0;


}