#include "isint.h"
#include<iostream>
#include<string>

bool isInt(std::string str)
{
    if (str == "")
        return false;
    for (int i = 0; i < (int)str.length(); ++i)
    {
        if (!isdigit(str[i])) {
            if (i == 0 && str[i] == '-') {
                continue;
            }
            return false;
        }
    }
    return true;
}

int inputInt(std::string message)
{
    std::string str;
    do {
        std::cout << message;
        std::cin >> str;
    } while (!isInt(str));
    return atoi(str.c_str());
}