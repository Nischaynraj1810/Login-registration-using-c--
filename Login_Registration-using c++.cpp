#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool login();
void registration();

int main() {
    int choice;
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registration();
            break;
        case 2:
            if (login()) {
                cout << "Login successful!\n";
            } else {
                cout << "Login failed! Check your credentials.\n";
            }
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
    }
    return 0;
}

void registration() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file;
    file.open("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

bool login() {
    string username, password, user, pass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    while (file >> user >> pass) {
        if (user == username && pass == password) {
            return true;
        }
    }
    return false;
}
