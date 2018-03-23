#include "rogue.h"

/* Set up the screen so that it will play */
	int 
screen_set_up(void)
{
	initscr();
	noecho(); /* keeps players input from being output */
	refresh();

	srand(time(NULL)); /* chooses door location */

	return 1;
}

	int 
main(void)
{
	Player *player;
	int ch;
	Position *new_pos;

	char **level;

	screen_set_up();

	map_set_up();

	level = save_level_pos();

	player = player_set_up();

	/* main game loop */
	while((ch = getch()) != 'q')
	{
		new_pos = input_handler(ch, player);       
		check_pos(new_pos,player,level);
	}
	endwin();

	return 0;
}
