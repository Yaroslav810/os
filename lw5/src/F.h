#pragma once
#include "Buffer.h"
#include "Exp.h"
#include "Terminal.h"

bool ParseExp(Buffer &buffer);

bool ParseF(Buffer &buffer) {
    if (CheckItem(Terminal::MINUS, buffer)) {
        ParseF(buffer);
        return true;
    } else if (CheckItem(Terminal::OPENING_BRACKET, buffer)) {
        ParseExp(buffer);
        CompareItem(Terminal::CLOSING_BRACKET, buffer);
        return true;
    } else if (CheckItem(Terminal::ID, buffer) || CheckItem(Terminal::NUM, buffer)) {
        return true;
    }
    return false;
}
