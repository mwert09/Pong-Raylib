#include "EnvironmentItem.h"

/* Loop through envItems array and draw everything to the screen */
void DrawEnvironment(EnvItem envItems[], int envItemLength) {
	for (int i = 0; i < envItemLength; i++) {
		DrawRectangleRec(envItems[i].rect, envItems[i].color);
	}
}