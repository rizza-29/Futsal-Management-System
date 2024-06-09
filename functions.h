#pragma once
#include"linkedlist.h"
#include<string>
#include<sstream>
using namespace std;
void user_sign_up(LinkedList<User> users) {
    User u;
    string name;
    int age;
    string password;
    string username;
    cout << "ENTER YOUR FULL NAME: " << endl;
    cin >> name;
    cout << "ENTER YOUR USERNAME: " << endl;
    cin >> username;
    cout << "CREATE NEW PASSWORD: " << endl;
    cin >> password;
    cout << "ENTER YOUR AGE: " << endl;
    cin >> age;
    u.set_name(name);
    u.set_UserName(username);
    u.set_Password(password);
    u.set_age(age);
    users.insertAtTail(u);
}
void admin_sign_up(LinkedList<admin> admins) {
    admin ad;
    string name;
    string u_name;
    int age;
    string password;
    string ID;
    cout << "ENTER YOUR FULL NAME: " << endl;
    cin >> name;
    cout << "ENTER YOUR USERNAME: " << endl;
    cin >> u_name;
    cout << "ENTER YOUR ID NAME: " << endl;
    cin >> ID;
    cout << "CREATE NEW PASSWORD: " << endl;
    cin >> password;
    cout << "ENTER YOUR AGE: " << endl;
    cin >> age;
    ad.set_name(name);
    ad.set_ID(ID);
    ad.set_Password(password);
    ad.set_UserName(u_name);
    admins.insertAtTail(ad);
}
void owner_sign_up(LinkedList<Owner> owners) {
    Owner CO;
    string name;
    string password;
    string Username, Contact_Num, court_name, court_location;
    cout << "ENTER YOUR FULL NAME: " << endl;
    cin >> name;
    cout << "ENTER YOUR USERNAME: " << endl;
    cin >> Username;
    cout << "CREATE NEW PASSWORD: " << endl;
    cin >> password;
    cout << "ENTER YOUR CONTACT NUMBER: " << endl;
    cin >> Contact_Num;
    cout << "ENTER YOUR COURT's NAME: " << endl;
    cin >> court_name;
    cout << "ENTER YOUR COURT's LOCATION: " << endl;
    cin >> court_location;
    CO.set_name(name);
    CO.set_username(Username);
    CO.set_Password(password);
    CO.set_ContactNum(Contact_Num);
    CO.set_court(court_name, court_location);
    owners.insertAtTail(CO);
}

