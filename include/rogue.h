#ifndef ROGUE_H /*if not defined ROGUE_H*/
#define ROGUE_H /*then define ROGUE_H*/

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

typedef struct Position
{
	int x;
	int y;
	// TILE_TYPE tile;
}Position;

typedef struct Room
{
	Position position;
	int height;
	int width;

	Position **doors;
	//    Monster **monsters;
	//    Item **items;
}Room;

typedef struct Player
{
	Position position;
	int health;
	// Room * room;
}Player;

int screen_set_up(void);

/* Level/Map functions */
Room **map_set_up(void);
char **save_level_pos(void);

/* Player functions */
Player *player_set_up(void);
Position *input_handler(int input, Player *player);
int player_move(Position *new_pos, Player *player, char **level);
int check_pos(Position *new_pos, Player *player, char **level);

/* Room functions */
Room *create_room(int y, int x, int height, int width);
int draw_room(Room *room);
int connect_doors(Position *door_one, Position *door_two);

#endif
