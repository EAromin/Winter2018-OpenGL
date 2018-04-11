#include "stdafx.h"
#include "Bounding_Sphere.h"
#include <iostream>
std::vector<Bounding_Sphere*> Bounding_Sphere::bs;
float Bounding_Sphere::compute_distance(const Bounding_Sphere & a, const Bounding_Sphere & b)
{

	float deltax, deltay, deltaz;
	deltax = a.location.x - b.location.x;
	deltay = a.location.y - b.location.y;
	deltaz = a.location.z - b.location.z;
	return sqrt((deltax*deltax)+(deltay*deltay)+(deltaz*deltaz));

	
}

void Bounding_Sphere::update_collision()
{if(!bs.empty()){
	for (int i = 0; i < bs.size() - 1; i++)
	{
		if (!bs[i]->touchy_horse->stopped)
		{

			for (int j = 0; j < bs.size()-1; j++)
			{
				if (i!=j &&(compute_distance(*bs[i], *bs[j]) <= (bs[i]->radius + bs[j]->radius)))
				{
					
					if (bs[j]->touchy_horse->horse_size != 2.0f)
						bs[j]->touchy_horse->horse_size = 2.0f;
					bs[j]->touchy_horse->stopped = true;
				}else
				{
					bs[i]->touchy_horse->stopped = false;
					bs[j]->touchy_horse->stopped = false;
				}
			}
		}
	}
}
}

Bounding_Sphere::Bounding_Sphere(){
	location = glm::vec3(0,0,0);
	touchy_horse = nullptr;
	radius = 0.0f;
	bs.push_back(this);
}

Bounding_Sphere::Bounding_Sphere(Horse &horsie){
	touchy_horse = &horsie;
	location = touchy_horse->get_absolute_position();
	radius = 1* touchy_horse -> horse_size;
	touchy_horse->touchy_ball = this;
	Bounding_Sphere *dis = this;
	bs.push_back(this);
	std::cout << "#of obj with sphere collider = " << bs.size() << std::endl;

}