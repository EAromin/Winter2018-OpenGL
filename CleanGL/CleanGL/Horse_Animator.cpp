#include "stdafx.h"
#include "Horse_Animator.h"

int Horse_Animator::flip_coin()
{
	int temp = rand() % 2;
	return temp;
}

Horse_Animator::Horse_Animator(Horse &horsie)
{
	my_horse = &horsie;
}

Horse_Animator::Horse_Animator()
{
}
