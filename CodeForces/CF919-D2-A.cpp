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
#include<iomanip>
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}

int main() {
	fast_in_out();
	cout << fixed << setprecision(6);
	int n, m; cin >> n >> m;
	double ans = 1e9;
	for (int i = 0; i < n; i++)
	{
		double x, y; cin >> x >> y;
		ans = min(ans, x / y);
	}
	cout << ans * m << endl;
	
	//system("pause");
		return 0;
}