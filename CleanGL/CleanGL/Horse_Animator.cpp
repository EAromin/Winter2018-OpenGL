#include "stdafx.h"
#include "Horse_Animator.h"
#include "Bounding_Sphere.h"
char Horse_Animator::possible_states[] = { '@',//default
's',//stroll
'c',//choose direction
'e', //eat
};
int Horse_Animator::flip_coin()
{
	int temp = rand() % 2;
	return temp;
}

void Horse_Animator::eat() {
	current_tick = ((int)(glfwGetTime() * 10)) % 10;
	if (current_tick != old_tick) {
		frame++;
		old_tick = current_tick;
	
		if (frame < 47) {
			switch (frame) {
			case 1: case 46: {
				my_horse->neckrot.y = 0;
				my_horse->headrot.y = 0;
				my_horse->ulfl.y = 0;
				my_horse->urfl.y = 0;
				my_horse->ulhl.y = 0;
				my_horse->urhl.y = 0;
				my_horse->llfl.y = 0;
				my_horse->lrfl.y = 0;
				my_horse->llhl.y = 0;
				my_horse->lrhl.y = 0;
				break;
				}
			case 2: case 45: {
				my_horse->neckrot.y = 5;

				break;
			}
			case 3: case 44: {
				my_horse->neckrot.y = 15;
				break;

			}
			case 4: case 43: {
				my_horse->neckrot.y = 30;
				break;

			}
			case 5: case 42: {
				my_horse->neckrot.y = 50;
				break;
			}
			case 6: case 41: {
				my_horse->neckrot.y = 60;
				my_horse->headrot.y = -10;
				break;
			}
			case 7: case 40:{
				my_horse->neckrot.y = 75;
				my_horse->headrot.y = -20;
				break;
			}
			case 8: case 15:case 16: case 23: 
			case 24: case 31: case 32: case 39:{
				my_horse->neckrot.y = 85;
				my_horse->headrot.y = -25;
				break;
			}
			case 9: case 14: case 17: case 22: 
			case 25: case 30: case 33: case 38:{

				my_horse->neckrot.y = 90;
				my_horse->headrot.y = -40;
				break;
			}
			case 10: case 13:case 18: case 21:
			case 26: case 29: case 34: case 37:{
				my_horse->neckrot.y = 87;
				my_horse->headrot.y = -30;
				break;
			}
			case 11: case 12: case 19: case 20: 
			case 27: case 28: case 35: case 36: {
				my_horse->neckrot.y = 90;
				my_horse->headrot.y = -20;
				break;

			}
			}
		}
		else {
			frame = -1;
			state = '@';
		}
	
	}
}
void Horse_Animator::walk() {
	looper = (((int)(glfwGetTime() * 20)) % 15) + 1;
	switch (looper) {

	case 1: {


		my_horse->neckrot.y = 0;
		my_horse->headrot.y = 0;
		my_horse->ulfl.y = 0;
		my_horse->ulhl.y = 0;
		my_horse->llfl.y = 0;
		my_horse->lrfl.y = 0;
		my_horse->llhl.y = 0;
		my_horse->lrhl.y = 0;

		my_horse->urhl.y = my_horse->ulfl.y = -30;

		break;
	}
	case 2: {
		my_horse->neckrot.y = 5;
		my_horse->headrot.y = 10;
		my_horse->urhl.y = my_horse->ulfl.y = -21.4f;
		my_horse->ulhl.y =my_horse->urfl.y = -10;
		my_horse->llhl.y = my_horse->lrfl.y = 10;
		break;
	}case 3: {


		my_horse->urhl.y = my_horse->ulfl.y = -12.8f;

		my_horse->ulhl.y = my_horse->urfl.y = -20;
		my_horse->llhl.y = my_horse->lrfl.y = 20;
		break;
	}
	case 4: {		my_horse->urhl.y = my_horse->ulfl.y = -4.2f;

		my_horse->neckrot.y = 0;

		my_horse->ulhl.y = my_horse->urfl.y = -30;
		my_horse->llhl.y = my_horse->lrfl.y = 40;
		break;
	}
	case 5: {
	

		my_horse->headrot.y = 0;
		my_horse->urhl.y = my_horse->ulfl.y = 0.f;

		my_horse->llhl.y = my_horse->lrfl.y = 30;

		break;

	}
	case 6: {
	

		my_horse->neckrot.y = 5;

		my_horse->llhl.y = my_horse->lrfl.y = 20;
		break;
	}
	case 7: {

		my_horse->llhl.y = my_horse->lrfl.y = 10;
		break;
	}
	case 8: {


		my_horse->headrot.y = 10;

		my_horse->neckrot.y = 0;
		my_horse->llhl.y = my_horse->lrfl.y = 0;
		break;
	}
	case 9: {
	

		my_horse->neckrot.y = 5;
		my_horse->ulhl.y = my_horse->urfl.y = -21.4f;

		my_horse->urhl.y = my_horse->ulfl.y = -10;
		my_horse->lrhl.y = my_horse->llfl.y = 10;
		break;
	}case 10: {
		my_horse->ulhl.y = my_horse->urfl.y = -12.8f;

		my_horse->urhl.y = my_horse->ulfl.y = -20;
		my_horse->lrhl.y = my_horse->llfl.y = 20;
		break;
	}
	case 11: {	
	
		my_horse->headrot.y = 0;
		my_horse->neckrot.y = 0;

		my_horse->urhl.y = my_horse->ulfl.y = -30;
		my_horse->lrhl.y = my_horse->llfl.y = 40;
		break;
	}
	case 12: {
		my_horse->ulhl.y = my_horse->urfl.y = 0.f;

		my_horse->lrhl.y = my_horse->llfl.y = 30;

		break;

	}
	case 13: {

		my_horse->neckrot.y = 5;
		my_horse->lrhl.y = my_horse->llfl.y = 20;
		break;
	}
	case 14: {
		my_horse->lrhl.y = my_horse->llfl.y = 10;
		break;
	}
	case 15: {
	
		my_horse->headrot.y = 10;

		my_horse->neckrot.y = 0;
		my_horse->lrhl.y = my_horse->llfl.y = 0;


		break;
	}
			 

	}
}
Horse_Animator::Horse_Animator(Horse &horsie, float angle)
{
	my_horse = &horsie;
	old_tick = 0;
	current_tick = 0;
	frame = 0;
	frame_stop = 0;
	upright = false;
	state = '@';
	my_horse->rotation = glm::rotate(my_horse->rotation, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
}

Horse_Animator::Horse_Animator()
{
	old_tick = 0;
	current_tick = 0;
	frame = 0;
	frame_stop = 0;
	upright = false;
	state = '@';

}
void Horse_Animator::stoppo() {
	if (upright)
	{
		my_horse->rotation = glm::translate(my_horse->rotation, my_horse->movement_log + glm::vec3(0.f, 1.3f, 0));
		my_horse->rotation *= glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		my_horse->rotation = glm::translate(my_horse->rotation, -(my_horse->movement_log + glm::vec3(0.f, 1.3f, 0)));

		my_horse->neckrot.y = 0;
		my_horse->headrot.y = 0;
		my_horse->ulfl.y = 0;
		my_horse->urfl.y = 0;
		my_horse->ulhl.y = 0;
		my_horse->urhl.y = 0;
		my_horse->llfl.y = 0;
		my_horse->lrfl.y = 0;
		my_horse->llhl.y = 0;
		my_horse->lrhl.y = 0;
		upright = false;
	}
}
void Horse_Animator::animation_loop() {


	if (state == '@') {
		state = Horse_Animator::possible_states[(rand() % 3) + 1];
		frame_stop = (rand() % 10) + 5;
	}
	else {
		switch (state) {
		case 's':
			walk();
			stroll(frame_stop);
			break;
		case 'c':
			choose_direction(frame_stop);
			break;
		case 'e':
			eat();
			break;
		}
	}

}
void Horse_Animator::stroll(int steps) {
	current_tick = ((int)(glfwGetTime() * 4)) % 10;
	if (current_tick != old_tick) {
		frame++;
		old_tick = current_tick;

		if (frame < steps) {
			glm::vec3 abspos = my_horse->get_absolute_position();
			if ((my_horse->get_absolute_position().x < -49) || (my_horse->get_absolute_position().x > 49) ||
				(my_horse->get_absolute_position().z < -49) || (my_horse->get_absolute_position().z > 49)) {

				my_horse->movement_log.x += 4.f;
				my_horse->rotation = glm::translate(my_horse->rotation, my_horse->movement_log);
				my_horse->rotation = glm::rotate(my_horse->rotation, glm::radians(-180.f), glm::vec3(0.0f, 1.0f, 0.0f));
				my_horse->rotation = glm::translate(my_horse->rotation, -my_horse->movement_log);

			}
			else {
				my_horse->movement_log.x -= 0.5f;
			}
		}
		else {
			frame = -1;
			state = '@';
		}
	}

}
void Horse_Animator::choose_direction(int howconfused) {
	current_tick = ((int)(glfwGetTime() * 5)) % 10;
	if (current_tick != old_tick) {
		frame++;
		old_tick = current_tick;


		if (frame < howconfused) {


			if (flip_coin()) {
				my_horse->rotation = glm::translate(my_horse->rotation, my_horse->movement_log);
				my_horse->rotation = glm::rotate(my_horse->rotation, glm::radians(-15.f), glm::vec3(0.0f, 1.0f, 0.0f));
				my_horse->rotation = glm::translate(my_horse->rotation, -my_horse->movement_log);
			}
			else {
				my_horse->rotation = glm::translate(my_horse->rotation, my_horse->movement_log);
				my_horse->rotation = glm::rotate(my_horse->rotation, glm::radians(15.f), glm::vec3(0.0f, 1.0f, 0.0f));
				my_horse->rotation = glm::translate(my_horse->rotation, -my_horse->movement_log);

			}
		}
		else {
			frame = -1;
			state = '@';
		}
	}
}
void Horse_Animator::walko() {
	current_tick = ((int)(glfwGetTime() * 15)) % 10;

	if (!upright) {
		my_horse->rotation = glm::translate(my_horse->rotation, my_horse->movement_log + glm::vec3(0.f, 1.3f, 0));
		my_horse->rotation *= glm::rotate(glm::mat4(1.0f), glm::radians(-180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		my_horse->rotation = glm::translate(my_horse->rotation, -(my_horse->movement_log + glm::vec3(0.f, 1.3f, 0)));

		upright = true;

	}
	switch (current_tick % 10) {

	case 1: {

		my_horse->neckrot.y = 45;
		my_horse->headrot.y = 0;
		my_horse->ulfl.y = 65;
		my_horse->urfl.y = 100;
		my_horse->ulhl.y = 95;
		my_horse->urhl.y = 70;
		my_horse->llfl.y = -15;
		my_horse->lrfl.y = -20;
		my_horse->llhl.y = 15;
		my_horse->lrhl.y = 5;


	}
			break;
	case 2: {

		my_horse->neckrot.y = 45;
		my_horse->headrot.y = 0;
		my_horse->ulfl.y = 60;
		my_horse->urfl.y = 105;
		my_horse->ulhl.y = 100;
		my_horse->urhl.y = 65;
		my_horse->llfl.y = -15;
		my_horse->lrfl.y = -20;
		my_horse->llhl.y = 15;
		my_horse->lrhl.y = 5;
	}			break;

	case 3: {

		my_horse->neckrot.y = 45;
		my_horse->headrot.y = -15;
		my_horse->ulfl.y = 55;
		my_horse->urfl.y = 110;
		my_horse->ulhl.y = 105;
		my_horse->urhl.y = 60;
		my_horse->llfl.y = -15;
		my_horse->lrfl.y = -20;
		my_horse->llhl.y = 15;
		my_horse->lrhl.y = 5;
	}			break;

	case 4: {

		my_horse->neckrot.y = 55;
		my_horse->headrot.y = 0;
		my_horse->ulfl.y = 60;
		my_horse->urfl.y = 105;
		my_horse->ulhl.y = 100;
		my_horse->urhl.y = 65;
		my_horse->llfl.y = -15;
		my_horse->lrfl.y = -20;
		my_horse->llhl.y = 20;
		my_horse->lrhl.y = 5;
	}			break;

	case 5: {

		my_horse->neckrot.y = 65;
		my_horse->headrot.y = 5;
		my_horse->ulfl.y = 70;
		my_horse->urfl.y = 95;
		my_horse->ulhl.y = 90;
		my_horse->urhl.y = 75;
		my_horse->llfl.y = -15;
		my_horse->lrfl.y = -20;
		my_horse->llhl.y = 20;
		my_horse->lrhl.y = 5;
	}			break;

	case 6: {

		my_horse->neckrot.y = 60;
		my_horse->headrot.y = -10;
		my_horse->ulfl.y = 80;
		my_horse->urfl.y = 85;
		my_horse->ulhl.y = 80;
		my_horse->urhl.y = 85;
		my_horse->llfl.y = -15;
		my_horse->lrfl.y = -25;
		my_horse->llhl.y = 25;
		my_horse->lrhl.y = 5;
	}			break;

	case 7: {

		my_horse->neckrot.y = 50;
		my_horse->headrot.y = -35;
		my_horse->ulfl.y = 90;
		my_horse->urfl.y = 75;
		my_horse->ulhl.y = 70;
		my_horse->urhl.y = 95;
		my_horse->llfl.y = -15;
		my_horse->lrfl.y = -20;
		my_horse->llhl.y = 5;
		my_horse->lrhl.y = 5;
	}			break;

	case 8: {

		my_horse->neckrot.y = 55;
		my_horse->headrot.y = -15;
		my_horse->ulfl.y = 80;
		my_horse->urfl.y = 85;
		my_horse->ulhl.y = 80;
		my_horse->urhl.y = 85;
		my_horse->llfl.y = -15;
		my_horse->lrfl.y = -20;
		my_horse->llhl.y = 5;
		my_horse->lrhl.y = 5;
	}			break;

	case 9: {

		my_horse->neckrot.y = 70;
		my_horse->headrot.y = 0;
		my_horse->ulfl.y = 75;
		my_horse->urfl.y = 105;
		my_horse->ulhl.y = 95;
		my_horse->urhl.y = 80;
		my_horse->llfl.y = -15;
		my_horse->lrfl.y = -20;
		my_horse->llhl.y = 10;
		my_horse->lrhl.y = 5;
	}			break;

	}
}