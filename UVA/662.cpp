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
const int N = 2e2 + 50, M = 4e4 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int dis[N][N], op[N][N];
int n, m;
int ar[N], cum[N];
int dp[N][33], vis[N][33];
int vid;
int get(int l, int r,int k) {
	int sz = r - l + 1;
	int x = ar[k] * sz;
	int sum = cum[r] - cum[l - 1];
	return abs(x - sum);
}
int solve(int ind, int cnt) {
	if (ind == n+1) {
		if (cnt == m)return 0;
		return 1e9;
	}
	if (cnt == m)return 1e9;
	int& ret = dp[ind][cnt];
	if (vis[ind][cnt] == vid)return ret;
	vis[ind][cnt] = vid;
	if (cnt == m - 1)
		return ret = dis[ind][n];
	ret = solve(ind + 1, cnt + 1);
	for (int j = ind+1; j <= n; j++) {
		ret = min(ret, solve(j + 1, cnt + 1) + dis[ind][j]);
	}
	return ret;
}
void print(int id,int x, int l, int r) {
	if (l != r)
		cout << "Depot " << id << " at restaurant " << x << " serves restaurants " << l << " to " << r << "\n";
	else
		cout << "Depot "<<id<<" at restaurant "<<x<<" serves restaurant "<<l<<"\n";
}
void build(int ind, int cnt) {
	if (ind == n + 1)
		return;
	int ret = dp[ind][cnt];
	if (cnt == m - 1) {
		print(cnt+1,op[ind][n], ind, n);
		return;
	}
	for (int j = ind; j <= n; j++) {
		if (ret == solve(j + 1, cnt + 1) + dis[ind][j]) {
			print(cnt + 1, op[ind][j], ind, j);
			build(j+1, cnt + 1);
			return;
		}
	}
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(3);
	int tt = 1;
	while (cin >> n >> m && n) {
		cout << "Chain " << tt++ << "\n";
		int mn = 1e9;
		for (int i = 1; i <= n; i++)
			cin >> ar[i], cum[i] = ar[i] + cum[i - 1];
		for (int i = 1; i <= n; i++) {
			dis[i][i] = 0;
			op[i][i] = i;
			for (int j = i + 1; j <= n; j++) {
				dis[i][j] = 1e9;
				for (int k = i; k <= j; k++) {
					int lft = get(i, k, k);
					int rgt = get(k, j, k);
					if (lft + rgt < dis[i][j]) {
						dis[i][j] = lft + rgt;
						op[i][j] = k;
					}
				}
			}
		}
		++vid;
		int total = solve(1, 0);
		build(1, 0);
		cout << "Total distance sum = "<<total<<"\n\n";
	}


	return 0;


}