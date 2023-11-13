#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<cmath>
#include<string>
#include <utility>
#include<queue>
#include "HashMap.hpp"
using namespace std;

vector<vector<string>> storeOrentation;
void swapp(string& s, int x,  int y) {
    int temp = s[x];
    s[x]=s[y];
    s[y]= temp;
    return;
}

pair<pair<vector<int>,vector<int>>,vector<string>> F(vector<string> input,vector<int> position, vector<int> orentationCubes){
    // Modifying input string
    string one,two,three,four;
    one=input[1];two=input[2];three=input[3];
    input[1]=input[4];
    input[2]=one;
    input[3]=two;
    input[4]=three;
    
    int onee,twoo,threee;
    onee=position[1];twoo=position[2];threee=position[3];
    position[1]=position[4];
    position[2]=onee;
    position[3]=twoo;
    position[4]=threee;
    
    for(int i=1;i<=4;i++){
        swapp(input[i],0,1);
    }
    for(int i=1;i<=4;i++){
        orentationCubes[position[i]]=storeOrentation[position[i]][i].find(input[i]);
    }
    return make_pair(make_pair(position,orentationCubes),input);
}

pair<pair<vector<int>,vector<int>>,vector<string>> U(vector<string> input,vector<int> position, vector<int> orentationCubes){
    // Modifying input string
    string one,two,three,four;
    one=input[1];two=input[2];three=input[5];
    input[2]=input[6];
    input[1]=two;
    input[5]=one;
    input[6]=three;
    
    int onee,twoo,threee;
    onee=position[1];twoo=position[2];threee=position[5];
    position[2]=position[6];
    position[1]=twoo;
    position[5]=onee;
    position[6]=threee;
    
    for(int i=1;i<=6;i++){
        swapp(input[i],1,2);
        if(i==2){i=4;}
    }
    for(int i=1;i<=6;i++){
        orentationCubes[position[i]]=storeOrentation[position[i]][i].find(input[i]);
        if(i==2){i=4;}
    }
    return make_pair(make_pair(position,orentationCubes),input);
}

pair<pair<vector<int>,vector<int>>,vector<string>> R(vector<string> input,vector<int> position, vector<int> orentationCubes){
    // Modifying input string
    string one,two,three,four;
    one=input[2];two=input[3];three=input[6];
    input[3]=input[7];
    input[2]=two;
    input[6]=one;
    input[7]=three;
    int onee,twoo,threee;
    onee=position[2];twoo=position[3];threee=position[6];
    position[3]=position[7];
    position[2]=twoo;
    position[6]=onee;
    position[7]=threee;
    for(int i=2;i<=7;i++){
        swapp(input[i],0,2);
        if(i==3){i=5;}
    }
    for(int i=2;i<=7;i++){
        orentationCubes[position[i]]=storeOrentation[position[i]][i].find(input[i]);
        if(i==3){i=5;}
    }
    return make_pair(make_pair(position,orentationCubes),input);
}

pair<pair<vector<int>,vector<int>>,vector<string>> F1(vector<string> input,vector<int> position, vector<int> orentationCubes){
    // Modifying input string
    string one,two,three,four;
    one=input[1];two=input[2];three=input[3];
    input[3]=input[4];
    input[4]=one;
    input[1]=two;
    input[2]=three;
    
    int onee,twoo,threee;
    onee=position[1];twoo=position[2];threee=position[3];
    position[3]=position[4];
    position[4]=onee;
    position[1]=twoo;
    position[2]=threee;
    
    for(int i=1;i<=4;i++){
        swapp(input[i],0,1);
    }
    for(int i=1;i<=4;i++){
        orentationCubes[position[i]]=storeOrentation[position[i]][i].find(input[i]);
    }
    return make_pair(make_pair(position,orentationCubes),input);
}

pair<pair<vector<int>,vector<int>>,vector<string>> U1(vector<string> input,vector<int> position, vector<int> orentationCubes){
    // Modifying input string
    string one,two,three,four;
    one=input[1];two=input[2];three=input[5];
    input[5]=input[6];
    input[6]=two;
    input[2]=one;
    input[1]=three;
    
    int onee,twoo,threee;
    onee=position[1];twoo=position[2];threee=position[5];
    position[5]=position[6];
    position[6]=twoo;
    position[2]=onee;
    position[1]=threee;
    
    for(int i=1;i<=6;i++){
        swapp(input[i],1,2);
        if(i==2){i=4;}
    }
    for(int i=1;i<=6;i++){
        orentationCubes[position[i]]=storeOrentation[position[i]][i].find(input[i]);
        if(i==2){i=4;}
    }
    return make_pair(make_pair(position,orentationCubes),input);
}

