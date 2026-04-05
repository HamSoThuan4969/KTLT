#include <iostream> 
#include <windows.h> // WinApi header 
using namespace std;



int main()
{
    int playSound[][2] = {
        {392, 500},   // Sol
        {392, 500},   // Sol
        {440, 1000},  // La
        {392, 1000},  // Sol
        {522, 1000},  // Đô (C5)
        {493, 2000},  // Si
        {392, 500},   // Sol
        {392, 500},   // Sol
        {440, 1000},  // La
        {392, 1000},  // Sol
        {586, 1000},  // Rê (D5)
        {522, 2000},  // Đô (C5)
    };
    // đếm số lượng note trong bài hát
    int numberNote = sizeof(playSound) / sizeof(playSound[0]);
    // chạy nhạc 
    for (int i = 0; i < numberNote; i++) {
		Beep(playSound[i][0], playSound[i][1]); // hàm hệ thống
    }
    return 0;

}