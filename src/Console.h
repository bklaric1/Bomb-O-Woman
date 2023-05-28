#ifndef CONSOLE_H
#define CONSOLE_H

//https://ansi.gabebanks.net/
//https://en.wikipedia.org/wiki/ANSI_escape_code#3-bit_and_4-bit
namespace Console
{
	void init();				//Leere Terminal, verstecke Cursor, Position 0,0
	void leeren();				//Leere Terminal

	void verstecken();			//Verstecke Cursor 	
	void zeigen();				//Zeige Cursor 

	void zeichne_punkt(int x, int y, char c); //Zeichne Zeichen c an Position x, y
}
#endif

