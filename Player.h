#ifndef PLAYER_H
#define PLAYER_H

/*This is the player class and will allow the user to create player objects that use username and points. */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Player {
private:
	std::string username;
	int points;
public:
	Player();
	std::string get_username();
	void set_username(string user_param);
	int get_points();
	void set_points(int points_param);
	void display_player();
	friend std::ostream& operator << (std::ostream&, Player&);
};

#endif // PLAYER_H

