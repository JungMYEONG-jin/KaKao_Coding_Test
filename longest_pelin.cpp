#include <iostream>
#include <string>


using namespace std;



int get_longest(string& s)
{

int len=s.size();

if(len==1)
	return 1;



int maxlen=1;

bool res[len][len];

memset(res, 0, sizeof(res));


for(int i=0;i<len;i++)
	res[i][i]=true;


for(int i=0;i<len-1;i++)
{
	


	if(s[i]==s[i+1])
	{
	res[i][i+1]=true;
	maxlen=2;
	}

}


// len 3

for(int k=3;k<=len;k++)
{
	for(int i=0;i<len-k+1;i++)
	{
		int j = i+k-1;
		if(res[i+1][j-1] && s[i]==s[j])
		{
			maxlen=max(maxlen,k);
		}

		
	
	}


}




return maxlen;


}

