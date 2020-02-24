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
const ld eps = 1e-9;
bool onSegment(point p, point q, point r) {
	if (q.X <= max(p.X, r.X) && q.X >= min(p.X, r.X) &&
		q.Y <= max(p.Y, r.Y) && q.Y >= min(p.Y, r.Y))
		return true;
	return false;
}
ld orientation(point p, point q, point r) {
	ld val = (q.Y - p.Y) * (r.X - q.X) - (q.X - p.X) * (r.Y - q.Y);
	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}
bool doIntersect(point p1, point q1, point p2, point q2) {
	ld o1 = orientation(p1, q1, p2);
	ld o2 = orientation(p1, q1, q2);
	ld o3 = orientation(p2, q2, p1);
	ld o4 = orientation(p2, q2, q1);
	if (fabs(o1 - o2) > EPS&& fabs(o3 - o4) > EPS)
		return true;
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
	return false;
}
class BestView {
public:
	int numberOfBuildings(vector<int>v) {
		int n = v.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				bool ok = 1;
				if (i == j)continue;
				point p1 = point(i, v[i]);
				point p2 = point(j, v[j]);
				for (int k = 0; k < n; k++) {
					if (k == i || k == j)continue;
					point p3 = point(k, 0);
					point p4 = point(k, v[k]);
					if (doIntersect(p1, p2, p3, p4))
						ok = 0;
				}
				cnt += ok;
			}
			ans = max(ans, cnt);
		}
		return ans;
	}
};
