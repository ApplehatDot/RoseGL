#ifndef GWM_GL_CORE_H
#define GWM_GL_CORE_H

typedef struct {
	float PosX;
	float PosY;
} WindowPosition;

typedef struct {
	float WinX;
	float WinY;
	char* DESC;
	float DescX;
	float DescY;
} GWMConfig;

void MakeWindow(GWMConfig *GWM, WindowPosition *WP);

#endif // GWM_GL_CORE_H
