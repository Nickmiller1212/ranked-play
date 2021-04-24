#ifndef POINTS_H
#define POINTS_H
/* This is the points class where we can use these functions to manipulate the points object and points from the players. */

#include <iostream>
#include<cmath>

class Points {
private:
	int T1_total_points;
	int T2_total_points;
	int T1_win_points;
	int T1_lose_points;
	int T2_win_points;
	int T2_lose_points;
	int max_points_win = 50;
	int max_points_lose = 50;
	int min_points_win = 10;
	int min_points_lose = 10;
	double base_points = 20;
public:
	void set_T1total_points(int T1_total_points);
	int get_T1total_points();
	void set_T2total_points(int T2_total_points);
	int get_T2total_points();
	void set_team1_win_odds(int T1_total_points, int T2_total_points);
	void set_team1_lose_odds(int T1_total_points, int T2_total_points);
	void set_team2_win_odds(int T2_total_points, int T1_total_points);
	void set_team2_lose_odds(int T2_total_points, int T1_total_points);
	int get_team1_win_odds();
	int get_team2_win_odds();
	int get_team1_lose_odds();
	int get_team2_lose_odds();
};

#endif // POINTS_H


