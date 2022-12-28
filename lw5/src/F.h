#pragma once
#include "Buffer.h"
#include "Exp.h"
#include "Terminal.h"

void ParseExp(Buffer &buffer);

void ParseF(Buffer &buffer) {
    if (CheckItem(Terminal::MINUS, buffer)) {
        ParseF(buffer);
    } else if (CheckItem(Terminal::OPENING_BRACKET, buffer)) {
        ParseExp(buffer);
        CompareItem(Terminal::CLOSING_BRACKET, buffer);
    } else if (CheckItem(Terminal::ID, buffer) || CheckItem(Terminal::NUM, buffer)) {
    } else {
        throw std::invalid_argument("\nERROR: Failed to parse F");
    }
}
