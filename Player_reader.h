#ifndef PLAYER_READER_H
#define PLAYER_READER_H
/* This is the player reader class that allows the user to read from a txt file and manipulate the input. */

#include "Player_List.h"
#include<fstream>
#include<string>

using namespace std;

class Player_Reader {
private:
	string filename;
public:
	Player_Reader();
	Player_Reader(string filename);
	static Player_List read(string filename);
	virtual void display_function() {
		cout << "This function is reading from " << filename << endl;
	}
};



#endif // PLAYER_READER_H

