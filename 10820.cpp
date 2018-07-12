#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;

int main(void)
{
	int capital_Count = 0, small_Count = 0, empty_Count = 0, number_Count = 0;

	while (getline(cin, s))
	{
		for (int i = 'a'; i <= 'z'; i++)
		{
			small_Count += count(s.begin(), s.end(), i);
		}

		for (int i = 'A'; i <= 'Z'; i++)
		{
			capital_Count += count(s.begin(), s.end(), i);
		}

		for (int i = '0'; i <= '9'; i++)
		{
			number_Count += count(s.begin(), s.end(), i);
		}

		empty_Count = count(s.begin(), s.end(), ' ');

		cout << small_Count << " " << capital_Count << " " << number_Count << " " << empty_Count << endl;

		capital_Count = 0;
		small_Count = 0;
		empty_Count = 0;
		number_Count = 0;
	}

	return 0;
}