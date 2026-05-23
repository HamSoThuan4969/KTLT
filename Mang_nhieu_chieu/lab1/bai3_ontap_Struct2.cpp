#include<iostream>
#include<string>
#include<fstream>
using namespace std;
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
	int ngay;
	int thang;
	int nam;
};
struct SanPham {
	string maSp;
	string tenSp;
	double dongia;
	int soLuongTon;
	NTN ngaysx;
};
void nhap(SanPham* sp, int& n) {
	cout << "Nhap so luong san pham: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin san pham thu " << i + 1 << endl;
		cout << "Nhap maSp: "; getline(cin, (sp + i)->maSp);
		cout << "Nhap tenSp:"; getline(cin, (sp + i)->tenSp);
		cout << "Nhap don gia: "; cin >> (sp + i)->dongia;
		cout << "Nhap so luong ton : "; cin >> (sp + i)->soLuongTon;
		cout << "Nhpa ngay san xuat: "; cin >> (sp + i)->ngaysx.ngay >> (sp + i)->ngaysx.thang >> (sp + i)->ngaysx.nam;
		cin.ignore();
		cout << "-------------------------------" << endl;
	}

}
void xuat(SanPham* sp, int n) {
	cout << "Danh sach san pham:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Ma sp: " << (sp + i)->maSp << " Ten sp: " << (sp + i)->tenSp << " Don gia: " << (sp + i)->dongia << " So luong ton: " << (sp + i)->soLuongTon << " Ngay san xuat: " << (sp + i)->ngaysx.ngay << "/" << (sp + i)->ngaysx.thang << "/" << (sp + i)->ngaysx.nam << endl;

	}
}
void timKiem(SanPham* sp, int n) {
	string chuoi;
	cout << "nhap chuo can tim kiem";
	getline(cin, chuoi);
	cout << "Danh sach san pham co ten chua chuoi '" << chuoi << "':" << endl;
	for (int i = 0; i < n; i++) {
		if ((sp + i)->tenSp.find(chuoi) != string::npos) {
			cout << "Ma sp: " << (sp + i)->maSp;
			cout << "Ten sp: " << (sp + i)->tenSp;
			cout << "Don gia: " << (sp + i)->dongia;
			cout << "So luong ton: " << (sp + i)->soLuongTon;
			cout << "Ngay san xuat: " << (sp + i)->ngaysx.ngay << "/" << (sp + i)->ngaysx.thang << "/" << (sp + i)->ngaysx.nam;
		}

	}
}
void xoa(SanPham* sp, int& n) {
	string maSP;
	cout << "Nhap ma san pham can xoa: ";
	getline(cin, maSP);
	for (int i = 0; i < n; i++) {
		if ((sp + i)->maSp == maSP) {
			for (int j = i; j < n - 1; j++) {
				*(sp + j) = *(sp + j + 1);
			}
			n--;
			return; // nếu mã sản phẩm là duy nhất, có thể dừng sau khi xóa
		}
	}

}
void SortTangDan(SanPham* sp, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((sp + i)->dongia > (sp + j)->dongia){
				// swap 
				SanPham temp = *(sp + i);
				*(sp + i) = *(sp + j);
				*(sp + j) = temp;
			}
		}
	}
	cout << "Sap xep thanh cong!" << endl;
}
void ghiFile(SanPham* sp, int n) {
	ofstream outFile;
	outFile.open("DSSP.txt", ios::out);
	if (!outFile) {
		cout << "Khong the mo file !" << endl;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			outFile << (sp + i)->maSp << "#" << (sp + i)->tenSp << "#" << (sp + i)->dongia << "#" << (sp + i)->soLuongTon << "#" << (sp + i)->ngaysx.ngay << "/" << (sp + i)->ngaysx.thang << "/" << (sp + i)->ngaysx.nam << endl;

		}
		outFile.close();
		cout << "Ghi file thanh cong!" << endl;
	}

}
int main() {
	SanPham* cuahang = new SanPham[60];
	int soLuong;
	nhap(cuahang, soLuong);
	xuat(cuahang, soLuong);
	timKiem(cuahang, soLuong);
	xoa(cuahang, soLuong);
	SortTangDan(cuahang, soLuong);
	xuat(cuahang, soLuong);
	ghiFile(cuahang, soLuong);

}