/*
 * beep.h
 *
 *  Created on: Oct 22, 2024
 *      Author: Uu
 */

#ifndef INC_BEEP_H_
#define INC_BEEP_H_

#include "distanceProc.h"
#include "tim.h"

#define BEEP_ROUNDS 10
#define BEEP_FREQUENCY_AUTORELOAD 1131
extern int beep_too_close;
extern int beep_rounds;
extern int beep_interval_rounds;
extern int beep_interval_rounds_tre;
void Beep();

#endif /* INC_BEEP_H_ */
