#ifndef COMMANDS_H
#define COMMANDS_H

#include "robot.h"
#include<vector>
#include<string>

//Define all the functions in commands.cpp
void show(std::vector<robot> &r);
void travelled(std::vector<robot> v);
void within(std::vector<robot> &v, int n);
void turnLeft(std::vector<robot> &v, int n);
void turnRight(std::vector<robot> &v, int n);
void move(std::vector<robot> &v, int n);
std::vector<std::string> split(const std::string& s);

#endif