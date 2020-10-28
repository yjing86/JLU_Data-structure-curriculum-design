//
//  main.cpp
//  D-1
//
//  Created by Jing Yu on 2020/4/18.
//  Copyright © 2020 Jing Yu. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int cishu=0;
    string a;
    cin>>a;
    int len=a.length();
    const char *q=a.data();
    //cout<<len;
    int count1=0;
    int temp=0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            temp=0;
            for(int k=0;k<len-j;k++){
                if(q[i+k]==q[j+k]){
                    temp++;
                    if(temp>count1)
                        count1=temp;
                }else{
                    break;
                }
            }
        }
    }
    //cout<<count1;
    int count2first=0;
    int count2second=0;
    bool panduan=true;
    for(int i=0;i<len;i++){
        panduan=true;
        for(int j=0;j<i;j++){
            if(q[j]==q[len-i+j]){
            }else{
                panduan=false;
            }
        }
        if(panduan==true){
            if(i>count2first){
                count2second=count2first;
                count2first=i;
            }else if(count2first>i&&i>count2second){
                count2second=i;
            }
        }
    }
    int count2=len-count2second*2;
    if(count2<0)
        count2=0;
    cout<<count2+count1;
    return 0;
}
