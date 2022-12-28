#pragma once
#include "Buffer.h"
#include "F.h"
#include "Terminal.h"

bool ParseT(Buffer &buffer) {
    auto result = ParseF(buffer);
    if (!result) {
        return result;
    }
    if (CheckItem(Terminal::MULTIPLY, buffer)) {
        ParseT(buffer);//ParseF(buffer);
    }
    return true;
}
