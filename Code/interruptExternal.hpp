/*
 * interruptExternal.h
 *
 * Created: 12/12/2022 11.24.56
 *  Author: fisikamodern
 */ 


#ifndef INTERRUPTEXTERNAL_H_
#define INTERRUPTEXTERNAL_H_

typedef enum{pinINT0,pinINT1}Pin;
typedef enum{activeWhen0To1,activeWhen1To0}Mode;
	
void interruptExternalInit(Pin pin,Mode mode);



#endif /* INTERRUPTEXTERNAL_H_ */