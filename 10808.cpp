#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

int main(void)
{
	cin >> s;

	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << count(s.begin(), s.end(), i) <<" ";
	}
		
	printf("\n");

	return 0;
}