#include "rogue.h"

	Room*
create_room(int x, int y, int height, int width)
{
	Room *new_room;
	new_room = malloc(sizeof(Room));

	new_room->position.x = x;
	new_room->position.y = y;
	new_room->height = height;
	new_room->width = width;

	new_room->doors = malloc(sizeof(Position)*4);

	/* top door */
	new_room->doors[0] = malloc(sizeof(Position));
	new_room->doors[0]->x = rand()%(width-2)+new_room->position.x+1;
	new_room->doors[0]->y = new_room->position.y;

	/* left door */
	new_room->doors[1] = malloc(sizeof(Position));
	new_room->doors[1]->x = new_room->position.x;
	new_room->doors[1]->y = rand()%(height-2)+new_room->position.y+1;

	/* bottom door */
	new_room->doors[2] = malloc(sizeof(Position));
	new_room->doors[2]->x = rand()%(width-2)+new_room->position.x+1;
	new_room->doors[2]->y = new_room->position.y+new_room->height-1;

	/* right door */
	new_room->doors[3] = malloc(sizeof(Position));
	new_room->doors[3]->x = new_room->position.x+width-1;
	new_room->doors[3]->y = rand()%(height-2)+new_room->position.y+1;

	return new_room;
}

	int
draw_room(Room *room)
{
	int x;
	int y;
	/* draw top and bottom */
	for(x = room->position.x; x < room->position.x+room->width; ++x)
	{
		mvprintw(room->position.y, x, "-"); /* top */
		mvprintw(room->position.y+room->height-1, x, "-"); /* bottom */
	}

	/* draw floors and side walls */
	for(y = room->position.y+1; y < room->position.y+room->height-1; ++y)
	{
		/* draw side walls */
		mvprintw(y, room->position.x, "|");
		mvprintw(y, room->position.x+room->width-1, "|");
		/* drawing floors */
		for(x = room->position.x+1; x < room->position.x+room->width-1; ++x)
			mvprintw(y, x, ".");
	}

	/* draw doors */
	mvprintw(room->doors[0]->y, room->doors[0]->x, "+");
	mvprintw(room->doors[1]->y, room->doors[1]->x, "+");
	mvprintw(room->doors[2]->y, room->doors[2]->x, "+");
	mvprintw(room->doors[3]->y, room->doors[3]->x, "+");

	return 1;
}

	int
connect_doors(Position *door_one, Position *door_two)
{
	Position temp;
	Position previous;

	int count = 0;

	temp.x = door_one->x;
	temp.y = door_one->y;

	previous = temp;

	while(1)
	{
		/* step left */
		if((abs((temp.x-1)-door_two->x) < abs(temp.x - door_two->x)) &&
				(mvinch(temp.y, temp.x-1) == ' '))
		{
			previous.x = temp.x;
			temp.x -= 1;
		}
		/* step right */
		else if((abs((temp.x+1)-door_two->x) < abs(temp.x - door_two->x)) &&
				(mvinch(temp.y, temp.x+1) == ' '))
		{
			previous.x = temp.x;
			temp.x += 1;
		}
		/* step down */
		else if((abs((temp.y+1)-door_two->y) < abs(temp.y - door_two->y)) &&
				(mvinch(temp.y+1, temp.x) == ' '))
		{
			previous.y = temp.y;
			temp.y += 1;
		}
		/* step up */
		else if((abs((temp.y-1)-door_two->y) < abs(temp.y - door_two->y)) &&
				(mvinch(temp.y-1, temp.x) == ' '))
		{
			previous.y = temp.y;
			temp.y -= 1;
		}
		else
		{
			if(count == 0)
			{
				temp = previous;
				++count;
				continue;
			}
			else
				return 0;
		}
		mvprintw(temp.y, temp.x, "#");
	}

	return 1;
}
