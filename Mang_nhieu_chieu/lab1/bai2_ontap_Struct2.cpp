#include<iostream>
#include<string>
using namespace std;

struct SinhVien {
	string mssv;
	string hoten;
	string diachi;
	int namsinh;
	double toan, van, nn;

};
struct Lop{
	SinhVien ds[45];
	int siso;
};
void Nhap(Lop& l, int &siso) {
	cout << "Nhap so luong sinh vien";
	cin >> siso;
	cin.ignore();
	for (int i = 0; i < l.siso; i++) {
		cout<<"Nhapp thong tin sinh vien thu " << i + 1 << endl;
		cout << "Ma so sinh vien : ";
		getline(cin, l.ds[i].mssv);
		cout << "hoe ten:";
		getline(cin, l.ds[i].hoten);
		cout << "Dia chi: ";
		getline(cin, l.ds[i].diachi);
		cout << "Nam sinh: ";
		cin >> l.ds[i].namsinh;
		cout << "Diem toan, van, ngoai ngu: ";
		cin >> l.ds[i].toan >> l.ds[i].van >> l.ds[i].nn;
		cin.ignore();
	}
}
void xuat(Lop& l, int siso) {
	cout << "xuat thong tin sinh vien" << endl;
	for (int i = 0; i < l.siso; i++) {
		cout << " mssv " << l.ds[i].mssv << endl;
		cout << " ho ten " << l.ds[i].hoten << endl;
		cout << " dia chi " << l.ds[i].diachi << endl;
		cout << " nam sinh " << l.ds[i].namsinh << endl;
		cout << " diem toan " << l.ds[i].toan << endl;
		cout << " diem van " << l.ds[i].van << endl;
		cout << " diem ngoai ngu " << l.ds[i].nn << endl;

	}
}
int AVG(Lop& l, int vitri) {
	return ((l.ds[vitri].toan + l.ds[vitri].van) * 2 + l.ds[vitri].nn) / 5;
}
void xuatTB(Lop& l, int siso) {
	cout << " danh sách sinh vien và diem trung binh" << endl;
	for (int i = 0; i < l.siso; i++) {
		cout << " mssv " << l.ds[i].mssv << endl;
		cout << " ho ten " << l.ds[i].hoten << endl;
		cout << " diem tb :" << AVG(l, i) << endl;
	}
}
string xepLoai(Lop& l, int vitri) {
	double diemTb = AVG(l, vitri);
	if (diemTb >= 8)
		return "Gioi";
	else if (diemTb >= 6.5)
		return "Kha";
	else if (diemTb >= 5)
		return "TB";
	else
		return "Duoi TB";
}
string taoEmail(Lop& l, int vitri) {
	int khoangTrangCuoi = l.ds[vitri].hoten.find(" ");
	string ten = l.ds[vitri].hoten.substr(khoangTrangCuoi + 1);
	return l.ds[vitri].mssv + ten + "@ou.edu.vn";
}

int main() {
	Lop l;
	Nhap(l, l.siso);
	xuat(l,l.siso);
	cout << "-----------------------------" << endl;
	xuatTB(l, l.siso);
	cout << "-----------------------------" << endl;
	cout<<" xep loai sinh vien" << endl;
	for (int i = 0; i < l.siso; i++) {
		cout << "mssv" << l.ds[i].mssv << " ho ten " << l.ds[i].hoten << " xep loai " << xepLoai(l, i) << endl;
	}
	cout << "-----------------------------" << endl;


}