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
const ld eps = 1e-9;
const int N = 1e5 + 50, M = 4e4 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
vector<vector<int>>adj;
int root;
int mx=-1,ans;
void dfs(int u,int par=-1, int lv = 0) {
	if (lv > mx) { root = u, mx = lv; }
	for (auto e : adj[u])
		if (e != par)
			dfs(e, u, lv + 1);
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(9);
	int t; cin >> t;
	while (t--) {
		point a, u, b, v;
		int x, y;
		cin >> x >> y;
		a = point(x, y);
		cin >> x >> y;
		u = point(x, y);
		cin >> x >> y;
		b = point(x, y);
		cin >> x >> y;
		v = point(x, y);
		point p1 = u - a, p2 = b - a;
		ld ang1 = atan2(p1.Y, p1.X) - atan2(p2.Y, p2.X);
		p1 = v - b, p2 = a - b;
		ld ang2 = atan2(p1.Y, p1.X) - atan2(p2.Y, p2.X);
		while (ang1 < 0)ang1 = ang1 + PI + PI;
		while (ang2 < 0)ang2 = ang2 + PI + PI;
		while (ang1 >= PI + PI)ang1 = ang1 - PI - PI;
		while (ang2 >= PI + PI)ang2 = ang2 - PI - PI;
		ang1 = min(ang1, PI + PI - ang1);
		ang2 = min(ang2, PI + PI - ang2);
		//cout << ang1 << " " << ang2 << endl;
		if (fabs(ang1 - ang2) <= EPS)
			cout << "0\n";
		else if (ang1 < ang2)
			cout << "Hero\n";
		else cout << "Heroine\n";
	
	}
	return 0;

}