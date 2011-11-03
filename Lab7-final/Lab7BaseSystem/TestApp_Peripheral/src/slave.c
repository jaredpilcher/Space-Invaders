#include "slave.h"
#include "xintc.h"
#include "intc_header.h"
void disableSlaveInterrupt(){
	Xint32 ier = XIntc_In32(XPAR_OPB_INTC_0_BASEADDR + XIN_IER_OFFSET);
	XIntc_Out32(XPAR_OPB_INTC_0_BASEADDR + XIN_IER_OFFSET, (ier & ~XPAR_LAB3_SLAVE_0_INTERRUPTREQUEST_MASK));
}

void enableSlaveInterrupt(){
	Xint32 ier = XIntc_In32(XPAR_OPB_INTC_0_BASEADDR + XIN_IER_OFFSET);
	XIntc_Out32(XPAR_OPB_INTC_0_BASEADDR + XIN_IER_OFFSET, (ier | XPAR_LAB3_SLAVE_0_INTERRUPTREQUEST_MASK));
	XIo_Out32(0x40080000 + 16, 1);
}

void acknowledgeSlaveInterrupts(){
	XIo_Out32(0x40080000 + 12, 1);
	XIntc_Out32(XPAR_OPB_INTC_0_BASEADDR + XIN_IAR_OFFSET, XPAR_LAB3_SLAVE_0_INTERRUPTREQUEST_MASK);
}