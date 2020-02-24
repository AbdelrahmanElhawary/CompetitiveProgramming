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
const int N = 1e2 + 50, M = 4e4 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
ll tim[N][N], dis[N][N];
int n, m;
void warshall(){
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (tim[i][j] > tim[i][k] + tim[k][j]) {
					tim[i][j] = tim[i][k] + tim[k][j];
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				else if (tim[i][j] == tim[i][k] + tim[k][j]) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
	return;
}
int main() {
	fast_in_out();
//	cout << fixed << setprecision(3);
	int t; cin >> t;
	bool f = 0;
	while (t--) {
		if (f)cout << endl;
		f = 1;
		cin >> n >> m;
		memset(tim, 63, sizeof tim);
		memset(dis, 63, sizeof dis);
		ll inf = tim[0][0];
		for (int i = 0; i < m; i++) {
			ll u, v, w, d;
			cin >> u >> v >> w >> d;
		//	cout << u << " " << v << " " << w << " " << d << endl;
			if (tim[u][v] > w)
				tim[u][v] = tim[v][u] = w,
				dis[u][v] = dis[v][u] = d;
			else if (tim[u][v] == w)
				dis[u][v] = dis[v][u] = min(dis[u][v], d);
		}
		warshall();
		int q; cin >> q;
		while (q--) {
			int u, v; cin >> u >> v;
			if (tim[u][v] == inf)
				cout << "No Path.\n";
			else cout << "Distance and time to reach destination is "<<dis[u][v]<<" & "<<tim[u][v]<<".\n";
		}
	}
	return 0;

}