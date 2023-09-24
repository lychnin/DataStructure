// 压缩矩阵
// 大坑:数据类型的转换,整型之间进行计算得到的还是整型,如果涉及小数则需使用浮点数
#include <iostream>
using namespace std;
// 对称矩阵
// 将对称矩阵按一维数组存储
int *storage(int **matrix, int row, int column)
{
    int *original;
    original = new int[row * column];
    int RowIndex = 0;
    int ColumnIndex = 0;
    int index = 0;
    while (RowIndex < row)
    {
        while (ColumnIndex <= RowIndex)
        {
            original[index] = matrix[RowIndex][ColumnIndex];
            cout << original[index] << ",";
            index++;
            ColumnIndex++;
        }
        RowIndex++;
        ColumnIndex = 0;
    }
    cout << "\n";
    for (index = 0; index < (row / 2.0 * (1 + row)); index++)
    {
        cout << original[index] << ",";
    }
    return original;
}
int **KeyMatrix(int &row, int &column)
{
    int index = 0;
    int **matrix;
    matrix = new int *[15];
    for (index = 0; index < 15; ++index)
    {
        matrix[index] = new int[10];
    }
    cout << "Enter rows and columns " << endl;
    cout << "Rows:";
    cin >> row;
    cout << "Columns:";
    cin >> column;
    int data = 0;
    int RowIndex = 0;
    int ColumnIndex = 0;
    while (RowIndex < row)
    {
        while (ColumnIndex < column)
        {
            cout << "Matrix[" << RowIndex + 1 << "]"
                 << "[" << ColumnIndex + 1 << "]:";
            cin >> matrix[RowIndex][ColumnIndex];
            ColumnIndex++;
        }
        RowIndex++;
        ColumnIndex = 0;
    }
    return matrix;
}
// 这里的RowIndex和ColumnIndex都从1开始
void SearchElem(int RowIndex, int ColumnIndex, int *original)
{
    int start;
    int end;
    int loc;
    int temp;
    if (RowIndex >= ColumnIndex)
    {
        // 这里的start和end表示逻辑位序,意为RowIndex位序的元素可以取到数组中第start+1个位置到第end个位置
        start = (RowIndex - 1) / 2.0 * (1 + RowIndex - 1) + 1;
        end = RowIndex / 2.0 * (1 + RowIndex);
        // 在这一行中,如果为1就是start,如果为n就是start+n-1
        loc = start + ColumnIndex - 1;
        cout << "[" << RowIndex << "]"
             << "[" << ColumnIndex << "]" << original[loc - 1] << ",";
    }
    else
    {
        temp = RowIndex;
        RowIndex = ColumnIndex;
        ColumnIndex = temp;
        // 这里的start和end表示逻辑位序,意为RowIndex位序的元素可以取到数组中第start+1个位置到第end个位置
        start = (RowIndex - 1) / 2.0 * (1 + RowIndex - 1) + 1;
        end = RowIndex / 2.0 * (1 + RowIndex);
        // 在这一行中,如果为1就是start,如果为n就是start+n-1
        loc = start - 1 + ColumnIndex;
        cout << "[" << ColumnIndex << "]"
             << "[" << RowIndex << "]" << original[loc - 1] << ",";
    }
}

void PrintMatrix(int original[], int row, int column)
{
    cout << "matrix:" << endl;
    int RowIndex = 1;
    int ColumnIndex = 1;
    while (RowIndex <= row)
    {
        while (ColumnIndex <= column)
        {
            // 传入的是逻辑位序
            SearchElem(RowIndex, ColumnIndex, original);
            ColumnIndex++;
        }
        cout << "\n";
        RowIndex++;
        ColumnIndex = 1;
    }
}
int main()
{
    int row;
    int column;
    int **matrix;
    int *original;
    int index = 0;
    int index2 = 0;
    // 声明一个二级指针,用于当作二维数组使用
    matrix = KeyMatrix(row, column);
    original = storage(matrix, row, column);
    //    SearchElem(1, 2, original);
    //    SearchElem(2, 1, original);
    PrintMatrix(original, row, column);
}