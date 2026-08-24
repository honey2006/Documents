#include <iostream>
using namespace std;

#include "LClass.h"

int main()
{
    Library lib;
    cout<<"Library Management System Portal"<<endl;
    while(1)
    {
        cout<<"0 to display options "<<"-1 to quit"<<endl;
        
        int input;
        cin>>input;

        lib.test();

        switch(input)
        {
            case -1:
                exit(0);
                break;
            case 0:
                lib.options();
                break;
            default:
                cout<<"Illegal input, please try again"<<endl;
                break;
        }
    }
    return 0;
}