#include<iostream>
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
        //string will be in caps 
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
        InsertFunction(child, str.substr(1));

        return ;
    }
    void Insert(string str)
    {
        InsertFunction(root, str);
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


};

int main(){
    system("cls");
    Trie* t = new Trie();

    t->Insert("abcde");
    cout<<"present or not " <<t->Search("abcde")<< endl;
    // cout<<"present or not " <<t->Search("abcd")<< endl;
    t->Remove("abcde");
    cout<<"present or not " <<t->Search("abcde")<< endl;
    t->Insert("abcde");
    t->Insert("doll");
    t->Insert("dolli");
    t->Insert("star");
    t->Insert("stardom");

    t->PrefixSearch("star");
    t->PrefixSearch("dol");
    t->PrefixSearch("dollsa");
    return 0;
}