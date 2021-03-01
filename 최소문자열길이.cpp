#include <string>
#include <vector>
#include <iostream>

using namespace std;




int solution(string s) {
    
    int len = s.size();
    // 절반까지가 길이 감소 가능
    // 0부터~절반까지시작해서 1~n/2까지 문자열 모두 탐색
    int mlen = 99999;
    for(int i=1;i<=len/2;i++)
    {
        auto str = s.substr(0, i);
        int count=0;
        string sub_len="";
        for(int j=0;j<len;j+=i)
        {
            if(str==s.substr(j, i))
            {
                count++;
            }else
            {
                // 만약 다르다면
                if(count>1)
                    sub_len+=to_string(count)+str;// i는 substring의 길이
                else
                    sub_len+=str;
                count=1; // 새로운 sub string의 시작
                str = s.substr(j,i);
            }

		
            if(j+i>=len)
            {

		if(count>1) sub_len+=to_string(count);
		sub_len+=str;
		break;


            }
        }
	
	//cout<<sub_len<<'\n';
        int len2 = sub_len.size();
        mlen = min(mlen, len2);
    }
    
    
    
    
    return mlen;
}


int main()
{

cout<<solution("aabbaccc")<<endl;
cout<<solution("ababcdcdababcdcd")<<endl;
cout<<solution("abcabcdede")<<endl;
cout<<solution("abcabcabcabcdededededede")<<endl;
cout<<solution("xababcdcdababcdcd")<<endl;








}
