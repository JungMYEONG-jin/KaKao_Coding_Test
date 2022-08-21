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
int nums[9];
bool visited[9];
int n, k;


bool isDone() {
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
			return false;
	}
	return true;
}


void getAllCases(int weight) {

	if (weight < 500)
		return;

	if (isDone() && weight >= 500)
		ans++;

	for (int i = 1; i <= n; i++) {
		if (!visited[i])
		{
			visited[i] = true;
			getAllCases(weight + nums[i] - k);
			visited[i] = false;
		}
	}

	

}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}

	getAllCases(500);
	cout << ans << endl;

	return 0;

}
