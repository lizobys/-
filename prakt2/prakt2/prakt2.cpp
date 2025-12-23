#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");
	long long sum = 0;
	for (int i = 0; i < 105000000; i++) {
		sum += i * i;
	}
	cout << "summa: " << sum << endl;

	int* arr = new int[100000];
	for (int i = 0; i < 100000; i++){
		arr[i] = i;
	}
	return 0;
}


