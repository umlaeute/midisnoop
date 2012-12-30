/*
 * midisnoop - MIDI monitor and prober
 * Copyright (C) 2012 Devin Anderson
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 675 Mass
 * Ave, Cambridge, MA 02139, USA.
 */

#ifndef __VIEW_H__
#define __VIEW_H__

#include <QtGui/QWidget>

#include "closeeventfilter.h"

class View: public QObject {

    Q_OBJECT

public:

    bool
    isCloseEnabled() const;

    bool
    isVisible() const;

public slots:

    void
    hide();

    virtual void
    setCloseEnabled(bool enabled);

    virtual void
    setVisible(bool visible);

    void
    show();

signals:

    void
    closeEnabledChanged(bool enabled);

    void
    closeRequest();

    void
    visibilityChanged(bool visible);

protected:

    explicit
    View(QWidget *rootWidget, QObject *parent=0);

    virtual
    ~View();

    const QWidget *
    getRootWidget() const;

    QWidget *
    getRootWidget();

private:

    CloseEventFilter closeEventFilter;
    QWidget *rootWidget;

};

#endif