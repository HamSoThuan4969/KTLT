#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<ctime>
using namespace std;


struct NhanVien{
	string Manv;
	string hoten;
	int namVaoLam;
	int namSinh;

};
void Nhap(NhanVien &nv) {
	cout << "nhap ma nhan vien: ";;
	getline(cin, nv.Manv);
	cout << "nhap ho ten: ";
	getline(cin, nv.hoten);
	cout << "nhap nam vao lam: ";
	cin >> nv.namVaoLam;
	cout << "nhap nam sinh: ";
	cin >> nv.namSinh;


}
void Xuat(NhanVien nv) {
	cout << "ma nhan vien: " << nv.Manv << endl;
	cout << "ho ten: " << nv.hoten << endl;
	cout << "nam vao lam: " << nv.namVaoLam << endl;
	cout << "nam sinh: " << nv.namSinh << endl;
}
int tinhTuoi(NhanVien nv) {
	time_t hienTai = time(0);
	tm* ntn = localtime(&hienTai);
	int namHienTai = ntn->tm_year + 1900;
	return namHienTai - nv.namSinh;
}
int main() {
	NhanVien nv1;
	Nhap(nv1);
	Xuat(nv1);
	cout << "tuoi: " << tinhTuoi(nv1) << endl;

}