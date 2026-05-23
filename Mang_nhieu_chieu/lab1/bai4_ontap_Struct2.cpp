#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct HocSinh {
	string hoTen;
	string namSinh;
	string quequan;
	double diemToan;
	double diemVan;
	double diemAnh;

};
void Nhap(HocSinh* hs, int& n) {
	cout << " nhao so luong hoc sinh";
	cin >> n;
	cin.ignore();
}
int main() {
	HocSinh* hs = new HocSinh[50];
	int n = 0;

}