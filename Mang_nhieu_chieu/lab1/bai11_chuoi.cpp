#include<iostream>
#include<string>
using namespace std;
int main() {
	string ho, ten, lot = "";
	cout << "Nhap ho: "; getline(cin, ho);
	cout << "Nhap ten: "; getline(cin, ten);
	cout << "Nhap ten lot: "; getline(cin, lot);

	string hoTen = ho;
	hoTen.append(" ").append(lot).append(" ").append(ten);
	cout << "Ho ten: " << hoTen << endl;
}