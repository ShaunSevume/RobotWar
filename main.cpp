#include "robot.h"
#include "commands.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<robot> robots; //A vector of robots to keep track of the ones that are created.
	
    ifstream f; //The first file to be opened
    int n, t, xp, yp; //The four variables that will be used as paramaters for each robot created. (name, team, x position, y position).
	f.open("start.txt"); //Opens "start.txt"
    while (f >> n >> t >> xp >> yp) //Reads the file line by line
    {
        robots.push_back(robot(n,t,xp,yp)); //Will create a robot using the deatails on each line.
    }
    f.close(); //Closes "start.txt" after we are done reading it.
    sort(robots.begin(), robots.end(), [](robot& r1, robot& r2) {return (r1.getNum() < r2.getNum());}); //Sorts the robots by their number size

    ifstream f2; //The second file to be opened
    string line; //The line to be read
    f2.open("commands.txt"); //Opens "commands.txt"
    if (f2.is_open()) {
        while (getline(f2, line)) { //Gets the current line from the open file
            auto v = split(line); //Splits it by spaces into a vector of strings.
            //Determine which function to call based on the value of the first element in the vector, which will be the command.
            //If the function requires a robot number, it will be passed in as the second element of the vector.
            if (v[0] == "show") {
                show(robots);
            }
            else if (v[0] == "travelled") {
                travelled(robots);
            }
            else if (v[0] == "within") {
                within(robots, stoi(v[1]));
            }
            else if (v[0] == "turnleft") {
                turnLeft(robots, stoi(v[1]));
            }
            else if (v[0] == "turnright") {
                turnRight(robots, stoi(v[1]));
            }
            else if (v[0] == "move") {
                move(robots, stoi(v[1]));
            }
        }
    }
    f2.close(); //Closes "commands.txt" after we are done reading it.
	return 0;
}