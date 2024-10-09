#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int val, vector<vector<int>> &sudoku)
{
    for (int i = 0; i < sudoku.size(); i++)
    {
        // 1.No same number in the row
        if( sudoku[row][i] == val )
        {
            return false;
        }
    
        // 2.No same number in the column
        if( sudoku[i][col] == val )
        {
            return false;
        }
        
        // 3.No same number in the 3x3 matrix
        if (sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val)
        {
            return false;
        }
    }
    return true;
}

bool SudokuSolver(vector<vector<int>> &sudoku)
{
    for(int i = 0; i<sudoku[0].size(); i++)
    {
        for (int j = 0; j<sudoku[0].size(); j++)
        {
            if(sudoku[i][j] == 0)//we found an empty slot
            {   
                for (int val = 1; val <= 9; val++)
                {
                    if(isSafe(i, j, val, sudoku)) //possible solution 
                    {   
                        sudoku[i][j] = val;

                        bool IsItSolution = SudokuSolver(sudoku);// check if the rest of the sudoku can be solved  

                        if(IsItSolution)
                        {
                            return true; //we found a solution that satisfies the rest of the sudoku 
                        }               //as well 
                        else
                        {
                            sudoku[i][j] = 0;// no the rest of the sudoku couldn't get solved 
                        }                // hence meaning that this val wasn't the correct 
                                        // digit to put here hence backtrack 
                    }
                }
                return false; // we couldn't find a solution for this slot even after checking the all 1-9 values
            }                //this means that there is no solution for this matrix hence no point in checking other 
                            // rest of the empty blocks  
        }                 
    }
    return true;
}

int main(){
    vector<vector<int>> sudoku = 
    {
        //0 means empty
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };
    SudokuSolver(sudoku);
    cout<<"finished";
    return 0;
}