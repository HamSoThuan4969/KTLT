#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ofstream outFile;

//Bài 3: Định nghĩa kiểu dữ liệu SanPham gồm các thông tin như sau :
//● Mã sản phẩm(string)
//● Tên sản phẩm(string)
//● Đơn giá(double)
//● Số lượng tồn kho(int)
//● Ngày sản xuất(kiểu NTN : gồm thuộc tính ngày, tháng, năm là 3 số nguyên)
//Thực hiện các yêu cầu sau :
//a.Tạo một cửa hàng gồm nhiều sản phẩm bằng cấp phát động.Lưu ý : cửa hàng chỉ chứa tối
//đa 60 sản phẩm.
//b.Viết hàm cho người dùng nhập thông tin của tất cả sản phẩm trong cửa hàng.
//c.Viết hàm xuất danh sách sản phẩm ra màn hình, mỗi sản phẩm trên một dòng.
//d.Viết hàm cho người dùng nhập vào một chuỗi ký tự bất kỳ, sau đó tìm và in ra tất cả sản
//phẩm có tên chứa chuỗi ký tự đó.
//e.Viết hàm cho nhập vào mã sản phẩm.Nếu tìm thấy, thực hiện xóa sản phẩm có mã tương
//ứng.
//f.Viết hàm sắp xếp toàn bộ danh sách sản phẩm theo thứ tự đơn giá tăng dần.
//g.Viết hàm ghi toàn bộ danh sách sản phẩm đã được sắp xếp ra tập tin DSSP.txt, mỗi sản
//phẩm trên một dòng.
//h.Viết hàm main kiểm chứng chương trình

struct NTN {
	int ngay, thang, nam;
};
struct SanPham {
	string masp;
	string tensp;
	double dongia;
	int soluong;
	NTN ngaySX;

};
void nhapSP(SanPham& sp) {
	cout << "nhap san pham: \n";
	cout << "Nhap ma san pham: ";
	getline(cin, sp.masp);
	cout << "Nhap ten san pham: ";
	getline(cin, sp.tensp);
	cout << "Nhap don gia: ";
	cin >> sp.dongia;
	cout << "Nhap so luong: ";
	cin >> sp.soluong;
	cout << "Nhap ngay san xuat (ngay thang nam): ";
	cin >> sp.ngaySX.ngay >> sp.ngaySX.thang >> sp.ngaySX.nam;
	cin.ignore();
}
void nhapCuaHang(SanPham cuahang[60], int sl) {
	for (int i = 0; i < sl; i++) {
		cout << "Nhap thong tin san pham thu : " << i + 1 << endl;
		nhapSP(cuahang[i]);
		cout << endl;
	}
}
void xuatSanPham(SanPham sp) {
	cout << "============================\n";
	cout << "Ma san pham: " << sp.masp << endl;
	cout << "Ten san pham: " << sp.tensp << endl;
	cout << "Don gia: " << sp.dongia << endl;
	cout << "So luong: " << sp.soluong << endl;
	cout << "Ngay san xuat: " << sp.ngaySX.ngay << "/" << sp.ngaySX.thang << "/" << sp.ngaySX.nam << endl;

}
void timkiem(SanPham cuahang[60], int sl) {
	string chuoi;
	cout << "nhap chuoi can tim" << endl;
	getline(cin, chuoi);
	cout << "Cac san pham co ten chua chuoi " << chuoi << "':\n";
	for (int i = 0; i < sl; i++) {
		if (cuahang[i].tensp.find(chuoi) != string::npos);
		xuatSanPham(cuahang[i]);
	}
}
void xoaSP(SanPham cuahang[60], int& sl) {
	string ma;
	cout << "nhap ma san pham can xoa";
	getline(cin, ma);
	for (int i = 0; i < sl; i++) {
		if (cuahang[i].masp == ma) {
			for (int j = i; j < sl - 1; j++) {
				cuahang[j] = cuahang[j + 1];
			}
			sl--;
		}
	}
}
void swap(SanPham a, SanPham b) {
	SanPham temp = a;
	a = b;
	b = temp;
}
void xepSanPham(SanPham cuahang[60], int sl) {
	for (int i = 0; i < sl - 1; i++) {
		for (int j = i + 1; j < sl; j++) {
			if (cuahang[i].dongia > cuahang[j].dongia) {
				swap(cuahang[i], cuahang[j]);
			}
		}
	}
}
void ghiFile(SanPham cuahang[60], int sl) {
	outFile.open("SanPham.txt", ios::out);
	if (!outFile.is_open()) {
		cout << "Khong mo duọc file " << endl;
		return;
	}
	else {
		for (int i = 0; i < sl; i++) {
			SanPham sp = cuahang[i];
			outFile << "============================\n";
			outFile << "Ma san pham: " << sp.masp << endl;
			outFile << "Ten san pham: " << sp.tensp << endl;
			outFile << "Don gia: " << sp.dongia << endl;
			outFile << "So luong: " << sp.soluong << endl;
			outFile << "Ngay san xuat: " << sp.ngaySX.ngay << "/" << sp.ngaySX.thang << "/" << sp.ngaySX.nam << endl;

			
		}
		outFile.close();
	}
}

int main() {
	SanPham cuahang[60];
	int sl;
	do {
		cout << "Nhap so luong san pham (1-60): ";
		cin >> sl;
		cin.ignore();
	} while (sl < 1 || sl > 60);
	nhapCuaHang(cuahang, sl);
	xuatSanPham(cuahang[0]);
	timkiem(cuahang, sl);
	xoaSP(cuahang, sl);
	xepSanPham(cuahang, sl);
	ghiFile(cuahang, sl);

}