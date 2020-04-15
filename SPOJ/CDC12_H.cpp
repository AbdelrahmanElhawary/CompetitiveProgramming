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
const int N = 1e5 + 10, M = 1e6 + 50, mod = 1e9+7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int n, q;
ll tree[N << 2], lazy[N << 2];
void push_down(int ind,int s,int e) {
	if (lazy[ind]) {
		int l = ind << 1, r = l | 1;
		int mid = s + e >> 1;
		int sz1 = mid - s + 1;
		int sz2 = e - mid;
		lazy[l] += lazy[ind];
		lazy[r] += lazy[ind];
		tree[l] += lazy[ind]*sz1;
		tree[r] += lazy[ind]*sz2;
		lazy[ind] = 0;
	}
}
void update(int ind, int s, int e, int x, int y) {
	if (x > e || y < s)return;
	if (s >= x && e <= y) {
		lazy[ind]++;
		tree[ind] += (e - s + 1);
		return;
	}
	push_down(ind,s,e);
	int mid = s + e >> 1;
	int l = ind << 1, r = l | 1;
	update(l, s, mid, x, y);
	update(r, mid + 1, e, x, y);
	tree[ind] = tree[l] + tree[r];
}
ll solve(int ind, int s, int e, int x, int y) {
	if (x > e || y < s)return 0;
	if (s >= x && e <= y)
		return tree[ind];
	push_down(ind,s,e);
	int mid = s + e >> 1;
	int l = ind << 1, r = l | 1;
	return solve(l, s, mid, x, y) + solve(r, mid + 1, e, x, y);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(3);
	//srand(time(0));
	int t, tt=1;
	cin >> t;
	while (t--) {
		cout << "Scenario #" << tt++ << ":\n";
		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
		cin >> n >> q;
		while (q--) {
			string s;int l, r;
			cin >> s >> l >> r;
			if (s[0] == 'a')
				cout << solve(1, 1, n, l, r) << endl;
			else {
				update(1, 1, n, l, r);
				cout << "OK\n";
			}
		}
	}
	return 0;
}