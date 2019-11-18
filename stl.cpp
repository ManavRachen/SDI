#include <iostream>
using namespace std;

//int main() {
//	list<int> intList(5);
//	int x = 0;
//
//	for (auto& p : intList)
//	{
//		if (x % 2 == 0)
//			p = x * (x + 2);
//		else
//			p = (x - 1) * (x + 3);
//		x++;
//	}
//
//	for (auto p : intList)
//		cout << p << " ";
//
//	return 0;
//}
//int main()
//{
//	float myFloat = 0.0f;
//	cout << "Enter a number. ENTER: ";
//	cin >> myFloat;
//	cout << myFloat << " in the power of 2 is " << pow(myFloat, 2) <<
//		endl;
//	cout << myFloat << " in the power of 3 is " << pow(myFloat, 3) <<
//		endl;
//	cout << myFloat << " in the power of 0.5 is " << pow(myFloat, 0.5)
//		<< endl;
//	return 0;
//}

int main()
{
	float myFloat = 0.0f;
	cout << "Enter a number. ENTER: ";
	cin >> myFloat;
	cout << "sin(" << myFloat << ") = " << sin(myFloat);
	cout << "cos(" << myFloat << ") = " << cos(myFloat) << endl;
	cout << "tan(" << myFloat << ") = " << tan(myFloat) << endl;
	return 0;
}