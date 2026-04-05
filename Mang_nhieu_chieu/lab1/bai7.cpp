#include<iostream>
using namespace std;


void intputArray(int a[100][100], int row, int col) {
	cout << "Nhap mang: " << endl;
	for (int i = 0; i < row; i++) {
		for(int j=0;j<col;j++){
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}
void outputArray(int a[100][100], int row, int col){
	cout << "Xuat mang" << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}
// b. tính trung bình cộng của tất cả phần tử trong mảng
int Average(int a[100][100], int row, int col) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			sum += a[i][j];
		}
	}
	return sum / (row * col);
}
bool findValue(int a[100][100], int row, int col, int value) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (a[i][j] == value) {
				return true;
			}
		}
	}
	return false;
}

void swap_value(int a[100][100], int row, int col, int value1, int value2) {
	if (findValue(a, row, col, value1) && findValue(a, row, col, value2)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (a[i][j] == value1) {
					a[i][j] = value2;
				}
				else {
					if (a[i][j] == value2) {
						a[i][j] = value1;
					}
				}
			}
		}
	}
}
int main() {
	int a[100][100];
	int row, col;
	int value;
	cout << "Nhap so dong: ";
	cin >> row;
	cout << "Nhap so cot: ";
	cin >> col;
	intputArray(a, row, col);
	outputArray(a, row, col);
	cout << endl;
	cout << "Trung binh cong cua mang la: " << Average(a, row, col) << endl;
	cout << "Nhap gia tri can tim: ";
	cin >> value;
	if (findValue(a, row, col, value)) {
		cout << "Gia tri " << value << " co trong mang." << endl;
	}
	else {
		cout << "Gia tri " << value << " khong co trong mang." << endl;
	}
	int value1, value2;
	cout << "Nhap gia tri can doi cho thu nhat: ";
	cin >> value1;
	cout << "Nhap gia tri can doi cho thu 2 : ";
	cin >> value2;
	swap_value(a, row, col, value1, value2);
	return 0;
}