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
#include<map>
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(4);
	string s; cin >> s;
	int arr[26]{0};
	for (int i = 0; i < s.size(); i++)
		arr[s[i] - 'a']++;
	int ans = 0;
	for (int i = 0; i < 26; i++)
		if (arr[i]>=1)ans++;
	if (ans % 2)cout << "IGNORE HIM!" << endl;
	else cout << "CHAT WITH HER!" << endl;
	//system("pause");
	return 0;
}