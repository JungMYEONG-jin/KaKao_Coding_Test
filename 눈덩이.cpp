#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>

#define INF (long long)1e15

using namespace std;

int up[101];
int n, m, ans;

void dfs(int idx, int snow, int sec) {
	if (sec == m || (idx==n && sec<=m )) {
		ans = max(ans, snow);
		return;
	}

	if (idx + 1 <= n) {
		dfs(idx + 1, snow + up[idx + 1], sec+1);
	}
	if (idx + 2 <= n) {
		dfs(idx + 2, snow / 2 + up[idx + 2], sec+1);
	}
}



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> up[i];
	}

	dfs(0, 1, 0);
	cout << ans << endl;

	return 0;

}
