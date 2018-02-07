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
	//cout << fixed << setprecision(6);
	int n; cin >> n; int mxy = -1;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		int y = sqrt(x);
		if (y*y != x)mxy = max(x, mxy);
	}
	cout << mxy << endl;
	//system("pause");
		return 0;
}