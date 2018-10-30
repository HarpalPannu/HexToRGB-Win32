#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <iostream>
#include "resource.h"
#include <stdlib.h>

HINSTANCE hInst;
void GetTextHZ(HWND hwndDlg);
BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        SendMessage(GetDlgItem(hwndDlg,HexCode), EM_SETLIMITTEXT, 7, 0);
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
            case Convert:
                GetTextHZ(hwndDlg);
            break;
        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgMain);
}

void GetTextHZ(HWND hwndDlg){
    TCHAR hexCodeString[10];
    GetDlgItemText(hwndDlg, HexCode, hexCodeString, 10);

    char colorCode[10];
	sprintf(colorCode, "%s",hexCodeString);

	char rHex[3];
	strncpy(rHex, colorCode+1, 2);
	rHex[2] = '\0';
	sprintf(rHex, "%d", (int)strtol(rHex, NULL, 16));
	SetDlgItemText(hwndDlg, rColor, rHex);

	char gHex[3];
	strncpy(gHex, colorCode+3, 2);
	gHex[2] = '\0';
	sprintf(gHex, "%d", (int)strtol(gHex, NULL, 16));
	SetDlgItemText(hwndDlg, gColor,gHex);

	char bHex[3];
	strncpy(bHex, colorCode+5, 2);
	bHex[2] = '\0';
	sprintf(bHex, "%d", (int)strtol(bHex, NULL, 16));
	SetDlgItemText(hwndDlg, bColor, bHex);


}



