/*
В каждом столбце матрицы подсчитать кол-во нулей, отсортировать столбцы матрицы по убыванию этого кол-ва
*/


#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int cols, rows;
    cin >> rows;
    cin >> cols;
    
    int** a = new int* [rows];
    for (int i = 0; i < rows; i++) {
        a[i] = new int[cols];
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = rand() % 2;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "---------------------------------------" << endl;

    int n = 0, m = 0, b[10];
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (a[i][j] == 0) {
                n++;
            }
        }
        b[m] = n;
        m++;
        n = 0;
    }

    int p = 0, x = 0;
    for (int i = 0; i < m; i++) {
        for (int j = m - 1; j > i; j--) {
            if (b[j - 1] < b[j]) {
                x = b[j - 1];
                b[j - 1] = b[j];
                b[j] = x;
                  for (int i = 0; i < rows; i++) {
                        p = a[i][j - 1];
                        a[i][j - 1] = a[i][j];
                        a[i][j] = p;
                  }
                
            }
        }
    }


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < rows; i++) {
        delete[] a[i];
    }
    delete[] a;
}

