#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>


using namespace std;

void create16(map<int, char>* m)
{
    (*m)[0]='0';
    (*m)[1]='1';
    (*m)[2]='2';
    (*m)[3]='3';
    (*m)[4]='4';
    (*m)[5]='5';
    (*m)[6]='6';
    (*m)[7]='7';
    (*m)[8]='8';
    (*m)[9]='9';
    (*m)[10]='A';
    (*m)[11]='B';
    (*m)[12]='C';
    (*m)[13]='D';
    (*m)[14]='E';
    (*m)[15]='F';
}









string solution(int n, int t,int m, int p) {
    string answer = "";
    map<int, char> m16;

    create16(&m16);
    string temp="0";
    int goal = t;

    for(int i=1;i<t*m;i++)
    {
        string test="";
        int k = i;

        while(k)
        {
            test+=m16[k%n];
            k/=n;
        }

        reverse(test.begin(), test.end());
            temp+=test;


    }

    int idx = p-1;
    for(int i=0;i<t;i++)
    {
        answer+=temp[idx];
        idx+=m;


    }



    return answer;
}
