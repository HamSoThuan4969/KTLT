#include<iostream>
#include<string>
using namespace std;
struct SanPham {
	char maSp[10];
	string tenSp;
	double dongia;
	int soLuongTon;

};
void nhap(SanPham* sp, int& n) {
	cout << "Nhap so luong san pham: ";
    cin >> n;
	
    for (int i = 0; i < n; i++) {
		cout << " Nhap thong tin cua sp thu " << i + 1 << endl;
        cin.ignore();
		cout << " Ma san pham: ";
        cin.getline((sp + i)->maSp, 10);
		cout << " Ten san pham: ";
        getline(cin, (sp + i)->tenSp);
		cout << " Don gia: ";
		cin >> (sp + i)->dongia;
		cout << " So luong ton: ";
		cin >> (sp + i)->soLuongTon;
		cout << "-----------------------------" << endl;

    }
}
void xuat(SanPham* sp, int n) {
    cout << " Danh sach sp : " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Ma sp : " << (sp + i)->maSp << endl;
        cout << " Ten sp: " << (sp + i)->tenSp << endl;
        cout << " Don gia: " << (sp + i)->dongia << endl;
        cout << "So luong ton: " << (sp + i)->soLuongTon << endl;
    }
}
void sua(SanPham* sp, int n) {
    int Vitri;
    cout << "Nhap vi tri can sua : ";
    cin >> Vitri;
    // đỏi sang hệ chỉ số 0
    Vitri--;
    if (Vitri < 0 || Vitri >= n) {
        cout << " Vi tri khong hop le!" << endl;
        return;
    }
    cout << " Nhap thong tin cua sp thu " << Vitri + 1 << endl;
    cout << "Nhap maSp: "; cin.getline((sp + Vitri)->maSp, 10);
    cout << "Nhap tenSp: "; getline(cin, (sp + Vitri)->tenSp);
    cout << " Nhap don gia: "; cin >> (sp + Vitri)->dongia;
	cout << "Nhap so luong ton: "; cin >> (sp + Vitri)->soLuongTon;
    cout<<"Sua thanh cong" << endl;
    cout << "-------------------------------" << endl;


}
void xoa(SanPham* sp, int& n) {
    int Vitri;
    cout << "Nhap vi tri can xao: ";
	cin >> Vitri;
    cin.ignore();
	// đổi sang hệ chỉ số 0
    Vitri--;
    if (Vitri < 0 || Vitri >= n) {
		cout << " Vi tri khong hop le!" << endl;
		return;
    }
    for (int i = Vitri; i < n - 1; i++) {
        *(sp + i) = *(sp + i + 1);

    }
    n--;
}
void Sort(SanPham* sp, int& n) {
    // tăng dần
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((sp + i)->soLuongTon > (sp + j)->soLuongTon) {
                SanPham temp = *(sp + i);
                *(sp + i) = *(sp + j);
				*(sp + j) = temp;
            }
        }
    }
	cout << "Sap xep thanh cong!" << endl;
}
int main() {
	SanPham* sp = new SanPham[30];
	int n = 0; // khai bao để lưu số lượng sản phẩm hiện có trong mảng
	int luaChon;
    do {
        cout << "\n====== MENU ======" << endl;
        cout << "1. Nhap san pham" << endl;
        cout << "2. Xuat san pham" << endl;
        cout << "3. Sua san pham" << endl;
        cout << "4. Xoa san pham" << endl;
        cout << "5. Sap xep san pham" << endl;
        cout << "0. Thoat" << endl;
        cout << "Lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
        case 1: nhap(sp, n);   break;
        case 2: xuat(sp, n);   break;
        case 3: sua(sp, n);    break;
        case 4: xoa(sp, n);    break;
        case 5: Sort(sp, n); break;
        case 0: cout << "Thoat!" << endl; break;
        default: cout << "Lua chon khong hop le!" << endl;
        }
    } while (luaChon != 0);
    delete[] sp;

}