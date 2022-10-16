#include<Windows.h>
#include<string>
#include<math.h>
#define DEFAULT_TEXT_COLOR 91
using namespace std;

void ShowCur(bool CursorVisibility);
void SetColor(WORD color);
void gotoXY(int x, int y);
void textColor(int x);
void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
void loadingAnimation(int x, int y, string loadContent, string loadContentDone);
void sleepFunc(short s);
void drawBox(
			 int x, 
			 int y, 
			 int w, 
			 int h, 
			 int b_color = 0, 
			 int t_color = 0, 
			 string content = "UNKNOWN", 
			 string align = "center" // align text in the box, accept 3 values: left, center, right
			 );
	
void currentTarget(
				   int x, 
				   int y, 
				   int w, 
				   int h, 
				   int b_color,  // background color for the current target
				   int t_color, // text color for the current target
				   string content, // content for the current target(should be the menu content)
				   string align // text align for the current target(should be the menu item align)
				   );
			 
			  

