//
//  main.cpp
//  D-4
//
//  Created by Jing Yu on 2020/4/18.
//  Copyright © 2020 Jing Yu. All rights reserved.
//
#include <iostream>
using namespace std;
struct tree{
    int num;
    bool IS;
    tree* son;
    tree* bro;
    tree* father;
    tree(int a){
        num=a;
        son=NULL;
        bro=NULL;
        father=NULL;
        IS=false;
    }
};
int main(int argc, const char * argv[]) {
    int n=0;
    cin>>n;
    tree *root=new tree(n);
    tree *p=root;
    int type=n;
    while(scanf("%d",&n)!=EOF){
        if(n!=0){
            if(type==0){
                tree *temp=p->son;
                while(temp->bro!=NULL)
                    temp=temp->bro;
                temp->bro=new tree(n);
                temp->bro->father=temp->father;
                p=temp->bro;
            }else{
                p->son=new tree(n);
                p->son->father=p;
                p=p->son;
            }
        }else{
            if(p->father==NULL)
                break;
            p=p->father;
        }
        type=n;
    }
    int list[150]={0};
    int templist[150]={0};
    p=root;
    tree*q=root;
 //   tree*rear=root;
    int sum=1,tempsum=1,level=0,templevel=0;;
    int num=0;
    templist[num]=q->num;
    sum=sum*q->num;
    tempsum=sum;
    while(q!=NULL){
        if(q->son!=NULL&&q->son->IS==false){
            q=q->son;
            q->IS=true;
            num++;
            templevel++;
            templist[num]=q->num;
            tempsum=tempsum*q->num;
            if(tempsum>sum){
                level=templevel;
                for(int i=0;i<150;i++)
                    list[i]=templist[i];
                sum=tempsum;
            }else if(tempsum==sum){
                if(level>templevel){
                    level=templevel;
                    for(int i=0;i<150;i++)
                        list[i]=templist[i];
                    sum=tempsum;
                }
            }
        }else{
            tempsum=tempsum/q->num;
            templist[num]=0;
            num--;
            if(q->bro!=NULL){
                q=q->bro;
                q->IS=true;
                num++;
                templist[num]=q->num;
                tempsum=tempsum*q->num;
                if(tempsum>sum){
                    level=templevel;
                    for(int i=0;i<150;i++)
                        list[i]=templist[i];
                    sum=tempsum;
                }else if(tempsum==sum){
                    if(level>templevel){
                        level=templevel;
                        for(int i=0;i<150;i++)
                            list[i]=templist[i];
                        sum=tempsum;
                    }
                }
            }else{
                q=q->father;
                templevel--;
            }
        }
    }
    cout<<sum<<endl;
    int i=0;
    int panduan=0;
    while(list[i]!=0){
        if(list[i]!=1)
            panduan=1;
        if(panduan==1)
            cout<<list[i]<<' ';
        i++;
    }
    return 0;
}
