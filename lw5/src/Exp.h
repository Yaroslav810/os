#pragma once
#include "Buffer.h"
#include "T.h"

bool ParseExp(Buffer &buffer) {
    auto result = ParseT(buffer);
    if (!result) {
        return false;
    }
    if (CheckItem(Terminal::PLUS, buffer)) {
        ParseExp(buffer);//ParseT(buffer);
    }
    return true;
}
