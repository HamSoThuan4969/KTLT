#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

void Input(char s[], int n) {
	cout << "Nhap ngay thang nam (mm/dd/yy): ";
	cin.getline(s, n);
}

int soNgayTrongThang(int thang, int nam) {
	int soNgay[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (thang == 2)
		if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
			return 29;
	return soNgay[thang - 1];
}

// [SUA 1] doi dau '-' thanh '/' theo dinh dang "mm/dd/yy" cua de bai
// [SUA 2] them & vao month de tra ve gia tri ra ngoai
// [SUA 3] kiem tra strlen == 8 vi nam chi co 2 chu so (mm/dd/yy = 8 ky tu)
bool checkTime(char* time, int& day, int& month, int& year) {
	// Buoc 1: kiem tra dinh dang
	if (strlen(time) != 8) return false;        // [SUA 3] 8 thay vi 10
	for (int i = 0; i < 8; i++) {
		if (i == 2 || i == 5) { if (time[i] != '/') return false; } // [SUA 1] '/' thay vi '-'
		else { if (!isdigit(time[i])) return false; }
	}

	// Buoc 2: tach thang ngay nam
	char month_str[3], day_str[3], year_str[3];
	strncpy(month_str, time, 2); month_str[2] = '\0';
	strncpy(day_str, time + 3, 2); day_str[2] = '\0';
	strncpy(year_str, time + 6, 2); year_str[2] = '\0'; // [SUA 3] chi lay 2 chu so

	month = atoi(month_str);
	day = atoi(day_str);
	year = atoi(year_str);

	// Buoc 3: kiem tra gia tri hop le
	if (month < 1 || month > 12) return false;
	if (year < 0)               return false;
	if (day   < 1 || day > soNgayTrongThang(month, year)) return false;

	return true;
}

void xuatDinhDangQuocTe(int day, int month, int year) {
	// [SUA 4] mang ten thang tieng Anh
	const char* tenThang[] = {
		"January", "February", "March",     "April",
		"May",     "June",     "July",      "August",
		"September","October", "November",  "December"
	};

	// [SUA 5] quy doi nam 2 chu so sang 4 chu so
	// 00->99 → them 1900 (vi du: 55 → 1955)
	if (year >= 0 && year <= 99)
		year += 1900;

	// Xuat: "July 21, 1955"
	cout << tenThang[month - 1] << " " << day << ", " << year << endl; /// quan trọng 
}

int main() {
	char s[100];
	int day = 0, month = 0, year = 0;

	Input(s, 100);

	if (!checkTime(s, day, month, year)) {
		cout << "Ngay thang nam khong hop le!" << endl;
		return 0;
	}

	cout << "Ket qua: ";
	xuatDinhDangQuocTe(day, month, year);

	return 0;
}