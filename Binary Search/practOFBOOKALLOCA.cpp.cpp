#include<iostream>
using namespace std;

bool possible(int *arr,int end,int nStudents,int mid){
    int student = 0;
    for(int i = 0; i <= end; i++){
    
        if (pages_allocated + arr[i] <= arr[mid])
            {
            pages_allocated += arr[i];//if the pages haven't reached more than arr[mid]
            }
        
        else{//if they reaches more than mid then go to another student now.
            student++;
                if (arr[i]>arr[mid] || student>nStudents)
                {
                return false;//agar next index me jo value h vo arr[mid] se badi hui....ya fir student hn hi nhi itne 
                }

                pages_allocated = arr[i];//resetting the no. of pages so we can start allocating to the new student.
            }
            
}
        if(student>nStudents)
                {
                    return false;
                }
    return true;
}

int binary(int *arr,int start,int end,int nStudents){
    int mid = start + (end - start)/2;//ek tareeke ka guess hota h mid. Fir ise trial and fail se badal-badal kr dekhte rhte hn ki konsi most optimal h.
    int ans;
    if(possible(arr,end,nStudents,mid)){//No. bat gya successfully....lekin check krte hn ki aur koi minimum value exist krti h i.e left me jao array ke 
        
        ans = mid;// yhi h minimum of maximum pages alloted.

        return binary(arr,start,mid,nStudents);
    }
    else{// Mid agar nhi batta toh use bdhao i.e array me right jao.
        
        return binary(arr,mid+1,end,nStudents);
        
    }
    
}

int main(){
    system("cls");

}