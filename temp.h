#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class temp{
    string ProductID, ProductName;
    int ProductQuantity, ProductPrice;
    fstream file, file1;
    string search;
    int quantity, ProductRate, TotalAmount;
    char ans;

    public :
        void AddProduct();
        void ViewProduct();
        void BuyProduct();
}obj;

void temp :: AddProduct(){
    cout << "Enter Product ID : ";
    cin >> ProductID;

    cout << "Enter Product Name : ";
    cin >> ProductName;

    cout << "Enter Product Quantity : ";
    cin >> ProductQuantity;

    cout << "Enter Product Price : ";
    cin >> ProductPrice;

    file.open("productdata.txt", ios :: out | ios :: app);
    file << ProductID << "\t" << ProductName << "\t" << ProductQuantity << "\t" << ProductPrice << endl;
    file.close();
}

void temp :: ViewProduct(){
    file.open("productdata.txt", ios :: in);
    file >> ProductID >> ProductName >> ProductQuantity >> ProductPrice;

    while(!file.eof()){
        cout << "-----------------------" << endl;
        cout << "Product ID\t\tProduct Name\t\tQuantity\t\tPrice" << endl;
        cout << ProductID << "\t\t\t" << ProductName << "\t\t\t" << ProductQuantity << "\t\t\t" << ProductPrice << endl;
        cout << "-----------------------" << endl;

        file >> ProductID >> ProductName >> ProductQuantity >> ProductPrice;
    }
    file.close();
}

void temp :: BuyProduct(){
    ans = 'y';

    while(ans == 'y'){
        file.open("productdata.txt", ios :: in);
        file1.open("makeshift.txt", ios :: out | ios :: app);
        file >> ProductID >> ProductName >> ProductQuantity >> ProductPrice;

        cout << "Enter Product ID : ";
        cin >> search;
        cout << "Enter Quantity : ";
        cin >> quantity;

        while(!file.eof()){
            if(ProductID == search){
                ProductQuantity = ProductQuantity - quantity;
                file1 << ProductID << "\t" << ProductName << "\t" << ProductQuantity << "\t" << ProductPrice << endl;

                ProductRate = quantity * ProductPrice;
                TotalAmount = TotalAmount + ProductRate;

                cout << "------ PAYMENT BILL ------" << endl;
                cout << "Total Price : " << TotalAmount << endl;
                cout << "--------------------------" << endl;
            } else {
                file1 << ProductID << "\t" << ProductName << "\t" << ProductQuantity << "\t" << ProductPrice << endl;
            }
            file >> ProductID >> ProductName >> ProductQuantity >> ProductPrice;
        }
        file.close();
        file1.close();
        remove("productdata.txt");
        rename("makeshift.txt", "productdata.txt");

        cout << "\n Continue Shopping ? (Y / N)";
        cin >> ans;

    }
}