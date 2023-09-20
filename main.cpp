#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string>gmail_pool;
vector<string>pass_pool;





void existance(){
    
    string temp;
    cout<<"Enter gmail"<<endl;
    getline(cin,temp);

    string pass_temp;
    cout<<"Enter Password"<<endl;
    getline(cin,pass_temp);

    vector<string>::size_type num=0;
    while(num<gmail_pool.size()){
        if(temp==gmail_pool[num]){
            vector<string>::size_type num2=0;
            while(num2<pass_pool.size()){
                if(pass_temp==pass_pool[num2]){
                    cout<<"Data Secured in DataBase"<<endl
                        <<"Access Granted"<<endl;
                }
                num2++;
            }
        } else{
            cout<<"your initials doesnt exist"<<endl<<"Try Loging in Again"<<endl;
        }
        num++;
    };
};





void pass_checks(){

    char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '[', ']', '{', '}', '<', '>', '?'};

    string temp_pass_hold;
    cout<<"Enter a valid password to create"<<endl;
    getline(cin,temp_pass_hold);
    

};





void gmail_checks(){
    string temp_hold;
    cout<<"Enter gmail";
    getline(cin,temp_hold);

    string const find_string="@gmail.com";
    string const find_second_string="@yahoo.com";

    if(temp_hold.find(find_string) != string::npos || temp_hold.find(find_second_string) != string::npos){
        pass_checks();
    } else{
        cout<<"Input was not a gmail"<<endl;
        gmail_checks();
    }
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
        gmail_checks();
    }

return 0;
};