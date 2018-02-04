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
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int arr[100001];
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	int n, sum = 0,x=0; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (arr[i - 1] - arr[i] + x < 0) { sum += arr[i] - arr[i - 1] - x; x = 0; }
		else x += arr[i - 1] - arr[i];
	}
	cout << sum  << endl;
	//system("pause");
		return 0;
}