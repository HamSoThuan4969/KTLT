#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

void Input(char s[], int n) {
	cout << "Nhap ho ten: ";
	cin.getline(s, n);
}

// Ham dung chung: xoa khoang trang dau cuoi, luu vao ketqua
void xoaKhoangTrang(char* chuoi, char* ketqua) {
	while (*chuoi == ' ') chuoi++;       // xoa khoang trang dau
	strcpy(ketqua, chuoi);
	for (int i = strlen(ketqua) - 1; i >= 0; i--) {
		if (ketqua[i] != ' ') {
			ketqua[i + 1] = '\0';        // xoa khoang trang cuoi
			break;
		}
	}
}

// Ham lay ho: token dau tien truoc khoang trang dau tien
void getHo(char* chuoi, char* ho) {
	char temp[200];
	xoaKhoangTrang(chuoi, temp);         // copy vao temp de khong pha chuoi goc

	char* token = strtok(temp, " ");
	if (token != NULL)
		strcpy(ho, token);
	else
		strcpy(ho, "");
}

// Ham lay ten: phan sau khoang trang cuoi cung
void getTen(char* chuoi, char* ten) {
	char temp[200];
	xoaKhoangTrang(chuoi, temp);         // copy vao temp de khong pha chuoi goc

	char* cuoi = strrchr(temp, ' ');
	if (cuoi == NULL)                    // chi co 1 tu -> khong co ten
		strcpy(ten, "");
	else
		strcpy(ten, cuoi + 1);           // phan sau ' ' cuoi = ten
}

// Ham lay chu lot: phan giua ho va ten
void getChuLot(char* chuoi, char* chulot) {
	char temp[200];
	xoaKhoangTrang(chuoi, temp);         // copy vao temp de khong pha chuoi goc

	char* ho = strtok(temp, " ");    // bo ho phia truoc
	char* phanCon = temp + strlen(ho) + 1; // dich qua ho + 1 khoang trang

	char* cuoi = strrchr(phanCon, ' '); // tim ' ' cuoi trong phan con lai
	if (cuoi == NULL)                    // chi con 1 tu -> khong co chu lot
		strcpy(chulot, "");
	else {
		*cuoi = '\0';                    // cat tai ' ' cuoi
		strcpy(chulot, phanCon);         // phan truoc ' ' cuoi = chu lot
	}
}

int main() {
	char chuoi[200];
	char ho[100], chulot[100], ten[100];

	Input(chuoi, 200);

	getHo(chuoi, ho);
	getChuLot(chuoi, chulot);
	getTen(chuoi, ten);

	cout << "\n--- Ket qua ---" << endl;
	cout << "Ho     : " << ho << endl;
	cout << "Chu lot: " << (strlen(chulot) ? chulot : "(khong co)") << endl;
	cout << "Ten    : " << (strlen(ten) ? ten : "(khong co)") << endl;

	return 0;
}