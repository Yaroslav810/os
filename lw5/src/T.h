#pragma once
#include "Buffer.h"
#include "F.h"
#include "Terminal.h"

void ParseT(Buffer &buffer) {
    ParseF(buffer);
    if (CheckItem(Terminal::MULTIPLY, buffer)) {
        ParseT(buffer);
    }
}
