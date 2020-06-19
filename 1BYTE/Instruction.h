#pragma once

#include "HeaderOfConvenience.h"
#include "Controller.h"

void add(Controller*, byte*);
void addi(Controller*, byte*);
void sub(Controller*, byte*);
void subi(Controller*, byte*);
void mov(Controller*, byte*);
void movi(Controller*, byte*);
void halt(Controller*, byte*);
void nop(Controller*, byte*);