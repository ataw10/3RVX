// Copyright (c) 2015, Matthew Malensek.
// Distributed under the BSD 2-Clause License (see LICENSE.txt for details)

#pragma once

#pragma comment(lib, "gdiplus.lib")

#include <Windows.h>
#include <gdiplus.h>
#include <vector>

#include "../MeterWnd/Meter.h"
#include "../SoundPlayer.h"

struct MeterComponent {
    Gdiplus::Bitmap *background;
    Gdiplus::Bitmap *mask;
    std::vector<Meter *> meters;
    SoundPlayer *sound = NULL;

    virtual ~MeterComponent() {
        delete background;
        delete mask;
        for (Meter *meter : meters) {
            delete meter;
        }
        delete sound;
    }
};