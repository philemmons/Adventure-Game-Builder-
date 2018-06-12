// Room.cpp: implementation of the Room class.
//
//////////////////////////////////////////////////////////////////////

#include "Room.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Room::Room()
{
	name_ = "The void";
	description_ = "There is nothing but blackness in every direction.";
	int i;
	for(i = 0; i < 4; i++) // set all exits to "closed"
		exits_.push_back(NULL);
}

Room::Room(string name, string desc)
{
	name_ = name;
	description_ = desc;
	int i;
	for(i = 0; i < 4; i++) // set all exits to "closed"
		exits_.push_back(NULL);
}

Room::~Room()
{
	// make sure all exits to this room are
	// destroyed so that no one can try to enter
	// this room from another location
	if(exits_[NORTH] != NULL)
		disconnect(NORTH);
	if(exits_[EAST] != NULL)
		disconnect(EAST);
	if(exits_[SOUTH] != NULL)
		disconnect(SOUTH);
	if(exits_[WEST] != NULL)
		disconnect(WEST);
}

// --- inspectors ---
Room * Room::north() const
{
	return exits_[NORTH];
}

Room * Room::south() const
{
	return exits_[SOUTH];
}

Room * Room::east() const
{
	return exits_[EAST];
}

Room * Room::west() const
{
	return exits_[WEST];
}


string Room::name() const
{
	return name_;
}

string Room::description() const
{
	return description_;
}

// --- mutators ---
void Room::set_name(string n)
{
	name_ = n;
}

void Room::set_description(string d)
{
	description_ = d;
}

// --- facilitators ---
bool Room::connect(Direction exit, Room *r, Direction to)
{
	// check that both exits are free
	if (exits_[exit] != NULL or r->exits_[to] != NULL)
		return false;
	// make connection
	exits_[exit] = r;
	r->exits_[to] = this;
	return true;
}

// --- private methods ---

void Room::disconnect(Direction d)
{
	// disconnects ALL exits from another
	// room to this one.  It's sloppy, but
	// that's OK.
	Room * other_room;
	other_room = exits_[d];
	int i;
	for(i = 0; i < 4; i++)	{
		if (other_room->exits_[i] == this)
			other_room->exits_[i] = NULL;
	}
}

// --- operators ---

ostream & operator<<(ostream & out, const Room & r) {
	out << r.name() << endl;
	out << r.description() << endl;
	return out;
}

