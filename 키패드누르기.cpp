#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int get_dist(int cur, int next)
{
    map<int, pair<int, int>> res;
    for (int i = 1; i <= 9; i++)
        res[i] = { (i-1) / 3,(i-1) % 3 };
    res[0] = { 3,1 };
    res['*'-0] = { 3,0 };
    res['#'-0] = { 3,2 };

    auto cur_pos = res[cur];
    auto next_pos = res[next];
    return abs(cur_pos.first - next_pos.first) + abs(cur_pos.second - next_pos.second);
}


string solution(vector<int> numbers, string hand)
{
    string ans;
    int left = '*' - 0;
    int right = '#' - 0;
    for (auto i : numbers)
    {
        if (i == 1 || i == 4 || i == 7)
        {
            left = i;
            ans += "L";

        }
        else if (i == 3 || i == 6 || i == 9)
        {
            right = i;
            ans += "R";

        }
        else if (i == 2 || i == 5 || i == 8 || i == 0)
        {

            auto left_dist = get_dist(left, i);
            auto right_dist = get_dist(right, i);

            if (left_dist == right_dist)
            {
                if (hand == "right")
                {
                    ans += "R";
                    right = i;
                }
                else {
                    ans += "L";
                    left = i;
                }
            }
            else if (left_dist < right_dist)
            {
                ans += "L";
                left = i;
            }
            else
            {
                ans += "R";
                right = i;
            }

        }

    }



    return ans;

}


int main()
{



    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    vector<int> numbers = { 1,3,4,5,8,2,1,4,5,9,5 };
    string hand = "right";
    cout << solution(numbers, hand) << endl;

    vector<int> numbers2 = { 7,0,8,2,8,3,1,5,7,6,2 };
    hand = "left";
    cout << solution(numbers2, hand) << endl;

    hand = "right";
    vector<int> numbers3 = { 1,2,3,4,5,6,7,8,9,0 };
    cout << solution(numbers3, hand) << endl;
}

