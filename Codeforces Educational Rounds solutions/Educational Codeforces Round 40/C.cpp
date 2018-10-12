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
int dx[] = { 0,0,-1,-1,-1,1,1,1 };
int dy[] = { -1,1,0,1,-1,-1,0,1 };
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	int n; 
	cin >> n;
	int c = 1, dif = -1;
	int shift = 0; bool f = 1;
	vector<int>v(n);
	int r=1e9,mxr=0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (i)
		{
			if (abs(v[i] - v[i - 1]) > 1)
			{
				if (c == 1)
					c = abs(v[i] - v[i - 1]);
				else if (abs(v[i] - v[i - 1]) != c)
					f = 0;
			}
			else if (abs(v[i] - v[i - 1]) != 1)
				f = 0;
		}
	}
	if (!f)
	{
		cout << "NO\n";
	}
	else
	{
	//	cout << "hola\n";
		int num = v[0];
		int x = num / c;
		if (num%c)x++;
		int y = num % c; if (y == 0)y = c;
		//cout << x << " " << y << endl;
		for (int i = 1; i < n; i++)
		{
		//	cout << v[i] << " ";
			if (v[i] == v[i - 1] + c)
			{
				x = x - 1;
				continue;
			}
			else if (v[i] + c == v[i - 1])
			{
				x = x + 1;
				continue;
			}
			else if (v[i] + 1 == v[i - 1])
			{
				y = y - 1;
				if (y < 1)
				{
					f = 0;
					break;
				}
				continue;
			}
			else if (v[i] - 1 == v[i - 1])
			{
				y = y + 1;
				if (y > c)
				{
					f = 0;
					break;
				}
				continue;
			}
			else f = 0;
		}
		//cout << endl;
		if (!f)cout << "NO\n";
		else cout << "YES\n" << r << " " << c << endl;
	}
	pause();
	return 0;
}