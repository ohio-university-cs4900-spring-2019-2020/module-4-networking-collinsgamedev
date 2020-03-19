#pragma once

#include "Model.h"
#include "WO.h"

#ifdef AFTR_CONFIG_USE_BOOST

namespace Aftr
{
	class Drone
	{
	public:
		static Drone* New(Vector pos = Vector(0, 0, 0), const std::string file = "../mm/models/drone.stl");
		void set_pos(float x, float y, float z)
		{
			drone->setPosition(Vector(x, y, z));
		};
		void set_position(Vector v)
		{
			drone->setPosition(v);
		};
		Vector get_position()
		{
			return drone->getPosition();
		};
		WO* get_drone()
		{
			return drone;
		};

	protected:
		WO* drone;
		Drone(Vector pos = Vector(0,0,0), const std::string file = "../mm/models/drone.stl");
	};

}

#endif
