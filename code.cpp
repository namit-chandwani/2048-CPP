#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void addTile(vector<vector<int>> &v, int n)
{
    int i, j;
    do
    {
        i = rand() % n;
        j = rand() % n;
    } while (v[i][j] != 0);
    v[i][j] = 2;
}

int main()
{
    int n = 4, i, j;
    vector<vector<int>> v(n, vector<int>(n, 0));
    srand(time(0));
    cout << "Welcome to the 2048 Game!" << endl;
    addTile(v, n);
    addTile(v, n);
    printMatrix(v, n);

    return 0;
}
