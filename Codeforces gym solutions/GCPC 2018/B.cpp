/*
for:
Hussien , Ayman , Emad
Abanob , George , Genawy
Ka8eem , Mosta7il , Stawro
 
 ICPC DREAM
 */
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<unordered_map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <complex>
#include <iostream>
using namespace std;
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
const double PI = acos(-1.0);
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
const ld eps = 1e-9;
const int mod = 1e9 + 7;
const int N = 501;
ld r;
double calcArc(point p1, point p2,point cen) {
	double d = length(vec(p1, p2));
	double ang = (angle(vec(cen, p1)) - angle(vec(cen, p2))) * 180 / PI;
	if (ang < 0)
		ang += 360;
	ang = min(ang, 360 - ang);
	return r * ang * PI / 180;
}
STATE circlePoint(const point & cen, const long double & r, const point& p) {
	long double lensqr = lengthSqr(vec(cen, p));
	if (fabs(lensqr - r * r) < EPS)
		return BOUNDRY;
	if (lensqr < r * r)
		return IN;
	return OUT;
}
int tangentPoints(const point & cen, const long double & r, const point& p, point &r1, point &r2) {
	STATE s = circlePoint(cen, r, p);
	if (s != OUT) {
		r1 = r2 = p;   return s == BOUNDRY;
	}
	point cp = vec(cen, p);
	long double h = length(cp);
	long double a = acos(r / h);
	cp = normalize(cp) * r;
	r1 = rotate(cp, a) + cen;
	r2 = rotate(cp, -a) + cen;
	return 2;
}
ld dis(point p1, point p2) {
	return length(vec(p1, p2));
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(7);
	point st, en, cen;
	int x, y;
	cin >> x >> y;
	st = point(x, y);
	cin >> x >> y;
	en = point(x, y);
	cin >> x >> x >> x >> x >> y >> r;
	cen = point(x, y);
	point st1, st2, en1, en2;
	tangentPoints(cen, r, st, st1, st2);
	tangentPoints(cen, r, en, en1, en2);
	ld ans = min({ dis(st, st1) + calcArc(st1, en1,cen) + dis(en1, en),
		dis(st, st1) + calcArc(st1, en2,cen) + dis(en2, en),
		dis(st, st2) + calcArc(st2, en1,cen) + dis(en1, en),
		dis(st, st2) + calcArc(st2, en2,cen) + dis(en2, en) });
	cout << ans << endl;
	return 0;
}