User user_sign_in(LinkedList<User> users) {
    string u_name, pass;
    Nodelist<User>* temp = users.top;
    cout << "Enter Username:";
    cin >> u_name;
    while (temp != NULL) {
        if (temp->key.get_UserName() == u_name) {
            cout << "Welcome " << temp->key.get_name() << endl;
            cout << "Enter Password:";
            cin >> pass;
            int tries = 3;
            while (tries > 0) {
                if (temp->key.get_password() == pass) {
                    cout << "Login Successful." << endl;
                    return temp->key;
                }
                cout << "Incorrect Password(" << --tries << " tries left)" << endl;
                cout << "Enter again:";
                cin >> pass;
            }
            cout << "0 Tries left." << endl;
        }
    }
    cout << "Username does not exist." << endl;
}
admin admin_sign_in(LinkedList<admin> admins) {
    string u_name, pass;
    Nodelist<admin>* temp = admins.top;
    cout << "Enter Username:";
    cin >> u_name;
    while (temp != NULL) {
        if (temp->key.get_UserName() == u_name) {
            cout << "Welcome " << temp->key.get_name() << endl;
            cout << "Enter Password:";
            cin >> pass;
            int tries = 3;
            while (tries > 0) {
                if (temp->key.get_password() == pass) {
                    cout << "Login Successful." << endl;
                    return temp->key;
                }
                cout << "Incorrect Password(" << --tries << " tries left)" << endl;
                cout << "Enter again:";
                cin >> pass;
            }
            cout << "0 Tries left." << endl;
        }
    }
    cout << "Username does not exist." << endl;
}
Owner owner_sign_in(LinkedList<Owner> owners) {
    string u_name, pass;
    Nodelist<Owner>* temp = owners.top;
    cout << "Enter Username:";
    cin >> u_name;
    while (temp != NULL) {
        if (temp->key.get_username() == u_name) {
            cout << "Welcome " << temp->key.get_name() << endl;
            cout << "Enter Password:";
            cin >> pass;
            int tries = 3;
            while (tries > 0) {
                if (temp->key.get_password() == pass) {
                    cout << "Login Successful." << endl;
                    return temp->key;
                }
                cout << "Incorrect Password(" << --tries << " tries left)" << endl;
                cout << "Enter again:";
                cin >> pass;
            }
            cout << "0 Tries left." << endl;
        }
    }
    cout << "Username does not exist." << endl;
}
int user_options() {
    int opt;
    cout << "0-Go Back" << endl;
    cout << "1-Book Slot" << endl;
    cout << "2-Delete Slot" << endl;
    cout << "3-Change Profile Data" << endl;
    cout << "4-Display Profile" << endl;
    cout << "Enter option Number to proceed:";
    cin >> opt;
    if(opt>=1 &&opt<=4)
    return opt;
    else {
        cout << endl << "Invalid Number!Enter Again" << endl;
        return user_options();
    }
}
int admin_options() {
    int opt;
    cout << "0-Go Back" << endl;
    cout << "1-User Details" << endl;
    cout << "2-Court Details" << endl;
    cout << "3-Change Profile Data" << endl;
    cout << "4-Display Profile" << endl;
    cout << "Enter option Number to proceed:";
    cin >> opt;
    if (opt >= 1 && opt <= 4)
        return opt;
    else {
        cout << endl << "Invalid Number!Enter Again" << endl;
        return user_options();
    }
}
int owner_options() {
    int opt;
    cout << "0-Go Back" << endl;
    cout << "1-Check Bookings" << endl;
    cout << "2-Delete Booking" << endl;
    cout << "3-Change Owner Data" << endl;
    cout << "4-Change Court Data" << endl;
    cout << "5-Display Profile" << endl;
    cout << "Enter option Number to proceed:";
    cin >> opt;
    if (opt >= 1 && opt <= 4)
        return opt;
    else {
        cout << endl << "Invalid Number!Enter Again" << endl;
        return user_options();
    }
}
Owner display_courts(const LinkedList<Owner>& owners) {
    cout << "Courts:" << endl;
    Nodelist<Owner>* temp = owners.top;
    int i = 1;
    while (temp != NULL) {
        cout << i << "-" << temp->key.get_CourtName() << endl;
        temp = temp->next;
        i++;
    }
    int opt;
    do {
        cout << "Enter option number to proceed:";
        cin >> opt;
        if (opt > i || opt <= 0) {
            cout << "Invalid option!" << endl;
        }
    } while (opt > i || opt <= 0);
    int j = 1;
    temp = owners.top;
    for (j; j < opt && temp->next != NULL; j++) {
        temp = temp->next;
    }
    return temp->key;
}
int main_screen(){
    int opt;
    cout << "DO YOU WANT TO:" << endl;
    cout << "0-END PROGRAM" << endl;
    cout << "1-SIGN IN" << endl;
    cout << "2-SIGN UP" << endl;
    cout << "Enter option number:";
    cin >> opt;
    return opt;
}
int second_screen() {
    int opt;
    cout << "ARE YOU A:" << endl;
    cout << "0-GO BACK" << endl;
    cout << "1-USER" << endl;
    cout << "2-ADMIN" << endl;
    cout << "3-COURT_OWNER" << endl;
    cout << "Enter option number:";
    cin >> opt;
    return opt;

}