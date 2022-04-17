#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <string>
#include <functional>

using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;

	int x, Bit, num;
	Bit = 0;
	string word = "";
	for (int i = 0; i < m; i++)
	{
		cin >> word;
		if (word == "add")
		{
			cin >> num;
			Bit |= (1 << num);
		}
		else if (word == "check")
		{
			cin >> num;
			if (Bit & (1<<num))
				cout << 1 << '\n';
			else
				cout << 0 <<'\n';
		}
		else if (word == "remove")
		{
			cin >> num;
			
			Bit &= ~(1 << num);
			
		}
		else if (word == "all")
		{
			Bit = (1 << 21)-1;
		}
		else if (word == "toggle")
		{
			cin >> num;
			Bit ^= (1 << num);
		}
		else if (word == "empty")
		{
			Bit = 0;
		}

	}


	return 0;

}
