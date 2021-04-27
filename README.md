My task was to implement a robot war, in which a large number of robots, grouped into several teams, move around in 2-dimensional space. The program reads as input two files, start.txt and commands.txt, and produces output on the standard output. Several different input combinations have been provided as test cases for the program. These can be viewed in the "test cases" folder. To try these out, the relative txt files will have to be replaced before the program is run.

The initial state of the system is described by a file start.txt, each line of which will contain four numbers identifying a robot, its team, and its initial position, e.g.

1673 2 53 -89
This says that robot 1673 belongs to team 2 and starts with x-coordinate 53 and y-coordinate -89. Robots and teams are indentified by positive whole numbers; coordinates are also whole numbers, but may be negative. Each robot is specified only once, and each robot starts out in a different position.

At any time, each robot will be facing north, east, south or west. All robots start off facing north. I assume a conventional 2-dimensional space, so one step north from (53, -89) is (53, -88), while one step east would be (54, -89).

The program reads commands.txt, acting on each line as it is read. The lines have the following forms and meanings, where r stands for a robot number. If the named robot does not exist, the command is silently ignored.

show

The program prints to the standard output the current positions of all the robots still in the system, in the same format as start.txt above, but in ascending order of robot number.

travelled

Lists all the robots in the system, each with the total distance it has travelled. For example, if a robot has moved north 3 steps, east 1 step, and then south 2 steps, it has moved a total of 6 steps, even though it is only 2 positions from where it started.

Each line of the output consists of two numbers, the robot number and the distance travelled, and they are in increasing order of distance travelled. If two robots have travelled the same distance, they are ordered by robot number.

within n

Prints out the number of robots within n steps of the origin. (That is, the distance is n or less.) Distance here is the sum of the absolute values of the x- and y-coordinates (the Manhattan metric), so the distance to (2, -5) is 7.

turnleft r

Makes robot r turn to the left, e.g. if it is facing north, turn it to face west.

turnright r

Makes robot r turn to the right, e.g. if it is facing north, turn it to face east.

move r

Attempt to move robot r one step in the direction it is facing. If the target location is already occupied by a robot on the same team, no move is possible, and the robot stays where it was. If the target location is occupied by a robot of another team, that robot is removed from the system, after which our robot moves.
