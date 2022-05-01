/* 
 * SPDX-FileCopyrightText: (C) 2022 Daniel Nicoletti <dantti12@gmail.com>
 * SPDX-License-Identifier: MIT
 */

#ifndef ANDROID_MANAGEMENT_QT_EXPORT_H
#define ANDROID_MANAGEMENT_QT_EXPORT_H

#include <QtCore/QtGlobal>

#if defined(AndroidManagement0Qt5_EXPORTS) || defined(AndroidManagement0Qt6_EXPORTS)
#define ANDROID_MANAGEMENT_QT_EXPORT Q_DECL_EXPORT
#else
#define ANDROID_MANAGEMENT_QT_EXPORT Q_DECL_IMPORT
#endif

#endif
