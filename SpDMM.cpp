#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <sstream>
using namespace std;

typedef vector<vector<long> > Matrix;
typedef vector<long> Vector;


Matrix multiplyMatrix(Vector M1_value, Vector M1_Col_Index, Vector M1_Row_Ptr , Matrix M2, long M1_col, long M1_row)
{  
    Matrix matrixMUL;
    long M2_row = (long)M2.size();
    long M2_col = (long)M2[0].size();

    // to check if the multiply is allowed
    if (M1_col != M2_row)
        {   cout << "multiply is not allowed";
        }   
        
    else
    {   
    for ( int k = 0 ; k < M2_col; k++){
        Vector Mul_temp;
    for ( int i =0 ; i < M1_row;i++){
        int sum = 0;
        for (int j = M1_Row_Ptr[i]; j < M1_Row_Ptr[i+1]; j++ ){
            sum = sum +  ((M1_value[j]) * M2[M1_Col_Index[j]][k]);         
        }
        Mul_temp.push_back(sum);
        
    } matrixMUL.push_back(Mul_temp);
     }
}
return matrixMUL;
}


int main()
{   
    /* mutliply 0 1 0 0 0 0   1 2
                0 1 0 1 0 0   1 2
                0 0 1 1 1 1   1 2 
                0 0 0 0 0 1   1 2
                              1 2
                              1 2   */

    Vector M1_value = {1, 1, 1, 1, 1, 1, 1, 1};
    Vector M1_Col_Index = {1, 1, 3, 2, 3, 4, 5, 5};
    Vector M1_Row_Ptr = {0, 1, 3, 7, 8};
    Matrix M2 = {{1,2}, {1 ,2}, {1,2}, {1,2}, {1,2}, {1,2}};
    long M1_row = 4;
    long M1_col = 6;

    Matrix M1MultM2 = multiplyMatrix(M1_value,M1_Col_Index,M1_Row_Ptr,M2,M1_col,M1_row);
    int m = M1MultM2.size();
    int n = M1MultM2[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << M1MultM2[i][j] << " ";       
    cout << endl;}

return 0;

}