pair<pair<vector<int>,vector<int>>,vector<string>> R1(vector<string> input,vector<int> position, vector<int> orentationCubes){
    // Modifying input string
    string one,two,three,four;
    one=input[2];two=input[3];three=input[6];
    input[6]=input[7];
    input[7]=two;
    input[3]=one;
    input[2]=three;
    
    int onee,twoo,threee;
    onee=position[2];twoo=position[3];threee=position[6];
    position[6]=position[7];
    position[7]=twoo;
    position[3]=onee;
    position[2]=threee;
    
    for(int i=2;i<=7;i++){
        swapp(input[i],0,2);
        if(i==3){i=5;}
    }
    for(int i=2;i<=7;i++){
        orentationCubes[position[i]]=storeOrentation[position[i]][i].find(input[i]);
        if(i==3){i=5;}
    }
    return make_pair(make_pair(position,orentationCubes),input);
}

pair<pair<vector<int>,vector<int>>,vector<string>> F2(vector<string> input,vector<int> position, vector<int> orentationCubes){
    // Modifying input string
    string one,two,three,four;
    one=input[1];two=input[2];three=input[3];
    input[2]=input[4];
    input[3]=one;
    input[4]=two;
    input[1]=three;
    
    int onee,twoo,threee;
    onee=position[1];twoo=position[2];threee=position[3];
    position[2]=position[4];
    position[3]=onee;
    position[4]=twoo;
    position[1]=threee;
    
    for(int i=1;i<=4;i++){
        orentationCubes[position[i]]=storeOrentation[position[i]][i].find(input[i]);
    }
    return make_pair(make_pair(position,orentationCubes),input);
}

pair<pair<vector<int>,vector<int>>,vector<string>> U2(vector<string> input,vector<int> position, vector<int> orentationCubes){
    // Modifying input string
    string one,two,three,four;
    one=input[1];two=input[2];three=input[5];
    input[1]=input[6];
    input[5]=two;
    input[6]=one;
    input[2]=three;
    
    int onee,twoo,threee;
    onee=position[1];twoo=position[2];threee=position[5];
    position[1]=position[6];
    position[5]=twoo;
    position[6]=onee;
    position[2]=threee;
    
    for(int i=1;i<=6;i++){
        orentationCubes[position[i]]=storeOrentation[position[i]][i].find(input[i]);
        if(i==2){i=4;}
    }
    return make_pair(make_pair(position,orentationCubes),input);
}

pair<pair<vector<int>,vector<int>>,vector<string>> R2(vector<string> input,vector<int> position, vector<int> orentationCubes){
    // Modifying input string
    string one,two,three,four;
    one=input[2];two=input[3];three=input[6];
    input[2]=input[7];
    input[6]=two;
    input[7]=one;
    input[3]=three;
    
    int onee,twoo,threee;
    onee=position[2];twoo=position[3];threee=position[6];
    position[2]=position[7];
    position[6]=twoo;
    position[7]=onee;
    position[3]=threee;
    
    for(int i=2;i<=7;i++){
        orentationCubes[position[i]]=storeOrentation[position[i]][i].find(input[i]);
        if(i==3){i=5;}
    }
    return make_pair(make_pair(position,orentationCubes),input);
}

bool checkvalid(vector<string> input){
    if(!((input[1][2]==input[2][2])&&(input[2][2]==input[3][2])&&(input[4][2]==input[3][2]))){  //Front face
        return false;
    }
    if(!((input[5][2]==input[6][2])&&(input[6][2]==input[7][2])&&(input[7][2]==input[8][2]))){  //Back Face
        return false;
    }
    if(!((input[2][1]==input[3][1])&&(input[3][1]==input[6][1])&&(input[6][1]==input[7][1]))){  //Right face
        return false;
    }
    if(!((input[1][1]==input[4][1])&&(input[4][1]==input[8][1])&&(input[8][1]==input[5][1]))){  //Left face
        return false;
    }
    if(!((input[1][0]==input[2][0])&&(input[2][0]==input[5][0])&&(input[5][0]==input[6][0]))){  //Top face
        return false;
    }
    if(!((input[3][0]==input[4][0])&&(input[4][0]==input[8][0])&&(input[8][0]==input[7][0]))){  //Bottom face  //Top face
        return false;
    }
    return true;
}

