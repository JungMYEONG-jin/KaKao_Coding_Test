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

int ans = 0;
int arr[10];
int answer[10];
int weight = 500;
int nums[9];
int weights[9];
bool visited[9];
int n, k;

void getAllCases(int idx) {

	if (idx>=n+1) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (nums[i] <= 0)
				cnt++;
		}
		ans = max(ans, cnt);
		return;
	}

	if (nums[idx] <= 0)
		getAllCases(idx + 1);
	else {
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			if (idx == i || nums[i] <= 0)
				continue;
			nums[idx] -= weights[i];
			nums[i] -= weights[idx];
			flag = true;
			getAllCases(idx + 1);
			nums[idx] += weights[i];
			nums[i] += weights[idx];
		}
		if (!flag)
			getAllCases(n+1); // 더이상 할게 없으면
	}

	

}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i] >> weights[i];
	}

	getAllCases(1);
	cout << ans << endl;

	return 0;

}
