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
ll tree[N], tmp1[N], tmp2[N], sum[N];
int ar[N];
void pushup(int ind) {
	int l = ind << 1, r = l | 1;
	sum[ind] = sum[l] + sum[r];
	tree[ind] = tree[l] + tree[r];
}
void pushdown(int ind,int s,int e) {
	int l = ind << 1, r = l | 1, mid = s + e >> 1;
	// update x
	if (tmp1[ind]) {
		tmp2[l] = tmp2[r] = 0; // remove add from child
		sum[l] = (mid - s + 1)*tmp1[ind];
		sum[r] = (e - mid)*tmp1[ind];
		tree[l] = (mid - s + 1)*tmp1[ind] * tmp1[ind];
		tree[r] = (e - mid)*tmp1[ind] * tmp1[ind];
		tmp1[l] = tmp1[r] = tmp1[ind];
		tmp1[ind] = 0;
	}
	// add x
	if (tmp2[ind]) {
		tree[l] = tree[l] + (mid - s + 1)*tmp2[ind] * tmp2[ind] + 2 * tmp2[ind] * sum[l];
		tree[r] = tree[r] + (e - mid)*tmp2[ind] * tmp2[ind] + 2 * tmp2[ind] * sum[r];
		sum[l] = sum[l] + (mid - s + 1)*tmp2[ind];
		sum[r] = sum[r] + (e - mid)*tmp2[ind];
		tmp2[l] = tmp2[r] = tmp2[ind];
		tmp2[ind] = 0;
	}
}
void build(int ind, int l, int r) {
	tmp1[ind] = tmp2[ind] = 0;
	if (l == r) {
		sum[ind] = ar[l];
		tree[ind] = 1LL * ar[l] *ar[l];
		return;
	}
	int mid = l + r >> 1;
	build(ind << 1, l, mid);
	build(ind << 1 | 1, mid + 1, r);
	pushup(ind);
}
void update(int ind, int s, int e, int x, int y,int val,bool op)
{
	if (x > e || y < s) return;
	if (s >= x && e <= y){
		if (!op) {// update
			tmp1[ind] = val;
			tmp2[ind] = 0;
			sum[ind] = 1LL*(e - s + 1)*val;
			tree[ind] = sum[ind] * val;
		}
		else { //add
			tmp2[ind] += val;
			tree[ind] = tree[ind] + sum[ind] * 2 * val + 1LL * (e - s + 1)*val*val;
			sum[ind] += (e - s + 1)*val;
		}
		return;
	}
	pushdown(ind, s, e);
	int mid = s + e >> 1, l = ind << 1;
	update(l, s, mid, x, y, val, op);
	update(l | 1, mid + 1, e, x, y, val, op);
	pushup(ind);
	return;
}
long long solve(int ind, int s, int e, int x, int y)
{
	if (x > e || y < s) return 0;
	if (s >= x && e <= y)
		return tree[ind];
	int mid = s + e >> 1, l = ind << 1;
	long long left, right;
	pushdown(ind, s, e);
	left = solve(l, s, mid, x, y);
	right = solve(l | 1, mid + 1, e, x, y);
	return left + right;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	//freopen("fetiera.in", "r", stdin);
	//kolo ray7 , ya 5rabyy
	int t; cin >> t;
	int tt = 1;
	while (t--) {
		int n, q; cin >> n >> q;
		for (int i = 1; i <= n; i++)
			cin >> ar[i];
		build(1, 1, n);
		cout << "Case " << tt++ << ":\n";
		while (q--) {
			int op, l, r;
			cin >> op >> l >> r;
			if (op == 2)
				cout << solve(1, 1, n, l, r) << endl;
			else {
				int x; cin >> x;
				update(1, 1, n, l, r, x, op);
			}
		}

	}
	return 0;
}