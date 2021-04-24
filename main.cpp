/* Nicholas Miller
* This program is my flex project!
* This programs is used to create a ranked play system that uses custom matches in call of duty
* This program will allow the user to add players to a list of players, remove players from a list of player
* create a match with a total of 8 players and then give each player xp based on the teams total xp
* this will then be saved in a txt file to allow the user to save the data for the username and ranks of each player
*/

#include "Player.h"
#include "Player_List.h"
#include "Points.h"
#include "Team.h"
#include "PlayerIO.h"
#include "Player_reader.h"
#include "Player_writer.h"

string filename = "Ranked_List.txt";

Player_List players = PlayerIO::read(filename);

void create_match();
void add_new_player();
void remove_player();
void view_players();

int main()
{
    int n;
    Player_Reader playerRead(filename);
    Player_Writer playerWrite(filename);
    PlayerIO update;
    cout << "Ranked Play by Nick Miller" << endl;
    playerRead.display_function();
    playerWrite.display_function();
    char command;

    do {
        cout << endl;
        cout << "COMMANDS" << endl;
        cout << "v - View list of players" << endl;
        cout << "a - Add a player to the list" << endl;
        cout << "r - Remove a player from the list" << endl;
        cout << "m - Create a Match" << endl;
        cout << "x - Exit (THIS IS A MUST TO UPDATE THE PLAYER LIST)" << endl;
        cout << endl << "command: ";
        cin >> command;
        switch (tolower(command))
        {
        case 'v':
            players.sortbypoints();
            view_players();
            break;
        case 'a':
            add_new_player();
            players.sortbypoints();
            break;
        case 'r':
            if (players.get_players().size() >= 1) {
                view_players();
                remove_player();
                players.sortbypoints();
            }
            else {
                cout << "There are no players to remove from the list" << endl;
            }
            break;
        case 'm':
            if (players.get_players().size() >= 8) {
                create_match();
            }
            else {
                cout << "Not enough players to create a match!" << endl << endl;
            }
            break;
        case'x':
            break;
        default:
            cout << "Please enter a valid command!" << endl << endl;
            break;
        }
    }   while (command != 'x');
    //sort the players from most points to least points
    players.sortbypoints();
    PlayerIO::write("Ranked_List.txt", players);
    update.display_funtion();
    cout << "Thanks for using Ranked Play!!" << endl;
    return 0;
}

