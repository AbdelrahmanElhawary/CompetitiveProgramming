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
const int N = 1e6 + 50, M = 4e4 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
struct node {
	point p;
	ld dis;
};
long double pointLineDist(const point& a, const point& b, const point& p) {
	if (same(a, b))  
		return hypot(a.X - p.X, a.Y - p.Y);
	return fabs(cross(vec(a, b), vec(a, p)) / length(vec(a, b)));
}
node pointSegmentDist(const point& a, const point& b, const point& p) {
	if (dot(vec(a, b), vec(a, p)) < EPS)
		return { a,length(vec(a, p)) };
	if (dot(vec(b, a), vec(b, p)) < EPS)
		return { b,length(vec(b, p)) };
	node u;
	u.dis = pointLineDist(a, b, p);
	ld k = dot(vec(a, p), vec(a, b)) / dot(vec(a, b), vec(a, b));
	u.p = a + vec(a, b) * k;
	return u;
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(4);
	point m;
	ld x, y;
	while (cin >> x >> y) {
		m = point(x, y);
		int n; cin >> n;
		vector<point>v(n + 1);
		for (int i = 0; i <= n; i++) {
			cin >> x >> y;
			v[i] = point(x, y);
		}
		node ans; ans.dis = 1e18;
		for (int i = 0; i < n; i++) {
			node u = pointSegmentDist(v[i], v[i + 1], m);
			if (u.dis < ans.dis) {
				ans = u;
			}
		}
		cout << ans.p.X << endl << ans.p.Y << endl;
	}
	return 0;

}