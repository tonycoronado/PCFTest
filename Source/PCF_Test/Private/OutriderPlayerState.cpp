// PCF Test


#include "OutriderPlayerState.h"

AOutriderPlayerState::AOutriderPlayerState()
{
	// a higher update frequency is needed since GAS component and attributes will be set on here
	NetUpdateFrequency = 100.0f; 
}
