#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;

bool vis[N];
int m, n, col[N];

bool good = true;

vector<int> g[N];

void dfs(int node, int cur) {
	col[node] = cur;
	for (int neg : g[node]) {
		int next = !cur;
		if (col[neg] == -1) {
			dfs(neg, next);
		} else if (col[neg] != next) {
			good = false;
		}
	}
}
void init() {
	for (int i = 1; i <= n; i++) {
		g[i].clear();
	}
	good = true;
	memset(col, -1, sizeof(col));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		init();
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (col[i] == -1)
				dfs(i, 0);
		}
		cout << "Scenario #" << k << ":\n";
		good ? cout << "No suspicious bugs found!\n"
			 : cout << "Suspicious bugs found!\n";
	}
}
