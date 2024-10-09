#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool Knows(vector<vector<int>> vec,int p1,int p2){
    if (vec[p2][p1] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool celebrityPresent(vector<vector<int>> vec){
    // PUSHING PEOPLE INTO STACK
    stack<int> s;
    for (int i = 0; i<vec.size()-1; i++){
        s.push(i);
    }
    // REMOVING THE UPPER TWO FROM THE STACK
    while (s.size()>1){   
        int p1=s.top();
        s.pop();
        int p2=s.top();
        s.pop();
    //CHECK IF THEY KNOW EACH OTHER
    if(Knows(vec,p1,p2)){
        s.push(p1);//if p2 knows p1 :"p2" cant be a celebrity
    }
    else if(Knows(vec,p2,p1)){
        s.push(p2);//if p1 knows p2 :"p1" cant be a celebrity
    }

    }
    //only one person is left in the stack now 
    //he is a potential celebrity 
    int potentialCelebrity = s.top();

    //WE WILL NOW VERIFY IT 
    
    //check row condition 
    bool knowsOther = false;
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[potentialCelebrity][j]==1 )
        {
            knowsOther=true;
            break;
        }
    }

    //check column condition
    bool OtherKnows=true;
    for (int i = 0; i < vec.size(); i++)
    {
        if(i == potentialCelebrity)//diagonal element
        {
            continue;
        }
        if (vec[i][potentialCelebrity]==0 )
        {
            OtherKnows=false;
            break;
        }
    }

    //NOW FINALLY WE CHECK AND RETURN
    if (knowsOther == false && OtherKnows == true)
    {
        return true;//a celebrity is present
    }
    else{
         return false;//no celebrity is present
    }
}

int main(){
    system("cls");
    vector<vector<int>> M= {{0,1,0},
                            {0,0,0}, 
                            {0,1,0}};
    
    cout<<celebrityPresent(M);

    return 0;
}