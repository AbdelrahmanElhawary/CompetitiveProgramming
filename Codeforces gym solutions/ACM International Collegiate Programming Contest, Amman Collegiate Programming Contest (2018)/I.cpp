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
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
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
//int dx[] = { -1,0,1,0,-1,1,-1,1 };
//int dy[] = { 0,-1,0,1,1,1,-1,-1 };
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//freopen("knights.in", "r", stdin);
	//freopen("","w",stdout);
	short t; cin >> t;
	while (t--)
	{
		int x, n;
		cin >> x >> n;
		if (x < n) { cout << -1 << endl; continue; }
		int dif = x / n, cnt = n-(x % n);
		for(int i=0;i<n;i++)
		{
			if (i)cout << " ";
			if (cnt > 0)
				cout << dif;
			else cout << dif + 1;
			cnt--;
		}
		cout << endl;
	}
	pause();
	return 0;
}