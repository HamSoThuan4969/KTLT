#include<iostream>
#include<string>
using namespace std;


struct PhanSo {
	int tu;
	int mau;

};
int ucln(int a, int b) {
	a = (a < 0) ? -a : a;
	b = (b < 0) ? -b : b;
	while (b != 0) {
		int r = b;
		b = a % b;
		a = r;
	}
	return a;
}
PhanSo rutGon(PhanSo ps) {
	int u = ucln(ps.tu, ps.mau);
	ps.tu /= u;
	ps.mau /= u;
	// chuẩn hóa mẫu không âm
	if (ps.mau < 0) {
		ps.tu = -ps.tu;
		ps.mau = -ps.mau;
	}
	return ps;
}
PhanSo Cong(PhanSo ps1, PhanSo ps2) {
	PhanSo kq;
	kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
	kq.mau = ps1.mau * ps2.mau;
	return rutGon(kq);
}
PhanSo Tru(PhanSo ps1, PhanSo ps2) {
	PhanSo kq;
	kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
	kq.mau = ps1.mau * ps2.mau;
	return rutGon(kq);
}
PhanSo Nhan(PhanSo ps1, PhanSo ps2) {
	PhanSo kq;
	kq.tu = ps1.tu * ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return rutGon(kq);
}
PhanSo Chia(PhanSo ps1, PhanSo ps2) {
	PhanSo kq;
	kq.tu = ps1.tu * ps2.mau;
	kq.mau = ps1.mau * ps2.tu;
	return rutGon(kq);
}
int main() {
	PhanSo ps1, ps2;
	cout << "Nhap phan so 1 (tu mau): ";
	cin >> ps1.tu >> ps1.mau;
	cout << "Nhap phan so 2 (tu mau): ";
	cin >> ps2.tu >> ps2.mau;
	PhanSo tong = Cong(ps1, ps2);
	PhanSo hieu = Tru(ps1, ps2);
	PhanSo tich = Nhan(ps1, ps2);
	PhanSo thuong = Chia(ps1, ps2);
	cout << "Tong: " << tong.tu << "/" << tong.mau << endl;
	cout << "Hieu: " << hieu.tu << "/" << hieu.mau << endl;
	cout << "Tich: " << tich.tu << "/" << tich.mau << endl;
	cout << "Thuong: " << thuong.tu << "/" << thuong.mau << endl;

	
}
