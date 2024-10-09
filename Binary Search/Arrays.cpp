#include<iostream>
#include<conio.h>
using namespace std;

// struct rect{
//     int length;
//     int breadth;
// };

// int main(){
//     // _lrotl;
//   struct rect r1={10,5};
//   cout<<sizeof(r1)<<endl;
//   return 0; 
//   getch();
// }
int main(){
    int a=10;
    int *ptr;
    ptr=&a; 
   cout<<*ptr;
   getch();
}