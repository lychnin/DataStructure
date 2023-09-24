// 压缩矩阵
// 大坑:数据类型的转换,整型之间进行计算得到的还是整型,如果涉及小数则需使用浮点数
#include <iostream>
using namespace std;
// 上三角矩阵type为0
// 下三角矩阵type为1
int **KeyMatrix(int &row, int &column, int &type)
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
    cout << "type:";
    cin >> type;
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
// 还需传入矩阵类型,为上三角矩阵还是下三角矩阵
int *storage(int **matrix, int row, int column, int type)
{
    int *original;
    original = new int[row * column];
    int RowIndex = 0;
    int ColumnIndex = 0;
    int index = 1;
    if (type == 1)
    {
        while (RowIndex < row)
        {
            while (ColumnIndex <= RowIndex)
            {
                original[index] = matrix[RowIndex][ColumnIndex];
                // cout << original[index] << ",";
                index++;
                ColumnIndex++;
            }
            // cout << "\n";
            RowIndex++;
            ColumnIndex = 0;
        }
        // 对于上三角矩阵,只需将最后一个元素存入即可
        original[0] = matrix[row - 2][column - 1];
    }
    if (type == 0)
    {
        ColumnIndex = column - 1;
        while (RowIndex < row)
        {
            while (ColumnIndex >= RowIndex)
            {
                original[index] = matrix[RowIndex][ColumnIndex];
                //  cout << original[index] << ",";
                index++;
                ColumnIndex--;
            }
            // cout << '\n';
            RowIndex++;
            ColumnIndex = column - 1;
        }
        cout << "\n";
        // 对于下三角矩阵,只需将最后一行的第一个元素存入即可
        original[0] = matrix[row - 1][0];
    }
    return original;
}

// 这里的RowIndex和ColumnIndex都从1开始
void SearchElem(int row, int column, int RowIndex, int ColumnIndex, int *original, int type)
{
    int start;
    int end;
    int loc;
    int temp;
    // 如果为下三角矩阵
    if (type == 1)
    {
        if (RowIndex >= ColumnIndex)
        {
            // 这里的start和end表示逻辑位序,意为RowIndex位序的元素可以取到数组中第start+1个位置到第end个位置
            start = (RowIndex - 1) / 2.0 * (1 + RowIndex - 1) + 1;
            end = RowIndex / 2.0 * (1 + RowIndex);
            // 在这一行中,如果为1就是start,如果为n就是start+n-1
            loc = start + ColumnIndex - 1;
            cout << "[" << RowIndex << "]"
                 << "[" << ColumnIndex << "]" << original[loc] << ",";
        }
        else
        {
            cout << "[" << ColumnIndex << "]"
                 << "[" << RowIndex << "]" << original[0] << ",";
        }
    }
    // 如果为上三角矩阵
    if (type == 0)
    {
        if (RowIndex <= ColumnIndex)
        {
            start = (column + column - (RowIndex - 1)) * ((RowIndex - 1) + 1) / 2.0;
            end = (column + column - RowIndex) * (RowIndex + 1) / 2.0;
            start = start + 1;
            loc = start + ColumnIndex - 1 - RowIndex;
            cout << "[" << RowIndex << "]"
                 << "[" << ColumnIndex << "]" << original[loc - 1] << ",";
        }
        else
        {
            cout << "[" << ColumnIndex << "]"
                 << "[" << RowIndex << "]" << original[0] << ",";
        }
    }
}

void PrintMatrix(int original[], int row, int column, int type)
{
    cout << "matrix:" << endl;
    int RowIndex = 1;
    int ColumnIndex = 1;
    while (RowIndex <= row)
    {
        while (ColumnIndex <= column)
        {
            // 传入的是逻辑位序
            SearchElem(row, column, RowIndex, ColumnIndex, original, type);
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
    int type = -1;
    // 声明一个二级指针,用于当作二维数组使用
    matrix = KeyMatrix(row, column, type);
    original = storage(matrix, row, column, type);
    //    SearchElem(1, 2, original);
    //    SearchElem(2, 1, original);
    PrintMatrix(original, row, column, type);
}