#include "Room.h"
#include <iostream>

using namespace std;

void menu();
void look(Room* current_room);
void exits(Room* current_room);
void add(Room* current, vector<Room*>& allRooms);
void connect(Room* current, vector<Room*> allRooms);
void rename(Room* current);
void description(Room* current);
Direction char2Direction(char c); // convert a char value ('N','S','E','W')
                                  // to an enum value NORTH, SOUTH, etc

int main()
{
    // initialize
    Room* current_room = new Room();
    vector<Room*> allRooms;
    allRooms.push_back(current_room);

    char choice;

    // menu loop
    do
    {
        cout<<"Enter a command (? to list): ?"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 'n':
                if (current_room->north()!= NULL)
                    current_room = current_room->north();
                else
                    cout<<"You cannot go that way"<<endl;
                break;
            case 'e':
                if (current_room->east()!= NULL)
                    current_room = current_room->east();
                else
                    cout<<"You cannot go that way"<<endl;
                break;
            case 's':
                if (current_room->south()!= NULL)
                    current_room = current_room->south();
                else
                    cout<<"You cannot go that way"<<endl;
                break;
            case 'w':
                if (current_room->west()!= NULL)
                    current_room = current_room->west();
                else
                    cout<<"You cannot go that way"<<endl;
                break;
            case 'l':
                look(current_room); break;
            case 'x':
                exits(current_room);break;
            case 'c':
                connect(current_room, allRooms); break;
            case 'r':
                rename(current_room); break;
            case 'd':
                description(current_room); break;
            case 'a':
                add(current_room, allRooms); break;
            case '?':
                menu(); break;
            default:
                cout<<"invalid command"<<endl;
        }
    }while(choice != 'q');



    // cleanup before quitting

    return 0;
}

// Show the name and description of a room */
void look(Room* r)
{


}

// add a new room, connected to the current room
//  Parameters
//     current -- the current room we are in
//     allRooms-- a vector of pointers to (addresses of) all the rooms in the game
//  Precondition
//     current refers to an existing room
//  Postcondition
//    if possible (current must have a free exit)
//     a) a new room has been added off one of the exits of current
//     b) the address of the new room has also been added to the allRooms vector
void add(Room* current, vector<Room*>& allRooms)
{

}

// add a new connection between current room and an already existing room.
//  Parameters
//     current -- the current room we are in
//     allRooms-- a vector of pointers to (addresses of) all the rooms in the game
//  Precondition
//     current refers to an existing room
//  Postcondition
//    if possible (both rooms must have a spare exit to link them together)
//     current is now linked to another room in the game
//
void connect(Room* current, vector<Room*> allRooms)
{

}

// change the name of a room
void rename(Room* current)
{

}

// change the description of a room
void description(Room* current)
{
    string text;
    cout<<"Enter a new description for this room and hit <enter>"<<endl;
    cin.ignore(1,'\n');
    getline(cin,text);
    current->set_description(text);
}

// for each exit from room r,
//   show the name of the room it connects to
//   or say "Nothing" if the link is null
void exits(Room* r)
{


}
void menu()
{
    cout<<"Please choose from the following: "<<endl;
    cout<<"     n or north --- move north (if possible)"<<endl;
    cout<<"      e or east --- move east (if possible)"<<endl;
    cout<<"     s or south --- move south (if possible)"<<endl;
    cout<<"      w or west --- move at west (if possible)"<<endl;
    cout<<"      l or look --- look at room"<<endl;
    cout<<"     x or exits --- show room exits"<<endl;
    cout<<"   c or connect --- connect this room to another (already made) room"<<endl;
    cout<<"    r or rename --- rename this room"<<endl;
    cout<<"      d or desc --- change description for this room"<<endl;
    cout<<"       a or add --- add new room"<<endl;
    cout<<"      q or quit --- exit program"<<endl;
    cout<<"              ? --- show commands (DUH)"<<endl;
}


// convert a char direction: 'N','S','E','W'
// into a Direction enum: NORTH, SOUTH, EAST, WEST
Direction char2Direction(char c)
{
    switch(c)
    {
        case 'N': return NORTH;
        case 'S': return SOUTH;
        case 'E': return EAST;
        case 'W': return WEST;
        default: return NORTH;
    }
}
