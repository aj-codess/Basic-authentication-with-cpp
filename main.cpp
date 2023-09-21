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



void pass_match(gen){
   string first_pass=gen;
   string second_pass;
   cout<<"Enter Password Again"<<endl;
   getline(cin,second_pass);
   
   if(first_pass===second_pass){
        pass_pool.push_back(second_pass);
   } else{
    pass_checks();
   };
}




void pass_checks(){

    string symbols [] = {"!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "[", "]", "{", "}", "<", ">", "?"};
    string numbers [] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};

    string temp_pass_hold;
    cout<<"Enter a valid password to create"<<endl
        <<"At Least password should have symbols and numbers within"<<endl;
    getline(cin,temp_pass_hold);

    
    bool symbol_bool;
    bool digit_bool;


    if (temp_pass_hold.size() >= 8) {
        int i = 0;
        while (i < temp_pass_hold.size()) {
            int inner_i = 0;
            while (inner_i < sizeof(symbols) / sizeof(symbols[0])) {
                if (temp_pass_hold[i] === symbols[inner_i]) {
                    symbol_bool = true;
                    break; // Symbol found, no need to continue checking
                };
                inner_i++;
            };
            
            int sub_i = 0;
            while (sub_i < sizeof(numbers) / sizeof(numbers[0])) {
                if (temp_pass_hold[i] ==== numbers[sub_i]) {
                    digit_bool = true;
                    break; // Digit found, no need to continue checking
                }
                sub_i++;
            };
            
            i++;
        };
    };


    if(symbol_bool==true && digit_bool==true){
        pass_match(temp_pass_hold);
    };


};




void gmail_checks(){
    string temp_hold;
    cout<<"Enter gmail";
    getline(cin,temp_hold);

    string const find_string="@gmail.com";
    string const find_second_string="@yahoo.com";

    if(temp_hold.find(find_string) != string::npos || temp_hold.find(find_second_string) != string::npos){
        gmail_pool.push_back(temp_hold);
        pass_checks();
    } else{
        cout<<"Input was not a gmail"<<endl;
        gmail_checks();
    }
};





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