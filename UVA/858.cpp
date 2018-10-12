#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
#include<list>
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#include <assert.h>
#include<complex>
#define point complex<double> // it can be long long not double 
#define X real()   // can sign values point a; a.real(5) , a.image(2)
#define Y imag()
#define angle(a)  (atan2((a).imag(), (a).real())) // angle with orignial
#define dist(a)   (hypot((a).imag(), (a).real())) // distance between two point send diff
#define vec(a,b)  ((b)-(a)) // diff x1-x2 , y1-y2 return vec (x,y)
#define rotateO(p,ang)    ((p)*exp(point(0,ang)))  // angle should be in radian aroun origin
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)// rotate around point
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS) // check to points same or not
#define dp(a,b)   ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep dot product A.B
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
#define norm(a)  (norm(a))  // return x^2 + y^2 a is point can use dp(a,a)
#define reflectO(v,m)  (conj((v)/(m))*(m))
#define normalize(a)            (a)/dist(a)
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
const ld eps = 1e-2;
const double PI = acos(-1.0);
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int dx[] = { -1,0,1,0,-1,1,-1,1 };
int dy[] = { 0,-1,0,1,1,1,-1,-1 };
template<class T>
istream& operator>> (istream& is, complex<T>& p) {
	T value;
	is >> value;
	p.real(value);
	is >> value;
	p.imag(value);
	return is;
}
struct Segment {
	point s, t;
};
bool in(ld a, ld b, ld c) {
	return c >= a && c <= b;
}
bool onLine(Segment a, point c) {
	ld minx, maxx, miny, maxy;
	minx = min(a.s.X, a.t.X);
	maxx = max(a.s.X, a.t.X);
	miny = min(a.s.Y, a.t.Y);
	maxy = max(a.s.Y, a.t.Y);
	if (in(minx, maxx, c.X) != 0 && in(miny, maxy, c.Y) != 0)
		if ((a.s.X - a.t.X)*(c.Y - a.s.X) == (a.s.Y - a.t.Y)*(c.X - a.s.X))
			return 1;
	return 0;
}
ld cross(point o, point a, point b) {
	return (a.X - o.X)*(b.Y - o.Y) - (a.Y - o.Y)*(b.X - o.X);
}
bool intersection(Segment a, Segment b, point &inter) {
	double d1 = cp(a.s - a.t, b.t - b.s), d2 = cp(a.s - b.s, b.t - b.s), d3 = cp(a.s - a.t, a.s - b.s);
	double t1 = d2 / d1, t2 = d3 / d1;
	inter = a.s + (a.t - a.s) * t1;
	if (onLine(a, b.s) || onLine(a, b.t) || onLine(b, a.s) || onLine(b, a.t))
		return 1;
	return cross(a.s, a.t, b.s)*cross(a.s, a.t, b.t) < 0 &&
		cross(a.t, a.s, b.s)*cross(a.t, a.s, b.t) < 0 &&
		cross(b.s, b.t, a.s)*cross(b.s, b.t, a.t) < 0 &&
		cross(b.t, b.s, a.s)*cross(b.t, b.s, a.t) < 0;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(3);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<point>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int h; double x;
		cin >> h >> x;
		Segment bird;
		point inter;
		bird.s = { x,1e9 }; bird.t = { x,-1e9 };
		vector<ld>ansy;
		for (int i = 0; i < n; i++)
			if (intersection({ v[i],v[(i + 1) % n] }, bird, inter))
				ansy.push_back(inter.Y);
		sort(ansy.begin(), ansy.end());
		ld ans=0;
		for (int i = 1; i < ansy.size(); i += 2)
			ans += (ansy[i] - ansy[i - 1]);
		if (ans >= h)
			cout << "YES\n";
		else cout << "NO\n";


	}
	pause();
	return 0;
}