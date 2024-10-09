#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

class TwoStack {

public:
        int* arr;
        int size;
        int topa;
        int topb;
    
    TwoStack(int s) {
        this->size=s;
        topa=-1;
        topb=s;
        arr= new int[s];
        }
    
    void push1(int num){ 
        if(topa + topb > 1)  
        {    
            topa++;
            arr[topa]=num;
        }
    }

    void push2(int num){
        if(topa + topb > 1)
        {
            topb--;
            arr[topb]=num;
        }
    }

    int pop1() {
        if(topa >= 0){
            int res = arr[topa];
            topa--;
            return res;
        }
        else{
            return -1;
        }
    }

    int pop2() {
        if(topb <= size-1){
            int res = arr[topb];
            topb++;
            return res;
        }
        else{
            return -1;
        }
    }
};
