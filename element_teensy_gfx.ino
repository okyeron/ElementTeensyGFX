// element labs stealth panel test (Teensy version)
// 12-6-12, smn: created
// 19-6-12, cmiller: updated to use GFX library

#include "SPI.h"
#include "element_GFX.h"

Element_GFX panel;

void setup()
{
	SPI.begin();
	panel.constructor();
	panel.setRotation(0); // options are 0, 1, 2, 3
/*
	Serial.begin(9600);
	Serial.println("height: " );
	Serial.println(panel.height());
	Serial.println("width: ");
	Serial.println(panel.width());
*/
}

// set x cursor position which will decrement to scroll text 
int xcur = 0; 

// MAIN LOOP

void loop()
{
	// Text to display on panels
	char *str = " hello world! ";
	
	// Set text size - size 1 is 6 or 7 pixels
	int txtsize = 2;

	
	int i, j;  
	for (i = 0; i < panel.width(); i++)	{
		for (j = 0; j < panel.height(); j++)
			panel.drawPixel(i, j, make_color(0, j/2, 0));
	}

//	panel.fillScreen(make_color(128, 128, 128));

	panel.sendFrame();


/*
	for (int i = 0; i < strlen(str); i++){
		panel.fillScreen(make_color(0, 0, 64));
		panel.drawChar(0, 0, str[i], make_color(64, 0, 0), make_color(0, 0, 64), 1);
		panel.sendFrame();
		delay(250);
	}


	panel.fillScreen(make_color(0, 0, 0));
	panel.setCursor(xcur,1);
	panel.setTextColor(make_color(0, 64, 0), make_color(0, 0, 0));
	panel.setTextSize(txtsize);
	panel.setTextWrap(false);
	for (int i = 0; i < strlen(str); i++)
	{
		panel.write(str[i]);
	}
    panel.sendFrame();
    xcur--;
	delay(10);
	
	if (xcur < -(txtsize*6)*(strlen(str)-1)) {
		xcur = 0;
	}
*/

}
