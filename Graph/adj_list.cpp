#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;

   vector<pair<int,int>>  matrix[n] = {};

//    matrix [0] = {{1,2}};
//    matrix [1] = {{2,4}};
//    matrix [2] = {};
//    matrix [3] = {{1,7},{2,8}};

     
  matrix[0].push_back({1,2});
  matrix[1].push_back({2,4});
  matrix[3].push_back({1,7});
  matrix[3].push_back({2,8});

//  for(auto mat : matrix)
//    {
//     cout << i << " -> ";
//         for(auto i : mat)
//         {
//             cout <<"("<< i.first<< " "<< i.second << ")" << " "; 
          
//         }
//         i++;
//         cout << endl;
//    }

    for (int i=0;i<n;i++)
    {
        cout << i << " -> ";

        for(int j = 0;j<matrix[i].size() ;j++)
        {
            cout << matrix[i][j].first << " " << matrix[i][j].second << " ";
        }
        cout << endl;
    }
  


    return 0;
}



/*

 0------1
      /   \
      2---3

 0 -> 1
 1 -> 2,3
 2 -> 1,2,3
 3 -> 1,2




*/