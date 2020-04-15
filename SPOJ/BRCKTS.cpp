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
int tree[N << 2];
int lft[N << 2];
int rgt[N << 2];
string str;
int n;
void push_up(int ind, int l, int r) {
	lft[ind] = lft[l] - min(lft[l], rgt[r]) + lft[r];
	rgt[ind] = rgt[r] - min(lft[l], rgt[r]) + rgt[l];
}
void build(int ind, int s, int e) {
	lft[ind] = rgt[ind] = 0;
	if (s == e) {
		if (str[s - 1] == '(')
			lft[ind] = 1;
		else rgt[ind] = 1;
		return;
	}
	int mid = s + e >> 1;
	int l = ind << 1, r = l | 1;
	build(l, s, mid);
	build(r, mid + 1, e);
	push_up(ind, l, r);
}
void update(int ind, int s, int e, int x) {
	if (x<s || x>e)return;
	if (s == e) {
		swap(lft[ind], rgt[ind]);
		return;
	}
	int mid = s + e >> 1;
	int l = ind << 1, r = l | 1;
	update(l, s, mid, x);
	update(r, mid + 1, e, x);
	push_up(ind, l, r);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(3);
	//srand(time(0));
	int t,tt=1;
	while (cin>>n) {
		cout << "Test " << tt++ << ":\n";
		cin >> str;
		build(1, 1, n);
		int q; cin >> q;
		while (q--) {
			int x; cin >> x;
			if (x)update(1, 1, n, x);
			else {
			//	cout << lft[1] << " " << rgt[1] << endl;
				if (lft[1] || rgt[1])
					cout << "NO\n";
				else cout << "YES\n";
			}
		}
	}
	return 0;
}