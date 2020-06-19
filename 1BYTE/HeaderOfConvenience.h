#pragma once

typedef unsigned char byte;

#define olif(condition, tru, fals) if (condition) { tru; } else { fals; }

#define fctPtr void(*)(Controller*, byte*)
