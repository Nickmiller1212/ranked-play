#ifndef TEAM_H
#define TEAM_H
/* This is the team class where we can create vectors of the 2 teams and manipulate what we would like to do with those vectors. */

#include"Player.h"
#include"Player_List.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Team {
private:
public:
	std::vector<Player> team_1;
	std::vector<Player> team_2;
	void display_team1();
	void display_team2();
};

#endif //TEAM_H

