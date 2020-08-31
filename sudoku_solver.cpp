#include <iostream>
using namespace std;
bool issafe(int a[20][20],int n,int x,int y,int k)
{
     for(int i=x,j=y;i>=0;i--)
    {
        if(a[i][j]==k)
        {
            return false;
        }
    }
     for(int i=x,j=y;j>=0;j--)
    {
        if(a[i][j]==k)
        {
            return false;
        }
    }
     for(int i=x,j=y;i<n;i++)
    {
        if(a[i][j]==k)
        {
            return false;
        }
    }
     for(int i=x,j=y;j<n;j++)
    {
        if(a[i][j]==k)
        {
            return false;
        }
    }
    int x1=3*(x/3);
    int y1=3*(y/3);
    for(int i=x1;i<x1+3;i++)
    {
        for(int j=y1;j<y1+3;j++)
        {
            if(a[i][j]==k)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudoku(int a[20][20],int n,int x,int y)
{
    if(x==n-1 && y==n)
 {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return true;
 }
    if(y==n)
    {
        x++;
        y=0;
    }
    if(a[x][y]==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(issafe(a,n,x,y,i))
            {
                a[x][y]=i;
                bool done =sudoku(a,n,x,y+1);
                if(done)
                {
                    return true;
                }
                a[x][y]=0;
                
            }
        
        }
    }
    else
    {
        return sudoku(a,n,x,y+1);
    }
    return false;
}
int main() 
{
    int n; 
    cout<<"Enter the size of the sudoku: ";
    cin>>n;
    int a[20][20];
    cout<<"\nProvide Input please:";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"\nResult: "<<"\n";
    cout<<sudoku(a,n,0,0);
}
