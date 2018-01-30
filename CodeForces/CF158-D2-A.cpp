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
using namespace std;
int arr[50];
int main()
{
	int n,k; cin >> n>>k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	k = arr[k - 1]; int ans = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] >= k && arr[i])ans++; else break;
	cout << ans << endl;
	//system("pause");
	return 0;
}