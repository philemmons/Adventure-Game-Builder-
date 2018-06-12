#include "Room.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Room* start = new Room("The Classroom", "A handful of students are nodding off as the lecturer drones on");
    Room* current = start;    // the address of the current room we are at


    Room* temp = new Room("The Lab","Computer geeks flood the terminals, hacking their way intoA long corridor with doors on either side");

    start->connect(EAST,temp,WEST); // if we travel east from start we will enter the Hallway

    current=current->east();  // travel east from current room to hallway

    cout<<current->name()<<": "<<current->description()<<endl;



    return 0;
}
