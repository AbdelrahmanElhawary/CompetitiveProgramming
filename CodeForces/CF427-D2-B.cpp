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
#include <iterator>
#include <functional> 
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
vector<int>v;
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	int n, t, c; cin >> n >> t >> c;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > t)v.push_back(i);
	}
	v.push_back(n);
	int ans = 0,p=0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] - p >= c)ans += v[i] - c - p + 1;
		p = v[i] + 1;
	}
	cout << ans << endl;
	//system("pause");
		return 0;
}