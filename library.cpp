#include "library.h"
#define Nmax 100
#define CRT_SECURE_NO_WARNINGS
using namespace std;

int n;

struct Array
{
	int a[Nmax][Nmax];
} arr;

void Input_0()
{
	do
	{
		cout << "¬ведите размерность квадрата от 3 до 5: ";
		cin >> n;
	} while ((n > 5) || (n < 3));
}

void Input()
{
	do
	{
		cout << "¬ведите размерность квадрата: ";
		cin >> n;
	} while (n < 3);

	cout << "¬ведите элементы квадрата: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> arr.a[i][j];
		}
	}
}

void Choice_N()
{
	int numbers = n * n;
	if (n % 2 == 1)
	{
		int i = 0, j = n / 2;

		for (int k = 1; k <= numbers; ++k)
		{
			arr.a[i][j] = k;
			i--;
			j++;
			if (k % n == 0)
			{
				i += 2;
				--j;
			}
			else
			{
				if (j == n) { j -= n; }
				if (i < 0) { i += n; }
			}
		}
	}
	else {
		for (int k = 1, i = 0, j = 0; k <= numbers; k++)
		{
			arr.a[i][j] = k;
			j++;
			if (j > n - 1) { i++; j -= n; }
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (i % 4 == 0 && j % 4 == 0)
					for (int k = 0; k < 4; k++) { arr.a[i + k][j + k] = (numbers + 1) - arr.a[i + k][j + k]; }
				if (i % 4 == 3 && j % 4 == 0)
					for (int k = 0; k < 4; k++) { arr.a[i - k][j + k] = (numbers + 1) - arr.a[i - k][j + k]; }
			}
	}
}

void Check_Summ()
{
	int flag;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr.a[i][j] < 0) { flag = 0; break; }
			if ((arr.a[i][j] == arr.a[i + 1][j]) || (arr.a[i][j] == arr.a[i][j + 1]))
			{
				flag = 0;
				break;
			}
			else {
				flag = 1;
			}
		}
	}

	int summ_row = 0, summ_row_0 = 0, summ_col = 0, summ_col_0 = 0, summ_d_main = 0, summ_d_side = 0;
	for (int j = 0; j < n; j++)
	{
		summ_row_0 += arr.a[0][j];
	}
	int k = 1;
	while (k < n)
	{
		for (int j = 0; j < n; j++)
		{
			summ_row += arr.a[k][j];
		}
		if (summ_row_0 == summ_row) {
			k++;
			summ_row = 0;
		}
		else { summ_row_0 = -1; break; }
	}

	for (int i = 0; i < n; i++)
	{
		summ_col_0 += arr.a[i][0];
	}
	int l = 1;
	while (l < n)
	{
		for (int i = 0; i < n; i++)
		{
			summ_col += arr.a[i][l];
		}
		if (summ_col_0 == summ_col) {
			l++;
			summ_col = 0;
		}
		else { summ_col_0 = -1; break; }
	}

	for (int i = 0; i < n; i++)
	{
		summ_d_main += arr.a[i][i];
		for (int j = 0; j < n; j++)
		{
			summ_d_side += arr.a[i][n + j - 1];
		}
	}

	if ((flag == 1) && (summ_row_0 == summ_col_0) && (summ_row_0 == summ_d_main) && (summ_row_0 == summ_d_side) && (summ_col_0 == summ_d_main) && (summ_col_0 == summ_d_side) && (summ_d_main == summ_d_side)) { cout << " вадрат €вл€етс€ магическим." << endl; }
	else { cout << " вадрат не €вл€етс€ магическим." << endl; }
}

void File()
{
	ifstream file("Square.txt");
	if (!file.is_open())
	{
		cout << "ќшибка открыти€ файла" << endl;
		return;
	}
	file >> n >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			file >> arr.a[i][j];
		}
	}
}

void InFile()
{
	ofstream file("Magic_Square.txt");
	if (!file.is_open())
	{
		cout << "ќшибка открыти€ файла" << endl;
		return;
	}
	file << n << " " << n << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			file << arr.a[i][j] << "\t";
		}
		file << endl;
	}
}

void Output()
{
	cout << " вадрат: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr.a[i][j] << "\t";
		}
		cout << endl;
	}
}