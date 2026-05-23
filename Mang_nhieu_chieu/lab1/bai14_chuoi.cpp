#include<iostream>
#include<string>
using namespace std;

//Bài 14. Viết chương trình nhập vào 1 chuỗi ký tự và 1 từ.Sau đó đếm số lần xuất hiện của từ
//trong chuỗi vừa nhập.
int demSoLanXuatHien(string chuoi, string tu) {
	int count = 0;
	for (int i = 0; i <= chuoi.length() - tu.length(); i++) {
		if (chuoi.substr(i, tu.length()) == tu) {
			count++;
		}
	}
	return count;
}
int main() {
	string chuoi = "";
	cout << "Nhap chuoi: "; getline(cin, chuoi);
	string tu = "";
	cout << "Nhap chuoi: "; getline(cin,tu);
	cout << "So lan xuat hien cua tu '" << tu << "' trong chuoi: " << demSoLanXuatHien(chuoi, tu) << endl;
}