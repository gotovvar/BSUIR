#include <cmath>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int rows, cols, i, j;
	cin >> rows;
	cin >> cols;
	int** a = new int* [rows];
	for (i = 0; i < rows; i++) {
		a[i] = new int[cols];
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			a[i][j] = rand() % 20;
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	int max, imax = 0;
	max = a[0][0];
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (max < a[i][j]) {
				max = a[i][j];
				imax = i;
			}
		}
	}



	int min, imin = 0;
	min = a[0][0];
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (min > a[i][j]) {
				min = a[i][j];
			    imin = i;
				
			}
		}
	}
       
	cout << "////////////////////////" << endl;
		
		for (j = 0; j < rows; j++) {
			int temp = a[imin][j];
			a[imin][j]= a[imax][j];
			a[imax][j] = temp;
		}

		

		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				cout << a[i][j] << "\t";
			}
			cout << endl;
		}
		
		for (int i = 0; i < rows; i++) {
			delete[] a[i];
		}

		delete[] a;
	
}