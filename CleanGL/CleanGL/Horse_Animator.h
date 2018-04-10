#pragma once
#include "Horse.h"
#include <iostream>
#include <time.h> 
class Horse_Animator {

private:
	Horse *my_horse;
	char state;
	int old_tick;
	int current_tick;
	int frame;
	int frame_stop;
public:
	static char possible_states[];


	int flip_coin();
	Horse_Animator(Horse &horsie, float angle);
	Horse_Animator();
	void walko();
	void stoppo();
	bool upright;
	void animation_loop();
	void stroll(int steps);
	void choose_direction(int howconfused);
};
