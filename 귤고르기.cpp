#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> db;
    for (auto tanger : tangerine)
        db[tanger]++;

    vector<pair<int, int>> res;
    for (auto& it : db)
        res.push_back({ it.first, it.second });

    sort(res.begin(), res.end(), [](auto it, auto it2) {return it.second > it2.second; });
    int cnt = 0;
    for (auto& it : res) {
        k -= it.second;
        cnt++;
        if (k <= 0)
            break;
    }
    answer = cnt;
    return answer;
}
