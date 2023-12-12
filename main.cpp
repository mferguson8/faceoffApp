#include <iostream>
#include <string>
using namespace std;

class User
{
public:
    string team;
    int totalWins;
    int totalLosses;
    int gradYear;
    int age;
    int height;
private:
    string name;
    string username;
    string password;
};

void createAccount(User& user); // Function prototype
void login(User& user); // Function prototype
void displayAccount(User& user); // Function prototype
void calculateWinPercentage(User& user); // Function prototype

int main()
{
    User currentUser;
    int choice;
    bool loggedIn = false;

    cout << "Welcome to the Faceoff App!" << endl;
    cout << "Please choose an option:" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        loggedIn = true;
        createAccount(currentUser);
        displayAccount(currentUser);
    }
    else if (choice == 2)
    {
        loggedIn = true;
        login(currentUser);
        displayAccount(currentUser);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

void createAccount(User& user)
{
    cout << "Enter team: ";
    cin >> user.team;

    cout << "Enter current amount of wins: ";
    cin >> user.totalWins;

    cout << "Enter current amount of losses: ";
    cin >> user.totalLosses;

    cout << "Enter graduation year: ";
    cin >> user.gradYear;

    cout << "Enter age: ";
    cin >> user.age;

    cout << "Enter height: ";
    cin >> user.height;

    cout << "Enter name: ";
    cin >> user.name;

    cout << "Enter a username: ";
    cin >> user.username;

    cout << "Enter a password: ";
    cin >> user.password;
}

void login(User& user)
{
    string username;
    string password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (username == user.username && password == user.password)
    {
        cout << "Login successful!" << endl;
    }
    else
    {
        cout << "Login failed!" << endl;
    }
}

void homeScreen(User& user){
    int choice;

    cout << "Welcome to the Faceoff App!" << endl;
    cout << "Please choose an option:" << endl;
    cout << "1. View Stats" << endl;
    cout << "2. Calculate Win %" << endl;
    cout << "3. Update Stats" << endl;
    cout << "4. Add a Game" << endl;
    cin >> choice;

    if (choice == 1)
    {
        displayAccount(user);
    }
    else if (choice == 2)
    {
        calculateWinPercentage(user);
    }
    else if (choice == 3)
    {
        updateStats(user);
    }
    else if (choice == 4)
    {
        addGame(user);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
}

void displayAccount(User& user)
{
    cout << "Team: " << user.team << endl;
    cout << "Total Wins: " << user.totalWins << endl;
    cout << "Total Losses: " << user.totalLosses << endl;
    cout << "Graduation Year: " << user.gradYear << endl;
    cout << "Age: " << user.age << endl;
    cout << "Height: " << user.height << endl;
    cout << "Name: " << user.name << endl;
    cout << "Username: " << user.username << endl;
    cout << "Password: " << user.password << endl;
}

void calculateWinPercentage(User& user)
{
    double winPercentage = (double)user.totalWins / (user.totalWins + user.totalLosses);
    cout << "Win Percentage: " << winPercentage << endl;
}

class game(){
    public:
        string opponent;
        string location;
        int wins;
        int losses;
};

void makeGame(User& user, game& game){
    cout << "Enter opponent: ";
    cin >> game.opponent;

    cout << "Enter location: ";
    cin >> game.location;

    cout << "Enter wins: ";
    cin >> game.wins;

    cout << "Enter losses: ";
    cin >> game.losses;

    user.totalWins += game.wins;
    user.totalLosses += game.losses;

    double winPercentage = calculateWinPercentage(user);

    cout << "Game added!" << endl;
}