string swapnewString(string s, int x,  int y) {
    string s1=s;
    auto temp = s1[x];
    s1[x]=s1[y];
    s1[y]= temp;
    return s1;
}

void orentation(vector<string> input,vector<vector<string>>& orent ){
    string s1,s2;
    vector<string> v;
    v.push_back("");
    orent.push_back(v);
    v.clear();
    for(int i=1;i<=8;i++){
        s1="";s2="";
        if((i==1)||(i==3)||(i==6)||(i==8)){
            s1=input[i];
            s2=swapnewString(s1,0,1);
          
        }
        else{
            s2=input[i];
            s1=swapnewString(s2,0,1);
         
        }
       
        v.clear();
        v.push_back("");
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

vector<string> solve(vector<string>& input,vector<int>& position,vector<int>& orentationCubes){
   
    auto visited=empty<pair<vector<int>,vector<int>>,string>();
    auto parent=empty<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>();
    
    // map<pair<int,int>,string,pair_hash> visited;
    // map<pair<int,int>,pair<int,int>,pair_hash> parent;

    queue<vector<string>> q;             
    queue<pair<vector<int>,vector<int>>> q1; 
                
    q.push(input);
    q1.push(make_pair(position,orentationCubes));
    insert<pair<vector<int>,vector<int>>,string>(visited,make_pair(position,orentationCubes),"Starting");
   

    vector<int> pos, orent;
    vector<string> u;

    while(!q.empty()){

        u=q.front();
        auto p=q1.front();
        pos=p.first;
        orent=p.second;

        q.pop();
        q1.pop();
        if(checkvalid(u)){
            vector<string> moves;
            while(lookup<pair<vector<int>,vector<int>>,string>(visited,make_pair(pos,orent))!="Starting"){
                moves.push_back(lookup<pair<vector<int>,vector<int>>,string>(visited,make_pair(pos,orent)));
                auto p=lookup<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>(parent,make_pair(pos,orent));
                pos=p.first;
                orent=p.second;
            }
            std::reverse(moves.begin(), moves.end());
            return moves;
        }   

        vector<int> posF, posU, posR, posF1, posU1, posR1, posF2, posU2, posR2;
        vector<int> orentF, orentU, orentR, orentF1, orentU1, orentR1, orentF2, orentU2, orentR2;
        vector<string> inputF, inputU, inputR, inputF1, inputU1, inputR1, inputF2, inputU2, inputR2;
        
        auto p1=F(u,pos,orent);
        posF=p1.first.first;
        orentF=p1.first.second;
        inputF=p1.second;
        if(!member<pair<vector<int>,vector<int>>,string>(visited, make_pair(posF,orentF))){
            insert<pair<vector<int>,vector<int>>,string>(visited,make_pair(posF,orentF),"F");
            insert<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>(parent,make_pair(posF,orentF),make_pair(pos,orent));
            q.push(inputF);
            q1.push(make_pair(posF,orentF));
        }
       
        auto p2=U(u,pos,orent);
        posF=p2.first.first;
        orentF=p2.first.second;
        inputF=p2.second;
        if(!member<pair<vector<int>,vector<int>>,string>(visited, make_pair(posF,orentF))){
            insert<pair<vector<int>,vector<int>>,string>(visited,make_pair(posF,orentF),"U");
            insert<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>(parent,make_pair(posF,orentF),make_pair(pos,orent));
            q.push(inputF);
            q1.push(make_pair(posF,orentF));
        }

        auto p3=R(u,pos,orent);
        posF=p3.first.first;
        orentF=p3.first.second;
        inputF=p3.second;
        if(!member<pair<vector<int>,vector<int>>,string>(visited, make_pair(posF,orentF))){
            insert<pair<vector<int>,vector<int>>,string>(visited,make_pair(posF,orentF),"R");
            insert<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>(parent,make_pair(posF,orentF),make_pair(pos,orent));
            q.push(inputF);
            q1.push(make_pair(posF,orentF));
        }
        
        auto p4=F1(u,pos,orent);
        posF=p4.first.first;
        orentF=p4.first.second;
        inputF=p4.second;
        if(!member<pair<vector<int>,vector<int>>,string>(visited, make_pair(posF,orentF))){
            insert<pair<vector<int>,vector<int>>,string>(visited,make_pair(posF,orentF),"F1");
            insert<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>(parent,make_pair(posF,orentF),make_pair(pos,orent));
            q.push(inputF);
            q1.push(make_pair(posF,orentF));
        }

        auto p5=U1(u,pos,orent);
        posF=p5.first.first;
        orentF=p5.first.second;
        inputF=p5.second;
        if(!member<pair<vector<int>,vector<int>>,string>(visited, make_pair(posF,orentF))){
            insert<pair<vector<int>,vector<int>>,string>(visited,make_pair(posF,orentF),"U1");
            insert<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>(parent,make_pair(posF,orentF),make_pair(pos,orent));
            q.push(inputF);
            q1.push(make_pair(posF,orentF));
        }

        auto p6=R1(u,pos,orent);
        posF=p6.first.first;
        orentF=p6.first.second;
        inputF=p6.second;
        if(!member<pair<vector<int>,vector<int>>,string>(visited, make_pair(posF,orentF))){
            insert<pair<vector<int>,vector<int>>,string>(visited,make_pair(posF,orentF),"R1");
            insert<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>(parent,make_pair(posF,orentF),make_pair(pos,orent));
            q.push(inputF);
            q1.push(make_pair(posF,orentF));
        }

        auto p7=F2(u,pos,orent);
        posF=p7.first.first;
        orentF=p7.first.second;
        inputF=p7.second;
        if(!member<pair<vector<int>,vector<int>>,string>(visited, make_pair(posF,orentF))){
            insert<pair<vector<int>,vector<int>>,string>(visited,make_pair(posF,orentF),"F2");
            insert<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>(parent,make_pair(posF,orentF),make_pair(pos,orent));
            q.push(inputF);
            q1.push(make_pair(posF,orentF));
        }

        auto p8=U2(u,pos,orent);
        posF=p8.first.first;
        orentF=p8.first.second;
        inputF=p8.second;
        if(!member<pair<vector<int>,vector<int>>,string>(visited, make_pair(posF,orentF))){
            insert<pair<vector<int>,vector<int>>,string>(visited,make_pair(posF,orentF),"U2");
            insert<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>(parent,make_pair(posF,orentF),make_pair(pos,orent));
            q.push(inputF);
            q1.push(make_pair(posF,orentF));
        }

        auto p9=R2(u,pos,orent);
        posF=p9.first.first;
        orentF=p9.first.second;
        inputF=p9.second;
        if(!member<pair<vector<int>,vector<int>>,string>(visited, make_pair(posF,orentF))){
            insert<pair<vector<int>,vector<int>>,string>(visited,make_pair(posF,orentF),"R2");
            insert<pair<vector<int>,vector<int>>,pair<vector<int>,vector<int>>>(parent,make_pair(posF,orentF),make_pair(pos,orent));
            q.push(inputF);
            q1.push(make_pair(posF,orentF));
        }
        
    }
    vector<string> v;
    v.push_back(0);
    return v;
}

void read_cube(vector<string>& arr){
    string s;
    // 'RBY','OWR',...... These types of input are required
    // loop will run 8 times because there are 8 cubies in the 2x2 rubix cube and we are taking the colors as input for each of these cubies.
    // Each cubie has exactly 3 colors and the order in which the inputs are required are "ABC" where A=Top/Bottom, B=Left/Right, C=Up/Down
    cout<<"Enter the input cube\n"<<endl;
    arr.push_back("");
    for(int i=1;i<=8;i++){           
        cin>>s;
        arr.push_back(s);
    }
    return;
}
// YRB YGB OGB ORB GYW GOW ROW RYW
// WRB YBO WOG OGY YRB YRG BWO WGR

int main(){
    vector<string> input;
    
    read_cube(input);
    orentation(input,storeOrentation);
    // for(auto i: storeOrentation){
    //     for(auto j: i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> position={0,1,2,3,4,5,6,7,8};
    vector<int> orentationCubes={0,0,0,0,0,0,0,0,0};

    auto move=solve(input,position, orentationCubes);
    cout<<"Total umber of moves required are "<<move.size()<<endl;
    for(auto i: move){
        cout<<i<<" ";
    }
    return 0;
}
