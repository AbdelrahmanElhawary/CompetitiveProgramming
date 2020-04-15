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
int tree[N << 2];
int ar[N];
int last[N];
void update(int ind, int s, int e, int x,int val) {
	if (x > e || x < s)return;
	if (s == e) {
		tree[ind] = val;
		return;
	}
	int mid = s + e >> 1;
	int l = ind << 1, r = l | 1;
	update(l, s, mid, x, val);
	update(r, mid + 1, e, x, val);
	tree[ind] = min(tree[l] ,tree[r]);
}
int solve(int ind, int s, int e, int x, int y) {
	if (x > e || y < s)return 1e9;
	if (s >= x && e <= y)
		return tree[ind];
	int mid = s + e >> 1;
	int l = ind << 1, r = l | 1;
	return min(solve(l, s, mid, x, y),solve(r, mid + 1, e, x, y));
}
void build(int ind, int s, int e) {
	if (s == e) {
		tree[ind] = ar[s];
		return;
	}
	int mid = s + e >> 1;
	build(ind << 1, s, mid);
	build(ind << 1 | 1, mid + 1, e);
	tree[ind] = min(tree[ind << 1], tree[ind << 1 | 1]);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(3);
	//srand(time(0));
	int tt = 1;
	while (cin>>n) {
		map<int, int>mp;
		for (int i = 1; i <= n; i++) {
			cin >> ar[i];
			last[i] = mp[ar[i]];
			mp[ar[i]] = i;
		}
		build(1, 1, n);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!ar[i])continue;
			if (!last[i])ans++;
			else {
				int x = solve(1, 1, n, last[i], i);
				if (x < ar[i])++ans;
			}
		}
		cout<<"Case "<<tt++<<": " << ans << endl;
	}
     return 0;
}