#include <iostream>
#include <string>
#include <windows.h>
#include "copy.h"

using namespace std;

int copy(string& Pass) {
    string Pass = "wvrerverv";
    char CharPass[50];
    strcpy_s(CharPass, Pass.c_str());
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