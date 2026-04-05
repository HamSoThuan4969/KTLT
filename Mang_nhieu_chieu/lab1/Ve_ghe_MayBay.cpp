#include<iostream>
using namespace std;
#include<string>

const int ROWS = 13;
const int COLS = 6; 


// check loại ghế theo hàng
string getClassByType(int row) {
    if (row >= 0 && row <= 1) return "Thuong gia";
    else if (row >= 2 && row <= 6) return "Pho thong";
    else if (row >= 7 && row <= 12) return "Tiet kiem";
}
// in danh sách ghế theo loại ghế
void outputTickerByClass(string Ticker[ROWS][COLS], int rowStart, int rowEnd) {
    cout << "\n BANG GHE NGOI \n";
    cout << "     A  B  C  D  E  F \n";
	cout << "   -----------------------\n";
    for (int i = rowStart -1; i <= rowEnd -1; i++) {
        cout << "hang " << i + 1 << " : ";
        for (int j = 0; j < COLS; j++) {
            cout << " " << Ticker[i][j] << " |";
        }
    }
	cout << "\n-----------------------------\n";
	cout << "* la con trong , X la da dat \n";
}
// đếm số ghế trống còn lại của hạng vé 
void countEmptyTicker(string Ticker[ROWS][COLS], int rowStart, int rowEnd) {
    int count = 0;
    cout << "so ghe trong con lai cua hang ve la : " << count;
    for (int i = rowStart - 1; i <= rowEnd - 1; i++) {
        for (int j = 0; j < COLS; j++) {
            if (Ticker[i][j] == "*") count++;
        }
    }
    
}

// phân tích dữ liệu nhập vào từ khách hàng 

int pareseInput(string input, int& row, int& col) {
    string rowPart = ""; // số hàng
    char colPart = ' ';

	// tách phần số hàng và phần cột
    for (int i = 0; i < input.size(); i++) {
        if (input[i] > '0' && input[i] <= '9') {
            rowPart += input[i];
        }
        else if (input[i] >= 'A' && input[i] <= 'F') {
            colPart = input[i];
        }
        else if (input[i] >= 'a' && input[i] <= 'f') {
			colPart -= -32; // chuyển thành chữ hoa
        }
    }
	// mục tiêu là chuyển cả 2 giá trị row và col thành số nguyên để dễ xử lý ( phần này cần lấy giá trị cho hàm khác nên truyền tham chiếu)
    row = stoi(rowPart);// chuyển chuỗi thành số nguyên
	col = colPart - 'A'; // chuyển ký tự cột thành số (A=0, B=1, ..., F=5)


	// sử lý khi người dùng nhập sai định dạng hàng 
    if (row < 1 || row >13) {
        cout << "\n nhap sai dinh dang , nhap tu 1 -> 13";
        return false;
    }
    //xử lý khi người dùng nhập sai định dàng cột
    if (row < 1 || row>6) {
		cout << "\n nhap sai dinh dang , nhap tu A -> F";
		return false;
    }
}
// hàm đặt vé 
void bookTIcker(string Ticker[ROWS][COLS], int row, int col) { // col và row được xử lý trong hàm pareseInput
    if (Ticker[row - 1][col] == "X") {
        cout << " ghe da duoc dat, chon ghe kha di \n";
        return;
    }
    Ticker[row - 1][col] = "X"; // đánh dấu ghế đã được đặt 
	cout << " dat ve thanh cong \n";
}
// menu khi đặt vé 
// - quy định 
// - khởi tạo các biến dùng để xác định các loại vé : chọn , 
// 
// 

void menuBookTicker(string Ticker[ROWS][COLS]) {
	cout << "-----------------MENU-----------------\n";
    cout << "Chon hang ve ";
    cout << "1. Thuong gia 1-2 \n";
    cout << "2. pho thong 3-7 \n";
	cout << "3. tiet kiem 8-13 \n";
    int choice;
	int rowStart, rowEnd;
    string tickerBook = "";
    cout << "\n nhap lua chon cua ban ";
    cin >> choice;
    if (choice == 1) { tickerBook = "Thuong_gia"; rowStart = 1; rowEnd = 2; }
    else if(choice ==2) {tickerBook ="Pho_thong"; rowStart=3;rowEnd=7;}
    else if (choice == 3) { tickerBook = "Tiet_kiem"; rowStart = 8; rowEnd = 13; }
	else { cout << "Lua chon khong hop le \n"; return; }


    // in bảng danh sách ghế ngồi nè 
    outputTickerByClass(Ticker, rowStart, rowEnd);
	// đếm số ghế trống còn lại của hạng vé
	countEmptyTicker(Ticker, rowStart, rowEnd);
	// yêu cầu khách hàng nhập vào vị trí ghế muốn đặt
	cout << "Nhap vi tri ghe muon dat (vi du : 1A, 2B, ...): ";
	string input;
	cin >> input;
	int row, col;
	if (!pareseInput(input, row, col)) { // truyền tham chiếu của row và col rồi nên hàm book dùng được row và col sau xử lý 
		cout << "Nhap sai dinh dang, vui long thu lai.\n";
		return;
	}
	// đặt vé 
	bookTIcker(Ticker, row, col);



}


int main() {
    string Ticker[ROWS][COLS] = {
        {"*","*","*","*","*","*"},  // hang 1  - thuong gia
        {"*","X","*","*","*","*"},  // hang 2  - thuong gia
        {"*","*","*","*","*","*"},  // hang 3  - pho thong
        {"*","*","X","*","*","*"},  // hang 4  - pho thong
        {"*","*","*","*","*","*"},  // hang 5  - pho thong
        {"*","*","*","X","*","*"},  // hang 6  - pho thong
        {"*","*","*","*","*","*"},  // hang 7  - pho thong
        {"*","*","*","*","*","*"},  // hang 8  - tiet kiem
        {"*","X","*","*","*","*"},  // hang 9  - tiet kiem
        {"*","*","*","*","*","*"},  // hang 10 - tiet kiem
        {"*","*","*","*","X","*"},  // hang 11 - tiet kiem
        {"*","*","*","*","*","*"},  // hang 12 - tiet kiem
        {"*","*","*","*","*","*"},  // hang 13 - tiet kiem
    };
    menuBookTicker(Ticker);
}