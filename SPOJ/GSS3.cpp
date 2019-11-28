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
const int N = 4e5 + 50, M = 500 + 10, mod = 998244353;
const ld eps = 1e-9;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int ar[N];
struct node {
	ll tree = -1e15, sum = -1e15, lmx = -1e15, rmx = -1e15;
}seg[N];
node add(node a,node b){
	node temp;
	temp.lmx = max(a.sum + b.lmx, a.lmx);
	temp.rmx = max(b.sum + a.rmx, b.rmx);
	temp.sum = a.sum + b.sum;
	temp.tree = max({ a.tree,b.tree,a.rmx + b.lmx });
	return temp;
}
void pushup(int ind) {
	int l = ind << 1, r = l | 1;
	seg[ind].lmx = max(seg[l].sum + seg[r].lmx, seg[l].lmx);
	seg[ind].rmx = max(seg[r].sum + seg[l].rmx, seg[r].rmx);
	seg[ind].sum = seg[l].sum + seg[r].sum;
	seg[ind].tree = max({ seg[l].tree,seg[r].tree,seg[l].rmx + seg[r].lmx });
}
void build(int ind, int l, int r) {
	if (l == r) {
		seg[ind].sum = ar[l];
		seg[ind].lmx = ar[l];
		seg[ind].tree = ar[l];
		seg[ind].rmx = ar[l];
		return;
	}
	int mid = l + r >> 1;
	build(ind << 1, l, mid);
	build(ind << 1 | 1, mid + 1, r);
	pushup(ind);
}
void update(int ind, int s, int e, int x, int val) {
	if (x > e || x < s) return;
	if (s==e) {
		seg[ind].sum = val;
		seg[ind].lmx = val;
		seg[ind].tree = val;
		seg[ind].rmx = val;
		return;
	}
	int mid = s + e >> 1, l = ind << 1;
	update(l, s, mid, x, val);
	update(l | 1, mid + 1, e, x, val);
	pushup(ind);
	return;
}
node NANIIIIII;
node solve(int ind, int s, int e, int x, int y) {
	if (x > e || y < s) return NANIIIIII;
	if (s >= x && e <= y)
		return seg[ind];
	int mid = s + e >> 1, l = ind << 1;
	node left = solve(l, s, mid, x, y);
	node right = solve(l | 1, mid + 1, e, x, y);
	return add(left, right);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	//freopen("fetiera.in", "r", stdin);
	//kolo ray7 , ya 5rabyy
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];
	build(1, 1, n);
	int q; cin >> q;
	while (q--) {
		int op; cin >> op;
		if (!op) {
			int x, y; cin >> x >> y;
			//ar[x] = y;
			update(1, 1, n, x, y);
		}
		else {
			int x, y; cin >> x >> y;
			cout << solve(1, 1, n, x, y).tree << endl;
		}
	}
	return 0;
}