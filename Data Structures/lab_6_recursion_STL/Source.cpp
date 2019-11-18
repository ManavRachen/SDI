#include <iostream>
using namespace std;


int recEx2(int x) {
	if (x <= 0)
		return 0;
	else if (x == 1)
		return 2;
	else
		return (recEx2(x - 1) + recEx2(x - 2) + recEx2(x - 3));
}
void main() {	cout << recEx2(9) << endl;}