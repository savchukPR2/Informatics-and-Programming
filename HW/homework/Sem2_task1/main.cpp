//#include<vcl>
#include<iostream>
#include<math.h>
//#include<stdio>
//#include<conio>
//#include <string>
using namespace std;
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
		this->hour = (this->hour + (this->min / 60 + this->sec / 60)) % 24;
		this->min = (this->min + this->sec / 60) % 60;
		this->sec %= 60;
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
			hour = 24 - abs(hour - time.hour);
		else
			hour = hour - time.hour;
		min = abs(min - time.min);
		sec = abs(sec - time.sec);
	}
};

int main()
{
	char str[80];
	int a;

	cout << "Enter Time in (Hour:Min:Sec) format: ";
	cin >> str;

	while (true)
	{

		cout << "Enter operation: " << endl << "1) 1 - minus" << endl << "2) 2 - plus" << endl << "3) 3 - exit" << endl;
		cin >> a;
		if (a == 3)
			break;
		if (a == 2)
		{
			Timee ob(str);
			cout << "Enter Time in (Hour:Min:Sec) format: ";
			cin >> str;
			Timee ob2(str);
			ob.PlusTime(ob2);
			ob.EditTime();
			ob.ShowTime();
		}
		if (a == 1)
		{
			Timee ob(str);
			cout << "Enter Time in (Hour:Min:Sec) format: ";
			cin >> str;
			Timee ob3(str);
			ob.MinusTime(ob3);
			ob.EditTime();
			ob.ShowTime();
		}
	}




	/*if(ob==ob2)
	cout«"ob==ob2";
	if(ob!=ob1)
	cout«"ob!=ob1"; */
	system("Pause");

}

