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
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define pb push_back
const ld eps = -1e9;
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
struct Point {
	ld x, y;
};
struct Segment {
	Point s, t;
};
bool in(ld a, ld b, ld c) {
	return c >= a && c <= b;
}
bool onLine(Segment a, Point c) {
	ld minx, maxx, miny, maxy;
	minx = min(a.s.x, a.t.x);
	maxx = max(a.s.x, a.t.x);
	miny = min(a.s.y, a.t.y);
	maxy = max(a.s.y, a.t.y);
	if (in(minx, maxx, c.x) != 0 && in(miny, maxy, c.y) != 0) 
		if ((a.s.x - a.t.x)*(c.y - a.s.y) == (a.s.y - a.t.y)*(c.x - a.s.x)) 
			return 1;
	return 0;
}
ld cross(Point o, Point a, Point b) {
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
bool intersection(Segment& a, Segment& b) {
	if (onLine(a, b.s) || onLine(a, b.t) || onLine(b, a.s) || onLine(b, a.t))
		return 1;
	return cross(a.s, a.t, b.s)*cross(a.s, a.t, b.t) < 0 &&
		cross(a.t, a.s, b.s)*cross(a.t, a.s, b.t) < 0 &&
		cross(b.s, b.t, a.s)*cross(b.s, b.t, a.t) < 0 &&
		cross(b.t, b.s, a.s)*cross(b.t, b.s, a.t) < 0 ;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	int t; cin >> t;
	while (t--)
	{
		Segment seg;
		cin >> seg.s.x >> seg.s.y >> seg.t.x >> seg.t.y;
		Point l, r;
		cin >> l.x >> l.y; cin >> r.x >> r.y;
		Segment a, b, c, d;
		a.s = l; a.t = { r.x,l.y };
		b.t = r; b.s = { l.x,r.y };
		c.s = l; c.t = b.s;
		d.s = b.t; d.t = a.t;
		if (l.x > r.x)
			swap(l.x, r.x);
		if (l.y > r.y)
			swap(r.y, l.y);
		if (intersection(seg, a) || intersection(seg, b) || intersection(seg, c) || intersection(seg, d)
			|| (in(l.x, r.x, seg.s.x) && in(l.y, r.y, seg.s.y))|| (in(l.x, r.x, seg.t.x) && in(l.y, r.y, seg.t.y)))
			cout << "T\n";
		else cout << "F\n";
	}
	pause();
	return 0;
}