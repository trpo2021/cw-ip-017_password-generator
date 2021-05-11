#include "copy.h"
#include <Windows.h>

using namespace std;

int copy(string& Pass)
{
    if (OpenClipboard(0)) {
        EmptyClipboard();
        char* buffer = (char*)GlobalAlloc(GMEM_FIXED, Pass.size() + 1);
        strcpy(buffer, Pass.c_str());
        SetClipboardData(CF_TEXT, buffer);
        CloseClipboard();
        return true;
    }
    return false;
}