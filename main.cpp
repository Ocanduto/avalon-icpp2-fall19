#include <iostream>
#include <string>
using namespace std;

int main()
{
	string stroka;
	int n, c;
	c = 1;
	cout << "VVedite kol-vo ISBN: ";
	cin >> n;
	cout << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Vvedite ISBN: ";
		cin >> stroka;
		size_t found = stroka.find_first_not_of("0123456789");

		if (found != string::npos || stroka.length() != 13)
		{
			cout << "V ISBN tolko cif(13)!" << endl << endl;
			n += 1;
		}
		else
		{
			const char* p1 = stroka.c_str();
			int S = 0;
			for (int k = 0; k < 12; k++)
			{
				if (c % 2 == 0)
				{
					S += (((int)p1[k] - 48) * 3);
					c += 1;
				}
				else if (c % 2 != 0)
				{
					S += (((int)p1[k] - 48) * 1);
					c += 1;
				}
			}
			div_t ost;
			ost = div(S, 10);
			c = ost.rem;
			c = 10 - c;
			if (c == ((int)p1[12] - 48))
			{
				cout << p1 << " - " << "ISBN - 13" << endl;
			}
			else
			{
				cout << p1 << " =/= " << "ISBN - 13" << endl;
			}
		}
	}
	system("pause");
}