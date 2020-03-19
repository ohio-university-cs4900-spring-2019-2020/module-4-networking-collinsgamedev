#include "drone.h"

#ifdef AFTR_CONFIG_USE_BOOST

using namespace Aftr;

Drone* Drone::New(Vector pos, const std::string file)
{
	return new Drone(pos, file);
}

Drone::Drone(Vector pos, const std::string file)
{
	this->drone = WO::New(file);
	this->drone -> setPosition(pos);
}

#endif