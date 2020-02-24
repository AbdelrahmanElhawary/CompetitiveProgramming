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
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ld eps = 1e-9;
const int N = 1e3 + 50, M = 4e4 + 10, mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
class UnsealTheSafe {
public:
	int ar[10] = { 2,3,2,3,4,3,3,3,2,1 };
	int val[10][4] = { { 7,-1,-1,-1 }, {2, 4,-1,-1}, { 1,3,5,-1 }, { 2,6,-1,-1 }, { 1,5,7,-1 }, { 2,4,6,8 }, { 3,5,9,-1 }, { 4,8,0,-1 }, { 5,7,9,-1 }, { 6,8,-1,-1 } };
	ll ans[31][31];

	ll countPasswords(int n) {
		for (int i = 0; i < 10; i++)
			ans[0][i] = 1;
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int k = 0; k < 10; k++)
				{
					for (int u = 0; u < 4; u++)
					{
						if (val[j][u] == -1)break;
						if (val[j][u] == k) ans[i + 1][k] += ans[i][j];
					}
				}
			}
		}
		ll ansy = 0;
		for (int j = 0; j < 10; j++)
			ansy += ans[n - 1][j];
			return ansy;
	}
};
