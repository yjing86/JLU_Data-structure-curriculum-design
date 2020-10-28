//
//  main.cpp
//  D-2
//
//  Created by Jing Yu on 2020/4/19.
//  Copyright © 2020 Jing Yu. All rights reserved.
//

#include<iostream>
#define max 999999
using namespace std;

struct ArcNode{
    int mark;
    int weight;
    ArcNode*next;
};
struct VexNode{
    int mark;
    ArcNode*next;
    VexNode*NextVexNode;
};
void digkstra(VexNode*VexNodeList,int vexnum){
    int ss[15000]={0};
    int dist[15000]={0};
    int path[15000]={0};
    for (int i=0;i<vexnum;i++){
        dist[i]=max;
        ss[i]=0;
        path[i]=-1;
    }
    dist[0]=0;
    ss[0]=1;
    ArcNode*p=VexNodeList[0].next;
    int u=0;
    for(int i=1;i<vexnum;i++){
        while(p!=NULL){
            int k=p->mark;
            if(ss[k]!=1&&dist[u]+p->weight<dist[k]){
                dist[k]=dist[u]+p->weight;
                path[k]=u;
            }else if(ss[k]==0&&dist[u]+p->weight==dist[k]){
                int levelOld=0,levelNew=1,templevel=k;
                while(path[templevel]!=-1){
                    levelOld++;
                    templevel=path[templevel];
                }
                templevel=u;
                while(path[templevel]!=-1){
                    levelNew++;
                    templevel=path[templevel];
                }
                if(levelNew<levelOld){
                    path[k]=u;
                }else if(levelOld==levelNew){
                    int tempPathOld[15000]={0};
                    int tempPathNew[15000]={0};
                    templevel=levelNew;
                    int Count=templevel;
                    levelOld=path[k];
                    levelNew=u;
                    while(templevel>0){
                        tempPathOld[templevel-1]=levelOld;
                        tempPathNew[templevel-1]=levelNew;
                        templevel--;
                        levelOld=path[levelOld];
                        levelNew=path[levelNew];
                    }
                    int panduan=0;
                    for(int i=0;i<Count;i++){
                        if(tempPathNew[i]<tempPathOld[i]){
                            panduan=1;
                            break;
                        }
                    }
                    if(panduan==1){
                        path[k]=u;
                    }
                }
            }
            p=p->next;
        }
        int ldist=max;
        for(int i=1;i<vexnum;i++){
            if(dist[i]<ldist&&ss[i]==0){
                ldist=dist[i];
                u=i;
            }
        }
        ss[u]=1;
        p=VexNodeList[u].next;
    }
    for(int i=1;i<vexnum;i++){
        int tempLevel=0;
        int tempNum=i;
        while(path[tempNum]!=-1){
            tempLevel++;
            tempNum=path[tempNum];
        }
        if(tempLevel==0)
            continue;
        int tempPath[15000]={0};
        int Count=tempLevel;
        tempNum=i;
        tempPath[tempLevel]=tempNum;
        while(tempLevel>0){
            tempPath[tempLevel-1]=path[tempNum];
            tempNum=path[tempNum];
            tempLevel--;
        }
        for(int j=0;j<=Count;j++){
            cout<<tempPath[j];
            if(j!=Count)
                cout<<"->";
        }
        if(i!=vexnum-1)
            cout<<endl;
    }
}
int main(){
    int vexnum=0,arcnum=0;
    cin>>vexnum>>arcnum;
    VexNode*VexNodeList=(VexNode*)malloc(sizeof(VexNode)*vexnum);
    for(int i=0;i<vexnum-1;i++){
        VexNodeList[i].NextVexNode=&VexNodeList[i+1];
        VexNodeList[i].mark=i;
        VexNodeList[i].next=NULL;
    }
    VexNodeList[vexnum-1].NextVexNode=NULL;
    VexNodeList[vexnum-1].mark=vexnum-1;
    VexNodeList[vexnum-1].next=NULL;
    int tempArcStart=0,tempArcEnd=0,tempArcWeight=0;
    for(int i=0;i<arcnum;i++){
        cin>>tempArcStart>>tempArcEnd>>tempArcWeight;
        ArcNode*p=VexNodeList[tempArcStart].next;
        if(p==NULL){
            VexNodeList[tempArcStart].next=(ArcNode*)malloc(sizeof(ArcNode));
            VexNodeList[tempArcStart].next->mark=tempArcEnd;
            VexNodeList[tempArcStart].next->weight=tempArcWeight;
            VexNodeList[tempArcStart].next->next=NULL;
        }else{
            while(p->next!=NULL)
                p=p->next;
            p->next=(ArcNode*)malloc(sizeof(ArcNode));
            p->next->mark=tempArcEnd;
            p->next->weight=tempArcWeight;
            p->next->next=NULL;
        }
    }
    digkstra(VexNodeList,vexnum);
}
