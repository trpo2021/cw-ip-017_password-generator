#define CATCH_CONFIG_MAIN
#include "libpwgen/Odn.h"
#include "libpwgen/Spec.h"
#include "libpwgen/copy.h"
#include "libpwgen/generate.h"
#include "libpwgen/isint.h"
#include "libpwgen/num.h"
#include "libpwgen/reg.h"
#include "thirdparty/catch.hpp"
#include <string>

using std::string;

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
    string Pass = "aCwd4s!b7R";
    copy(Pass);
    CHECK(Pass == GetClipboardText());
}
TEST_CASE("isInt", " ")
{
    CHECK(isInt("abbc") == false);
    CHECK(isInt("1.3") == false);
    CHECK(isInt("1,67") == false);
    CHECK(isInt(".45") == false);
    CHECK(isInt("5") == true);
    CHECK(isInt("-5") == false);
}

TEST_CASE("generate", " ")
{
    int Mask[6], n = 0;
    string Pass;
    Generate(6, Pass, Mask);
    for (auto& c : Pass) {
        if (islower(c)) {
            // proverka na vsekh li mestakh bukvy nizhnego registra
            n++;
        }
    }
    CHECK(n == 6);
}
TEST_CASE("Spec", " ")
{
    int Mask[] = {1, 2, 1, 0, 1, 2};
    string Pass = "2W1r9Y";
    Spec(6, Pass, Mask, 2);
    int k = 0;
    for (auto& c : Pass) {
        if (isalnum(c) && isupper(c)) {
            k++;
        }
    }
    CHECK(k == 2);
}
TEST_CASE("num", " ")
{
    int k = 0;
    int Mask[] = {0, 0, 0, 0};
    string Pass = "cifj";
    Num(4, Pass, Mask, 2);
    for (auto& c : Pass) {
        if (isalpha(c)) {
            k++;
        }
    }
    CHECK(k == 2);
}
TEST_CASE("SmZn", " ")
{
    string Pass = "z";
    SmZn(10, '0', Pass, 0);
    CHECK(((Pass[0] != '0') && (Pass[0] != '1') && (Pass[0] != '2')
           && (Pass[0] != '5'))
          == true);
    SmZn(26, 'A', Pass, 0);
    CHECK(((Pass[0] != 'I') && (Pass[0] != 'S') && (Pass[0] != 'Z')
           && (Pass[0] != 'O'))
          == true);
    SmZn(26, 'a', Pass, 0);
    CHECK(((Pass[0] != 'o') && (Pass[0] != 's') && (Pass[0] != 'z')
           && (Pass[0] != 'l'))
          == true);
}
TEST_CASE("Vibor", " ")
{
    string Pass = "z";
    int Mask[1] = {0};
    Vibor(0, 10, Pass, Mask);
    CHECK(islower(Pass[0]) != 0);
    Pass[0] = 'Z';
    Mask[0] = 2;
    Vibor(0, 9, Pass, Mask);
    CHECK(isupper(Pass[0]) != 0);
    Pass[0] = '1';
    Mask[0] = 1;
    Vibor(0, 5, Pass, Mask);
    CHECK(((Pass[0] >= '0') && (Pass[0] <= '9')) == true);
}
TEST_CASE("Odn", " ")
{
    string Pass = "o1Z";
    int Mask[3] = {0, 1, 2};
    Odn(3, Pass, Mask);
    CHECK(((Pass[0] != 'o') && (Pass[0] != 's') && (Pass[0] != 'z')
           && (Pass[0] != 'l'))
          == true);
    CHECK(((Pass[1] != '0') && (Pass[1] != '1') && (Pass[1] != '2')
           && (Pass[1] != '5'))
          == true);
    CHECK(((Pass[2] != 'I') && (Pass[2] != 'S') && (Pass[2] != 'Z')
           && (Pass[2] != 'O'))
          == true);
}
