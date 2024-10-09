#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void print(vector<string> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i];
        cout<<endl;
    }
}

//to check whether a step is valid or not.
bool isSafe(vector<vector<int>> &maze, int i, int j, vector<vector<int>> prevPath, int size)
{
    if (i < size and j < size and i >= 0 and j >= 0)
    {
        if (maze[i][j] && prevPath[i][j] == 0)
            return true;
    }
    return false;
}

void RatMaze(vector<vector<int>> &maze,vector<vector<int>> prevPath,int size,string path,vector<string> &ans,int i,int j){
    if(i == (size-1) && j == (size-1))//Base Case
    {   
        ans.push_back(path);
        return;   
    }
    
    //Next block : down,left,up,right
        prevPath[i][j] = 1;
    //left
    int neWi = i;
    int neWj = j-1;
    if (isSafe(maze,neWi,neWj,prevPath,size))
    {   
        path.push_back('L');
        RatMaze(maze,prevPath,size,path,ans,neWi,neWj);
        path.pop_back();
    }

    //right
    neWi = i;
    neWj = j+1;
    if (isSafe(maze,neWi,neWj,prevPath,size))
    {   
        // prevPath[i][j] = 1;
        path.push_back('R');
        RatMaze(maze,prevPath,size,path,ans,neWi,neWj);
        path.pop_back();
    }
    
    //up
    neWi = i-1;
    neWj=  j;
    if (isSafe(maze,neWi,neWj,prevPath,size))
    {   
        // prevPath[i][j] = 1;
        path.push_back('U');
        RatMaze(maze,prevPath,size,path,ans,neWi,neWj);
        path.pop_back();
    }
    //down
    neWi = i+1;
    neWj = j;
    if (isSafe(maze,neWi,neWj,prevPath,size))
    {    
        // prevPath[i][j] = 1;
        path.push_back('D');
        RatMaze(maze,prevPath,size,path,ans,neWi,neWj);
        path.pop_back();
    }

    prevPath[i][j] = 0;//BackTracking   
}


int main(){
    system("cls");
    int size = 4;
    vector<vector<int>> prevPath = {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};
    vector<vector<int>> maze = {{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
    string path ="";
    vector<string> ans;
    RatMaze(maze,prevPath,size,path,ans,0,0);
    print(ans);
    return 0;
}
    
