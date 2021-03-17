#include <iostream>
#include <cmath>


using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    double left=a;
    double right=b;
    while(n)
    {


        left=left/2>0?left/2:1;
        right=right/2>0?right/2:1;
        answer++;
        int l = ceil(left);
        int r = ceil(right);
        if((l-r)==0)
            return answer;

        n/=2;
    }






    cout << "Hello Cpp" << endl;

    return 1;
}
