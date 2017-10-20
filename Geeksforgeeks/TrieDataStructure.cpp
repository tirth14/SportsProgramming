/*

***Phone Directory***

Given a list of contacts which exist in a phone directory. The task is to implement search query for the phone directory. The search query on a string ‘str’ displays all the contacts which prefix as ‘str’. One special property of the search function is that, when a user searches for a contact from the contact list then suggestions (Contacts with prefix as the string entered so for) are shown after user enters each character.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains three lines. First line of each test case contains N i.e., number of contacts. Second line contains space separated all the contacts in the form of string. And third line contains query string.

Output
For each test case, print the query results in new line. If there is no match between query and contacts, print "0".

Constraints:
1<=T<=100
1<=N<=50
1<=|contact[i].length|<=50
1<=|query length|<=6

Example:
Input:
1
3
geeikistest geeksforgeeks geeksfortest
geeips

Output:

geeikistest geeksforgeeks geeksfortest 
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
  struct TrieNode* child[26];
  bool isLast;
  
  TrieNode()
  {
    for(int i=0;i<26;i++)
        child[i]=NULL;
    isLast=false;
  }
};

void insert(TrieNode* root, string s)
{
    struct TrieNode* pCrawl=root;
    
    for(int i=0;i<s.length();i++)
    {
        int index=s[i]-'a';
        
        //cout<<"Inserting "<<char('a'+index)<<" "<<endl;;
        if(!pCrawl->child[index])
                pCrawl->child[index]=new TrieNode();
        
        pCrawl=pCrawl->child[index];
    }
    
    pCrawl->isLast = true;
}

void displayContactsUtil(TrieNode* currNode, string prefix)
{
    if(currNode->isLast==true) 
    cout<<prefix<<" ";
    
    for(int i=0;i<26;i++)
    {
        if(currNode->child[i]!=NULL)
        {
            displayContactsUtil(currNode->child[i], prefix+char('a'+i));
        }    
    }
}

//Displays suggestions  after entering each character
void displayContacts(TrieNode* root, string s)
{
    TrieNode* preNode = root;
    string prefix="";
    
    int i;
    for(i=0;i<s.length();i++)
    {
        prefix+=s[i];
        TrieNode* currNode=preNode->child[s[i]-'a'];
        
        if(!currNode)
            break;
         
         displayContactsUtil(currNode,prefix);
         cout<<endl;
         
         preNode=currNode;
         
    }
    
    for(;i<s.length();i++)
        cout<<"0"<<endl;
}


int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        TrieNode* root = new TrieNode();
        
        int n;
        cin>>n;
        
        //formation of trie
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            insert(root,s);
        }
        
        string query;
        cin>>query;
        
        displayContacts(root, query);
    }   
    
}
