#include <iostream>
#include<fstream>

using namespace std;

struct mail
{
    char userName[50];
    char passWord[50];
    void reg(int);

}obj[5];

void mail::reg(int k) {
    int i = k;
    cout << "PLEASE ENTER USERNAME:\t\n";
    cin >> userName;
    cout << "PLEASE ENTER PASSWORD:\t\n";
    cin >> passWord;

    ofstream outputFile;
    outputFile.open("C:\\Users\\paulw\\projects\\registration-system\\registration.txt", ios::app | ios::binary);
    if (!outputFile)
    {
        cout << "SORRY WE CANNOT OPEN FILE\n";
    }
    else {
        cout << "\n";
    }
    outputFile.write((char*)&obj[i], sizeof(mail));
    outputFile.close();

}



int main() {

    int t;
    cout << "\nEnter Registration Details for User 1 :: \n";
    obj[0].reg(0);
    cout << "\nEnter Registration Details for User 2 :: \n";
    obj[1].reg(1);
    cout << "\nEnter Registration Details for User 3 :: \n";
    obj[2].reg(2);

    mail obj2;

    

    ifstream fileIn;

    // For the file to read properly please add your own file path below 
    fileIn.open("C:\\Users\\paulw\\projects\\registration-system\\registration.txt", ios::app | ios::binary);
    if (!fileIn)
    {
        cout << "\nUnable to open file to read\n";
    }
    else
    {
        cout << "\nRegistered Details of All Users :: \n";
        fileIn.read((char*)&obj2, sizeof(obj2));
        while (fileIn)
        {
            cout << "\nUsername :: " << obj2.userName << "\nPasswword :: " << obj2.passWord << "\n";
            fileIn.read((char*)&obj2, sizeof(obj2));
        }
        fileIn.close();
    }

    return(0);
}