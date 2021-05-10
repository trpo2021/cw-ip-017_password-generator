#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "libpwgen/reg.h"
#include "libpwgen/Odn.h"
#include "libpwgen/num.h"
#include "libpwgen/Spec.h"
#include "libpwgen/generate.h"
#include "libpwgen/copy.h"
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
    CHECK(copy(Pass));
}

TEST_CASE("generate", " ")
{
    int Mask[6], n = 0;
    string Pass;
    Generate(6, Pass, Mask);
    for (auto& c : Pass) {
        if (islower(c)) { 
            //proverka na vsekh li mestakh bukvy nizhnego registra
            n++;
        }
    }
    CHECK(n == 6);
}