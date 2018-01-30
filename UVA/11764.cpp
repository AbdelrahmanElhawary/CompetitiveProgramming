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
#define F first
#define S second
#define ll long long
using namespace std;
int arr[51];
int main()
{
	int t,tt=1; cin >> t;
	while (t--)
	{
		int n,h=0,l=0; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (i&&arr[i] > arr[i - 1])h++; else if (i&&arr[i]<arr[i-1])l++;
		}
		cout <<"Case "<<tt++<<": "<< h << " " << l << endl;
	}
//	system("pause");
	return 0;
}