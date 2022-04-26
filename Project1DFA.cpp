#include <iostream>

using namespace std;

float stringToFloatVerificationConversion(string s)
{
	int state = 0, power = -1;
	int exponent = 0;
	float floatNum = 0.0;

	for (int i = 0; i <= s.length(); i++)
	{
		switch (state)
		{
		case 0:
			if (isdigit(s[i]))
			{
				state = 1;
				floatNum += (s[i] - 48);
			}
			else if (s[i] == '.')
			{
				state = 3;
			}
			else
			{
				state = 9;
			}
			break;

		case 1:
			if (isdigit(s[i]))
			{
				state = 1;
				floatNum = ((floatNum * 10) + (s[i] - 48));
			}
			else if (s[i] == '_')
			{
				state = 2;
			}
			else if (s[i] == '.')
			{
				state = 3;
			}
			else if (s[i] == 'e' || s[i] == 'E')
			{
				state = 6;
			}
			else if (s[i] == 'f' || s[i] == 'F' || s[i] == 'd' || s[i] == 'D')
			{
				state = 8;
			}
			else
			{
				state = 9;
			}
			break;

		case 2:
			if (s[i] == '_')
			{
				state = 2;
			}
			else if (isdigit(s[i]))
			{
				state = 1;
				floatNum = ((floatNum * 10) + (s[i] - 48));
			}
			else
			{
				state = 9;
			}
			break;

		case 3:
			if (isdigit(s[i]))
			{
				state = 4;
				floatNum += ((s[i] - 48) * pow(10, power));
				power--;
			}
			else if (s[i] == 'e' || s[i] == 'E')
			{
				state = 6;
			}
			else if (s[i] == 'f' || s[i] == 'F' || s[i] == 'd' || s[i] == 'D')
			{
				state = 8;
			}
			else if (s[i] == NULL)
			{
				state = 8;
			}
			else
			{
				state = 9;
			}
			break;

		case 4:
			if (isdigit(s[i]))
			{
				state = 4;
				floatNum += ((s[i] - 48) * pow(10, power));
				power--;
			}
			else if (s[i] == '_')
			{
				state = 5;
			}
			else if (s[i] == 'e' || s[i] == 'E')
			{
				state = 6;
			}
			else if (s[i] == 'f' || s[i] == 'F' || s[i] == 'd' || s[i] == 'D')
			{
				state = 8;
			}
			else if (s[i] == NULL)
			{
				state = 8;
			}
			else
			{
				state = 9;
			}
			break;

		case 5:
			if (s[i] == '_')
			{
				state = 5;
			}
			else if (isdigit(s[i]))
			{
				state = 4;
				floatNum += ((s[i] - 48) * pow(10, power));
				power--;
			}
			else
			{
				state = 9;
			}
			break;

		case 6:
			if (isdigit(s[i]))
			{
				state = 7;
				exponent += (s[i] - 48);
			}
			else
			{
				state = 9;
			}
			break;

		case 7:
			if (isdigit(s[i]))
			{
				state = 7;
				exponent = ((exponent * 10) + (s[i] - 48));
			}
			else if (s[i] == 'f' || s[i] == 'F' || s[i] == 'd' || s[i] == 'D')
			{
				state = 8;
			}
			else if (s[i] == NULL)
			{
				state = 8;
			}
			else
			{
				state = 9;
			}
			break;

		case 8:
			if (s[i] == 'f' || s[i] == 'F' || s[i] == 'd' || s[i] == 'D')
			{
				state = 9;
			}
			break;
		}
	}

	if (state == 8)
	{
		return (floatNum * pow(10, exponent));
	}
	else if (state == 9)
	{
		return -1;
	}
}

int main()
{
	string s = "";

	while (true)
	{
		cout << "Please enter a string: ";
		cin >> s;

		float convertedFloat = stringToFloatVerificationConversion(s);

		if (convertedFloat > -1)
		{
			cout << "It's a float number." << endl;
			cout << "The inputted string is equal to float value " << convertedFloat << endl;
		}
		else if (convertedFloat == -1)
		{
			cout << "It's not a float number." << endl;
		}
	}

	return 0;
}