#include<iostream>
using namespace std;
// tìm các submatrix có tổng bằng 100 và đưa nó vào thành một mảng 3 chiều
int ***findSubMatrix(int **a,int length, int width, int length_sub, int width_sub, int &count){
    int sum;
     count = 0;
    for(int i=0;i<=length-length_sub;i++){
        for(int j=0;j<=width-width_sub;j++){
            sum = 0;
            for(int k=i;k<i+length_sub;k++){
                for(int l=j;l<j+width_sub;l++){
                    sum += a[k][l];
                }
            }
            if(sum == 100){
                count++;
            }
        }
    }
    int ***b = new int**[count];
    for(int i=0;i<count;i++){
        b[i] = new int*[length_sub];
        for(int j=0;j<length_sub;j++){
            b[i][j] = new int[width_sub];
        }
    }
    int temp = count;
    for(int i=0;i<=length-length_sub;i++){
        for(int j=0;j<=width-width_sub;j++){
            sum = 0;
            for(int k=i;k<i+length_sub;k++){
                for(int l=j;l<j+width_sub;l++){
                    sum += a[k][l];
                }
            }
            if(sum == 100){
                for(int k=i;k<i+length_sub;k++){
                    for(int l=j;l<j+width_sub;l++){
                        b[count-temp][k-i][l-j] = a[k][l];
                    }
                }
                temp--;
            }
        }
    }
    return b;
}
void output3DArray(int ***a, int length, int width, int height){
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){
            for(int k=0;k<height;k++){
                cout<<a[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
int main(){
    int **a = new int*[4];
    for(int i=0;i<4;i++){
        a[i] = new int[4];
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            a[i][j] = rand()%6*10;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int count = 0;
    int ***b = findSubMatrix(a,4,4,2,2,count);
    output3DArray(b,count,2,2);
    cout<<count;
    return 0;
    
}
