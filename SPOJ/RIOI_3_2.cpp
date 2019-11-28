/*
for:
Hussien , Ayman , Emad
Abanob , George , Genawy
Ka8eem , Mosta7il , Stawro
Shahat , Omar
ICPC DREAM
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<chrono>
#include<unordered_map>
#include <random>
#include <complex> 
using namespace std;
#define ll long long
#define ld double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define holla(x,y) cout <<"# holla "<<y<<" "<< #x << " is " << x << endl;
typedef complex<long double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(), (n).end()
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
#define reflect(p,m) ((conj((p)/(n)))*(n))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine 
enum STATE { IN, OUT, BOUNDRY };
const double PI = acos(-1.0);
#ifndef ONLINE_JUDGE
int __builtin_popcount(int mask) {
	int cnt = 0;
	for (int i = 0; i < 23; i++)
		if (mask&(1 << i)) ++cnt;
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
const int N = 4e5 + 50, M = 500 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dp[21][N],dp2[21][N];
int solve2(int ind, int m) {
	if (ind == 0)
		return m == 0;
	if (ind < 0 || m < 0)return 0;
	int &ret = dp2[ind][m];
	if (ret != -1)return ret;
	ret = solve2(ind - 1, m - ind) + solve2(ind, m - ind);
	if (ret >= mod)ret -= mod;
	return ret;
}
int solve(int ind, int m) {
	int &ret = dp[ind][m];
	if (ret != -1)return ret;
	ret = solve2(ind, m);
	if (m)ret += solve(ind, m - 1);
	if (ret >= mod)ret -= mod;
	return ret;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	//freopen("fetiera.in", "r", stdin);
	//kolo ray7 , ya 5rabyy
	int t; cin >> t;
	memset(dp, -1, sizeof dp);
	memset(dp2, -1, sizeof dp2);
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << solve(n,m) << endl;
	}
	return 0;
}