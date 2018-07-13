#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T = 0; // test case

string s;

string right(string get_string)
{
	int cnt = 0, steel = 0;

	for (int i = 0; i < get_string.size(); i++)
	{
		if (get_string[i] == '(') ++cnt;
		else
		{
			--cnt;

			if (cnt < 0) return "NO";		
		}
	}

	if (cnt == 0) return "YES";
	else return "NO";
}

int main(void)
{
	scanf("%d", &T);

	getchar();

	while (T > 0)
	{
		getline(cin, s);

		cout << right(s) << endl;

		--T;
	}

	return 0;
}