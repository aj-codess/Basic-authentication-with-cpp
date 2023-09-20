#include <iostream>
#include <vector>

using namespace std;

vector<string>gmail_pool;

void password_dataBase(){

}

void existance(){
    gmail_pool.push_back("jagyei339@gmail.com");
    string temp;
    cout<<"Enter gmail"<<endl;
    getline(cin,temp);
    vector<string>::size_type num=0;
    while(num<gmail_pool.size()){
        if(temp==gmail_pool[num]){
            cout<<"Access granted"<<endl;
        } else{
            cout<<"access denied"<<endl;
        }
        num++;
    };
};

void gmail_checks(){

};

void pass_req(){

};

void pass_match(){

}

int main(){
    string options;
    cout<<"Login / SignUp"<<endl;
    getline(cin,options);
    if(options=="Login" || options=="login"){
        existance();
    } else{
        
    }

return 0;
};