#include "Player_reader.h"
#include <sstream>
Player_Reader::Player_Reader() {}
Player_Reader::Player_Reader(string filename) {
	this->filename = filename;
}
//reads from the txt file and uses the += overloaded operator to add player to players
Player_List Player_Reader::read(string filename) {
	Player_List players;
	ifstream read_file(filename);
	string username;
	string s_points;
	int points;
	if (read_file.is_open()) {
		while (!read_file.eof()) {
			getline(read_file, username, '\t');
			//checks to see if there is already a player in the file.
			if (username != "") {
				getline(read_file, s_points, '\n');
				stringstream(s_points) >> points;
				Player player;
				player.set_username(username);
				player.set_points(points);
				//uses the overloaded +=
				players += player;
			}
		}
		read_file.close();
	}
	else {
		cout << "Unable to open file. Please check to see if there is a text file is Called Ranked_List.txt!" << endl;
		exit(1);
	}
	return players;
}
