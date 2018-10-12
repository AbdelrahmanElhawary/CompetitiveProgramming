#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n, m;
int a[100 * 1000 + 5];
pair<int, int> tree[4 * 1000 * 100 + 5];

ll p[100 * 1000 + 5 ];
void build(int cur, int l, int r) {
	tree[cur] = {0 , 0};
	if(l == r) {
		tree[cur].first = (a[l]%2 == 0);
		tree[cur].second = (a[l] %2);
		return;
	}

	int md =l+r>>1;
	int left = cur <<1;
	int right = left |1;

	build(left , l ,md);build(right , md+1 , r);
	tree[cur].first = tree[right].first + tree[left].first;
	tree[cur].second = tree[right].second + tree[left].second;
}
pair<int,int> query(int cur, int l, int r, int x, int y) {
	if (x <= l && y >= r) {
		return tree[cur];
	}
	int md = l + r >> 1;
	int left = cur << 1;
	int right = left | 1;
	if (md >= y) {
		return query(left, l, md, x, y);
	} else if (md < x) {
		return query(right, md + 1, r, x, y);
	} else {
		pair<int, int> one, two;
		one = query(left, l, md, x, y);
		two = query(right, md + 1, r, x, y);
		pair<int, int> three;
		three.first = one.first + two.first;
		three.second = one.second + two.second;
		return three;
	}
}
int main() {
        std::ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	p[0] = 1;
	for(int i = 1;i<=1000*100;i++){
		p[i] = p[i-1] * 2;
		p[i]%=mod;
	}
	while (t--) {
		memset(a, 0, sizeof a);
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		build(1, 1, n);
		while (m--) {
			int l, r, tt;
			cin >> l >> r >> tt;
			pair<int, int> ret = query(1, 1, n, l, r);
			if (tt == 1) {
				cout<<p[ret.second] - 1<<"\n";
			} else {
				cout<<((p[ret.first] - 1) *(p[ret.second]))%mod<<"\n"; 
			}
		}
	}
	return 0;
}