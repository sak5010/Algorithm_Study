#include <iostream>
using namespace std;

void selection_sort(int data[]) {
	int i, j, min, tmp, min_index;
	for(int i=0; i<10; ++i) {
		min = 9999;
		for(int j=i; j<10; ++j) {
			if(data[j] < min) {
				min = data[j];
				min_index = j;
			}
		}
		tmp = data[i];
		data[i] = data[min_index];
		data[min_index] = tmp;
	}
}

void print_out(int data[]) {
	for(int i=0; i<10; ++i) {
		cout << data[i] << " ";
	}
	cout << endl;
}

int main(void) {
	int data[10] = { 1, 9, 5, 2, 7, 8, 3, 4, 6, 10 };
	
	selection_sort(data);
	print_out(data);
	
	return 0;
}
