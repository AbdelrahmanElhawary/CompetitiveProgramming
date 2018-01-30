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
		string s; cin >> s;
		int ans = s.size(),c=0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')c++;
			else c--;
			if (c < 0) { ans--; c++; }
		}
		ans -= c;
		cout << ans << endl;
		//system("pause");
	return 0;
}