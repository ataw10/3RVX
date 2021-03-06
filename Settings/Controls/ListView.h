// Copyright (c) 2015, Matthew Malensek.
// Distributed under the BSD 2-Clause License (see LICENSE.txt for details)

#pragma once

#include <Windows.h>
#include <CommCtrl.h>

#include "Control.h"

class ListView : public Control {
public:
    ListView(int id, Dialog &parent) :
    Control(id, parent, false),
    _columns(0) {

    }

    void AddListExStyle(DWORD style);

    void AddColumn(std::wstring name, int width);
    void InsertColumn(int index, std::wstring name, int width);

    int Count();

    int AddItem(std::wstring item);
    int InsertItem(int index, std::wstring item);
    std::wstring ItemText(int index, int subIndex);
    void ItemText(int index, int subIndex, std::wstring str);

    void RemoveItem(int index);

    bool Checked(int index);
    void Checked(int index, bool checked);

    int Selection();
    void Selection(int index);

    virtual BOOL CALLBACK Notification(NMHDR *nHdr);

public:
    /* Event Handlers */
    std::function<void(NMLISTVIEW *lv)> OnItemChange;

protected:
    void ItemState(int index, unsigned int state, unsigned int mask);

private:
    int _columns;
    static const int LVIS_UNCHECKED = 0x1000;
    static const int LVIS_CHECKED = 0x2000;
};