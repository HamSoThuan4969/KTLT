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
	return 0;
}