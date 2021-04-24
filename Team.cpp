#include "Team.h"

void Team::display_team1() {
	std::cout << "Team 1 Roster" << std::endl;
	for (int i = 0; i < team_1.size(); i++) {
		std::cout << setw(12) << team_1[i] << std::endl;
	}
}

void Team::display_team2() {
	std::cout << "Team 2 Roster" << std::endl;
	for (int i = 0; i < team_2.size(); i++) {
		std::cout << setw(12) << team_2[i] << std::endl;
	}
}
