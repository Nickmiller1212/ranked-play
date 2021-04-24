#include "Player.h"

Player::Player() {}

std::string Player::get_username() {
	return username;
}
void Player::set_username(std::string username) {
	this->username = username;
}
int Player::get_points() {
	return points;
}
void Player::set_points(int points) {
	this->points = points;
}

void Player::display_player() {
	cout << setw(12) << get_username() << "\t" << setw(6) << get_points();
}

std::ostream& operator << (std::ostream& out, Player& player) {
	out << left << setw(12) << player.get_username() << '\t' << left << setw(8) << player.get_points();
	return out;
}

