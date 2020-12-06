#include <bits/stdc++.h>
using namespace std;
 
const int Row = 3;
const int Column = 5;
 

bool issafe(int i, int j)
{
    if (i >= 0 && i < Row && j >= 0 && j < Column)
        return true;
    return false;
}
 
int rottenoranges(int v[Row][Column])
{
    bool t = false;
    int vi = 2;
    while (true) {
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Column; j++) {
 
                
                if (v[i][j] == vi) {
                    if (issafe(i + 1, j) && v[i + 1][j] == 1) {
                       t = true;
                    }
                    if (issafe(i, j + 1) && v[i][j + 1] == 1) {
                        v[i][j + 1] = v[i][j] + 1;
                        t = true;
                    }
                    if (issafe(i - 1, j) && v[i - 1][j] == 1) {
                        v[i - 1][j] = v[i][j] + 1;
                        t = true;
                    }
                    if (issafe(i, j - 1) && v[i][j - 1] == 1) {
                        v[i][j - 1] = v[i][j] + 1;
                        t = true;
                    }
                }
            }
        }
 
        
        if (!t)
            break;
        t = false;
        vi++;
    }
 
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Column; j++) {
 
            
            if (v[i][j] == 1)
                return -1;
        }
    }
 
    
    return vi - 2;
}
 

int main()
{
 
    int v[Row][Column] = { { 2, 1, 0, 2, 1 },
                    { 1, 0, 1, 2, 1 },
                    { 1, 0, 0, 2, 1 } };
 
    cout << "time frame:" << rottenoranges(v);
    int ones=0;
    int twos=0;
    for(int i=0;i<Row;i++)
    {   for(int j=0;j<Column;j++)
        {   if(v[i][j]==1)
                ones++;
            else if(v[i][j]==2)
                twos++;
        }
    }
    cout<<"\n fresh oranges:"<<ones;
    cout<<"\n rotten oranges:"<<twos;
 
    return 0;
}
 
