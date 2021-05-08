#include <Windows.h>
#include "copy.h"

using namespace std;

int copy(string& Pass) {
    char CharPass[50];
    strncpy(CharPass, Pass.c_str(),50);
    if (OpenClipboard(0))
    {
        EmptyClipboard();
        char* hBuff = (char*)GlobalAlloc(GMEM_FIXED, strlen(CharPass) + 1);
        strcpy(hBuff, CharPass);
        SetClipboardData(CF_TEXT, hBuff);
        CloseClipboard();

    }
    return 0;
}