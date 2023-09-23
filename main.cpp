#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <array>
#include <fstream>

using namespace std;

vector<string> gmail_pool;
vector<string> pass_pool;

void login_logic(){
    string temp_gmail;
    string temp_pass;
    cout<<"------------Enter Gmail-------------"<<endl;
    getline(cin,temp_gmail);
    cout<<"------------Enter Password----------"<<endl;
    getline(cin,temp_pass);

    bool gmail_bool = false;
    bool password_bool = false;

    int get_gmail_v_size=gmail_pool.size();
    int get_pass_v_size=pass_pool.size();

    for(int i=0; i < get_gmail_v_size; i++){
        if(temp_gmail == gmail_pool[i]){
            gmail_bool = true;
            break;
        }
    }

    for(int ii=0; ii < get_pass_v_size ; ii++){
        if(temp_pass == pass_pool[ii]){
            password_bool=true;
            break;
        }
    }

    if(gmail_bool && password_bool){
        cout<<"--------successfully Logged In------------"<<endl;
    } else{
        cout<<"---------Wrong Login Details--------------"<<endl;
    }

}

void pass_match(string old_pass){
    string new_pass;
    cout<<"-------------Enter Password Again-------------"<<endl;
    getline(cin,new_pass);

    if(old_pass==new_pass){
        pass_pool.push_back(new_pass);
        cout<<"have successfuly signed up"<<endl;
    } else{
        cout<<"password doesnt match"<<endl;
    }
}

// Function to check if a password meets criteria and add it to the password pool
void pass_checks(string temp_pass_hold) {
    array<char,17> symbols = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '[', ']', '{', '}', '<', '>', '?'};
    array<char,11> numbers = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

    int get_symbol_length = sizeof(symbols) / sizeof(symbols[0]);;
    int get_numbers_length = sizeof(numbers) / sizeof(numbers[0]);

    bool symbol_bool = false;
    bool digit_bool = false;

    int pass_size=temp_pass_hold.size();

    if (temp_pass_hold.length() >= 8) {
        for (int i = 0; i < pass_size ; i++) {

            char target=temp_pass_hold[i];

            for (int sub_1=0; sub_1 < get_symbol_length; sub_1++) {
                if (target == symbols[sub_1]) {
                    symbol_bool = true;
                    break; // Symbol found
                }
            }
            for (int sub_2 = 0; sub_2 < get_numbers_length; sub_2++) {
                if (target==numbers[sub_2]) {
                    digit_bool = true;
                    break; // Digit found
                }
            }
        }
    }

    if (symbol_bool && digit_bool) {
        pass_pool.push_back(temp_pass_hold);
        cout << "Password meets criteria......" << endl<<"Comparing....."<<endl;
        pass_match(temp_pass_hold);
    } else {
        cout << "Password does not meet criteria. Try again." << endl;
    };
};

// Function to check if a Gmail address is valid and add it to the Gmail pool
void gmail_checks() {
    string user_name;
    cout<<"------------------Enter Username---------------"<<endl;
    getline(cin,user_name);

    string temp_hold;
    cout << "------------Enter Gmail address: -------------"<<endl;
    getline(cin, temp_hold);

    string const find_string = "@gmail.com";
    string const find_second_string = "@yahoo.com";

    if (temp_hold.find(find_string) != string::npos || temp_hold.find(find_second_string) != string::npos) {
        gmail_pool.push_back(temp_hold);
        string temp_pass_hold;
        cout << "Enter a valid password to create an account: "<<endl
                <<"Password show contain at least a symbol and a number"<<endl;
        getline(cin, temp_pass_hold);
        pass_checks(temp_pass_hold);
    } else {
        cout << "Input was not a Gmail or Yahoo address." << endl;
        gmail_checks();
    }
}

int main() {
    string options;
    cout << "------------------Login / SignUp------------------" << endl;
    getline(cin, options);

    if (options == "Login" || options == "login") {
        login_logic();
    } else if (options == "SignUp" || options == "signup") {
        gmail_checks();
    } else {
        cout << "---------------Invalid option.---------------" << endl;
    }

    return 0;
};