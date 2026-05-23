#include<iostream>
#include<string>
using namespace std;

struct SinhVien {
	string masv;
	string hoten;
	string diachi;
	int namsinh;
	double dtoan;
	double dvan;
	double av;

};
struct Lop {
	SinhVien ds[45];
	int siSo;
};

void nhap(Lop& l) {
	cout << "Nhap so luong sinh vien: ";
	cin >> l.siSo;
	cin.ignore(); // Để loại bỏ ký tự newline sau khi nhập số
	
	for (int i = 0; i < l.siSo; i++) {
		cout << " Nhap thong tin sinh vien thu: " << i + 1 << endl;
		cout << " Ma sinh vien: " << endl;
		getline(cin, l.ds[i].masv);
		cout << " Ho ten: " << endl;
		getline(cin, l.ds[i].hoten);
		cout << " Dia chi: "<<endl;
		getline(cin, l.ds[i].diachi);
		cout << " Nam sinh: " << endl;
		cin >> l.ds[i].namsinh;
		cout << " Diem toan: " << endl;
		cin >> l.ds[i].dtoan;
		cout << " Diem van: " << endl;
		cin >> l.ds[i].dvan;
		cout << "Diem av"<<endl;
		cin >> l.ds[i].av;
		cin.ignore(); // Để loại bỏ ký tự newline sau khi nhập số
		cout << "-----------------------------" << endl;

	}
	

}
void xuat(Lop l) {
	cout << " thong tin sinh vien : " << endl;
	for (int i = 0; i < l.siSo; i++) {
		cout << " ma so sinh vien "; 	cout << l.ds[i].masv << endl;
		cout << " ho ten: "; cout << l.ds[i].hoten << endl;
		cout << " dia chi: "; cout << l.ds[i].diachi << endl;
		cout << " nam sinh: "; cout << l.ds[i].namsinh << endl;
		cout << " diem toan: "; cout << l.ds[i].dtoan << endl;
		cout << " diem van: "; cout << l.ds[i].dvan << endl;
		cout << " diem av: "; cout << l.ds[i].av << endl;
		cout << "-----------------------------" << endl;

	}
}
int tinhTB(Lop& l, int i) {
	double AVG = ((l.ds[i].dtoan + l.ds[i].dvan)*2 + l.ds[i].av)/5;
	return AVG;
}
void xepLoai(Lop& l) {
	for (int i = 0; i < l.siSo; i++) {
		double avg = tinhTB(l, i);
		cout << l.ds[i].hoten << " co diem trung binh la: " << avg << " va xep loai: ";
		if (avg >= 9) {
			cout << "Xuat sac" << endl;
		}
		else if (avg >= 8) {
			cout << "Gioi" << endl;
		}
		else if (avg >= 7) {
			cout << "Kha" << endl;
		}
		else if (avg >= 5) {
			cout << "Trung binh" << endl;
		}
		else {
			cout << "Yeu" << endl;
		}
	}
}
int main() {
	Lop l;
	nhap(l);
	xuat(l);
	for (int i = 0; i < l.siSo; i++) {
		cout << l.ds[i].hoten << " co diem trung binh la: " << tinhTB(l, i) << endl;
	}
	xepLoai(l);
	return 0;

}