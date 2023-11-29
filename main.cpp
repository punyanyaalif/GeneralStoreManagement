#include <iostream>
#include "temp.h"

using namespace std;

int main(){
    int rep;

    cout << "\n\n\t\t...... General Store Menu ......";
    cout << "\n\n\t\t 1. Start Shopping\n";
    cout << "\n\n\t\t 2. Exit Menu\n";
    cout << "\n\n\t\t Choose number only : ";

    cin >> rep;

    switch(rep){
        case 0:
            obj.AddProduct();
        break;
        case 1:
            obj.ViewProduct();
            obj.BuyProduct();
        break;
        case 2:
            system("exit");
        break;
        default:
            cout << "Invalid input... Try again...";
    }
    return 0;
}