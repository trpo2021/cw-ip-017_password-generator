#define CATCH_CONFIG_MAIN
#include "thirdparty/catch.hpp"
#include "libpwgen/reg.h"
#include "libpwgen/Odn.h"
#include "libpwgen/num.h"
#include "libpwgen/Spec.h"
#include "libpwgen/generate.h"
#include "libpwgen/copy.h"
#include "libpwgen/isint.h"

string GetClipboardText()
{
    char* text = nullptr;
    if (OpenClipboard(0)) {
        HANDLE hData = GetClipboardData(CF_TEXT);
        text = (char*)(wchar_t*)GlobalLock(hData);
        GlobalUnlock(hData);
        CloseClipboard();
    };
    return text;
}

TEST_CASE("reg", " ")
{
    string Pass = "acwdbsnbwr";
    int Mask[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Reg(Pass.size(), Pass, Mask, 4);
    int count = 0;
    for (auto& c : Pass) {
        if (isalpha(c) && isupper(c)) {
            count++;
        }
    }
    CHECK(count == 4);
}
TEST_CASE("copy", " ")
{
    std::string Pass = "aCwd4s!b7R";
    copy(Pass);
    CHECK(Pass == GetClipboardText());
}
TEST_CASE("isInt", " ")
{
    /*CHECK(isInt("abbc")==false);
    CHECK(isInt("1.3")==false);
    CHECK(isInt("1,67")==false);
    CHECK(isInt(".45")==false);
    CHECK(isInt("5")==true);*/
    CHECK(isInt("-5")==true);
}