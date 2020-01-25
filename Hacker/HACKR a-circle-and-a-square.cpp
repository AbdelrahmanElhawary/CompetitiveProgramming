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
#define vec(a,b) ((b)-(a))
#define X real()
#define Y imag()
#define length(v) ((long double)hypot((v).Y,(v).X))
#define cross(a,b) ((conj(a)*(b)).imag())
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}/*
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };*/
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
const ld eps = 1e-9;
const int N = 1e3 + 50, M = 1e5 + 10, mod = 1e9+7;
ll gcd(ll a, ll b) {  return b ?gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
// given 2 diagonal points for the square find the other two
void square_points(point p1, point p3, point& p2, point& p4) {
	// center point
	ld cx = (p1.X + p3.X) / 2.;  
	ld cy = (p1.Y + p3.Y) / 2.;  
	// half-diagonal
	ld dx = (p1.X - p3.X) / 2.;
	ld dy = (p1.Y - p3.Y) / 2.;
	ld x2 = cx - dy, y2 = cy + dx;    // second corner
	ld x4 = cx + dy,  y4 = cy - dx;    // Fourth corner
	p2 =point (x2, y2);
	p4 =point (x4, y4);
	return;
}
ld triangleArea3points(const point& a, const point& b, const point& c) {
	return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;
}
bool point_inside_square(point p, point p1, point p2, point p3, point p4) {
	ld rectangle_area = length(vec(p1, p2)) * length(vec(p1, p2));
	ld tris_area = triangleArea3points(p1, p2, p) + triangleArea3points(p2, p3, p) +
		triangleArea3points(p3, p4, p) + triangleArea3points(p4, p1, p);
	return fabs(rectangle_area - tris_area) < eps;
}
bool point_inside_circle(point p,point c, ld r) {
	return r - length(vec(p, c)) > -eps;
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(9);
	int m, n;
	cin >> m >> n;
	int x, y; 
	cin >> y >> x;
	point c(x, y);
	int r; cin >> r;
	cin >> y >> x;
	point p1(x, y);
	cin >> y >> x;
	point p3(x, y);
	point p2, p4;
	//cout << p1.X << " " << p1.Y << endl;
	//cout << p3.X << " " << p3.Y << endl;
	square_points(p1, p3, p2, p4);
	//cout << p2.X << " " << p2.Y << endl;
	//cout << p4.X << " " << p4.Y << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (point_inside_circle(point(i,j), c, r) || point_inside_square(point( i,j), p1, p2, p3, p4))
				cout << "#";
			else cout << ".";
		}
		cout << endl;
	}
	return 0;
}