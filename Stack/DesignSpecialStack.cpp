#include<iostream>
#include<stack>
using namespace std;

class SpecialStack{
    public:
    stack<int> s;
    int mini;

    void push(int data)
    {

        if (s.empty())
        {
            s.push(data);
            mini=data;
        }
        else
        {
            if (data < mini)
            {
                int val = 2*data - mini;
                s.push(val);
                mini = val;
            }
            else
            {
                s.push(data);
            }
        }
    }
    void pop()
    {
        int curr =s.top();
        if (s.empty())
        {
            return -1;
        }
        else
        {
            if (curr > mini)
            {
                s.pop();
            }
            else
            {
                s.pop(); 
                int val;
                val=2*mini-curr;
                mini=val;
            }
        }
    }
};