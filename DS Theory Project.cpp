#include<iostream>
#include"user.h"
#include"admin.h"
#include"court_admin.h"
#include"functions.h"
using namespace std;
int main() {
    LinkedList<User> users;
    LinkedList<Owner> owners;
    LinkedList<admin> admins;
    int opt,opt2,opt3,opt4;
    do {
        opt = main_screen();
        system("cls");
        if (opt == 2) {
            do {
                opt2 = second_screen();
                system("cls");
                if (opt2 == 1)
                    user_sign_up(users);
                else if (opt2 == 2)
                    admin_sign_up(admins);
                else if (opt2 == 3)
                    owner_sign_up(owners);
                else if (opt != 0)
                    cout << "INVALID OPTION!" << endl;
            } while (opt2 != 0);
        }
        else if (opt == 1) {
            opt2 = second_screen();
            system("cls");
            do {
                if (opt2 == 1) {
                    User u = user_sign_in(users);
                    do {
                        opt3 = user_options();
                        system("cls");
                        if (opt3 == 1) {
                            Owner temp = display_courts(owners);
                            temp.booking();
                        }
                        else if (opt3 == 2) {
                            Owner temp = display_courts(owners);
                            temp.delete_booking();
                        }
                        else if (opt3 == 3) {
                            u.update_profile();
                        }
                        else if (opt3 == 4) {
                            u.display_profile();
                        }
                        else if (opt3 != 0)
                            cout << "INVALID OPTION!" << endl;
                    } while (opt3 != 0);
                }
                else if (opt2 == 2) {
                    admin a = admin_sign_in(admins);
                    do {
                        opt3 = admin_options();
                        system("cls");
                        if (opt3 == 1) {
                            a.user_detail(users);
                        }
                        else if (opt3 == 2) {
                            a.court_detail(owners);
                        }
                        else if (opt3 == 3) {
                            a.update_profile();
                        }
                        else if (opt3 == 4) {
                            a.display_profile();
                        }
                        else if (opt3 != 0)
                            cout << "INVALID OPTION!" << endl;
                    } while (opt3 != 0);
                }
                else if (opt2 == 3) {
                    Owner o = owner_sign_in(owners);
                    do {
                        opt3 = owner_options();
                        system("cls");
                        if (opt3 == 1) {
                            o.display_b();
                        }
                        else if (opt3 == 2) {
                            Owner temp = display_courts(owners);
                            temp.delete_booking();
                        }
                        else if (opt3 == 3) {
                            o.update_profile();
                        }
                        else if (opt3 == 4) {
                            o.update_CourtDetails();
                        }
                        else if (opt3 == 5) {
                            o.display_profile();
                        }
                        else if (opt3 != 0)
                            cout << "INVALID OPTION!" << endl;
                    } while (opt3 != 0);
                }
                else if (opt2 != 0) {
                    cout << "INVALID OPTION!" << endl;
                }
            } while (opt2 != 0);
        }
        else if (opt != 0)
            cout << "INVALID OPTION!" << endl;
    } while (opt != 0);
}
