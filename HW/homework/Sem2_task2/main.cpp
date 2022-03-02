#include<iostream>
#include<math.h>
using namespace std;
#include <W:\Informatics-and-Programming\HW\homework\Sem2_task2\source.h>



int main()
{
	char str[80];
	int a;

	cout << "Enter the number in HEX format: ";
	cin >> str;
	Hex ob(str);

	while (true)
	{
		cout << "Enter operation: " << endl << "1) 1 - minus" << endl << "2) 2 - plus" << endl << "3) 3 - show number in HEX format" << endl << "4) 4 - show number in DEC format" << endl;
		cin >> a;
		if (a == 1)
		{
			ob.InDec();

			cout << "Enter the second number in HEX format: ";
			cin >> str;

			Hex ob1(str);
			ob1.InDec();

			ob -= ob1;

			ob.InHex();

			ob.ShowHex();

		}

		if (a == 2)
		{
			ob.InDec();

			cout << "Enter the second number in HEX format: ";
			cin >> str;
			Hex ob1(str);
			ob1.InDec();

			ob += ob1;
			ob.ShowHex();
		}

		if (a == 3)
		{
			ob.InDec();
			ob.InHex();
			ob.ShowHex();
		}

		if (a == 4)
		{
			ob.InDec();
			ob.ShowDec();
		}

		if (a == 5)
			break;
		
	}
	
	system("Pause");
}