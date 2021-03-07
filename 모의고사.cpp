#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int len = 5;
    int len2 = 8;
    int len3 = 10;

    vector<int> person1 = {1,2,3,4,5};
    vector<int> person2 = {2,1,2,3,2,4,2,5};
    vector<int> person3 = {3,3,1,1,2,2,4,4,5,5};

    int max1=0;
    int max2=0;
    int max3=0;

    for(int i=0;i<answers.size();i++)
    {
        max1=person1[i%len]==answers[i]?max1+1:max1;
        max2=person2[i%len2]==answers[i]?max2+1:max2;
        max3=person3[i%len3]==answers[i]?max3+1:max3;
    }



    auto it = max(max1, max2);
    auto it2 = max(it, max3);

    // it2 is maximum
    if(it2==0)
        return answer;
    else
    {
        if(max1==it2)
            answer.push_back(1);
        if(max2==it2)
            answer.push_back(2);
        if(max3==it2)
            answer.push_back(3);
    }

    return answer;
}
