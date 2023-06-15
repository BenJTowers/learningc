#include <stdio.h>
#include <math.h>

void set_vector(int n, double V[n], double s){
int i = 0;
while(i < n){
    V[i] = s;
 i++;    
}
}
void add_scalar_to_vector(int n, double Vin[n], double Vout[n], double s){
    int i = 0;
  while(i < n){
    Vout[i] = Vin[i] + s;
 i++;    
}
}
double dot_product(int n, double V1[n], double V2[n]){
  int i = 0;
  double x = 0;  
  while(i < n){
    x = x + V1[i]*V2[i];
      i++;    
}
    return x;
}
double norm(int n, double V[n]){
    int i = 0;
    double x = 0;
    double y = 0;
    while(i < n){
      x = x + V[i]*V[i];
       i++;   
    }
    y = sqrt(x);
        return y;
}
void add_vectors(int n, double V1[n], double V2[n], double Vout[n]){
   int i = 0;
    while(i < n){
      Vout[i] = V1[i] + V2[i];
       i++;   
    }
}
/* matrix time ooga booga */

void identity(int n, double M[n][n]){
    int i = 0;
    int j = 0;
    while( i < n && j < n){
        if(i == j){
    M[i][j]  = 1;
        }else{
            M[i][j]  = 0;
        }
        
        if(i < n){
            i ++;
        }
        if(i == (n)){
            i = 0;
            j ++;
        }
      
}
}
int matrices_equal(int rows, int cols, double A[rows][cols], double B[rows][cols]){
     int i = 0;
    int j = 0;
    while( i < rows && j < cols){
        if(A[i][j] != B[i][j]){
            return 0;
        }
        
        if(i < rows){
            i ++;
        }
        if(i == rows){
            i = 0;
            j ++;
        }
      
}
    return 1;
}
void add_matrices(int rows, int cols, double A[rows][cols], double B[rows][cols], double C[rows][cols]){
  int i = 0;
    int j = 0;
    while( i < rows && j < cols){
        C[i][j] = A[i][j] + B[i][j];
        if(i < rows){
            i ++;
        }
        if(i == rows){
            i = 0;
            j ++;
        }
      
}
}
double trace(int n, double A[n][n]){
    int i = 0;
    int j = 0;
    double x = 0;
    while( i < n && j < n){
        if(i == j){
       x = x + A[i][j];
        }
        if(i < n){
            i ++;
        }
        if(i == (n)){
            i = 0;
            j ++;
        }   
}
    return x;
}
void transpose(int n, int k, double A[n][k], double T[k][n]){
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    while( i < n && j < k && a < k && b < n){
        T[a][b] = A[i][j];
        if(b < n){
            b ++;
        }
        if(b == n){
            b = 0;
            a ++;
        }  
        if(i < n){
            i ++;
        }
        if(i == (n)){
            i = 0;
            j ++;
        }   
}
}
void omit_row(int n, int k, double A[n][k], double B[n-1][k], int omit_idx){
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    while( a < (n-1) && b < k){
         if(i == omit_idx){
            i++;
        }
       B[a][b] = A[i][j];
        if(b < k){
            b ++;
        }
        if(b == k){
            b = 0;
            a ++;
        }
        if(j < k){
            j ++;
        }
        if(j == k){
            j = 0;
            i ++;
        }
      
}
}
void omit_column(int n, int k, double A[n][k], double B[n][k-1], int omit_idx){
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    while( a < n && b < (k-1)){
         if(j == omit_idx){
            j++;
        }
       B[a][b] = A[i][j];
        if(a < n){
            a ++;
        }
        if(a == n){
            a = 0;
            b ++;
        }
        if(i < n){
            i ++;
        }
        if(i == n){
            i = 0;
            j ++;
        }
      
} 
}
void matrix_vector_multiply(int n, int k, double A[n][k], double V[k], double Vout[n]){
   int i = 0;
    int j = 0;
    int a = 0;
    double b = 0;
    int w = 0;
    while(i < n && j < k){
        while(a < k){
        b = b + A[i][j]*V[a];
        a++;
        j++;
        }
        Vout[w] = b;
        b = 0;
        a = 0;
        w++;
        if(j == k){
            j = 0;
            i ++;
        }  
} 
}
void matrix_multiply(int m, int n, int k, double A[m][n], double B[n][k], double C[m][k]){
    int i = 0;
    int j = 0;
    int a = 0;
    double b = 0;
    int w = 0;
    int c = 0;
    int e = 0;
    while(i < m && j < n){
        while(a < n){
        b = b + A[i][j]*B[a][c];
        a++;
        j++;
        }
        C[w][e] = b;
        b = 0;
        e++;
        if(e == k){
            e = 0;
            w ++;
        }  
        if(a == n){
            a = 0;
            c ++;
        }
        if(c == k){
            c = 0;
            i++;
        }
        if(j == n){
            j = 0;
        }  
}
}
void tile(int n, int k, double A[n][k], int s, int t, double B[s][t]){
     int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    while(i < n && j < k && a < s && b < t){
        B[a][b] = A[i][j];
        b++;
        j++;
        if(b == t){
            b = 0;
            j = 0;
            a ++;
            i ++;
        } 
        if(j == k){
            j = 0;
        }  
        if(i == n){
            i = 0;
        }
} 
}
