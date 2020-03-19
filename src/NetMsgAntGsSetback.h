#pragma once

#include "NetMsg.h"
#include "../../../include/aftr/Vector.h"
#include "drone.h"

#ifdef AFTR_CONFIG_USE_BOOST

namespace Aftr
{

class NetMsgAntGsSetback : public NetMsg
{
public:
   NetMsgMacroDeclaration( NetMsgAntGsSetback );

   NetMsgAntGsSetback(const Vector& pos);
   virtual ~NetMsgAntGsSetback();
   virtual bool toStream( NetMessengerStreamBuffer& os ) const;
   virtual bool fromStream( NetMessengerStreamBuffer& is );
   virtual void onMessageArrived();
   virtual std::string toString() const;

   float antSetbackCourse;
protected:
	Vector pos;
};

} //namespace Aftr

#endif
