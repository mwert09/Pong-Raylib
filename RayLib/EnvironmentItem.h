#ifndef ENVIRONMENTITEM_H
#define ENVIRONMENTITEM_H

#include <raylib.h>
#include <stdbool.h>

/* Type definition for Environment items*/
typedef struct {
	Rectangle rect;
	bool blocking;
	Color color;
}EnvItem;

/* Environment array */
extern EnvItem envItems[];
/* Function to draw environment */
void DrawEnvironment(EnvItem envItems[], int envItemLength);

#endif