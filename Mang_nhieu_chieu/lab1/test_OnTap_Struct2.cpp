#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>;
#include<ctime>;
using namespace std;


struct NhanVien {
	string maNV;
	string hoten;
	int namvaolam;
	int namSinh;
};
void nhap(NhanVien &nv) {
	cout << "Nhap thong tin nhan vien";
	cout << " Ma nhan vien: ";
	getline(cin, nv.maNV);
	cout << " Ho ten: ";
	getline(cin, nv.hoten);
	cout << " Nam vao lam: ";
	cin >> nv.namvaolam;
	cout << " Nam sinh: ";
	cin >> nv.namSinh;
	cin.ignore(); // Để loại bỏ ký tự newline sau khi nhập số
}
void xuat(NhanVien nv) {
	cout << " thogn tin nhan vien " << endl;
	cout << "Ma nhan vien" << nv.maNV << endl;
	cout << " Ho ten: " << nv.hoten << endl;
	cout << " Nam vao lam: " << nv.namvaolam << endl;
	cout << " Nam sinh: " << nv.namSinh << endl;

	
}
int tinhTuo(NhanVien nv) {
	time_t hientai = time(0);
	tm* ntn = localtime(&hientai);
	int namHienTai = ntn->tm_year + 1900;
	return namHienTai - nv.namSinh;
}
int thamNien(NhanVien nv) {
	time_t hientai = time(0);
	tm* ntn = localtime(&hientai);
	int namHientai = ntn->tm_year + 1900;
	return namHientai - nv.namvaolam;
}
int main() {
	NhanVien nv1;
	nhap(nv1);
	xuat(nv1);
	cout << " Tuoi cua nhan vien: " << tinhTuo(nv1) << endl;
	cout << " Tham nien cua nhan vien: " << thamNien(nv1) << endl;

}