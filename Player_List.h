#ifndef PLAYER_LIST_H
#define PLAYER_LIST_H
/* This is the player list class that will allow the user to create a list of player objects and manipulate and get the list. */

#include<vector>
#include<algorithm>
#include "Player.h"

using namespace std;


class Player_List {
private:
	vector<Player> players;
public:
	vector<Player> get_players();
	void display_players();
	void remove_player(int);
	friend Player_List& operator += (Player_List&, Player);
	Player& operator[](int);
	void sortbypoints();
};

#endif // PLAYER_LIST
