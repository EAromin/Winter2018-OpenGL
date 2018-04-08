#pragma once
#include "Horse.h"
#include <iostream>
#include <time.h> 
class Horse_Animator {

private:
	Horse *my_horse;
public:
	int flip_coin();
	Horse_Animator(Horse &horsie);
	Horse_Animator();
};