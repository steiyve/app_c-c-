#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool login(string userName, string password){
    string line;
    ifstream myfile ("var/login.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if (line == userName + " " + password)
            {
                cout << "Login successful!" << endl;
                myfile.close();
                return true;
            }
        }
        cout << "Login failed!" << endl;
        myfile.close();
        return false;
    }
    else 
    {
        cout << "Unable to open file"; 
        return false; // Add this line
    }
}