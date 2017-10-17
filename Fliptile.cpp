//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int mat[17][17], mat2[17][17], ans[16][16];

int po(int n)
{
    int a=1, i;
    for(i=0;i<n;i++)
        a*=2;
    return a;
}

int main()
{
    int m, n;
    int i, j, k;
    
    cin >> m >> n;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            cin >> mat[i][j];
    int power=po(n);
    
    for(i=0;i<power;i++){
        memset(ans, 0, sizeof(ans));
        int num=i;
        for(j=1;j<=m;j++)
            for(k=1;k<=n;k++)
                mat2[j][k]=mat[j][k];
        for(j=n;j>=1;j--){
            if(num%2)
                ans[1][j]=1, mat2[1][j]=1-mat2[1][j], mat2[2][j]=1-mat2[2][j], mat2[1][j-1]=1-mat2[1][j-1], mat2[1][j+1]=1-mat2[1][j+1];
            num/=2;
        }
        for(j=2;j<=m;j++)
            for(k=1;k<=n;k++)
                if(mat2[j-1][k]==1){
                    ans[j][k]=1;
                    mat2[j][k]=1-mat2[j][k], mat2[j-1][k]=1-mat2[j-1][k], mat2[j+1][k]=1-mat2[j+1][k], mat2[j][k-1]=1-mat2[j][k-1], mat2[j][k+1]=1-mat2[j][k+1];
                }
        bool good=true;
        for(j=1;j<=n;j++)
            if(mat2[m][j]==1)
                good=false;
        if(good){
            for(j=1;j<=m;j++){
                for(k=1;k<=n;k++)
                    cout << ans[j][k] << " ";
                cout << endl;
            }
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}
