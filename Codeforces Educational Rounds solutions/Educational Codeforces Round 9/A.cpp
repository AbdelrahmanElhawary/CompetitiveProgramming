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
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
#define point complex<double> // it can be long long not double
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
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
string grid[1001];
int dx[] = { 0,0,0,-1,-1,-2,-2,-2 };
int dy[] = { 0,-1,-2,0,-2,0,-1,-2 };
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	int n, m;
	cin >> n >> m;
	int arr[40];
	ld ans = 1; 
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		if (s.size() == 4)
			arr[i] = 1;
		else arr[i] = 2;
	}
	
	for (int i = n - 2; i > -1; i--)
	{
		if (arr[i] == 2)
		{
			ans += .5;
			ans *= 2;
		}
		else ans *= 2;
	}
	ld cost = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 2)
		{
			
			cost += ans/2.0;
			ans /= 2; ans -= .5;
		}
		else {
			cost += ans/2.0;
			ans /= 2;
		}
		//cout << cost << endl;
	}
	cout << (ll)(cost*m) << endl;
	pause();
	return 0;
}