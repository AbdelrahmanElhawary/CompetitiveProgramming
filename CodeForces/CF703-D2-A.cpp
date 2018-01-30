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
vector<int>v;
int main() {
		fast_in_out();
	//	cout << fixed << setprecision(4);
		int n, c1 = 0, c2 = 0; cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y; cin >> x >> y;
			if (x > y)c1++;
			if (y > x)c2++;
		}
		if (c1 > c2)cout << "Mishka\n";
		else if (c1 < c2)cout << "Chris\n";
		else cout << "Friendship is magic!^^\n";
		
	//	system("pause");
	return 0;
}