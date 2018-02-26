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

int main()
{
	fast_in_out();
	int m, n;
	while (cin >> m >> n)
	{
		int arr[21];
		if (!n && !m)break;
		for (int i = 1; i <= m; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++)
		{
			int l, r, c;
			cin >> r >> l >> c;
			arr[l] += c; arr[r] -= c;
		}
		bool f = 1;
		for (int i = 1; i <= m; i++)
			if (arr[i] < 0)f = 0;
		if (f)cout << "S\n"; else cout << "N\n";

	}
	
	//system("pause");
	return 0;
}