#pragma once

void ParseType(Buffer &buffer) {
    if (CheckItem(Terminal::INT, buffer) || CheckItem(Terminal::INT, buffer) || CheckItem(Terminal::INT, buffer) || CheckItem(Terminal::INT, buffer)) {
        return;
    }
    throw std::invalid_argument("\nERROR: Invalid type! Unexpected \"" + buffer.GetOriginalItem() + "\"");
}
