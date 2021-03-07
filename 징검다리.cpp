#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());
    int left=1;
    int len = rocks.size();
    int right =  distance;

    // left right is distance

    int maxval=1;
    while(left<=right)
    {
        int mid = (left+right)/2;
        int number=0;
        int prev=0;

        for(auto i : rocks)
        {
            if(i-prev<mid)
                number++;
            else
                prev = i;
        }

        if(distance-prev<mid)
            number++;


        if(number<=n)
        {
            left = mid+1;
            answer = max(answer, mid);
        }
        else
        {
            right = mid-1;
        }

    }


    return answer;
}
