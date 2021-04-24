#include "Player_List.h"

std::vector<Player> Player_List::get_players() {
	return players;
}
//overloads the += opperator to then add players to the players vector
Player_List& operator += (Player_List& player_list, Player player) {
	//This loop will only push back values that both has a username and point value
	if (player.get_username() == "" || player.get_points() < 0) {
		exit;
	}
	else {
		player_list.players.push_back(player);
	}
	return player_list;
}
//overloads the [] opperator to allow us to index the players vector
Player& Player_List::operator[](int index) {
	return players[index];
}
//removes players from the vector
void Player_List::remove_player(int number) {
	players.erase(players.begin()+(number - 1));
}
//sorts the player list from most points to least points
void Player_List::sortbypoints() {
	sort(players.begin(), players.end(), [](Player a, Player b) {
		return a.get_points() > b.get_points();
		});
}