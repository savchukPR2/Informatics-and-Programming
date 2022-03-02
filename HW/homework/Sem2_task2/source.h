using namespace std;
#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<math.h>
class Hex
{
private:
	unsigned char* elem;
	int num, dec;
	string mainHex;
public:
	Hex(char* str)
	{
		num = strlen(str);
		elem = new unsigned char[num];

		string a; ;
		for (int i = 1; i <= num; i++)
		{
			elem[i] = str[num - i];
		}
	}

	void InDec()
	{
		int k = 0;

		for (int i = 1; i <= num; i++)
		{
			switch (elem[i])
			{
			case 'A':
				k = 10;
				break;
			case 'B':
				k = 11;
				break;
			case 'C':
				k = 12;
				break;
			case 'D':
				k = 13;
				break;
			case 'E':
				k = 14;
				break;
			case 'F':
				k = 15;
				break;
			case '0':
				k = 0;
				break;
			case '1':
				k = 1;
				break;
			case '2':
				k = 2;
				break;
			case '3':
				k = 3;
				break;
			case '4':
				k = 4;
				break;
			case '5':
				k = 5;
				break;
			case '6':
				k = 6;
				break;
			case '7':
				k = 7;
				break;
			case '8':
				k = 8;
				break;
			case '9':
				k = 9;
				break;
			}
			dec += k * pow(16, i - 1);
		}
	}

	void InHex()
	{
		int a = this->dec;
		int k = 0;
		int flag = 0;
		string s;
		while (a > 0)
		{
			k = a % 16;
			switch (k)
			{
			case 0:
				mainHex.insert(flag, "0");
				flag += 1;
				break;
			case 1:
				mainHex.insert(flag, "1");
				flag += 1;
				break;
			case 2:
				mainHex.insert(flag, "2");
				flag += 1;
				break;
			case 3:
				mainHex.insert(flag, "3");
				flag += 1;
				break;
			case 4:
				mainHex.insert(flag, "4");
				flag += 1;
				break;
			case 5:
				mainHex.insert(flag, "5");
				flag += 1;
				break;
			case 6:
				mainHex.insert(flag, "6");
				flag += 1;
				break;
			case 7:
				mainHex.insert(flag, "7");
				flag += 1;
				break;
			case 8:
				mainHex.insert(flag, "8");
				flag += 1;
				break;
			case 9:
				mainHex.insert(flag, "9");
				flag += 1;
				break;
			case 10:
				mainHex.insert(flag, "A");
				flag += 1;
				break;
			case 11:
				mainHex.insert(flag, "B");
				flag += 1;
				break;
			case 12:
				mainHex.insert(flag, "C");
				flag += 1;
				break;
			case 13:
				mainHex.insert(flag, "D");
				flag += 1;
				break;
			case 14:
				mainHex.insert(flag, "E");
				flag += 1;
				break;
			case 15:
				mainHex.insert(flag, "F");
				flag += 1;
				break;
			}
			a /= 16;
		}

		std::reverse(mainHex.begin(), mainHex.end());

	}

	void ShowDec()
	{
		std::cout << "Number in DEC format = " << dec << std::endl;
	}

	void ShowHex()
	{
		std::cout << "Number in HEX format = " << mainHex << std::endl;
	}

	Hex& operator += (const Hex& hex)
	{
		dec += hex.dec;

		return *this;
	}

	Hex& operator -= (const Hex& hex)
	{
		dec -= hex.dec;

		return *this;
	}

	
};