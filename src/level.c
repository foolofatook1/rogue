#include "rogue.h"

/* Display the map */
	Room**
map_set_up(void)
{
	Room **rooms;
	rooms = malloc(sizeof(Room)*6);

	rooms[0] = create_room(13,13,6,8);
	draw_room(rooms[0]);

	rooms[1] = create_room(40,2,6,8);
	draw_room(rooms[1]);

	rooms[2] = create_room(40,10,6,12);
	draw_room(rooms[2]);

	connect_doors(rooms[0]->doors[3],rooms[2]->doors[1]);
	connect_doors(rooms[1]->doors[2],rooms[0]->doors[0]);

	return rooms;
}

	char **
save_level_pos(void)
{
	int x,y;
	char **positions;
	positions = malloc(sizeof(char *)*25);

	/* 25 is map size */
	for(y = 0; y < 25; ++y)
	{
		positions[y] = malloc(sizeof(char)*100);
		for(x = 0; x < 100; ++x)
		{
			positions[y][x] = mvinch(y,x);
		}
	}
	return positions;
}
