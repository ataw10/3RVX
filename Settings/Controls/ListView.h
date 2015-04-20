#pragma once

#include "Control.h"

class ListView : public Control {
public:
    ListView() :
    _columns(0) {

    }

    ListView(int id, HWND parent) :
    Control(id, parent),
    _columns(0) {

    }

    void AddColumn(std::wstring name, int width);
    void InsertColumn(int index, std::wstring name, int width);

    int AddItem(std::wstring item);
    int InsertItem(int index, std::wstring item);

    void ItemText(int index, int subIndex, std::wstring str);

    int Size();

private:
    int _columns;
};