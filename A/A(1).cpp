#include <iostream>
using namespace std;
int panduan(int a[30][30],int b[30][30],int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==-1&&b[i][j]!=-1){
                return -1;
            }
        }
    }
    cout<<"You win";
    exit(0);
    return 0;
}
void output(int a[30][30],int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j];
            if(j!=m){
                cout<<' ';
            }
        }
        if(i!=n)
            cout<<endl;
    }
}
int dig(int a[30][30],int b[30][30],int n,int m,int row,int col){
    // miss 0
    // win 1
    
    if(a[row][col]==-1){
        if(b[row][col]==-1){
            cout<<"You lose";
            exit(0);
        }
        if(b[row][col]>0){
            a[row][col]=b[row][col];
            return -1;
//            output(a, n, m);
//            cout<<endl;
//            panduan(a, b, n, m);
        }
        if(b[row][col]==0){
            a[row][col]=0;
           // output(a, n, m);
            if(row>1&&col>1)
                dig(a, b, n, m, row-1, col-1);
            if(row>1)
                dig(a, b, n, m, row-1, col);
            if(row>1&&col<m)
                dig(a, b, n, m, row-1, col+1);
            if(col>1)
                dig(a, b, n, m, row, col-1);
            if(col<m)
                dig(a, b, n, m, row, col+1);
            if(row<n&&col>1)
                dig(a, b, n, m, row+1, col-1);
            if(row<n)
                dig(a, b, n, m, row+1, col);
            if(row<n&&col<m)
                dig(a, b, n, m, row+1, col+1);
        }
        
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    int n=0,m=0,k=0,l=0;
    cin>>n>>m>>k>>l;
    int row=0,col=0;
    int a[30][30],b[30][30];
    //a: dig or not
    //b: thunder is or not
    for(int q=0;q<30;q++){
        for(int p=0;p<30;p++){
            a[q][p]=0;
            b[q][p]=0;
        }
    }
    for(int q=1;q<=n;q++){
        for(int p=1;p<=m;p++){
            a[q][p]=-1;
        }
    }
    for(int q=0;q<k;q++){
        //install thunder
        cin>>row>>col;
        b[row+1][col+1]=-1;
    }
    for(int q=1;q<=n;q++){
        for(int p=1;p<=m;p++){
            //calculate
            if(b[q][p]!=-1){
                if(b[q-1][p-1]==-1)
                    b[q][p]++;
                if(b[q-1][p]==-1)
                    b[q][p]++;
                if(b[q-1][p+1]==-1)
                    b[q][p]++;
                if(b[q][p-1]==-1)
                    b[q][p]++;
                if(b[q][p+1]==-1)
                    b[q][p]++;
                if(b[q+1][p+1]==-1)
                    b[q][p]++;
                if(b[q+1][p]==-1)
                    b[q][p]++;
                if(b[q+1][p-1]==-1)
                    b[q][p]++;
            }
        }
    }
//    output(a, n, m);
//    cout<<endl;
//     output(b, n, m);
//    cout<<endl;
    for(int q=0;q<l;q++){
        //dig
        cin>>row>>col;
        row++;
        col++;
        if(a[row][col]==-1){
        dig(a, b, n, m, row, col);
        output(a, n, m);
        cout<<endl;
        panduan(a, b, n, m);
            if(q!=l-1)
            cout<<endl;
        }
        
    }
//        output(a, n, m);
//        cout<<endl;
//        output(b, n, m);
    return 0;
}

