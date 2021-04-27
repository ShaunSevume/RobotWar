#ifndef ROBOT_H
#define ROBOT_H

#include <string>

class robot {
	int num; //The robot number
	int team; //The robot team
	int dist; //The total distance the robot has travelled
	std::pair<int, int> pos; //The position of the robot as a pair.
	char dir; //Direction robot will be facing (N = North, E = East, S = South, W = West)

public:
	robot(int n, int t, int xp, int yp) : num(n), team(t) { dist = 0, pos = std::make_pair(xp, yp), dir = 'N'; } //Assigns all values passed in to this class' member values (attributes). Default direction is 'N' for North.
	const int getNum() const { return num; } //The FIRST const means that the value referenced will never change. The SECOND const is a promise for the member function to not change the value it returns. All the getter methods will keep the second promise, at least.
	const int getTeam() const { return team; }
	int getDist() const { return dist; }
	int getX() const { return pos.first; }
	int getY() const { return pos.second; }
	std::pair<int,int> getPos() const { return pos; }
	char getDir() const { return dir; }

	void upDist() { dist++; }
	void setPos(std::pair<int, int> p) { pos = std::make_pair(p.first, p.second); }
	void setDir(char c) { dir = c; }
};
#endif