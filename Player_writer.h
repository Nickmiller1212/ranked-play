#ifndef PLAYER_WRITER_H
#define PLAYER_WRITER_H

/* This is the player writer class that allows the user to write to a txt file. */

#include "Player_List.h"
#include<fstream>
#include<string>

using namespace std;

class Player_Writer {
private:
	string filename;
public:
	Player_Writer();
	Player_Writer(string filename);
	static void write(string, Player_List);
	virtual void display_function() {
		cout << "This function is writing to " << filename << endl << endl;
	}
};

#endif // PLAYER_WRITER_H

