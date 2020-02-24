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
map<pair<int,int>,int> cost;
int a, b, c;
bool check(int x, int y) {
	if (cost.find(mk(x,y))==cost.end())
		return 1;
	return 0;
}
pair<int, int>pour(int x, int y, int m) {
	int rem = m - y;
	int tok = min(x, rem);
	x -= tok;
	y += tok;
	return mk(x, y);
}
int main() {
	fast_in_out();
	//	cout << fixed << setprecision(9);
	int t; cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		if (a > b)swap(a, b);
		if (c > b) { cout << "-1\n"; continue; }
		if (c % gcd(a, b)) { cout << "-1\n"; continue; }
		cost[mk(0,0)] = 0;
		queue<pair<int, int>>q;
		int ret = -1;
		q.push({ 0,0 });
		cost.clear();
		while (q.size()) {
			int x = q.front().first;
			int y = q.front().second;
			int cst = cost[mk(x, y)];
			//cout << x << " " << y << endl;
			q.pop();
			if (x == c || y == c) {
				ret = cst;
				break;
			}
			if (check(a, y)) {
				cost[mk(a, y)] = cst + 1;
				q.push({ a,y });
			}
			if (check(x, b)) {
				cost[mk(x, b)] = cst + 1;
				q.push({ x,b });
			}
			if (check(0, y)) {
				cost[mk(0, y)] = cst + 1;
				q.push({ 0,y });
			}
			if (check(x, 0)) {
				cost[mk(x, 0)] = cst + 1;
				q.push({ x,0 });
			}
			pair<int, int>p = pour(x, y, b);
		//	cout << x << " " << y << " " << a << " " << b << endl;
		//	cout << p.first << " " << p.second << endl;
			if (check(p.first, p.second)) {
				cost[mk(p.first, p.second)] = cst + 1;
				q.push({ p.first,p.second });
			}
			p = pour(y, x, a);
			swap(p.first, p.second);
		//	cout << p.first << " " << p.second << endl;
			if (check(p.first, p.second)) {
				cost[mk(p.first, p.second)] = cst + 1;
				q.push({ p.first,p.second });
			}
		}
		cout << ret << endl;
	}
	return 0;

}