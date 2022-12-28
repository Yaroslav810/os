#pragma once
#include "Buffer.h"
#include "Exp.h"
#include "Idlist.h"
#include "Terminal.h"

bool ParseRead(Buffer &buffer) {
    auto checking = CheckItem(Terminal::READ, buffer);
    if (!checking) {
        return false;
    }
    CompareItem(Terminal::OPENING_BRACKET, buffer);
    ParseIdlist(buffer);
    CompareItem(Terminal::CLOSING_BRACKET, buffer);
    CompareItem(Terminal::SEMICOLON, buffer);
    return true;
}

bool ParseWrite(Buffer &buffer) {
    auto checking = CheckItem(Terminal::WRITE, buffer);
    if (!checking) {
        return false;
    }
    CompareItem(Terminal::OPENING_BRACKET, buffer);
    ParseIdlist(buffer);
    CompareItem(Terminal::CLOSING_BRACKET, buffer);
    CompareItem(Terminal::SEMICOLON, buffer);
    return true;
}

bool ParseAssign(Buffer &buffer) {
    auto checking = CheckItem(Terminal::ID, buffer);
    if (!checking) {
        return false;
    }
    CompareItem(Terminal::ASSIGNMENT, buffer);
    ParseExp(buffer);
    CompareItem(Terminal::SEMICOLON, buffer);
    return true;
}

bool ParseSt(Buffer &buffer) {
    bool checking;
    checking = ParseRead(buffer);
    if (checking) {
        return true;
    }
    checking = ParseWrite(buffer);
    if (checking) {
        return true;
    }
    checking = ParseAssign(buffer);
    if (checking) {
        return true;
    }

    return false;
}

void ParseListst(Buffer &buffer) {
    ParseSt(buffer);
    while (ParseSt(buffer)) {}
}
