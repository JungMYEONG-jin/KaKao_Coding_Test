#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <set>
#include <numeric>
#include <cmath>

#define INF (long long)1e15

using namespace std;

vector<string> arr;
vector<string> temp(20, "");
bool visited[21];
int col, row;

void dfs(int idx) {
	

	if (idx == col) {
		bool flag = true;
		for (int i = 0; i < col; i++) {
			for (int j = i + 1; j < col; j++) {
				flag &= (temp[i][j] == temp[j][i]);
			}
		}
		if (flag) {
			for (int i = 0; i < col; i++) {
				for (int j = 0; j < col; j++) {
					cout << temp[i][j];
				}
				cout << '\n';
			}
			exit(0);
		}
		return;
	}

	for (int i = 0; i < row; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		temp[idx] = arr[i];
		dfs(idx + 1);
		visited[i] = false;
	}

}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(11);

	
	int n, k;
	cin >> n >> k;

	int nums[500];
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	set<double> res;

	auto std = [&nums](int start, int end) {
		double res = 0.0;
		double mean = 0.0;
		int len = end - start + 1;
		for (int i = start; i <= end; i++) {
			mean += nums[i];
		}
		mean /= len;
		for (int i = start; i <= end; i++) {
			res += pow((nums[i] - mean), 2);
		}
		res /= len;
		return sqrt(res);
	};

	int start = 0;
	int end = 0;
	for (int i = k - 1; i < n; i++) {
		start = 0;
		end = i;
		while (end < n) {
			res.insert(std(start, end));
			start++;
			end++;
		}
		
	}

	cout << *res.begin() << endl;
	

	return 0;

}
