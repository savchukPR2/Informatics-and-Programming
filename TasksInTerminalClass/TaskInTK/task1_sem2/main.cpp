#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <conio.h>
#include <Windows.h>

#define KEY_ESC 27


void getConsoleFontSize(int num) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX fontInfo;

    fontInfo.cbSize = sizeof(fontInfo);

    GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);

    wcscpy(fontInfo.FaceName, L"Lucida Console");

    fontInfo.dwFontSize.Y = (int)num;
    SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);

}

void getConsoleFontColor(char* str) {

    char* color = str;
    int k;

    /*for (int i = 0; i < strlen(color); i++) {
        if (color[i] > 64 && color[i] < 71) {
            k = (int)(color[i] - 55);
        }
        if (color[i] > 47 && color[i] < 58) {
            k = (int)(color[i] - 48);
        }
    }*/

    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);


 
}

 

int main()
{
    int num;
    int userWish;
    char* backFontColor;

    while (true) {


        std::cout << std::endl << "1 - Font Size in Console. Deafault Font Size = 12; " << std::endl << "2 - Font Color and console Color in Console; " << std::endl << "3 - Exit; " << std::endl << std::endl;
        std::cin >> userWish;

        switch (userWish)
        {
        case 1:
            do {
                std::cout << "Enter Font Size: " << std::endl << "For Example: 19" << std::endl << "Your choice: ";
                std::cin >> num;

                std::cout << std::endl << "If you want to choose something else: PRESS ESC" << std::endl << std::endl;

                getConsoleFontSize(num);

            } while (_getch() != KEY_ESC);
            break;
        case 2:
            do {

                std::cout << "Enter Font Color and Console Color in (00) Format. " << std::endl << "First number - background color, second - Font Color" << std::endl << "For Example: 0F - White" << std::endl;

                std::cout << "All colors: " << std::endl << "0 - Black" << std::endl << "1 - Blue" << std::endl << "2 - Green" << std::endl << "3 - Sky Blue" << std::endl << "4 - Red" << std::endl << "5 - Puple" << std::endl << "6 - Brown" << std::endl << "7 - Light Grey" << std::endl << "8 - Dark Grey" << std::endl << "9 - Light Blue" << std::endl << "A - Light Green" << std::endl << "B - Light Light Blue" << std::endl << "C - Light Red" << std::endl << "D - Light Purple" << std::endl << "E - Yellow" << std::endl << "F - White" << std::endl;
                std::cin >> backFontColor;

                getConsoleFontColor(backFontColor);

            } while (_getch() != KEY_ESC);

            break;
        case 3:
            break;
        }

        if (userWish == 4)
            break;
    }

    return 0;
}