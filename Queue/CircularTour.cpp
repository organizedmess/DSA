#include<iostream>
#include<queue>
using namespace std;

class petrolPump{
    public:
    int petrol;
    int distance;
};

int startingIndex(petrolPump p[],int n){
    int balance=0;
    int deficit=0;//used to optimize the code

    int start=0;

    for (int i=0;i<n;i++)
    {
        balance += p[i].petrol -p[i].distance;
        if (balance<0)
        {
            deficit += balance;
            start=i+1;//resetting because any pump between start and 'i'th pump wont be able to make the distance without the help of any extrinsic balance
            balance=0;
        }
    }

    if (deficit+balance>=0)
    {
        return start;//the balance we have gotten suffices the need for petrol between the pumps where we ran out. 
    }
    else
    {
        return -1;//journey is not possible 
    }
}
            
    

int main(){
    system("cls");
    petrolPump p[6]; 

    p[0].petrol= 6;
    p[0].distance= 5;

    p[1].petrol= 7;
    p[1].distance= 6;
    
    p[2].petrol= 4;
    p[2].distance= 7;
    
    p[3].petrol= 10;
    p[3].distance= 8;
    
    p[4].petrol= 6;
    p[4].distance= 6;
    
    p[5].petrol= 5;
    p[5].distance= 4;

    cout<<startingIndex(p,6);
    return 0;
}