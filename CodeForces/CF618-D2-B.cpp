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
#define ld long double
#define dong long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
bool vis[51];
int main()
{
	fast_in_out();
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int  mxy = 1;
		for (int j = 0; j < n; j++)
		{
			int x; cin >> x;
			if (mxy < x)mxy = x;
		}
		if (vis[mxy])mxy++;
		vis[mxy] = 1;
		cout << mxy << " ";

	}
	cout << endl;
//	system("pause");
	return 0;
}