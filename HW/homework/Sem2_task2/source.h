using namespace std;
#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<math.h>
#include<iomanip>
#include <typeinfo>
class Hex
{
private:
	unsigned char* elem;
	int num, dec;
	bool isDec;
	std::string mainHex;
public:

	// Конструктор по умолчанию
	Hex() {
		num = 5; 
		dec = 0; 
		mainHex = ""; 
		isDec = false;
		elem = new unsigned char[num];
		for (int i = 0; i < num; i++)
			elem[i] = 0;
	};

	// Конструктор инициализации
	Hex(unsigned char* _elem, int _num, int _dec, std::string _mainHex, bool _isDec) { 
		elem = _elem;
		num = _num;
		isDec = _isDec;
		dec = _dec;
		mainHex = _mainHex;
		elem = new unsigned char[num];
		for (int i = 0; i < num; i++)
			elem[i] = _elem[i];
	};

	// Конструктор копирования
	Hex(const Hex& hex) { 
		num = hex.num;
		dec = hex.dec;
		isDec = hex.isDec;
		mainHex = hex.mainHex;
		elem = new unsigned char[num];
		for (int i = 0; i < num; i++)
			elem[i] = hex.elem[i];
	};

	// Деструктор (удаление памяти, выделенной под массив)
	~Hex() {
		delete[] elem;
	};

	Hex(char* str)
	{
		num = strlen(str);
		elem = new unsigned char[num];

		string a; ;
		for (int i = 1; i <= num; i++)
		{
			elem[i] = str[num - i];
		}

		isDec = true;
		InDec(this->num);
	}
private:
	void InDec(int num)
	{
		int k = 0;

		if (isDec) {
			for (int i = 1; i <= num; i++)
			{
				if (elem[i] > 64 && elem[i] < 71) {
					k = (int)(elem[i] - 55);
					this->dec += k * pow(16, i - 1);
				}
				if (elem[i] > 47 && elem[i] < 58) {
					k = (int)(elem[i] - 48);
					this->dec += k * pow(16, i - 1);
				}
			}
		}

		isDec = false;
	}
public:
	void InHex(int num)
	{
		int n = num;
		std::string k;

		while (n > 0) {
			if (n % 16 > 9) {
				k += char((n % 16) + 55);
			}
			if ((n % 16) < 10) {
				k += char((n % 16) + 48);
			}
			n = n / 16;
		}

		this->mainHex = std::string(k.crbegin(),k.crend());
	}

	void ShowDec()
	{
		std::cout << "Number in DEC format: " << this->dec << std::endl;
	}

	void ShowHex()
	{
		InHex(dec);
		std::cout << "Number in HEX format: " << this->mainHex << std::endl;
	}

	Hex& operator+=(const Hex& hex)
	{
		this->dec += hex.dec;

		return *this;
	}

	Hex& operator-=(const Hex& hex)
	{
		this->dec -= hex.dec;

		return *this;
	}

	
};