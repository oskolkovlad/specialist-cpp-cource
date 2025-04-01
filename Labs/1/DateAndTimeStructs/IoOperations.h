#pragma once

#include <iostream>
#include <format>
#include "Structures.h"

using std::cin;
using std::cout;
using std::endl;
using std::format;

void Read(Date& item);

void Read(Time& item);

void Print(const Date& item, bool withEndl = true);

void Print(const Time& item, bool withEndl = true);
