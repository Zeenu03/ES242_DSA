#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<cmath>
#include<string>
#include <utility>
#include<queue>
#include<map>
using namespace std;

vector<vector<string>> storeOrentation;
enum {
    white=0,
    red=1,
    blue=2,
    green=3,
    yellow=4,
    orange=5
};
void swapp(string& s, int x,  int y) {
    int temp = s[x];
    s[x]=s[y];
    s[y]= temp;
    return;
}
pair<pair<vector<int>,vector<int>>,vector<string>> F(vector<string> input,vector<int> position, vector<int> orentationCubes){
    rotate(input.begin()+1,input.begin()-1,input.begin()+5);
    rotate(position.begin()+1,position.begin()+5,position.begin()+5);
    for(int i=1;i<=4;i++){
        swapp(input[i],0,1);
    }
    for(int i=1;i<=4;i++){
        orentationCubes[position[i]]=storeOrentation[position[i]][i].find(input[i]);
    }
    return make_pair(make_pair(position,orentationCubes),input);
}


void read_cube(vector<string>& arr){
    string s;
    // 'RBY','OWR',...... These types of input are required
    // loop will run 8 times because there are 8 cubies in the 2x2 rubix cube and we are taking the colors as input for each of these cubies.
    // Each cubie has exactly 3 colors and the order in which the inputs are required are "ABC" where A=Top/Bottom, B=Left/Right, C=Up/Down
    arr.push_back(0);
    for(int i=1;i<=8;i++){           
        cin>>s;
        arr.push_back(s);
    }
    return;
}
void orentation(vector<string> input,vector<vector<string>>& orent ){
    string s1,s2;
    vector<string> v;
    orent.push_back(v);
    for(int i=1;i<=8;i++){
        s1="";s2="";
        if((i==1)||(i==3)||(i==6)||(i==8)){
            s1=input[i];
            s2.append(1,s1[1]);s2.append(1,s1[0]);s2.append(1,s1[2]);
        }
        else{
            s2=input[i];
            s1.append(1,s2[1]);s1.append(1,s2[0]);s1.append(1,s2[2]);
        }
        s1=input[i];
        s2.append(1,s1[1]);s2.append(1,s1[0]);s2.append(1,s1[2]);
        v.clear();
        v.push_back(0);
        for(int j=1;j<=8;j++){
            if((j==1)||(j==3)||(j==6)||(j==8)){
                v.push_back(s1+s1);
            }
            else{
                v.push_back(s2+s2);
            }
        }
        orent.push_back(v);
    }
    return ;
}
constexpr int fact(int i)
{
    int p = 1;
    for (int j = 2; j <= i; ++j) {
        p *= j;
    }
    return p;
}
pair<int,int> ord(vector<int>& position,vector<int>& orentationCubes){
    int pos;int orent;
    int seen[9] = { 0 };
    int a = 0;
    int k = 7;
    for(int i=1;i<=8;i++){
        int v=position[i];
        int o=0;
        for(int j=1;j<v;j++){
            if(!seen[j]){o++;}
        }
        a+=o*fact(k);
        k--;
        seen[v]=1;
    }
    pos=a;
    int o=0;
    int j=0;
    for(int i=1;i<=8;i++){
        o+=orentationCubes[i]*pow(7,j);
        j++; 
    }
    orent=o;
    return make_pair(pos,orent);
}

vector<char> solve(vector<string>& input,vector<int>& position,vector<int>& orentationCubes){
    // cout<<"Hello"<<endl;
    map<pair<int,int>,string> visited;
    map<pair<int,int>,pair<int,int>> parent;
    int count=0;
    queue<vector<string>> q;             
    queue<pair<vector<int>,vector<int>>> q1;             
    q.push(input);
    q1.push(make_pair(position,orentationCubes));
    visited[ord(position,orentationCubes)] = "Starting";          //S means start
    int maxSize=0;
    vector<int> pos, orent;
    vector<string> u;
    while(!q.empty()){
        u=q.front();
        auto p=q1.front();
        pos=p.first;
        orent=p.second;
        // maxSize=(maxSize<q.size())? q.size():maxSize;
        q.pop();
        q1.pop();
        // if(checkvalid(u)){
        //     vector<char> moves;
        //     int o=ord(u);
        //     while(visited[o]!='S'){
        //         moves.push_back(visited[o]);
        //         o=parent[o];
        //     }
        //     std::reverse(moves.begin(), moves.end());
        //     print_board(u);
        //     cout<<"Size of queue "<<q.size();
        //     cout<<"\n The total boards added in queue "<<count;
        //     cout<<"Max size of cube is "<<maxSize<<endl;
        //     return moves;
        // }   

        vector<int> posF, posU, posR, posF1, posU1, posR1, posF2, posU2, posR2;
        vector<int> orentF, orentU, orentR, orentF1, orentU1, orentR1, orentF2, orentU2, orentR2;
        vector<string> inputF, inputU, inputR, inputF1, inputU1, inputR1, inputF2, inputU2, inputR2;
        auto p1=F(u,pos,orent);
        posF=p1.first.first;
        orentF=p1.first.second;
        inputF=p1.second;
        
    }
    vector<char> v;
    v.push_back(0);
    return v;
}
int main(){
    vector<string> input;
    
    read_cube(input);
    orentation(input,storeOrentation);
    vector<int> position={0,1,2,3,4,5,6,7,8};
    vector<int> orentationCubes={0,0,0,0,0,0,0,0,0};
    // auto move=solve
    return 0;
}
