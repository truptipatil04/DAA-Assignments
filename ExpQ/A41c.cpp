#include <bits/stdc++.h>
#include <cmath>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

int nextPowerOf2(int k)
{
    return pow(2, int(ceil(log2(k))));
}

void display(vii C, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        cout << ""
             << " ";
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << "" << endl;
    }
}

void add(vii &A, vii &B, vii &C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void sub(vii &A, vii &B, vii &C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void Strassen_algorithm(vii &A, vii &B, vii &C, int size)
{
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int newSize = size / 2;
        vi z(newSize);
        vii a(newSize, z), b(newSize, z), c(newSize, z), d(newSize, z),
            e(newSize, z), f(newSize, z), g(newSize, z), h(newSize, z),
            c11(newSize, z), c12(newSize, z), c21(newSize, z), c22(newSize, z),
            p1(newSize, z), p2(newSize, z), p3(newSize, z), p4(newSize, z),
            p5(newSize, z), p6(newSize, z), p7(newSize, z), fResult(newSize, z),
            sResult(newSize, z);
        int i, j;

        for (i = 0; i < newSize; i++)
        {
            for (j = 0; j < newSize; j++)
            {
                a[i][j] = A[i][j];
                b[i][j] = A[i][j + newSize];
                c[i][j] = A[i + newSize][j];
                d[i][j] = A[i + newSize][j + newSize];

                e[i][j] = B[i][j];
                f[i][j] = B[i][j + newSize];
                g[i][j] = B[i + newSize][j];
                h[i][j] = B[i + newSize][j + newSize];
            }
        }

        sub(f, h, sResult, newSize);
        Strassen_algorithm(a, sResult, p1, newSize);

        add(a, b, fResult, newSize);
        Strassen_algorithm(fResult, h, p2, newSize);

        add(c, d, fResult, newSize);
        Strassen_algorithm(fResult, e, p3, newSize);

        sub(g, e, sResult, newSize);
        Strassen_algorithm(d, sResult, p4, newSize);

        add(a, d, fResult, newSize);
        add(e, h, sResult, newSize);
        Strassen_algorithm(fResult, sResult, p5, newSize);

        sub(b, d, fResult, newSize);
        add(g, h, sResult, newSize);
        Strassen_algorithm(fResult, sResult, p6, newSize);

        sub(a, c, fResult, newSize);
        add(e, f, sResult, newSize);
        Strassen_algorithm(fResult, sResult, p7, newSize);

        add(p1, p2, c12, newSize);
        add(p3, p4, c21, newSize);

        add(p4, p5, fResult, newSize);
        add(fResult, p6, sResult, newSize);
        sub(sResult, p2, c11, newSize);

        sub(p1, p3, fResult, newSize);
        add(fResult, p5, sResult, newSize);
        sub(sResult, p7, c22, newSize);

        for (i = 0; i < newSize; i++)
        {
            for (j = 0; j < newSize; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + newSize] = c12[i][j];
                C[i + newSize][j] = c21[i][j];
                C[i + newSize][j + newSize] = c22[i][j];
            }
        }
    }
}

void ConvertToSquareMat(vii &A, vii &B, int r1, int c1, int r2, int c2)
{
    int maxSize = max({r1, c1, r2, c2});
    int size = nextPowerOf2(maxSize);

    vi z(size);
    vii Aa(size, z), Bb(size, z), Cc(size, z);

    for (unsigned int i = 0; i < r1; i++)
    {
        for (unsigned int j = 0; j < c1; j++)
        {
            Aa[i][j] = A[i][j];
        }
    }
    for (unsigned int i = 0; i < r2; i++)
    {
        for (unsigned int j = 0; j < c2; j++)
        {
            Bb[i][j] = B[i][j];
        }
    }
    Strassen_algorithm(Aa, Bb, Cc, size);
    vi temp1(c2);
    vii C(r1, temp1);
    for (unsigned int i = 0; i < r1; i++)
    {
        for (unsigned int j = 0; j < c2; j++)
        {
            C[i][j] = Cc[i][j];
        }
    }
    display(C, r1, c1);
}
int main()
{
    vii a = {{2, 5, 1, 3},
             {1, 4, 2, 3},
             {4, 1, 3, 1},
             {2, 2, 1, 1}};

    vii b = {{1, 1, 4, 2},
             {1, 3, 5, 2},
             {2, 3, 1, 1},
             {3, 2, 1, 4}};

    ConvertToSquareMat(a, b, 4, 4, 4, 4);
    return 0;
}
