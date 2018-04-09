#pragma once
#include "Horse.h"
#include <iostream>
#include <time.h> 
class Horse_Animator {

private:
	Horse *my_horse;
public:
	int old_tick;
	int current_tick;
	int flip_coin();
	Horse_Animator(Horse &horsie);
	void walko();
	Horse_Animator();
};