/* Joy 2001 */

#include "sysdeps.h"
#include "hardware.h"
#include "cpu_emulation.h"
#include "memory.h"
#include "yamaha.h"
#include "parameters.h"

YAMAHA::YAMAHA() {
	active_reg = 0;
}

static const int HW = 0xff8800;

uae_u8 YAMAHA::handleRead(uaecptr addr) {
	addr -= HW;
	switch(addr) {
		case 0: return yamaha_regs[active_reg];
	}

	return 0;
}

void YAMAHA::handleWrite(uaecptr addr, uae_u8 value) {
	addr -= HW;
	switch(addr) {
		case 0: active_reg = value & 0x0f; break;
		case 2: yamaha_regs[active_reg] = value; break;
	}
}

int YAMAHA::getFloppyStat() {
	return yamaha_regs[14] & 7;
}
