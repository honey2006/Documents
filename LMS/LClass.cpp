#include <iostream>
using namespace std;

class Library
{
    class Book{};
    public:
        void test(){cout<<"Library is functioning"<<endl;}
        void options(){
            cout<<"Here are the options"<<endl;
            // login
        }
        void login(){} // differenr privileges
        void add_new_book(){}
        void return_a_book(){}
        void borrow_book(){} // title / no. acc to privileges
        void late_return(){}
        void damage_to_book(){}
        void book_listing(){} // filter
};