#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];//array of trieNode
    bool isEnd;

    TrieNode(char ch){//every node is capable of creating a child node of any possible alphabets 
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i]=NULL;
        }
        isEnd = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode('\0');
    }

    void InsertFunction(TrieNode* root,string str){
        if (str.length() == 0)
            {
                root->isEnd = true;
                return ;
            }
        //assuming string will be in caps 
        int index = str[0] - 'A';
        TrieNode* child;//the node that will contain the new char

        //present 
        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{//absent
            child = new TrieNode(str[0]);
            root->children[index] = child;
        }

        //recursive call
        InsertFunction(child,str.substr(1));
    
    }
    void Insert(string str)
    {
        InsertFunction(root,str);
    }

    bool SearchFunction(TrieNode* root,string str){
        
        if (str.length() == 0)
        {   
            if (root->isEnd == true)
            {
                return true ;
            }
            else
            {
                return false;
            }
        }
        
        int index = str[0] - 'A';
        TrieNode* child ;
        if (root->children[index] != NULL)
        {//present
         //check the next char of the string 
         //recursive call
            child = root->children[index];
            return SearchFunction(child, str.substr(1));
        
        }
        else{
            //absent 
            return false ;
        }
    }   
    bool Search(string str){
        bool ans = SearchFunction(root,str);
        return ans;
    }

    void RemoveFunction(TrieNode* root, string str){
        
        if(str.length() == 0)
        {   
            root->isEnd = false;
            return ;
 
        }
        
        int index = str[0] - 'A';
        TrieNode* child;
        
        
        if (root->children[index] != NULL)
        {   
            child = root->children[index];
        }
        else
        {   
            cout<<"String does not exists !!";
            return ;
        }
        return RemoveFunction(child,str.substr(1));
    }
    void Remove(string str){
        RemoveFunction(root,str);
    }

    void printSuggestions(TrieNode *curr,vector<string> &temp,string prefix){
        //we will fill string and then empty it out 
        if(curr->isEnd)
        {
            temp.push_back(prefix);   
        }
        for(char ch = 'A';ch <= 'Z';ch++)//iterations for all the children of the lastChar 
        {
            TrieNode* next = curr->children[ch - 'A'];//next represents all the possibiilities of the suggestions after the prefix ends 
            
            if(next != NULL)
            {//every child of next is a suggestion
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);//we take a one brach and print all its suggestions
                prefix.pop_back();                //using recursion and then we do same with other children
            }
        }
    }
    vector<vector<string>> getSuggestions(string str){
        TrieNode* prev = root;
        vector<vector<string>> output;//will contain all the suggestions for all the instances of a string 
        string prefix = "";//this is the string that we will fill and then empty
                          //hence trying out all the suggestions of the string 

        for (int i = 0; i < str.length(); i++)
        {
            char lastChar = str[i];
            prefix.push_back(lastChar);

            //check for whether the last char exists in the children of this current Trienode
            TrieNode* curr = prev->children[lastChar - 'A'];

            //not found 
            if(curr == NULL){
                cout<<"not found ";
                break;
            }

            //found 
            vector<string> temp ;
            printSuggestions(curr,temp,prefix);
            
            output.push_back(temp);//temp would contain all the 
            temp.clear();         //suggestions for an iteration of the loop
            prev = curr;
            
        }
        return output;
    }
};

int main(){
    system("cls");
    Trie* t = new Trie();

    t->Insert("CODING");
    t->Insert("CODINGNINJA");
    t->Insert("CODER");
    t->Insert("CODEHELP");

    vector<vector<string>> ans = t->getSuggestions("CODINGN");
    for (int i = 0; i < ans.size(); i++)
    {  
        for (int j = 0; j < ans[i].size(); j++)
        {
           cout<<ans[i][j]<<" ";  
        }
        cout<<endl;
    }
    return 0;
}