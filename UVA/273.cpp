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
const int N = 1e3 + 50, M = 4e4 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
bool onSegment(point p, point q, point r) {
	if (q.X <= max(p.X, r.X) && q.X >= min(p.X, r.X) &&
		q.Y <= max(p.Y, r.Y) && q.Y >= min(p.Y, r.Y))
		return true;
	return false;
}
int orientation(point p, point q, point r) {
	int val = (q.Y - p.Y) * (r.X - q.X) - (q.X - p.X) * (r.Y - q.Y);
	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}
bool doIntersect(point p1, point q1, point p2, point q2) {
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if (o1 != o2 && o3 != o4)
		return true;
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
	return false;
}
int par[N];
int find(int u) {
	if(par[u] == u)
		return u;
	return par[u] = find(par[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	//cout << u << " " << v << endl;
	if (u == v)return;
	par[u] = v;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	int t; cin >> t;
	bool f = 0;
	while (t--) {
		if (f)cout << endl;
		f = 1;
		int n; cin >> n;
		vector<point>v1(n), v2(n);
		for(int i=0;i<n;i++){
			int x, y; cin >> x >> y;
			v1[i] = point(x, y);
			cin >> x >> y;
			v2[i] = point(x, y);
			par[i] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (doIntersect(v1[i], v2[i], v1[j], v2[j]))
					merge(i, j);
			}
		}
		int a, b;
		while (cin >> a >> b) {
			if (!a || !b)break;
			if (find(a - 1) == find(b - 1))
				cout << "CONNECTED\n";
			else cout << "NOT CONNECTED\n";
		}
	}
	return 0;

}