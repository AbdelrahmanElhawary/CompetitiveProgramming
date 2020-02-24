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
long double cosRule(long double a, long double b, long double c) {
	// Handle denom = 0
	long double res = (b * b + c * c - a * a) / (2 * b * c);
	if (res > 1)  
		res = 1;
	if (res < -1)
		res = -1;
	return acos(res); 
} 
int circleCircleIntersection(const point& c1, const long double& r1, const point& c2, const long double& r2, point& res1, point& res2) {
	if (same(c1, c2) && fabs(r1 - r2) < EPS) {
		res1 = res2 = c1;
		return fabs(r1) < EPS ? 1 : OO;
	}
	long double len = length(vec(c1, c2));
	if (fabs(len - (r1 + r2)) < EPS || fabs(fabs(r1 - r2) - len) < EPS) {
		point d, c; 
		long double r;
		if (r1 > r2) 
			d = vec(c1, c2), c = c1, r = r1; 
		else
			d = vec(c2, c1), c = c2, r = r2; 
		res1 = res2 = normalize(d) * r + c; 
		return 1;
	}
	if (len > r1 + r2 || len < fabs(r1 - r2)) 
		return 0;
	long double a = cosRule(r2, r1, len);
	point c1c2 = normalize(vec(c1, c2)) * r1;
	res1 = rotate(c1c2, a) + c1;
	res2 = rotate(c1c2, -a) + c1;
	return 2;
}
int par[N], rnk[N];
int n;
int find(int u) {
	if (u == par[u])return u;
	return par[u] = find(par[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)return;
	if (rnk[u] < rnk[v])swap(u, v);
	rnk[u] += rnk[v];
	par[v] = u;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(3);
	while (cin >> n && n != -1) {
		vector<point>v(n);
		vector<ld>vr(n);
		for (int i = 0; i < n; i++) {
			ld x, y, r;
			cin >> x >> y >> r;
			v[i] = point(x, y);
			vr[i] = r;
			par[i] = i;
			rnk[i] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				point p1, p2;
				if (circleCircleIntersection(v[i], vr[i], v[j], vr[j], p1, p2)) {
					merge(i,j);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, rnk[i]);
		if (ans == 1)
			cout << "The largest component contains " << ans << " ring.\n";
		else
			cout << "The largest component contains "<<ans<<" rings.\n";
	}
	return 0;


}