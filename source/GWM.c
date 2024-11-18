/*	GWM-GL [Graphical Window Manager for GL]
 * Cross-platform solution for simple window notificaions
 * 
 */ 

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdbool.h>
#include <string.h>
#include "GWM.h"

 
void RenderText(GWMConfig* GWM, const char* text) {

    glRasterPos2f(GWM->DescX, GWM->DescY);
    glutBitmapString(GLUT_BITMAP_8_BY_13, text);
		
	/* This supports "\n" - its small but enough. */
    
}

void MakeWindow(GWMConfig* GWM, WindowPosition* WP) {
	
    glBegin(GL_LINES);
        // underline
        glVertex2f(WP->PosX, WP->PosY);
        glVertex2f(WP->PosX + GWM->WinX, WP->PosY);

        // right
        glVertex2f(WP->PosX + GWM->WinX, WP->PosY);
        glVertex2f(WP->PosX + GWM->WinX, WP->PosY + GWM->WinY);

        // upper line
        glVertex2f(WP->PosX + GWM->WinX, WP->PosY + GWM->WinY);
        glVertex2f(WP->PosX, WP->PosY + GWM->WinY);

        // Left
        glVertex2f(WP->PosX, WP->PosY + GWM->WinY);
        glVertex2f(WP->PosX, WP->PosY);

        // Two Lines effect
        int numLines = 2; 
        float gap = GWM->WinY * 0.05f;

        for (int i = 1; i <= numLines; i++) {
            float offset = GWM->WinY - i * gap; // Pozycja linii poniżej górnej krawędzi
            glVertex2f(WP->PosX, WP->PosY + offset);
            glVertex2f(WP->PosX + GWM->WinX, WP->PosY + offset);
        }
    glEnd();

    RenderText(GWM, GWM->DESC);
	
}