void create_match() {
    int t_players = 0, num_players = 0;
    char player_add = 0;
    //creates the objects for team 1 and the first 4 players.
    Team team1;
    Player player1;
    Player player2;
    Player player3;
    Player player4;
    int number;
    int i = 0;
    int j = 0;
    //shows the user that they entered an invalid number
    cout << "Create Team 1" << endl;
    view_players();
    cout << "Select a number value for the player you would like to add to team 1 from the list (1 - " << players.get_players().size() << ") : ";
    cin >> number;
    if (number > players.get_players().size()) {
        cout << "INVALID CHOICE" << endl << endl;
    }
    else {
        //gives the player 1 object a set username and points then pushes onto the team 1 vector
        player1.set_username(players[number - 1].get_username());
        player1.set_points(players[number - 1].get_points());
        team1.team_1.push_back(player1);
        //removes the player from the list so they cant be used anymore
        players.remove_player(number);
        //view the players that are left in the players list vector
        view_players();
    }
    cout << "Select a number value for the player you would like to add to team 1 from the list (1 - " << players.get_players().size() << ") : ";
    cin >> number;
    if (number > players.get_players().size()) {
        cout << "INVALID CHOICE" << endl << endl;
    }
    else {
        //sets values for player 2
        player2.set_username(players[number - 1].get_username());
        player2.set_points(players[number - 1].get_points());
        team1.team_1.push_back(player2);
        players.remove_player(number);
        view_players();
    }
    cout << "Select a number value for the player you would like to add to team 1 from the list (1 - " << players.get_players().size() << ") : ";
    cin >> number;
    if (number > players.get_players().size()) {
        cout << "INVALID CHOICE" << endl << endl;
    }
    else {
        //sets values for player 3
        player3.set_username(players[number - 1].get_username());
        player3.set_points(players[number - 1].get_points());
        team1.team_1.push_back(player3);
        players.remove_player(number);
        view_players();
    }
    cout << "Select a number value for the player you would like to add to team 1 from the list (1 - " << players.get_players().size() << ") : ";
    cin >> number;
    if (number > players.get_players().size()) {
        cout << "INVALID CHOICE" << endl << endl;
    }
    else {
        //sets values for player 4 
        player4.set_username(players[number - 1].get_username());
        player4.set_points(players[number - 1].get_points());
        team1.team_1.push_back(player4);
        players.remove_player(number);
        view_players();
    }
    //creates a points object for team 1 so we are able to manipulate the value of the teams points
    Points team1_points;
    //displays the roster for team 1
    if (team1.team_1.size() == 4){
        cout << "---------------------" << endl;
        team1.display_team1();
    //adds all the team 1 players points and sets the points to team1_points
    team1_points.set_T1total_points(player1.get_points() + player2.get_points() + player3.get_points() + player4.get_points());
    cout << "Total Points: ";
    cout << team1_points.get_T1total_points() << endl;
    cout << "---------------------" << endl << endl;
    
    }
    else {
        cout << "------------------------------------------------------------------------" << endl;
        cout << "One of the players you selected for Team 1 was INVALID (not on the list)" << endl;
        cout << "------------------------------------------------------------------------" << endl << endl;
    }

    //Creates Team 2
    Team team2;
    Player player5;
    Player player6;
    Player player7;
    Player player8;

    cout << "Create Team 2" << endl;
    view_players();
    cout << "Select a number value for the player you would like to add to team 2 from the list (1 - " << players.get_players().size() << ") : ";
    cin >> number;
    if (number > players.get_players().size()) {
        cout << "INVALID CHOICE" << endl << endl;
    }
    else {
        //sets the values for player 5
        player5.set_username(players[number - 1].get_username());
        player5.set_points(players[number - 1].get_points());
        team2.team_2.push_back(player5);
        players.remove_player(number);
        view_players();
    }
    cout << "Select a number value for the player you would like to add to team 2 from the list (1 - " << players.get_players().size() << ") : ";
    cin >> number;
    if (number > players.get_players().size()) {
        cout << "INVALID CHOICE" << endl << endl;
    }
    else{
        //sets values for player 6
        player6.set_username(players[number - 1].get_username());
        player6.set_points(players[number - 1].get_points());
        team2.team_2.push_back(player6);
        players.remove_player(number);
        view_players();
    }

        cout << "Select a number value for the player you would like to add to team 2 from the list (1 - " << players.get_players().size() << ") : ";
        cin >> number;
        if (number > players.get_players().size()) {
            cout << "INVALID CHOICE" << endl << endl;
        }
        else {
            //sets values for player 7
            player7.set_username(players[number - 1].get_username());
            player7.set_points(players[number - 1].get_points());
            team2.team_2.push_back(player7);
            players.remove_player(number);
            view_players();
        }
        cout << "Select a number value for the player you would like to add to team 2 from the list (1 - " << players.get_players().size() << ") : ";
        cin >> number;
        if (number > players.get_players().size()) {
            cout << "INVALID CHOICE" << endl << endl;
        }
        else {
            //sets values for player 8
            player8.set_username(players[number - 1].get_username());
            player8.set_points(players[number - 1].get_points());
            team2.team_2.push_back(player8);
            players.remove_player(number);
            view_players();
        }
        //adds all the team 1 players points and sets the points to team1_points
        Points team2_points;
        
 
        if (team2.team_2.size() == 4) {
            cout << "---------------------" << endl;
            team2.display_team2();
            team2_points.set_T2total_points(player5.get_points() + player6.get_points() + player7.get_points() + player8.get_points());
            cout << "Total Points: ";
            cout << team2_points.get_T2total_points() << endl;
            cout << "---------------------" << endl << endl;
        }
        else {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "One of the players you selected for Team 2 was INVALID (not on the list)" << endl;
            cout << "------------------------------------------------------------------------" << endl << endl;
        }

        if (team1.team_1.size() + team2.team_2.size() == 8) {
            //creates a output showing the two teams and their odds of winning
            cout << left;
            cout << "------------------------------------------------" << endl;
            cout << setw(24) << "Team1" << setw(23) << "| Team2" << "|" << endl;
            cout << setw(16) << "Players" << setw(6) << "Points" << "\t" << setw(16) << "| Players" << setw(6) << "Points |" << endl;
            cout << "------------------------|----------------------|" << endl;

            //displays the players on the teams
            player1.display_player(), cout << "\t" << "| ", player5.display_player(), cout << " |" << endl;
            player2.display_player(), cout << "\t" << "| ", player6.display_player(), cout << " |" << endl;
            player3.display_player(), cout << "\t" << "| ", player7.display_player(), cout << " |" << endl;
            player4.display_player(), cout << "\t" << "| ", player8.display_player(), cout << " |" << endl;

            //calcuates the odd for the match.
            team1_points.set_team1_win_odds(team1_points.get_T1total_points(), team2_points.get_T2total_points());
            team2_points.set_team2_win_odds(team2_points.get_T2total_points(), team1_points.get_T1total_points());
            team1_points.set_team1_lose_odds(team1_points.get_T1total_points(), team2_points.get_T2total_points());
            team2_points.set_team2_lose_odds(team2_points.get_T2total_points(), team1_points.get_T1total_points());

            //displays the different points to win and points to lose values for both teams
            cout << left;
            cout << setw(16) << "PTS WIN: " << setw(8) << team1_points.get_team1_win_odds() << "| ";
            cout << setw(14) << "PTS WIN: " << setw(6) << team2_points.get_team2_win_odds() << " |" << endl;
            cout << setw(16) << "PTS LOSE: " << setw(8) << team1_points.get_team1_lose_odds() << "| ";
            cout << setw(14) << "PTS LOSE: " << setw(6) << team2_points.get_team2_lose_odds() << " |" << endl << endl;
            cout << "------------------------------------------------" << endl;

            //asks the user who won the match between the two teams
            char choice;
            cout << "Are these the correct teams?(y/n): ";
            cin >> choice;
            if (choice == 'y') {
                cout << "Who won Team 1 or Team 2 (1/2): ";
                int match_winnner;
                int winning_points = 0;
                int losing_points = 0;
                cin >> match_winnner;
                //team 1 wins the match
                if (match_winnner == 1) {
                    winning_points += team1_points.get_team1_win_odds();
                    losing_points += team2_points.get_team2_lose_odds();
                    //add or remove the points from the players on each team
                    player1.set_points(player1.get_points() + winning_points), player2.set_points(player2.get_points() + winning_points),
                    player3.set_points(player3.get_points() + winning_points), player4.set_points(player4.get_points() + winning_points);
                    //doesnt allow the player to lose more points then he has and if they lose it leaves them with 1 point
                    if (player5.get_points() < losing_points) {
                        player5.set_points(1);
                    }
                    else {
                        player5.set_points(player5.get_points() - losing_points);
                    }
                    if (player6.get_points() < losing_points) {
                        player6.set_points(1);
                    }
                    else {
                        player6.set_points(player6.get_points() - losing_points);
                    }
                    if (player7.get_points() < losing_points) {
                        player7.set_points(1);
                    }
                    else {
                        player7.set_points(player7.get_points() - losing_points);
                    }
                    if (player8.get_points() < losing_points) {
                        player8.set_points(1);
                    }
                    else {
                        player8.set_points(player8.get_points() - losing_points);
                    }
                    cout << "TEAM 1 HAS WON THE MATCH!! Points have been taken from team 2 and rewarded to team 1!" << endl << endl;
                }
                //team 2 wins the match
                else if (match_winnner == 2) {
                    winning_points += team2_points.get_team2_win_odds();
                    losing_points += team1_points.get_team1_lose_odds();
                    player5.set_points(player5.get_points() + winning_points), player6.set_points(player6.get_points() + winning_points),
                    player7.set_points(player7.get_points() + winning_points), player8.set_points(player8.get_points() + winning_points);
                    //doesnt allow the player to lose more points then he has and if they lose it leaves them with 1 point
                    if (player1.get_points() < losing_points) {
                        player1.set_points(1);
                    }
                    else {
                        player1.set_points(player1.get_points() - losing_points);
                    }
                    if (player2.get_points() < losing_points) {
                        player2.set_points(1);
                    }
                    else {
                        player2.set_points(player2.get_points() - losing_points);
                    }
                    if (player3.get_points() < losing_points) {
                        player3.set_points(1);
                    }
                    else {
                        player3.set_points(player3.get_points() - losing_points);
                    }
                    if (player4.get_points() < losing_points) {
                        player4.set_points(1);
                    }
                    else {
                        player4.set_points(player4.get_points() - losing_points);
                    }
                    cout << "TEAM 2 HAS WON THE MATCH!! Points have been taken from team 1 and rewarded to team 2!" << endl << endl;
                }
                else {
                    cout << "You did not select a correct team. The match was NOT played!!" << endl << endl;
                }
            }
            else {
                cout << "This match was not played!" << endl;
            }
        }
        else {
            cout << "There were not enough users to play this match!!" << endl << endl;
        }
            //adds the players back to the list with their updated values 
            players += player1, players += player2, players += player3, players += player4, players += player5, players += player6, players += player7, players += player8;
}




void add_new_player() {
    int starting_points = 200;
    Player player;
    string username;
    cout << "Username: ";
    cin.ignore();
    getline(cin, username);
    player.set_points(starting_points);
    player.set_username(username);
    players += player;
}

void remove_player() {
    int number;
    cout << "Select the person you would like to remove: " << "(1 - " << players.get_players().size() << ") : ";
    cin >> number;
    if (number <= players.get_players().size() && number != 0) {
        players.remove_player(number);
    }
    else {
        cout << "Invalid input please select a number between those values!" << endl;
    }
}

void view_players() {
    int n;
    n = 1;
    for (int i = 0; i < players.get_players().size(); i++) {
        cout << right << setw(3) << n << ". " << left << setw(12) << players[i].get_username() << "\t" << left << setw(8) << players[i].get_points() << endl;
        n++;
    }
    if (players.get_players().size() == 0) {
        cout << "There are no players! Start by adding a player to the list." << endl;
    }
    cout << endl;
}