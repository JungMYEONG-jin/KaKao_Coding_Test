
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<vector<int>>& temp)
{
    for(auto& it : temp)
    {
        int x = it[0];
        int y = it[1];
        int structure = it[2];
        if(structure==1) // 보
        {
            bool flag = false;
            bool left = false;
            bool right = false;
            for(int j=0,len = temp.size();j<len;j++)
            {
                if(x==temp[j][0] && y-1 == temp[j][1] && 0==temp[j][2])
                    flag = true;
                if(x+1==temp[j][0] && y-1 == temp[j][1] && 0==temp[j][2])
                    flag = true;
                if(x-1==temp[j][0] && y==temp[j][1] && 1==temp[j][2])
                    left = true;
                if(x+1==temp[j][0] && y == temp[j][1] && 1==temp[j][2])
                    right = true;
            }
            if(left && right) flag = true;
            if(!flag) return false;
        }else if(structure==0) // 기둥
        {
            bool flag = false;
            if(y==0)
                flag  = true;
            for(int j=0,len = temp.size();j<len;j++)
            {
                if(x-1==temp[j][0] && y==temp[j][1] && temp[j][2]==1)
                    flag = true;
                if(x==temp[j][0] && y-1==temp[j][1] && temp[j][2]==0)
                    flag = true;
                if(x==temp[j][0] && y==temp[j][1] && temp[j][2]==1)
                    flag = true;
            }
            if(!flag) return false;

        }

    }
     return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(auto& build : build_frame)
    {
        int x = build[0];
        int y = build[1];
        int structure = build[2];
        int op = build[3];
        if(op==0)
        {
            auto it = find(answer.begin(), answer.end(), vector<int>{x, y, structure});
            answer.erase(it);
            if(check(answer)==false)
                answer.push_back(vector<int>{x,y,structure});
        }
        if(op==1)
        {
            answer.push_back(vector<int>{x, y, structure});
            if(check(answer)==false)
                answer.pop_back();

        }

    }
    sort(answer.begin(), answer.end(), [](auto e, auto k){return e[0]<k[0] || e[0]==k[0] && e[1]<k[1] ||
                                                 e[0]==k[0] && e[1]==k[1] && e[2]<k[2];      });


    return answer;
}
