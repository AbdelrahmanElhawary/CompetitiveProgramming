#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const long double EPS = (1e-7);
const long long   OO = 1e9;
const long long   mod = 1e9 + 7;
int dcmp(long double x, long double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

#define ll long long
void fast(){
#ifndef ONLINE_JUDGE
	freopen("D:\\Competitve\\solving\\input.txt", "r", stdin);
	freopen("D:\\Competitve\\solving\\output.txt", "w", stdout);

#endif
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

const int MLOG = 35;
const int MAX = 2 * 100 * 1000 + 5;
int n, k;
int main(){
	fast();
	
	int n;
	cin >> n;
	map<string, pair<int, int>>mp;
	vector<string>v(n);
	for (int i = 0; i < n; i++){
		string x;
		cin >> x;
		v[i] = x;
		map<string, bool>vis;
		for (int j = 0; j < x.size(); j++){
			string y;
			for (int k = j; k < x.size(); k++){
				y += x[k];
				if (vis.find(y) == vis.end()){
					mp[y].first++;
					mp[y].second = i;
				}
				else {
					continue;
				}
				vis[y] = 1;
			}
		}
	}

	int q;
	cin >> q;
	while (q--){
		string x;
		cin >> x;
		if (mp.find(x) == mp.end()){
			cout << "0 -\n";
		}
		else {
			cout << mp[x].first << " " << v[mp[x].second] << "\n";
		}
	}
	return 0;
}