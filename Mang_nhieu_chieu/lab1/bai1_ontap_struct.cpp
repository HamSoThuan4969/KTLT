#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

//Bài 1: Định nghĩa kiểu dữ liệu NhanVien gồm các thông tin sau :
//● Mã nhân viên(string)
//● Họ tên(string)
//● Năm vào làm(int)
//● Năm sinh(int)
//Thực hiện các yêu cầu sau :
//a.Viết hàm nhập vào đầy đủ thông tin của một nhân viên.
//b.Viết hàm xuất thông tin của nhân viên vừa nhập.
//c.Viết hàm tính tuổi và thâm niên làm việc của nhân viên này.Biết rằng :
//Tuổi = Năm hiện tại – Năm sinh
//Thâm niên = Năm hiện tại – Năm vào làm
//d.Viết hàm main kiểm chứng chương trình.
struct NhanVien {
	string ma;
	string hoten;
	int namvaolam;
	int namsinh;
};
void nhap(NhanVien& nv) {
	cout << "Nhap ma nhan Vien: ";
	getline(cin, nv.ma);
	cout << "Nhap ho ten: ";
	getline(cin, nv.hoten);
	cout << "Nhap nam vao lam: ";
	cin >> nv.namvaolam;
	cout << "Nhap nam sinh: ";
	cin >> nv.namsinh;
	cin.ignore();


}
void xuat(NhanVien nv) {
	cout << "Ma :" << nv.ma << endl;
	cout << "Ho ten: " << nv.hoten << endl;
	cout << "Nam vao lam: " << nv.namvaolam << endl;
	cout << "nam sinh: " << nv.namsinh << endl;
}
int tinhTuoi(NhanVien nv) {
	time_t hientai = time(0);
	tm* ntn = localtime(&hientai);
	int namhientai = ntn->tm_year + 1900;
	return namhientai - nv.namvaolam;
}
int tinhThamnien(NhanVien nv) {
	time_t hientai = time(0);
	tm* ntn = localtime(&hientai);
	int namhientai = ntn->tm_year + 1900;
	return namhientai - nv.namsinh;
}

int main() {
	NhanVien nv1, nv2;
	nhap(nv1);
	xuat(nv1);
	nhap(nv2);
	xuat(nv2);
	cout << "Tuoi: " << tinhTuoi(nv1) << endl;
	cout << "Tham nien: " << tinhThamnien(nv1) << endl;


}