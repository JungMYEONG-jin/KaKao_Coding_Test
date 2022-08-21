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
char arr[5][5];
bool visited[5][5];
int n, m, ans, k;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void dfs(int sx, int sy, int cnt) {
	if (cnt == k) {
		if (arr[sx][sy]=='H')
		{
			ans++;
			return;
		}
	}


	for (int i = 0; i < 4; i++) {
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		if (arr[nx][ny] == 'T' || nx<0 || ny<0 || nx>=n || ny>=m || visited[nx][ny])
			continue;
	
		visited[nx][ny] = true;
		dfs(nx, ny, cnt + 1);
		visited[nx][ny] = false;	
	}
}



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	arr[0][m - 1] = 'H';
	visited[n - 1][0] = true;
	dfs(n-1, 0, 1); 
	cout << ans << endl;

	return 0;

}
