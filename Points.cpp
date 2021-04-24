#include "Points.h"

void Points::set_T1total_points(int T1_total_points) {
	this->T1_total_points = T1_total_points;
}
int Points::get_T1total_points() {
	return T1_total_points;
}
void Points::set_T2total_points(int T2_total_points) {
	this->T2_total_points = T2_total_points;
}
int Points::get_T2total_points() {
	return T2_total_points;
}

void Points::set_team1_win_odds(int T1_total_points, int T2_total_points) {
	double odds = 0.0;
	odds = float(T2_total_points) / float(T1_total_points);
	T1_win_points = odds * base_points;
	if (T1_win_points >= max_points_win) {
		T1_win_points = max_points_win;
	}
	else if (T1_win_points <= min_points_win) {
		T1_win_points = min_points_win;
	}
	this->T1_win_points = T1_win_points;
}

void Points::set_team1_lose_odds(int T1_total_points, int T2_total_points) {
	double odds = 0.0;
	odds =   float (T1_total_points) / float (T2_total_points);
	T1_lose_points = odds * base_points;
	if (T1_lose_points >= max_points_lose) {
		T1_lose_points = max_points_lose;
	}
	else if (T1_lose_points <= min_points_lose) {
		T1_lose_points = min_points_lose;
	}
	this->T1_lose_points = T1_lose_points;
}

void Points::set_team2_win_odds(int T2_total_points, int T1_total_points) {
	double odds = 0.0;
	odds = float (T1_total_points) / float (T2_total_points);
	T2_win_points = odds * base_points;
	if (T2_win_points >= max_points_win) {
		T2_win_points = max_points_win;
	}
	else if (T2_win_points <= min_points_win) {
		T2_win_points = min_points_win;
	}
	this->T2_win_points = T2_win_points;

}

void Points::set_team2_lose_odds(int T2_total_points, int T1_total_points) {
	double odds = 0.0;
	odds =   float (T2_total_points) / float (T1_total_points);
	T2_lose_points = odds * base_points;
	if (T2_lose_points >= max_points_lose) {
		T2_lose_points = max_points_lose;
	}
	else if (T2_lose_points <= min_points_lose) {
		T2_lose_points = min_points_lose;
	}
	this->T2_lose_points = T2_lose_points;
}


int Points::get_team1_win_odds() {
	return T1_win_points;
}


int Points::get_team1_lose_odds() {
	return T1_lose_points;

}

int Points::get_team2_win_odds() {
	return T2_win_points;
}

int Points::get_team2_lose_odds() {
	return T2_lose_points;
}
