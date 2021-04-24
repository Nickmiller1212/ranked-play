#ifndef PLAYERIO_H
#define PLAYERIO_H
/* This IO class inherits from the reader and writer class to allow this class to have the functions from the other class and work with those. */

#include "Player_reader.h"
#include "Player_writer.h"

class PlayerIO : public Player_Writer, public Player_Reader {
public:
	PlayerIO() {};
	virtual void display_funtion() {
		cout << "We have updated the data in the file" << endl << endl;
	}
};


#endif // PLAYERIO_H

