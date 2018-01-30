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
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	bool f = 0;
	for (int i = 1; i < n-1; i++)
		if (arr[i] + arr[i - 1] > arr[i + 1])f = 1;
	if (f)cout << "YES\n"; else cout << "NO\n";
//	system("pause");
	return 0;
}