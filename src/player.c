#include "rogue.h"

/* check what is at next position */
	int
check_pos(Position *new_pos, Player *player, char **level)
{
	int space;
	switch(mvinch(new_pos->y, new_pos->x))    
	{
		case '.':
		case '#':
		case '+':
			player_move(new_pos, player, level);
			break;
		default:
			move(player->position.y, player->position.x);
			break;
	}

	return 1;
}

	int 
player_move(Position *new_pos, Player *player, char **level)
{
	char buffer[8];

	sprintf(buffer, "%c", level[player->position.y][player->position.x]);
	mvprintw(player->position.y, player->position.x, buffer);

	player->position.y = new_pos->y;
	player->position.x = new_pos->x;

	mvprintw(player->position.y, player->position.x, "@");
	move(player->position.y, player->position.x);

	return 1;
}

/* Handles any input */
	Position * 
input_handler(int input, Player *player)
{
	Position *new_pos;
	new_pos = malloc(sizeof(Position));
	switch(input)
	{
		/* move down */
		case 'j':
		case 'J':
			new_pos->y = player->position.y+1;
			new_pos->x = player->position.x;
			break;

			/* move up */
		case 'k':
		case 'K':
			new_pos->y = player->position.y-1;
			new_pos->x = player->position.x;
			break;

			/* move left */
		case 'h':
		case 'H':
			new_pos->y = player->position.y;
			new_pos->x = player->position.x-1;
			break;


			/* move right */
		case 'l':
		case 'L':
			new_pos->y = player->position.y;
			new_pos->x = player->position.x+1;
			break;

		default:
			break;
	}

	return new_pos;
}

/* Add a player */
	Player* 
player_set_up(void)
{
	Player *new_player;
	new_player = malloc(sizeof(Player));

	new_player->position.x = 14;
	new_player->position.y = 14;
	new_player->health = 20;

	mvprintw(new_player->position.y,new_player->position.x, "@");
	move(new_player->position.y,new_player->position.x);

	return new_player;
}
