#include <windows.h>
#include <stdio.h>

int main() {
	/*Ustvarjanje novega kljuca*/
	LONG reg;
	HKEY key;
	reg = RegCreateKeyEx(
		HKEY_CURRENT_USER,
		"Software\\SPO\\C",
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		NULL,
		&key,
		NULL);
	if (reg != ERROR_SUCCESS) {
		printf("Ustvarjanje kljuca ni uspelo: %s\n", GetLastError());
	} else {
		printf("Ustvarjanje kljuca je bilo uspesno.\n");
	}
	/*Ustvarjanje nove vrednosti*/
	DWORD data = 1234;
	reg = RegSetValueEx(
		key,
		"Vrednost dodana v C-ju",
		0,
		REG_DWORD,
		(LPBYTE) &data,
		sizeof(data)
		);
	if (reg != ERROR_SUCCESS) {
		printf("Dodajanje vrednosti ni uspelo: %s\n", GetLastError());
	} else {
		printf("Dodajanje vrednosti je uspelo.\n");
	}
	RegCloseKey(key);
}