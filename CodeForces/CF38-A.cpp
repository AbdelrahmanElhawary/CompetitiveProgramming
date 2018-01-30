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
#define F first
#define S second
#define ll long long
using namespace std;
int arr[100001];
int main()
{
	int n, ans = 0;; cin >> n;
	for (int i = 1; i < n; i++)
		cin >> arr[i];
	int a, b; cin >> a >> b;
	for (int i = a; i < b; i++)
		ans += arr[i]; cout << ans << endl;
	
//	system("pause");
	return 0;
}