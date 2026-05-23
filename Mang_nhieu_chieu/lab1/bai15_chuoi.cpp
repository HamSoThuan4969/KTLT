#include<iostream>
#include<string>
using namespace std;
//Bài 15. Viết chương trình nhập vào 2 chuỗi s1 và s2.Yêu cầu người dùng nhập vị trí cần chèn
//(phải hợp lệ) để tiến hành chèn s2 vào s1 bắt đầu từ vị trí đã nhập.Xuất lại chuỗi kết quả sau
//khi chèn.

int main() {
	string s1, s2;
	int vitri;
	cout << "Nhap chuoi 1: "; getline(cin, s1);
	cout << "Nhap chuoi 2: "; getline(cin, s2);
	while (true) {
		cout << "Nhap vi tri can chen: "; cin >> vitri;
		if (vitri >= 0 && vitri <= s1.length()) {
			break;
		}
	}
	s1.insert(vitri, s2);
	cout << "Chuoi sau khi chen: " << s1 << endl;
}