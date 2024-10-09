#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];//array of trieNode
    bool isEnd;
    int childCount;
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
        //string will be in caps 
        int index = str[0] - 'A';
        TrieNode* child;//the node that will contain the new char

        //present 
        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{//absent
            root->childCount++;
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

    bool prefixSearchFunction(TrieNode*root,string str){
        if (str.length() == 0) 
        {   
            cout<<"words with that prefix exists"<<endl;
            return true;
        }

        int index = str[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
            prefixSearchFunction(child , str.substr(1));
        }
        else{
            cout<<"No words with that prefix!!"<<endl;
            return false; 
        }
        
        
    }
    bool PrefixSearch(string str){
        prefixSearchFunction(root,str);
    }

    string Lcp(string str, string &ans){

       for(int i = 0; i < str.length(); i++)
       {    
             char ch = str[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                //aage badh jao
                int index = ch - 'A';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if(root->isEnd)
                break;
       }
        return ans;
    }

};

//without using TRIE
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;
   for(int col=0;col<arr[0][col];col++){
        char ch = arr[0][col];
        bool match = true;

        //we are traversing the elements of all the strings 
        //not traversing a single string's character one by one 
        //in the loop below
       for(int row=1;row<n;row++){
           if(arr[row].size() < col|| arr[row][col] != ch)
           {
                match = false;
                break;   
           }
        }
        //two ways to come out if this loop
        //1. the loop simply ends i.e this string is same as first
        //2. the unequal character comes i.e match is not the same 
        if(match == false){
            break;
        }
        else{//this char is common in all the strings 
            ans.push_back(ch);
        }
   }

    return ans;
}

//using TRIE 

int main(){
    system("cls");
    vector<string> vec = {"ninja","nil","nina","nimrod"};
    string ans = longestCommonPrefix(vec,4);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i];
    }
    

    Trie* obj = new Trie();

    obj->Insert("ninja");obj->Insert("nil");obj->Insert("nina");obj->Insert("nimrod");
    
    string first = vec[0];
    string result = "";
    obj->Lcp(first,result);

    cout<<endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i];
    }

    
    return 0;
}