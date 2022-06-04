#include<iostream>
#include<math.h>
using namespace std;
#include <W:\Informatics-and-Programming\HW\homework\Sem2_task1\Source.h>

bool operator>(const Timee& time1, const Timee& time2)
{
	if (time1.hour > time2.hour)
		return time1.hour > time2.hour;
	else
		if (time1.min > time2.min)
			return time1.min > time2.min;
		else
			if (time1.sec > time2.sec)
				return time1.sec > time2.sec;
}

int main()
{
	char str[80];
	int a;

	cout << "Enter Time in (Hour:Min:Sec) format: ";
	cin >> str;

	while (true)
	{

		cout << "Enter operation: " << endl << "1) 1 - minus" << endl << "2) 2 - plus" << endl << "3) 3 - compare" << endl << "4) 4 - show time" << endl << "5) 5 - exit" << endl;
		cin >> a;
		if (a == 5)
			break;

		if (a == 4)
		{
			Timee ob(str);
			ob.ShowTime();
		}

		if (a == 2)
		{
			Timee ob(str);
			cout << "Enter Time in (Hour:Min:Sec) format: ";
			cin >> str;
			Timee ob2(str);
			ob += ob2;
			ob.EditTime();
			ob.ShowTime();
		}

		if (a == 1)
		{
			Timee ob(str);
			cout << "Enter Time in (Hour:Min:Sec) format: ";
			cin >> str;
			Timee ob1(str);
			ob -= ob1;
			ob.EditTime();
			ob.ShowTime();
		}

		if (a == 3)
		{
			Timee ob(str);
			cout << "Enter Time in (Hour:Min:Sec) format: ";
			cin >> str;
			Timee ob3(str);
			if (ob > ob3)
			{
				cout << "Main time is greater than yours" << endl;
			}
			else
				cout << "Main time is not greater than yours" << endl;
		}
	}




	/*if(ob==ob2)
	cout<<"ob==ob2";
	if(ob!=ob1)
	cout<<"ob!=ob1"; */
	system("Pause");

}