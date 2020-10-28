#include <iostream>
#include <vector>
using namespace std;
struct tree {
    int mark;
    tree* brother;
    tree* son;
};
int AlphaBeta(tree *A,int level,int alpha,int beta){
    //A:root node;level:The number of layers from the top down.The first node marks 1;
    tree*p=A;
    if(p->son==NULL)
        return p->mark;
    if(level/2==0){
        //min
        tree *q=p->son;
        while(q!=NULL){
            p->mark=AlphaBeta(q, level+1,alpha,beta);
            if(p->mark<beta){
                beta=p->mark;
                if(alpha>=beta)
                    return alpha;
            }
            q=q->brother;
        }
        return beta;
    }else{
        //max
        tree *q=p->son;
        while(q!=NULL){
            p->mark=AlphaBeta(q, level+1, alpha, beta);
            if(p->mark>alpha){
                alpha=p->mark;
                if(alpha>=beta)
                    return beta;
            }
            q=q->brother;
        }
        return alpha;
    }
}
void MinMax(tree *A){
    // use this
    AlphaBeta(A, 1, -9999999, 9999999);
}
int main(){
   
}


