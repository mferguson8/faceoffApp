#include <iostream>
#include <string>
#include <vector>
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
    string name;
    string username;
    string password;
};

class Game {
public:
    string yourTeam;
    string opponent;
    string location;
    string time;
    int wins;
    int losses;
};

void createAccount(User& user); // Function prototype
void login(User& user); // Function prototype
void displayAccount(User& user); // Function prototype
void calculateWinPercentage(User& user); // Function prototype
void makeGame(User& user, vector<Game>& games); // Function prototype
void viewAllGames(const vector<Game>& games); // Function prototype

int main()
{
    User user;
    vector<Game> games;

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
        createAccount(user);
        displayAccount(user);
    }
    else if (choice == 2)
    {
        loggedIn = true;
        login(user);
        displayAccount(user);
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    while (loggedIn)
    {
        cout << "Please choose an option:" << endl;
        cout << "1. View Stats" << endl;
        cout << "2. Calculate Win %" << endl;
        cout << "3. Make a Game" << endl;
        cout << "4. View All Games" << endl;
        cout << "5. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

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
            makeGame(user, games);
        }
        else if (choice == 4)
        {
            viewAllGames(games);
        }
        else if (choice == 5)
        {
            loggedIn = false;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
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

void displayAccount(User& user)
{
    cout << "Username: " << user.username << endl;
    cout << "Team: " << user.team << endl;
    cout << "Total Wins: " << user.totalWins << endl;
    cout << "Total Losses: " << user.totalLosses << endl;
    cout << "Graduation Year: " << user.gradYear << endl;
    cout << "Age: " << user.age << endl;
    cout << "Height: " << user.height << endl;
    cout << "Name: " << user.name << endl;
    
}

void calculateWinPercentage(User& user)
{
    double winPercentage = (double)user.totalWins / (user.totalWins + user.totalLosses);
    cout << "Win Percentage: " << winPercentage*100 << "%" << endl;
}

void makeGame(User& user, vector<Game>& games)
{
    Game game;
    int choice;
    string endGame;

    cout << "Would you like to simulate a game, or enter a complete game?" << endl;
    cout << "1. Simulate" << endl;
    cout << "2. Enter complete game" << endl;
    cin >> choice;

    if(choice == 1){
        cout << "Enter your team: ";
        cin >> game.yourTeam;

        cout << "Enter opponent: ";
        cin >> game.opponent;

        cout << "Enter location: ";
        cin >> game.location;

        cout << "Enter time: ";
        cin >> game.time;

        while(endGame != "q"){
            cout << "Enter q to quit: ";
            cin >> endGame;
            if(endGame == "q"){
                break;
            }
            else{
                cout << "Enter 1 for a faceoff win, 2 for a loss: ";
                cin >> choice;
                if(choice == 1){
                    game.wins++;
                }
                else if(choice == 2){
                    game.losses++;
                }
                else{
                    cout << "Invalid choice!" << endl;
                }
            }
        }

    }
    if(choice == 2){
        cout << "Enter your team: ";
        cin >> game.yourTeam;

        cout << "Enter opponent: ";
        cin >> game.opponent;

        cout << "Enter location: ";
        cin >> game.location;

        cout << "Enter time: ";
        cin >> game.time;

        cout << "Enter wins: ";
        cin >> game.wins;

        cout << "Enter losses: ";
        cin >> game.losses;
    }
    
    user.totalWins += game.wins;
    user.totalLosses += game.losses;

    games.push_back(game);

    cout << "Game added!" << endl;
}

void viewAllGames(const vector<Game>& games)
{
    for (const auto& game : games)
    {
        cout << "Your Team: " << game.yourTeam << endl;
        cout << "Opponent: " << game.opponent << endl;
        cout << "Location: " << game.location << endl;
        cout << "Time: " << game.time << endl;
        cout << "Wins: " << game.wins << endl;
        cout << "Losses: " << game.losses << endl;
        cout << endl;
    }
}
