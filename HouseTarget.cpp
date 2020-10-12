#include <bits/stdc++.h>

using namespace std;

const int N = 110;
vector<int> adj[110];
bool vis[N] = {false};

bool search_path(int node, int target){
    vis[node] = true;
    for(auto u: adj[node]){
        if(u==target) return true;
        if(!vis[u]){
            search_path(u,target);
        }

    }   
    return false; 
/* 
7 
2 1 0 1 2 1 6

5
*/
}


int possiblerotation(int n, vector<int> arr, int s)// n is the number of houses, arr contains the house number markings,
//s is the house number from which Harry starts the hunt.
{
    
    // WRITE YOUR CODE HERE
    
    // return 1 if hunt is possible and 0 if not possible
    int size = arr.size();
    int target =-1;
    for(int i=0;i<arr.size();i++){
        int u,v; 
        if(arr[i] == 0) target = i;
        if(i-arr[i]>=0){
            adj[i].push_back(i-arr[i]);
            // adj[i+arr[i]].push_back((i+arr[i]));
        }
        if(i+arr[i]<n){
            adj[i].push_back(i+arr[i]);
        }
    }

    return search_path(s-1,target) ? 1:0;

    return -1;
}

void printPossiblerotation(int n, vector<int> arr, int s)
{
    if(possiblerotation(n,arr,s)==1)
    {
        cout<<"Yes\n";
    }
    else if(possiblerotation(n,arr,s)==0)
    {
        cout<<"No\n";
    }
}

int main()
{
    int len, temp, s, nTest;
    cin>>nTest;
    for(int j=0;j<nTest;++j)
    {
        cin>>len;
        vector<int> arr;
        for(int i=0; i<len;++i)
        {
            cin>>temp;
            arr.push_back(temp);
        }
        cin>>s;
        printPossiblerotation(len,arr,s);
    }
    return 0;
}