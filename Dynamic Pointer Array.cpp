#include<bits/stdc++.h>
using namespace std;


int main(){

int **a,row,*col;

    cout<<"How many Rows: "<<endl;
    cin>>row;
    col=new int [row];

    for(int r=0;r<row;r++){
        cout<<"Enter col size for each row: "<<r<<" :";
        cin>>col[r];
    }

   //Dynamic memory allocation

    a=new int *[row];
    for(int r=0;r<row;r++)
    {
        a[r]=new int [col[r]];
    }


   //Input Section
     for(int r=0;r<row;r++){
        cout<<"Row "<<r<<" : ";
        for(int c=0;c<col[r];c++){
            cin>>a[r][c];
        }

    }

   //Output Section
    cout<<"Dynamic 2d Array: "<<endl;
    for(int r=0;r<row;r++){
        cout<<"Row "<<r<<" : ";
        for(int c=0;c<col[r];c++){
            cout<<a[r][c]<<" ";
        }
        cout<<endl;
    }







return 0;
}
