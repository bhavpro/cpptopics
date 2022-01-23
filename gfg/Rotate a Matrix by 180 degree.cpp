#include <iostream>

using namespace std;

const int N = 4;
void rotateMatrix(int mat[N][N])
{
    for (int i = 0; i < (N >> 1); i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = temp;
        }
    }

    if (N & 1)
    {
        for (int i = 0; i < (N >> 1); i++)
        {
            int temp = mat[N >> 1][i];
            mat[N >> 1][i] = mat[N >> 1][N - 1 - i];
            mat[N >> 1][N - 1 - i] = temp;
        }
    }
}

int main()
{
    int mat[N][N] = {
        {
            1,
            2,
            3,
            4,
        },
        {
            6,
            7,
            8,
            9,
        },
        {11, 12, 13, 14},
        {16, 17, 18, 19},
    };
    rotateMatrix(mat);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
