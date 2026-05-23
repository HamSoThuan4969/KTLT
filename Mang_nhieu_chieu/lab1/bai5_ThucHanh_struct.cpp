#include<iostream>
#include<string>
using namespace std;

struct NTN {
	int ngay;
	int thang;
	int nam;

};
struct Sach {
	char tenSach[20];
	char tacGia[20];
	NTN ngayXuatBan;
};
struct KeSach {
	Sach ds[100];
	int soLuong;
};
void Nhap(KeSach& ks) {
	do {
		cout << " Nhap so luong sach: ";
		cin >> ks.soLuong;
	} while (ks.soLuong < 0 || ks.soLuong > 50);
	cin.ignore(); // Để loại bỏ ký tự newline sau khi nhập số
	for (int i = 0; i < ks.soLuong; i++) {
		cout << " nhap thong ton sach thu " << i + 1 << endl;
		cout << " ten sach: " << endl;
		cin.getline(ks.ds[i].tenSach, 20);
		cout << " tac gia: " << endl;
		cin.getline(ks.ds[i].tacGia, 20);
		cout << " ngay xuat ban: " << endl;
		cout << " ngay: " << endl;
		cin >> ks.ds[i].ngayXuatBan.ngay;
		cout << " thang: " << endl;
		cin >> ks.ds[i].ngayXuatBan.thang;
		cout << " nam: " << endl;
		cin >> ks.ds[i].ngayXuatBan.nam;
		cin.ignore(); // Để loại bỏ ký tự newline sau khi nhập số
		cout << "-----------------------------" << endl;
	}
}
void Xuat(KeSach& ks) {
	for (int i = 0; i < ks.soLuong; i++) {
		cout << " thong tin ke sach " << endl;
		cout << "ten sach :" << ks.ds[i].tenSach << endl;
		cout << " tac giac :" << ks.ds[i].tacGia << endl;
		cout << " ngay xuat ban: " << ks.ds[i].ngayXuatBan.ngay << "/" << ks.ds[i].ngayXuatBan.thang << "/" << ks.ds[i].ngayXuatBan.nam << endl;
	}
}
void XuatDK(KeSach& ks, char r[]) {
	for (int i = 0; i < ks.soLuong; i++) {
		if (strcmp(ks.ds[i].tacGia, r) == 0) {
			cout << " thong tin sach can Tim " << endl;
			cout << "ten sach :" << ks.ds[i].tenSach << endl;
			cout << " tac giac :" << ks.ds[i].tacGia << endl;
		}
	}
}

int main() {
	KeSach ks;
	char r[20] = "kan";
	Nhap(ks);
	Xuat(ks);
	XuatDK(ks, r);
}