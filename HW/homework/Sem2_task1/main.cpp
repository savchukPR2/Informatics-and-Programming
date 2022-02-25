#include<iostream>
#include<math.h>
using namespace std;
 
#define DAY 24
#define MIN 60

class Timee
{
private:
	int hour, min, sec;

public:
	Timee() { hour == min == sec == 0; }

	Timee(const char* str)
	{
		string a;
		int n = 0, ob[3];
		for (int i = 0; i < (strlen(str) + 1); i++)
			if (str[i] != ':' && i != strlen(str))
				a += str[i];
			else
			{
				ob[n] = atoi(a.c_str());

				n++;
				a = "";
			}
		hour = ob[0];
		min = ob[1];
		sec = ob[2];
	}

	void ShowTime()
	{
		cout << hour << ":" << min << ":" << sec << endl;
	}

	void EditTime()
	{
		this->hour = (this->hour + (this->min / MIN + this->sec / MIN)) % DAY;
		this->min = (this->min + this->sec / MIN) % MIN;
		this->sec %= MIN;
	}

	void PlusTime(const Timee& time)
	{
		hour += time.hour;
		min += time.min;
		sec += time.sec;
	}
	void MinusTime(const Timee& time)
	{
		if ((hour - time.hour) < 0)
			hour = DAY - abs(hour - time.hour);
		else
			hour = hour - time.hour;
		min = abs(min - time.min);
		sec = abs(sec - time.sec);
	}
};

