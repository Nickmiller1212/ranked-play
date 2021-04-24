#include "Player_writer.h"

Player_Writer::Player_Writer() {}
Player_Writer::Player_Writer(string filename) {
	this->filename = filename;
}
void Player_Writer::write(string filename, Player_List players) {
	ofstream write_file(filename);
	for (int i = 0; i < players.get_players().size(); i++) {
		if (i == 0) {
			//uses the overloaded <<
			write_file << players[i];
		}
		else {
			write_file << endl << players[i];
		}
	}
	
}