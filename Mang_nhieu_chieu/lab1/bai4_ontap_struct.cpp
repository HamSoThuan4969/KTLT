#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

ifstream fin;
ofstream fout;

struct HocSinh
{
	string hoTen;
	string ngaySinh;
	string queQuan;
	double toan, van, anh;
};

// Ham nhap 1 hoc sinh
void nhapHS(HocSinh& hs)
{
	cout << "=============================\n";
	cout << "Nhap ho ten: ";
	getline(cin, hs.hoTen);
	cout << "Nhap ngay sinh: ";
	getline(cin, hs.ngaySinh);
	cout << "Nhap que quan: ";
	getline(cin, hs.queQuan);
	cout << "Nhap diem: ";
	cin >> hs.toan >> hs.van >> hs.anh;
	cin.ignore();
}

// Ham tinh diem trung binh
double tinhDTB(HocSinh hs)
{
	return (hs.toan + hs.van + hs.anh) / 3;
}

// Ham tinh tuoi
int tinhTuoi(HocSinh hs)
{
	// Tim dau gach cuoi
	int dauGachCuoi = hs.ngaySinh.rfind("-");
	// Tach nam sinh tu dau gach cuoi + 1 den cuoi
	string namSinh = hs.ngaySinh.substr(dauGachCuoi + 1);
	// Chuyen chuoi thanh so
	int ns = stoi(namSinh);
	// Lay nam hien tai
	time_t hienTai = time(0);
	tm* ntn = localtime(&hienTai);
	int namHienTai = ntn->tm_year + 1900;
	// Tru va tra ve tuoi
	return namHienTai - ns;
}

// Ham xuat 1 hoc sinh
void xuatHS(HocSinh hs)
{
	cout << "==========================\n";
	cout << "Ho ten: " << hs.hoTen << endl;
	cout << "Ngay sinh: " << hs.ngaySinh << endl;
	cout << "Que quan: " << hs.queQuan << endl;
	cout << "Diem: " << hs.toan << ", " << hs.van << ", " << hs.anh << endl;
	cout << "DTB: " << tinhDTB(hs) << endl;
	cout << "Tuoi: " << tinhTuoi(hs) << endl;
}

// Ham xuat thong tin cua tat ca hoc sinh
void xuatLop(HocSinh lop[], int sl)
{
	// Duyet theo so luong hoc sinh cua lop
	for (int i = 0; i < sl; i++)
		xuatHS(lop[i]);
}

// Ham doc du lieu tu file
void docFile(HocSinh lop[], int& sl)
{
	fin.open("HocSinh.txt", ios::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			HocSinh hs;
			// Doc ho ten
			getline(fin, hs.hoTen, ';');
			fin.ignore(); // Bo qua khoang trang
			// Doc ngay sinh
			getline(fin, hs.ngaySinh, ';');
			fin.ignore();
			// Doc que quan
			getline(fin, hs.queQuan, ';');
			fin.ignore();
			// Doc diem toan
			fin >> hs.toan;
			fin.ignore();
			// Doc diem van
			fin >> hs.van;
			fin.ignore();
			// Doc diem anh
			fin >> hs.anh;
			fin.ignore();
			lop[sl] = hs; // Them hoc sinh vao lop
			sl++; // Tang so luong cua lop
		}
		fin.close();
	}
	else
		cout << "Mo file that bai\n";
}

// Ham ghi/cap nhat file
void ghiFile(HocSinh lop[], int sl)
{
	fout.open("HocSinh.txt", ios::out);
	if (fout.is_open())
	{
		// Duyet theo so luong lop hien tai
		for (int i = 0; i < sl; i++)
		{
			// Ghi lai thong tin hoc sinh nhu file goc
			fout << lop[i].hoTen << "; "
				<< lop[i].ngaySinh << "; "
				<< lop[i].queQuan << "; "
				<< lop[i].toan << "; "
				<< lop[i].van << "; "
				<< lop[i].anh << endl;
		}
		fout.close();
	}
	else
		cout << "Mo file that bai\n";
}

// Ham them hoc sinh
void themHS(HocSinh lop[], int& sl)
{
	if (sl < 50)
	{
		// Nhap thong tin hoc sinh moi
		HocSinh hs;
		nhapHS(hs);

		// Them hoc sinh moi vao cuoi danh sach
		lop[sl] = hs;
		sl++;
		ghiFile(lop, sl);
	}
	else
		cout << "Lop da day\n";
}

// Ham sap xep danh sach hoc sinh
void sapXep(HocSinh lop[], int sl)
{
	for (int i = 0; i < sl - 1; i++)
		for (int j = i + 1; j < sl; j++)
			if (tinhDTB(lop[i]) > tinhDTB(lop[j]))
				swap(lop[i], lop[j]);
	ghiFile(lop, sl);
}

int main()
{
	// Cau a: nhapHS, xuatHS, tinhDTB, tinhTuoi

	// Cau b
	HocSinh lop[50];
	int sl = 0; // Chua doc hoc sinh

	// Cau c
	docFile(lop, sl);
	xuatLop(lop, sl);

	// Cau d
	themHS(lop, sl);

	// Cau e
	sapXep(lop, sl);
	system("pause");
	return 0;
}