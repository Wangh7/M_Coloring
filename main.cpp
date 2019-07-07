//
//  main.cpp
//  M Coloring
//
//  Created by wbb on 2018/5/14.
//  Copyright © 2018年 Wangh7. All rights reserved.
//

#include <iostream>
#include <string.h>
#define MAX 500
using namespace std;

class Color{
    friend int M_Coloring(int,int,bool**);
private:
    bool Ok(int k);
    void Backtrack(int t);
    int n,m,*x,sum;
    bool **a;
};

bool Color::Ok(int k){
    for(int j=1;j<=n;j++){
        if((a[k][j]==1)&&(x[j]==x[k]))
            return false;
    }
    return true;
}

void Color::Backtrack(int t){
    if(t>n)
        sum++;
    else
        for(int i=1;i<=m;i++){
            x[t]=i;
            if(Ok(t))
                Backtrack(t+1);
            x[t]=0;
        }
}

int M_Coloring(int n,int m,bool **a){
    Color C;
    C.n=n;
    C.m=m;
    C.a=a;
    C.sum=0;
    int *p=new int [n+1];
    for(int i=0;i<=n;i++)
        p[i]=0;
    C.x=p;
    C.Backtrack(1);
    delete []p;
    return C.sum;
}

int main(){
    int n,m,e,k,j;
    cin>>n>>e>>m;
    bool** a=new bool* [n+1];
    a[0]=new bool[(n+1)*(n+1)];
    for(int i=1;i<n+1;i++)
        a[i]=a[i-1]+n+1;
    memset(a,0,sizeof(bool));
    //cin>>n>>e>>m;
    for(int i=0;i<e;i++){
        cin>>k>>j;
        a[k][j]=1;
        a[j][k]=1;
    }
    if(M_Coloring(n,m,a)==0)
        cout<<"NO";
    else
        cout<<"YES";
    delete[] a;
    return 0;
}
