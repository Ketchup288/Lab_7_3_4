#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

//void Create(int** a, const int rowCount, const int colCount,
//    const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Smtd_Matrix(int** a, int** b, const int rowCount, const int colCount, int rowNo, int colNo);
void Check_Matrix(int** a, int** b, const int rowCount, const int colCount, int rowNo, int colNo);
void InputRow(int** a, const int rowNo, const int colCount, int colNo);
void InputRows(int** a, const int rowCount, const int colCount, int rowNo);
int Sum_Mtrx(int** b, const int rowCount, const int colCount, int& sum, int rowNo, int colNo);
void Find_Mtrx(int** b, const int rowCount, const int colCount, int& sum, int rowNo, int colNo);


int main()
{
    /*
    srand((unsigned)time(NULL));
    int Low = -100;
    int High = -1;
    */
    int n;
    cout << "n = "; cin >> n;
    int rowCount = n, colCount = n; // Матриця n x n


    int** a = new int* [rowCount];
    for (int rowNo = 0; rowNo < rowCount; rowNo++)
        a[rowNo] = new int[colCount];

    //Create(a, rowCount, colCount, Low, High, 0, 0);
    InputRows(a, rowCount, colCount, 0);
    Print(a, rowCount, colCount, 0, 0);


    int** b = new int* [rowCount];
    for (int rowNo = 0; rowNo < rowCount; rowNo++)
        b[rowNo] = new int[colCount];

    Smtd_Matrix(a, b, rowCount, colCount, 0, 0);
    Print(b, rowCount, colCount, 0, 0);

    int sum = 0;

    int summing = Sum_Mtrx(b, rowCount, colCount, sum, 1, 0);

    cout << "sum (modul) = " << sum << endl;

    for (int rowNo = 0; rowNo < rowCount; rowNo++)
        delete[] a[rowNo];
    delete[] a;

    for (int rowNo = 0; rowNo < rowCount; rowNo++)
        delete[] b[rowNo];
    delete[] b;

    return 0;
}

void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << "a[" << rowNo << "][" << colNo << "] = ";
    cin >> a[rowNo][colNo];
    if (colNo < colCount - 1)
        InputRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}


void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    InputRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        InputRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}


/*void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1)
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else
        if (i < rowCount - 1)
            Create(a, rowCount, colCount, Low, High, i + 1, 0);
}
*/

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << a[i][j];
    if (j < colCount - 1)
        Print(a, rowCount, colCount, i, j + 1);
    else
        if (i < rowCount - 1)
        {
            cout << endl;
            Print(a, rowCount, colCount, i + 1, 0);
        }
        else
            cout << endl << endl;
}



void Smtd_Matrix(int** a, int** b, const int rowCount, const int colCount, int rowNo, int colNo) {
    if (rowNo < rowCount) {
        Check_Matrix(a, b, rowCount, colCount, rowNo, colNo);
        Smtd_Matrix(a, b, rowCount, colCount, rowNo + 1, colNo);
    }
}




void Check_Matrix(int** a, int** b, const int rowCount, const int colCount, int rowNo, int colNo)
{
    int tmp = a[rowNo][colNo]; int col = 1; // добавляє до розрахунків сам елемент
    if (rowNo > 0)  // далі поетапна перевірка кожної з позицій навколо елемента
    {
        tmp += a[rowNo - 1][colNo];
        col++;
        if (colNo > 0)
        {
            tmp += a[rowNo - 1][colNo - 1];
            col++;
        }
        if (colNo < colCount - 1)
        {
            tmp += a[rowNo - 1][colNo + 1];
            col++;
        }
    }
    if (rowNo < rowCount - 1)
    {
        tmp += a[rowNo + 1][colNo];
        col++;
        if (colNo > 0)
        {
            tmp += a[rowNo + 1][colNo - 1];
            col++;
        }
        if (colNo < colCount - 1)
        {
            tmp += a[rowNo + 1][colNo + 1];
            col++;
        }
    }
    if (colNo > 0)
    {
        tmp += a[rowNo][colNo - 1];
        col++;
    }
    if (colNo < colCount - 1)
    {
        tmp += a[rowNo][colNo + 1];
        col++;
    }

    b[rowNo][colNo] = tmp / col;

    if (colNo < colCount - 1)
        Check_Matrix(a, b, rowCount, colCount, rowNo, colNo + 1);
}

int Sum_Mtrx(int** b, const int rowCount, const int colCount, int& sum, int rowNo, int colNo) {
    if (rowNo < rowCount) {
        Find_Mtrx(b, rowCount, colCount, sum, rowNo, colNo);
        return Sum_Mtrx(b, rowCount, colCount, sum, rowNo + 1, colNo);
    }
    else {
        return sum;
    }
}

void Find_Mtrx(int** b, const int rowCount, const int colCount, int& sum, int rowNo, int colNo) {
    if (colNo < rowNo)
        sum += abs(b[rowNo][colNo]);
    if (colNo < colCount - 1) {
        Find_Mtrx(b, rowCount, colCount, sum, rowNo, colNo + 1);
    }
}