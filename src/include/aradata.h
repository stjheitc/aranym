/* Joy 2001 */

#ifndef _ARADATA
#define _ARADATA
#include "icio.h"

class ARADATA : public ICio {
private:
	int mouse_x, mouse_y;

public:
	ARADATA();
	virtual uae_u8 handleRead(uaecptr addr);
	virtual void handleWrite(uaecptr addr, uae_u8 value);
	int getAtariMouseX()	{ return mouse_x; }
	int getAtariMouseY()	{ return mouse_y; }
};
#endif /* _ARADATA */
