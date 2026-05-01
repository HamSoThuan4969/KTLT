#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
void Input(char s[100]) {
	cout << "nhap chuoi:  \n";
	cin.getline(s, 100);
}
void Output(char s[]) {
	cout << "Xuat chuoi : \n";
	for (int i = 0; i < strlen(s); i++) {
		cout << s[i];
	}
	cout << endl;
}
//Bài 6. Xây dựng hàm nhận vào 1 chuỗi ký tự có dạng : “ngay - thang - nam” với mỗi giá trị
//ngày, tháng là 2 ký tự, năm là 4 ký tự(Ví dụ : “06 - 01 - 2007”).Sau đó trả về xem ngày đó là
//ngày thứ mấy trong năm.

int soNgayTrongThang(int thang, int nam) {
	int soNgay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (thang == 2)
		if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
			return 29;
	return soNgay[thang - 1];
}

bool checkTime(char* time, int &day, int month, int &year) {
	// Bước 1: kiểm tra định dạng
	if (strlen(time) != 10) return false;
	for (int i = 0; i < 10; i++) {
		if (i == 2 || i == 5) { if (time[i] != '-')    return false; }
		else { if (!isdigit(time[i])) return false; }
	}

	// Bước 2: tách ngày tháng năm
	char day_str[3], month_str[3], year_str[5];
	strncpy(day_str, time, 2); day_str[2] = '\0';
	strncpy(month_str, time + 3, 2); month_str[2] = '\0';
	strncpy(year_str, time + 6, 4); year_str[4] = '\0';

	 day = atoi(day_str);
	 month = atoi(month_str);
	 year = atoi(year_str);

	// Bước 3: kiểm tra giá trị hợp lệ
	if (month < 1 || month > 12) return false;
	if (year < 1)               return false;
	if (day   < 1 || day > soNgayTrongThang(month, year)) return false;

	return true;
}
int tinhNgayThu(int day, int month, int year) {
	int ngayThu = 0;
	for (int i = 1; i < month; i++) {
		ngayThu += soNgayTrongThang(i, year);
	}
	ngayThu += day;
	return ngayThu;
}
int main() {
	char s[100];
	int day = 0;
	int month = 0;
	int year = 0;
	Input(s);
	Output(s);
	if (checkTime(s, day, month, year)) {
		cout << "Ngay thang nam hop le! \n";
		cout << "Ngay thu " << tinhNgayThu(day, month, year) << " trong nam " << year << endl;
	}
	else
		cout << "Ngay thang nam khong hop le! \n";

}