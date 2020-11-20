#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &v, int n, int &empty)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 0)
            {
                cout << "* ";
                continue;
            }
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // cout << "No. of empty cells: " << empty << endl;
}
void addTile(vector<vector<int>> &v, int n, int &empty)
{
    int i, j;
    do
    {
        i = rand() % n;
        j = rand() % n;
    } while (v[i][j] != 0);
    v[i][j] = 2;
    empty--;
}
void moveUp(vector<vector<int>> &v, int n)
{
    for (int j = 0; j < n; j++)
    {
        int currPos = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i][j] != 0)
            {
                v[currPos][j] = v[i][j];
                currPos++;
            }
        }
        for (int i = currPos; i < n; i++)
        {
            v[i][j] = 0;
        }
    }
}
void moveDown(vector<vector<int>> &v, int n)
{
    for (int j = 0; j < n; j++)
    {
        int currPos = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i][j] != 0)
            {
                v[currPos][j] = v[i][j];
                currPos--;
            }
        }
        for (int i = 0; i <= currPos; i++)
        {
            v[i][j] = 0;
        }
    }
}
void moveLeft(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int currPos = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] != 0)
            {
                v[i][currPos] = v[i][j];
                currPos++;
            }
        }
        for (int j = currPos; j < n; j++)
        {
            v[i][j] = 0;
        }
    }
}
void moveRight(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int currPos = n - 1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (v[i][j] != 0)
            {
                v[i][currPos] = v[i][j];
                currPos--;
            }
        }
        for (int j = 0; j <= currPos; j++)
        {
            v[i][j] = 0;
        }
    }
}

void mergeUp(vector<vector<int>> &v, int n, int &empty)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i][j] != 0 && v[i][j] == v[i + 1][j])
            {
                v[i][j] *= 2;
                for (int k = i + 1; k < n - 1; k++)
                {
                    v[k][j] = v[k + 1][j];
                }
                v[n - 1][j] = 0;
                empty++;
            }
        }
    }
}
void mergeDown(vector<vector<int>> &v, int n, int &empty)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (v[i][j] != 0 && v[i][j] == v[i - 1][j])
            {
                v[i][j] *= 2;
                for (int k = i - 1; k > 0; k--)
                {
                    v[k][j] = v[k - 1][j];
                }
                v[0][j] = 0;
                empty++;
            }
        }
    }
}

void mergeLeft(vector<vector<int>> &v, int n, int &empty)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (v[i][j] != 0 && v[i][j] == v[i][j + 1])
            {
                v[i][j] *= 2;
                for (int k = j + 1; k < n - 1; k++)
                {
                    v[i][k] = v[i][k + 1];
                }
                v[i][n - 1] = 0;
                empty++;
            }
        }
    }
}
void mergeRight(vector<vector<int>> &v, int n, int &empty)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (v[i][j] != 0 && v[i][j] == v[i][j - 1])
            {
                v[i][j] *= 2;
                for (int k = j - 1; k > 0; k--)
                {
                    v[i][k] = v[i][k - 1];
                }
                v[i][0] = 0;
                empty++;
            }
        }
    }
}
int main()
{
    int n = 4, i, j, empty;
    char move;
    empty = n * n;
    srand(time(0));
    vector<vector<int>> v(n, vector<int>(n, 0));
    cout << "Welcome to the 2048 Game!\n"
         << endl;
    addTile(v, n, empty);
    addTile(v, n, empty);
    printMatrix(v, n, empty);
    while (empty != 0)
    {
        cout << "Enter move: (u: UP, d: DOWN, l: LEFT, r: RIGHT)" << endl;
        cin >> move;
        cout << endl;
        switch (move)
        {
        case 'u':
            moveUp(v, n);
            mergeUp(v, n, empty);
            break;
        case 'd':
            moveDown(v, n);
            mergeDown(v, n, empty);
            break;
        case 'l':
            moveLeft(v, n);
            mergeLeft(v, n, empty);
            break;
        case 'r':
            moveRight(v, n);
            mergeRight(v, n, empty);
            break;
        default:
            cout << "Invalid move. Try again!" << endl;
            continue;
        }
        addTile(v, n, empty);
        printMatrix(v, n, empty);
    }
    cout << "Game over" << endl;
    return 0;
}