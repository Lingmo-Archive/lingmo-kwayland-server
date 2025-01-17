/*
    SPDX-FileCopyrightText: 2019 Aleix Pol Gonzalez <aleixpol@kde.org>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#ifndef KWAYLAND_KEYSTATE_INTERFACE_H
#define KWAYLAND_KEYSTATE_INTERFACE_H

#include <KWaylandServer/kwaylandserver_export.h>
#include "global.h"
#include "resource.h"

namespace KWaylandServer
{

class Display;

/**
 * @brief Exposes key states to wayland clients
 *
 * @since 5.58
 **/
class KWAYLANDSERVER_EXPORT KeyStateInterface : public Global
{
    Q_OBJECT
public:
    virtual ~KeyStateInterface();

    enum class Key {
        CapsLock = 0,
        NumLock = 1,
        ScrollLock = 2,
    };
    Q_ENUM(Key);
    enum State {
        Unlocked = 0,
        Latched = 1,
        Locked = 2,
    };
    Q_ENUM(State)

    void setState(Key k, State s);

private:
    explicit KeyStateInterface(Display *display, QObject *parent = nullptr);
    friend class Display;

    class Private;
};

}

#endif
