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
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
#define endl '\n'

using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
pair<int,int> arr[1001];
int main() {
	fast_in_out();
//	cout << fixed << setprecision(6);
	int n, s;
	cin >> s >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		if (s > arr[i].first) { c++; s += arr[i].second; }
		else break;
	}
	if (c == n)cout << "YES\n"; else cout << "NO\n";
	
//	system("pause");
	return 0;
}