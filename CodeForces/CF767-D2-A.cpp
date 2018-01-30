#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>
#include <utility>
#include<set>
#include<string.h>
#include <deque>
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int arr[100001];
bool ar[100001];
int main() {
		fast_in_out();
	//	cout << fixed << setprecision(4);
		int n, c; cin >> n; c = n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (arr[i] == c) { cout << arr[i]; for (;;)if (ar[--c])cout << " " << c; else break; cout << endl; }
			else { cout << endl; ar[arr[i]] = 1; }
		}
		
		
	//	system("pause");
	return 0;
}