#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <regex>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <functional>

using namespace std;

vector<int> db[3][2][2][2]; // 언어 분야 경력 음식 그리고 점수는 벡터에 저장









vector<int> solution(vector<string> info, vector<string> query) {

    vector<int> answer;

    transform(query.begin(), query.end(), query.begin(), [](auto e){
        return e = regex_replace(e, regex("and "),"");
    });


    auto info_divide = [](string& s)
    {
        string temp;
        vector<int> res;
        for(auto i : s)
        {
            if(i==' ')
            {
                if(temp=="cpp" || temp=="backend" || temp=="junior" || temp=="chicken") res.push_back(0);
                else if(temp=="python") res.push_back(2);
                else
                    res.push_back(1);
                temp="";
            }else
                temp+=i;
        }
        res.push_back(stoi(temp));
        return res;
    };


    auto query_divide = [](string& s){
        vector<string> res;
        string temp;
        for(auto i : s)
        {
            if(i==' ')
            {
                res.push_back(temp);
                temp="";
            }else
                temp+=i;
        }
        res.push_back(temp);
        return res; 
    };    



    for(auto i : info)
    {
        vector<int> k = info_divide(i);
        db[k[0]][k[1]][k[2]][k[3]].push_back(k[4]);
    }

    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
            for(int h=0;h<2;h++)
                for(int p=0;p<2;p++)
                    sort(db[i][j][h][p].begin(), db[i][j][h][p].end());


    for(auto& it : query)
    {
        vector<string> query2 = query_divide(it);

        int ai, bi, aj, bj, ak, bk, al, bl;
        if(query2[0]=="cpp") ai=bi=0;
        else if(query2[0]=="java") ai=bi=1;
        else if(query2[0]=="python") ai=bi=2;
        else
        {ai=0; bi=2;}

        if(query2[1]=="backend") aj=bj=0;
        else if(query2[1]=="frontend") aj=bj=1;
        else
        {aj=0; bj=1;}

        if(query2[2]=="junior") ak=bk=0;
        else if(query2[2]=="senior") ak=bk=1;
        else
        {ak=0; bk=1;}

        if(query2[3]=="chicken") al=bl=0;
        else if(query2[3]=="pizza") al=bl=1;
        else
        {al=0; bl=1;}

        int score = stoi(query2[4]);

        int cnt=0;
        for(int i=ai;i<=bi;i++)
            for(int j=aj;j<=bj;j++)
                for(int k=ak;k<=bk;k++)
                    for(int l=al;l<=bl;l++)
                    {
                        int n = db[i][j][k][l].size();
                        if(n==0) continue;

                        auto it2 = lower_bound(db[i][j][k][l].begin(), db[i][j][k][l].end(), score);

                        if(it2!=db[i][j][k][l].end())
                            cnt+=n-(it2-db[i][j][k][l].begin());
                    }




        answer.push_back(cnt);



    }




    return answer;
}
