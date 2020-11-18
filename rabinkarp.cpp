#include<iostream>
using namespace std;

int main(){
    string source,key;
    cout<<"Enter Source String :";
    cin>>source;
    cout<<"Enter Key to be Searched :";
    cin>>key;
    int source_hash=0;
    int key_hash=0;
    int key_length = key.length();
    int Start,End,found[100]={0},counter=0;
    for(int i=0;i<key_length;i++){
        key_hash+=(int)key[i];
    }
    key_hash%=13;

    for(Start=0,End=Start+key_length;End!=source.length()+1;Start++,End++){
        int i,j=0;
        source_hash=0;
        for(i=Start,j=0;j!=key_length;i++,j++){
            source_hash+=(int)source[i];
        }
    source_hash%=13;
        if(source_hash==key_hash){
            for(i=Start,j=0;j!=key_length;i++,j++){
                if(source[i]!=key[j])
                    break;
                if(j==key_length-1){
                    found[i-key_length+1]=1;
                    counter++;
                }
            }
        }
    }
    cout<<endl<<"Total "<<counter<<" matches Found at Index :";
        for(int i=0;i<100;i++){
            if(found[i]==1){
                cout<<i<<" ";
        }
    }
}
