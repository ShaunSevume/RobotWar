#include "commands.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void show(vector<robot>& r) {
    for (auto& x : r) {
        cout << x.getNum() << ' ' << x.getTeam() << ' ' << x.getX() << ' ' << x.getY() << '\n';
    }
}

void travelled(vector<robot> v) {
    sort(v.begin(), v.end(), [](robot& r1, robot& r2) {return (r1.getDist() < r2.getDist());}); //stable_sort can be used to guarantee the preservation of the order, but it has a much larger time complexity.
    for (auto& x : v) {
        cout << x.getNum() << ' ' << x.getDist() << '\n';
    }
}

void within(vector<robot>& v, int n) {
    cout << count_if(v.begin(), v.end(), [n](robot& r) {return ((abs(r.getX()) + abs(r.getY())) <= n); }) << '\n'; //Prints out the robots that are within n steps of the origin. (Calculated by evaluating if the absolute value of their x and y co-ordinates are less than n).
}

void turnLeft(vector<robot>& v, int n) {
    for (auto& r : v) { //For each robot r in vector v, check if its number equals to n (which means the robot the command specifies exists).
        if (r.getNum() == n) {
            switch (r.getDir()) { //Get the direction the robot is currently facing and set it to the direction to the left.
            case 'N':
                r.setDir('W');
                break;
            case 'E':
                r.setDir('N');
                break;
            case 'S':
                r.setDir('E');
                break;
            case 'W':
                r.setDir('S');
                break;
            }
        }
    }
}

void turnRight(vector<robot>& v, int n) {
    for (auto& r : v) {
        if (r.getNum() == n) {
            switch (r.getDir()) { //Get the direction the robot is currently facing and set it to the direction to the right.
            case 'N':
                r.setDir('E');
                break;
            case 'E':
                r.setDir('S');
                break;
            case 'S':
                r.setDir('W');
                break;
            case 'W':
                r.setDir('N');
                break;
            }
        }
    }
}

void move(vector<robot>& v, int n) {
    pair<int, int> movePos; //A variable to store the  x and y position we want to move to.
    for (auto& r : v) {
        if (r.getNum() == n) {
            switch (r.getDir()) { //Get the direction the robot is currently facing and set it to the direction to the left.
            case 'N':
                movePos = make_pair(r.getX(), (r.getY() + 1));
                break;
            case 'E':
                movePos = make_pair((r.getX() + 1), r.getY());
                break;
            case 'S':
                movePos = make_pair(r.getX(), (r.getY() - 1));
                break;
            case 'W':
                movePos = make_pair((r.getX() - 1), r.getY());
                break;
            }

            auto x = find_if(v.begin(), v.end(), [&movePos](robot& r1) {return (movePos == r1.getPos());}); //Find out if there is a robot in the vector of robots that is at the position we are trying to move to.

            if (x != v.end()) { //If a robot was found at the position we are trying to move to 
                if (x->getTeam() != r.getTeam()) { //If the robot found at the position we are trying to move to is NOT on the same team as the robot we are trying to move...
                    r.setPos(movePos); //...and move our robot to where the one it just destroyed was.
                    r.upDist(); //Increases the distance travelled by 1.
                    v.erase(remove_if(v.begin(), v.end(), [&x](robot& r1) {return(r1.getNum() == x->getNum());}), v.end()); //...then remove it...
                }
                else {
                    //do nothing as the robots were on the same team and cannot be moved.
                }
            }
            else {
                r.setPos(movePos); //If there wasn't a robot found in the position we were trying to move to, then we can move our robot as intended.
                r.upDist(); //Increases the distance travelled by 1.
            }
            break; //Since only one robot can move at a time, once this block of code has run, the encasing for loop should stop so that it does not "try" to move the other robots and waste time.
        }
    }
}

vector<string> split(const string& s) {
    vector<string> v;
    auto space = [](char c) {return c == ' ';}; //A lambda function to define whether a character is a space or not.
    auto start = find_if_not(s.cbegin(), s.cend(), space);//Find the first non space.
    while (start != s.cend()) {//Check to see the end hasnt been reached
        auto end = find_if(start, s.cend(), space);//Find the next space.
        v.push_back(string(start, end));//Put the characters between the spaces into a string and push it onto the vector.
        start = find_if_not(end, s.cend(), space);//Find the next space.
    }
    return v;
}