#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &v, int n, int &empty)
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
    cout << "No. of empty cells: " << empty << endl;
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
int main()
{
    int n = 4, i, j, empty;
    char move;
    empty = n * n;
    srand(time(0));
    vector<vector<int>> v(n, vector<int>(n, 0));
    printMatrix(v, n, empty);
    addTile(v, n, empty);
    addTile(v, n, empty);
    printMatrix(v, n, empty);
    while (empty != 0)
    {
        cout << "Enter move: (u: UP, d: DOWN, l: LEFT, r: RIGHT)" << endl;
        cin >> move;
        switch (move)
        {
        case 'u':
            moveUp(v, n);
            break;
        case 'd':
            //Move Down Code
            break;
        case 'l':
            moveLeft(v, n);
            break;
        case 'r':
            moveRight(v, n);
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
