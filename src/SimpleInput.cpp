#include "SimpleInput.h"
#include "Configuration.h"
#include <iostream>

SimpleInput::SimpleInput()
{
}

SimpleInput::~SimpleInput()
{
}
#if defined(__linux__) //Linuxvariante
#include <termios.h> //Terminalkontrollfunktionen (Puffer, Verzögerung, Echo, etc.)
#include <unistd.h>  //Stellt unter anderem sleep und usleep bereit
#include <fcntl.h>	 //Unix Systemcalls (Filedescriptor) Lese-/Schreibfunktionalität
#include <chrono>	 //Zeitumrechnungsfunktionen und exakte Zeitnahme

//Funktion prüft auf Tastatureingabe für die Dauer des Intervalls in ms
char SimpleInput::getSteuerung(long interval)
{
	//Hilfsvariablen zur Berechnung der Rechenzeit der Funktion
	auto startzeit = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - startzeit);

	struct termios tio, oldtio;
	tcgetattr(STDIN_FILENO, &oldtio); 		// Sichern der aktuellen Terminaleinstellung
	oldtio.c_lflag &= ~(ECHO);				// Echo für Eingaben dauerhaft auf false setzen.
	tio = oldtio;
	tio.c_lflag &= ~(ICANON | ECHO); 		// Verzögerungsfreies Einlesen ohne Ausgabe auf der Konsole
	tio.c_cc[VMIN] = 0; 					// Minimale Anzahl an Zeichen pro Lesevorgang
	tio.c_cc[VTIME] = 0; 					// Timeout bei Verwendung von Select in 1/10s
	tcsetattr(STDIN_FILENO, TCSANOW, &tio); // Setzen der neuen Terminaleinstellung
	//Puffer leeren
	char dump;
	while (read(STDIN_FILENO, &dump, 1) > 0);

	//Wartet bis zur Restdauer in ms auf Tastatureingaben. Abtastrate 1000Hz
	char c = 'x';
	while (duration.count() < interval)
	{
		if (read(STDIN_FILENO, &c, 1) == 1)
		{
			//std::cout << "Eingabe: " << c << std::endl;
			break;
		}
		usleep(1); // Reduziert die CPU-Belastung durch Reduzierung der Abtastrate
		//Ermitteln der Restzeit für das Warten auf Tastatureingaben
		duration = std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::high_resolution_clock::now() - startzeit);
	}
	// Zurücksetzen der Terminaleinstellung
	tcsetattr(STDIN_FILENO, TCSANOW, &oldtio);

	duration = std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - startzeit);
	//Berechnen der verbleibenden Restzeit in ms
	long dauer = 0;
	if (interval - duration.count() > 0)
		dauer = (interval - duration.count()) * 1000;
	//Mainthread pausiert für die Dauer der Restzeit
	usleep(dauer);
	return c;
}

char SimpleInput::getWASD(long interval)
{
	char c = getSteuerung(interval);

	if (c == 'w')
		return Configuration::GAMEOBJECT_MOVE_UP;// 'w';
	else if (c == 'a')
		return Configuration::GAMEOBJECT_MOVE_LEFT;// 'a';
	else if (c == 's')
		return Configuration::GAMEOBJECT_MOVE_DOWN;// 's';
	else if (c == 'd')
		return Configuration::GAMEOBJECT_MOVE_RIGHT;// 'd';
	else if (c == 'e')
		return Configuration::GAMEOBJECT_ACTION;// 'e';
	else
		return 'x';
}

char SimpleInput::getArrow(long interval)
{
	char c = getSteuerung(interval);

	if (c == '8')
		return Configuration::GAMEOBJECT_MOVE_UP;// '8';
	else if (c == '4')
		return Configuration::GAMEOBJECT_MOVE_LEFT;// '4';
	else if (c == '5')
		return Configuration::GAMEOBJECT_MOVE_DOWN;// '5';
	else if (c == '6')
		return Configuration::GAMEOBJECT_MOVE_RIGHT;// '6';
	else if (c == '7')
		return Configuration::GAMEOBJECT_ACTION;// '7';
	else
		return 'x';
}

#elif defined(_WIN32) //Greift bei Windows 32-bit und 64-bit
//Windows Virtual Key Codes => https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

#include <windows.h>
char SimpleInput::getSteuerung(long interval)
{
	Sleep(interval);
	const int KEY_UP = 0x1;
	if ((GetAsyncKeyState(0x57) & KEY_UP) == KEY_UP)
		return 'w';
	else if ((GetAsyncKeyState(0x41) & KEY_UP) == KEY_UP)
		return 'a';
	else if ((GetAsyncKeyState(0x53) & KEY_UP) == KEY_UP)
		return 's';
	else if ((GetAsyncKeyState(0x44) & KEY_UP) == KEY_UP)
		return 'd';
	else if ((GetAsyncKeyState(0x45) & KEY_UP) == KEY_UP)
		return 'e';
	else
		return 'x';
}

char SimpleInput::getWASD(long interval)
{
	Sleep(interval);
	const int KEY_UP = 0x1;
	if ((GetAsyncKeyState(0x57) & KEY_UP) == KEY_UP)
		return Configuration::GAMEOBJECT_MOVE_UP;// 'w';
	else if ((GetAsyncKeyState(0x41) & KEY_UP) == KEY_UP)
		return Configuration::GAMEOBJECT_MOVE_LEFT;// 'a';
	else if ((GetAsyncKeyState(0x53) & KEY_UP) == KEY_UP)
		return Configuration::GAMEOBJECT_MOVE_DOWN;// 's';
	else if ((GetAsyncKeyState(0x44) & KEY_UP) == KEY_UP)
		return Configuration::GAMEOBJECT_MOVE_RIGHT;// 'd';
	else if ((GetAsyncKeyState(0x45) & KEY_UP) == KEY_UP)
		return Configuration::GAMEOBJECT_ACTION;// 'e';
	else
		return 'x';
}

char SimpleInput::getArrow(long interval)
{
	Sleep(interval);
	const int KEY_UP = 0x1;
	//VK UP
	if ((GetAsyncKeyState(0x26) & KEY_UP) == KEY_UP)
		return Configuration::GAMEOBJECT_MOVE_UP;// '8';
	//VK LEFT
	else if ((GetAsyncKeyState(0x25) & KEY_UP) == KEY_UP)
		return Configuration::GAMEOBJECT_MOVE_LEFT;// '4';
	//VK DOWN
	else if ((GetAsyncKeyState(0x28) & KEY_UP) == KEY_UP)
		return Configuration::GAMEOBJECT_MOVE_DOWN;// '5';
	//VK RIGHT
	else if ((GetAsyncKeyState(0x27) & KEY_UP) == KEY_UP)
		return Configuration::GAMEOBJECT_MOVE_RIGHT;// '6';
	//Enter
	else if ((GetAsyncKeyState(0x0D) & KEY_UP) == KEY_UP) //Enter Taste
		return Configuration::GAMEOBJECT_ACTION;// 'e';
	else
		return 'x';
}

#else //Betriebssystem unbekannt / andere Betriebssysteme
char SimpleInput::getSteuerung(long interval)
{
	char eingabe;
	std::cin >> eingabe;
	return eingabe;
}
char SimpleInput::getWASD(long interval)
{
	return getSteuerung();
}
char SimpleInput::getArrow(long interval)
{
	return getSteuerung();
}
#endif
