#include <iostream>
#include <windows.h>
#include <conio.h>

int main() {
    HDC hDC = GetDC(GetConsoleWindow());
    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hDC, Pen);

    MoveToEx(hDC, 0, 170, NULL);
    LineTo(hDC, 400, 170);
    MoveToEx(hDC, 200, 0, NULL);
    LineTo(hDC, 200, 340);

    for (double x = -10; x <= 10; x += 0.0001) {
        MoveToEx(hDC, 20 * x + 200, -20 * (cos(x)) + 170, NULL);
        LineTo(hDC, 20 * x + 200, -20 * (cos(x)) + 170);
    }
    _getch();
}
