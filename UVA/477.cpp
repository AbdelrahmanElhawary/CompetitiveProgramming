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
struct circle {
	point cen;
	ld r;
	int ind;
};
struct rect {
	point p1, p2;
	int ind;
};
bool point_inside_square(point p, point p1, point p2) {
	return p1.X <= p.X && p1.Y >= p.Y && p2.X >= p.X&& p2.Y <= p.Y;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(2);
	vector<circle>ci;
	vector<rect>re;
	char ch;
	int ind = 1;
	while (cin >> ch) {
		if (ch == '*')break;
		if (ch == 'c') {
			ld x, y, r;
			cin >> x >> y >> r;
			ci.push_back({ point(x,y),r,ind++ });
		}
		else {
			ld x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			point p1 = point(x1, y1), p2 = point(x2, y2);
			re.push_back({ p1,p2,ind++ });
		}
	}
	ld x, y;
	ind = 1;
	while (cin >> x >> y) {
		vector<int>ans;
		point p = point(x, y);
		if (fabs(x-9999.9)<eps && fabs(y-9999.9)<eps)break;
		for (auto e : ci) {
			point d = vec(p, e.cen);
			d = point(d.X * d.X, d.Y * d.Y);
			if (d.X + d.Y <= e.r * e.r)
				ans.push_back(e.ind);
		}
		for (auto e : re) {
			if (point_inside_square(p, e.p1, e.p2))
				ans.push_back(e.ind);
		}
		if (ans.empty()) {
			cout << "Point "<<ind<<" is not contained in any figure\n";
		}
		else {
			sort(ans.begin(), ans.end());
			for (auto e : ans) {
				cout << "Point "<<ind<<" is contained in figure "<<e<<"\n";
			}
		}
		ind++;
	}

	return 0;

}