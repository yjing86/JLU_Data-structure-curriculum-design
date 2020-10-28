//
//  main.cpp
//  D-3
//
//  Created by Jing Yu on 2020/4/21.
//  Copyright © 2020 Jing Yu. All rights reserved.
//

#include<iostream>
#define max  999999
using namespace std;
int n=0, s=0, t=0;
int* Dijkstra(int** VexNode,int& dic,int tempStart,int tempEnd,int cost){
    int min,u=1,panduan=0,calculate=1;
    int* dis=new int [n+1];
    int* path = new int[n + 1];
    int* mark=new int [n+1];
    VexNode[tempStart][tempEnd] = cost;
    VexNode[tempEnd][tempStart] = cost;
    panduan=1;
    while(panduan<=n){
        mark[panduan] = 0;
        dis[panduan] = VexNode[s][panduan];
        path[panduan] = s;
        panduan++;
    }
    mark[s] = 1;
    while(calculate<=n){
        min = max;
        panduan=1;
        while(panduan<=n){
            int temp=(mark[panduan] == 0 && min > dis[panduan]);
            if (temp){
                min = dis[panduan];
                u = panduan;
            }
            panduan++;
        }
        mark[u] = 1;
        panduan=1;
        while(panduan<=n){
            int temp=(!mark[panduan] && dis[panduan] > dis[u] + VexNode[u][panduan]);
            if(temp){
                dis[panduan] = dis[u] + VexNode[u][panduan];
                path[panduan] = u;
            }
            panduan++;
        }
        calculate++;
    }
    dic = dis[t];
    delete []dis;
    delete []mark;
    return path;
}
int main(void){
    cin >> n >> s >> t;
    int m=0,k=0;
    cin >> m;
    int** VexNode = new int* [n + 1];
    int count=0,calculate=0;
    while(count<=n){
        VexNode[count] = new int[n + 1];
        count++;
    }
    count=0;
    while(count<=n){
        calculate=0;
        while(calculate<=n){
            VexNode[count][calculate]=max;
            calculate++;
        }
        count++;
    }
    count=0;
    int tempStart=0,tempEnd=0;
    while(count<m){
        cin>>tempStart>>tempEnd;
        cin>>VexNode[tempStart][tempEnd];
        VexNode[tempEnd][tempStart]=VexNode[tempStart][tempEnd];
        count++;
    }
    cin>>k;
    int *path=NULL;
    int min=max,minTrans=0,way=0,dic=0,cost=0;
    int* minPath = new int[n];
    int *pathBus=Dijkstra(VexNode,way, 0, 0, 0);
    count=0;
    while(count<k) {
        cin >> tempStart >> tempEnd;
        cin >> cost;
        path = Dijkstra(VexNode, dic, tempStart, tempEnd, cost);
        int temp=(dic < min);
        if (temp) {
            for (int j = 0; j < n; j++)
                minPath[j] = path[j];
            min = dic;
            minTrans = tempStart;
        }
        delete path;
        count++;
    }
    int temp=(dic < way);
    if (temp)
        cout << dic<<endl<<minTrans;
    else
        cout<<minTrans<<endl<< "only bus";
    delete []pathBus;
    count=0;
    while(count<n){
        delete VexNode[count];
        count++;
    }
    delete[]VexNode;
}


