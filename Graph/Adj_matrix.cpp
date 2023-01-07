#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes = 4;

    int matrix[nodes][nodes] = {};

    // memset(matrix,0,sizeof(matrix));

       for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            matrix[i][j] = 1;
        }
        
    }



    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
// T.C -> O(n^2)
// S.c -> O(n^2)