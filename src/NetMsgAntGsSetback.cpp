#include "NetMsgCreateWO.h"
#ifdef AFTR_CONFIG_USE_BOOST

#include <iostream>
#include <sstream>
#include <string>
#include "AftrManagers.h"
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
#include "NetMsgAntGsSetback.h"
#include "Model.h"
#include "WOLight.h"
#include "GLViewNewModule.h"

using namespace Aftr;

//NetMsgMacroDefinition( NetMsgAntGsSetback );

NetMsgAntGsSetback::NetMsgAntGsSetback(const Vector& pos)
{
	this->pos = pos;
}

NetMsgAntGsSetback::~NetMsgAntGsSetback()
{
}

bool NetMsgAntGsSetback::toStream( NetMessengerStreamBuffer& os ) const
{
	os << this->pos.x << this->pos.y << pos.z;
   return true;
}

bool NetMsgAntGsSetback::fromStream( NetMessengerStreamBuffer& is )
{
	is >> this->pos.x >> this->pos.y >> this->pos.z;
   return true;
}

void NetMsgAntGsSetback::onMessageArrived()
{
	((GLViewNewModule*)ManagerGLView::getGLView())->drone->set_pos(this->pos.x, this->pos.y, this->pos.z);

   std::cout << this->toString() << std::endl;
}

std::string NetMsgAntGsSetback::toString() const
{
   std::stringstream ss;

   ss << NetMsg::toString();
   ss << "Position: " << this->pos << "\n";

   return ss.str();
}

#endif
