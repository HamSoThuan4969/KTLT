#include<iostream>
#include<string>
#include<ctime>
using namespace std;
//Bài 2: Định nghĩa kiểu dữ liệu SinhVien gồm các thông tin :
//● Mã số sinh viên(string)
//● Họ tên(string)
//● Địa chỉ(string)
//● Năm sinh(int)
//● Điểm toán(double)
//● Điểm văn(double)
//● Điểm ngoại ngữ(double)
//Thực hiện các yêu cầu sau :
//a.Tạo một lớp học gồm nhiều sinh viên bằng mảng.Lưu ý : sĩ số không quá 45 sinh viên.
//b.Viết hàm nhập vào thông tin của một sinh viên trong lớp học.
//c.Viết hàm xuất thông tin của sinh viên theo số thứ tự mà người dùng nhập.
//d.Viết hàm tính điểm trung bình của tất cả sinh và xuất danh sách sinh viên gồm mã số sinh
//viên, họ tên và điểm trung bình của từng sinh viên.Biết :
//	Điểm trung bình = ((Điểm toán + Điểm văn) * 2 + Điểm ngoại ngữ) / 5
//	e.Viết hàm xếp loại sinh viên.Nếu điểm trung bình từ 8 trở lên thì xếp loại là “Giỏi”.Nếu
//	điểm trung bình từ 6.5 đến < 8 thì xếp loại là “Khá”.Nếu điểm trung bình từ 5 đến < 6.5
//	thì xếp loại là “TB”.Nếu điểm dưới 5 thì xếp loại “Dưới TB”.
//	f.Viết hàm tạo email cho từng sinh viên theo định dạng sau :
//<Mã số sinh viên><Tên sinh viên>@ou.edu.vn
//g.Viết hàm in đầy đủ thông tin của tất cả sinh viên trong lớp học(bao gồm các thông tin cơ
//	bản, điểm trung bình, xếp loại, và email).
//	h.Viết hàm main kiểm chứng chương trình.
struct SinhVien {
	string mssv;
	string hoten;
	string diachi;
	int namsinh;
	double toan, van, nn;

};
void nhap(SinhVien& sv) {
	cout << "Nhap ma so sinh vien : ";
	getline(cin, sv.mssv);
	cout << "Nhap ho ten: ";
	getline(cin, sv.hoten);
	cout << "Nhap dia chi: ";
	getline(cin, sv.diachi);
	cout << "Nhap nam sinh: ";
	cin >> sv.namsinh;
	cout << "Nhap diem toan, van, ngoai ngu: ";
	cin >> sv.toan >> sv.van >> sv.nn;
	cin.ignore();
}


void nhapLop(SinhVien lop[45], int sl) {
	for (int i = 0; i < sl; i++) {
		cout << "Nhap thong tin sinh vien thu " << i + 1 << " \n";
		nhap(lop[i]);
	}
}
double tinhDiemTB(SinhVien sv){
	return ((sv.toan + sv.van) * 2 + sv.nn) / 5;
}
string xepLoai(SinhVien sv) {
	double dtv = tinhDiemTB(sv);
	if (dtv >= 8)
		return "Gioi";
	else if (dtv >= 6.5)
		return "Kha";
	else if (dtv >= 5)
		return "TB";
	else
		return "Duoi TB";
}
string taoEmail(SinhVien sv) {
	int khoangTrangCuoi = sv.hoten.rfind(" ");
	string ten = sv.hoten.substr(khoangTrangCuoi + 1);
	// tạo email: 
	return sv.mssv + ten + "@ou.edu.vn";
}
void xuatSV(SinhVien sv) {
	cout << "Ma so sinh vien: " << sv.mssv << endl;
	cout << "Ho ten: " << sv.hoten << endl;
	cout << "Dia chi: " << sv.diachi << endl;
	cout << "Nam sinh: " << sv.namsinh << endl;
	cout << "Diem toan: " << sv.toan << endl;
	cout << "Diem van: " << sv.van << endl;
	cout << "Diem ngoai ngu: " << sv.nn << endl;
	cout << "Diem tb: " << tinhDiemTB(sv) << endl;
	cout << "Xep loai: " << xepLoai(sv) << endl;
	cout << "Email: " << taoEmail(sv) << endl;
}

int main() {
	SinhVien lop[45];
	int sl;
	cout << "Nhap so luong sinh vien ( <= 45): ";
	do {
		cin >> sl;
		if (sl < 1 || sl > 45) {
			cout << "So luong sinh vien khong hop le. Vui long nhap lai: ";
		}
	} while (sl < 1 || sl > 45);
	cin.ignore();
	nhapLop(lop, sl);
	cout << "Thong tin sinh vien thu 2: \n";
	xuatSV(lop[1]);


}