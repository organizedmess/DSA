#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class element{
    public:
    int data;
    int row;
    int col;
    int arrsize;
    element(int d,int r,int c,int s){
        this->data = d;
        this->row = r;
        this->col = c;
        this->arrsize = s;
    }
};
class compare{
    public:
    int data;
    bool operator()(element a,element b){
        bool condition = a.data > b.data; 
        return condition;
    }
};

vector<int> smallestRange(vector<vector<int>>& a) 
{
        int minn = INT_MAX;int maxx = INT_MIN;
        int range = INT_MAX;
        int low,high;
    priority_queue<element,vector<element>,compare> pq;
    for (int i = 0; i < a.size(); i++)
    {//pushing first elements of all the lists
        pq.push(element(a[i][0],i,0,a[i].size()));
        minn =  (minn>a[i][0] ? a[i][0] : maxx) ;
        maxx =  (maxx<a[i][0] ? a[i][0] : maxx) ;
        //here minn/maxx is actually the smallest/maximum value of the elements inserted
    }

    while (!pq.empty())
    {
        element topElement = pq.top();
        pq.pop();
        int possible_minn = topElement.data;
        //but here minn is not going to be the minimum value but the minimun value at which range is minimum
        
        if (range > (maxx - possible_minn))
        {//possibility of a smaller range
            minn = possible_minn; 
            range = maxx - minn;
            low = minn;
            high = maxx;
        }
        
        if (topElement.col == topElement.arrsize - 1)
            break;//the moment we got out of bound even for a single array
                //stop the loop and return range coz its the best answer possible
             //coz from now on the range will not contain any element from this array

        topElement.col++;
        pq.push(element(a[topElement.row][topElement.col],topElement.row,topElement.col,topElement.arrsize));
        maxx = (maxx > a[topElement.row][topElement.col] ? maxx : a[topElement.row][topElement.col]);
        //checking if the new element pushed is larger
    }
    vector<int> v{low,high};
    return v;       
}     

int main(){
    system("cls");

    return 0;
}