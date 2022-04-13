/*
 * SPDX-FileCopyrightText: (C) 2022 Daniel Nicoletti <dantti12@gmail.com>
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */
#include "androidmanagementpolicy.h"

#include <QMetaEnum>
#include <QStringList>

using namespace AndroidManagementQt;

AndroidManagementPolicy::AndroidManagementPolicy()
{

}

AndroidManagementPolicy::AndroidManagementPolicy(const AndroidManagementPolicy &other) : m_data(other.m_data)
{

}

AndroidManagementPolicy::AndroidManagementPolicy(const QJsonObject &data) : m_data(data)
{

}

QString AndroidManagementPolicy::name() const
{
    return m_data[QLatin1String("name")].toString();
}

QString AndroidManagementPolicy::version() const
{
    return m_data[QLatin1String("version")].toString();
}

QString AndroidManagementPolicy::maximumTimeToLock() const
{
    return m_data[QLatin1String("maximumTimeToLock")].toString();
}

AndroidManagementPolicy &AndroidManagementPolicy::setMaximumTimeToLock(qint64 value)
{
    m_data[QLatin1String("maximumTimeToLock")] = QString::number(value);
    return *this;
}

bool AndroidManagementPolicy::screenCaptureDisabled() const
{
    return m_data[QLatin1String("screenCaptureDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setScreenCaptureDisabled(bool value)
{
    m_data[QLatin1String("screenCaptureDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::cameraDisabled() const
{
    return m_data[QLatin1String("cameraDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setCameraDisabled(bool value)
{
    m_data[QLatin1String("cameraDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::addUserDisabled() const
{
    return m_data[QLatin1String("addUserDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setAddUserDisabled(bool value)
{
    m_data[QLatin1String("addUserDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::adjustVolumeDisabled() const
{
    return m_data[QLatin1String("adjustVolumeDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setAdjustVolumeDisabled(bool value)
{
    m_data[QLatin1String("adjustVolumeDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::factoryResetDisabled() const
{
    return m_data[QLatin1String("factoryResetDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setFactoryResetDisabled(bool value)
{
    m_data[QLatin1String("factoryResetDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::installAppsDisabled() const
{
    return m_data[QLatin1String("installAppsDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setInstallAppsDisabled(bool value)
{
    m_data[QLatin1String("installAppsDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::mountPhysicalMediaDisabled() const
{
    return m_data[QLatin1String("mountPhysicalMediaDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setMountPhysicalMediaDisabled(bool value)
{
    m_data[QLatin1String("mountPhysicalMediaDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::modifyAccountsDisabled() const
{
    return m_data[QLatin1String("modifyAccountsDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setModifyAccountsDisabled(bool value)
{
    m_data[QLatin1String("modifyAccountsDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::safeBootDisabled() const
{
    return m_data[QLatin1String("safeBootDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setSafeBootDisabled(bool value)
{
    m_data[QLatin1String("safeBootDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::uninstallAppsDisabled() const
{
    return m_data[QLatin1String("uninstallAppsDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setUninstallAppsDisabled(bool value)
{
    m_data[QLatin1String("uninstallAppsDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::statusBarDisabled() const
{
    return m_data[QLatin1String("statusBarDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setStatusBarDisabled(bool value)
{
    m_data[QLatin1String("statusBarDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::keyguardDisabled() const
{
    return m_data[QLatin1String("keyguardDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setKeyguardDisabled(bool value)
{
    m_data[QLatin1String("keyguardDisabled")] = value;
    return *this;
}

int AndroidManagementPolicy::minimumApiLevel() const
{
    return m_data[QLatin1String("minimumApiLevel")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setMinimumApiLevel(int value)
{
    m_data[QLatin1String("minimumApiLevel")] = value;
    return *this;
}

bool AndroidManagementPolicy::bluetoothContactSharingDisabled() const
{
    return m_data[QLatin1String("bluetoothContactSharingDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setBluetoothContactSharingDisabled(bool value)
{
    m_data[QLatin1String("bluetoothContactSharingDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::wifiConfigsLockdownEnabled() const
{
    return m_data[QLatin1String("wifiConfigsLockdownEnabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setWifiConfigsLockdownEnabled(bool value)
{
    m_data[QLatin1String("wifiConfigsLockdownEnabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::bluetoothConfigDisabled() const
{
    return m_data[QLatin1String("bluetoothConfigDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setBluetoothConfigDisabled(bool value)
{
    m_data[QLatin1String("bluetoothConfigDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::cellBroadcastsConfigDisabled() const
{
    return m_data[QLatin1String("cellBroadcastsConfigDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setCellBroadcastsConfigDisabled(bool value)
{
    m_data[QLatin1String("cellBroadcastsConfigDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::credentialsConfigDisabled() const
{
    return m_data[QLatin1String("credentialsConfigDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setCredentialsConfigDisabled(bool value)
{
    m_data[QLatin1String("credentialsConfigDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::mobileNetworksConfigDisabled() const
{
    return m_data[QLatin1String("mobileNetworksConfigDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setMobileNetworksConfigDisabled(bool value)
{
    m_data[QLatin1String("mobileNetworksConfigDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::tetheringConfigDisabled() const
{
    return m_data[QLatin1String("tetheringConfigDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setTetheringConfigDisabled(bool value)
{
    m_data[QLatin1String("tetheringConfigDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::vpnConfigDisabled() const
{
    return m_data[QLatin1String("vpnConfigDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setVpnConfigDisabled(bool value)
{
    m_data[QLatin1String("vpnConfigDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::wifiConfigDisabled() const
{
    return m_data[QLatin1String("wifiConfigDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setWifiConfigDisabled(bool value)
{
    m_data[QLatin1String("wifiConfigDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::createWindowsDisabled() const
{
    return m_data[QLatin1String("createWindowsDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setCreateWindowsDisabled(bool value)
{
    m_data[QLatin1String("createWindowsDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::networkResetDisabled() const
{
    return m_data[QLatin1String("networkResetDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setNetworkResetDisabled(bool value)
{
    m_data[QLatin1String("networkResetDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::outgoingBeamDisabled() const
{
    return m_data[QLatin1String("outgoingBeamDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setOutgoingBeamDisabled(bool value)
{
    m_data[QLatin1String("outgoingBeamDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::outgoingCallsDisabled() const
{
    return m_data[QLatin1String("outgoingCallsDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setOutgoingCallsDisabled(bool value)
{
    m_data[QLatin1String("outgoingCallsDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::removeUserDisabled() const
{
    return m_data[QLatin1String("removeUserDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setRemoveUserDisabled(bool value)
{
    m_data[QLatin1String("removeUserDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::shareLocationDisabled() const
{
    return m_data[QLatin1String("shareLocationDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setShareLocationDisabled(bool value)
{
    m_data[QLatin1String("shareLocationDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::smsDisabled() const
{
    return m_data[QLatin1String("smsDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setSmsDisabled(bool value)
{
    m_data[QLatin1String("smsDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::unmuteMicrophoneDisabled() const
{
    return m_data[QLatin1String("unmuteMicrophoneDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setUnmuteMicrophoneDisabled(bool value)
{
    m_data[QLatin1String("unmuteMicrophoneDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::usbFileTransferDisabled() const
{
    return m_data[QLatin1String("usbFileTransferDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setUsbFileTransferDisabled(bool value)
{
    m_data[QLatin1String("usbFileTransferDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::ensureVerifyAppsEnabled() const
{
    return m_data[QLatin1String("ensureVerifyAppsEnabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setEnsureVerifyAppsEnabled(bool value)
{
    m_data[QLatin1String("ensureVerifyAppsEnabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::setUserIconDisabled() const
{
    return m_data[QLatin1String("setUserIconDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setUserIconDisabled(bool value)
{
    m_data[QLatin1String("setUserIconDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::setWallpaperDisabled() const
{
    return m_data[QLatin1String("setWallpaperDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setWallpaperDisabled(bool value)
{
    m_data[QLatin1String("setWallpaperDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::dataRoamingDisabled() const
{
    return m_data[QLatin1String("dataRoamingDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setDataRoamingDisabled(bool value)
{
    m_data[QLatin1String("dataRoamingDisabled")] = value;
    return *this;
}

AndroidManagementPolicy::LocationMode AndroidManagementPolicy::locationMode() const
{
    const QString mode = m_data[QLatin1String("locationMode")].toString();
    const int idx = staticMetaObject.indexOfEnumerator("LocationMode");
    if (idx != -1) {
        QMetaEnum me = staticMetaObject.enumerator(idx);
        return static_cast<AndroidManagementPolicy::LocationMode>(me.keyToValue(mode.toLatin1().constData()));
    }
    return LOCATION_MODE_UNSPECIFIED;
}

AndroidManagementPolicy &AndroidManagementPolicy::setLocationMode(AndroidManagementPolicy::LocationMode value)
{
    const int idx = staticMetaObject.indexOfEnumerator("LocationMode");
    if (idx != -1) {
        QMetaEnum me = staticMetaObject.enumerator(idx);
        m_data[QLatin1String("locationMode")] = QString::fromLatin1(me.valueToKey(value));
    }
    return *this;
}

bool AndroidManagementPolicy::networkEscapeHatchEnabled() const
{
    return m_data[QLatin1String("networkEscapeHatchEnabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setNetworkEscapeHatchEnabled(bool value)
{
    m_data[QLatin1String("networkEscapeHatchEnabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::bluetoothDisabled() const
{
    return m_data[QLatin1String("bluetoothDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setBluetoothDisabled(bool value)
{
    m_data[QLatin1String("bluetoothDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::blockApplicationsEnabled() const
{
    return m_data[QLatin1String("blockApplicationsEnabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setBlockApplicationsEnabled(bool value)
{
    m_data[QLatin1String("blockApplicationsEnabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::installUnknownSourcesAllowed() const
{
    return m_data[QLatin1String("installUnknownSourcesAllowed")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setInstallUnknownSourcesAllowed(bool value)
{
    m_data[QLatin1String("installUnknownSourcesAllowed")] = value;
    return *this;
}

bool AndroidManagementPolicy::debuggingFeaturesAllowed() const
{
    return m_data[QLatin1String("debuggingFeaturesAllowed")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setDebuggingFeaturesAllowed(bool value)
{
    m_data[QLatin1String("debuggingFeaturesAllowed")] = value;
    return *this;
}

bool AndroidManagementPolicy::funDisabled() const
{
    return m_data[QLatin1String("funDisabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setFunDisabled(bool value)
{
    m_data[QLatin1String("funDisabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::autoTimeRequired() const
{
    return m_data[QLatin1String("autoTimeRequired")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setAutoTimeRequired(bool value)
{
    m_data[QLatin1String("autoTimeRequired")] = value;
    return *this;
}

bool AndroidManagementPolicy::kioskCustomLauncherEnabled() const
{
    return m_data[QLatin1String("kioskCustomLauncherEnabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setKioskCustomLauncherEnabled(bool value)
{
    m_data[QLatin1String("kioskCustomLauncherEnabled")] = value;
    return *this;
}

bool AndroidManagementPolicy::skipFirstUseHintsEnabled() const
{
    return m_data[QLatin1String("skipFirstUseHintsEnabled")].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setSkipFirstUseHintsEnabled(bool value)
{
    m_data[QLatin1String("skipFirstUseHintsEnabled")] = value;
    return *this;
}

const static auto s_privateKeySelectionEnabled = QLatin1String("privateKeySelectionEnabled");
bool AndroidManagementPolicy::privateKeySelectionEnabled() const
{
    return m_data[s_privateKeySelectionEnabled].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setPrivateKeySelectionEnabled(bool value)
{
    m_data[s_privateKeySelectionEnabled] = value;
    return *this;
}

const static auto s_usbMassStorageEnabled = QLatin1String("usbMassStorageEnabled");
bool AndroidManagementPolicy::usbMassStorageEnabled() const
{
    return m_data[s_usbMassStorageEnabled].toBool();
}

AndroidManagementPolicy &AndroidManagementPolicy::setUsbMassStorageEnabled(bool value)
{
    m_data[s_usbMassStorageEnabled] = value;
    return *this;
}

QString AndroidManagementPolicy::updateMask(const AndroidManagementPolicy &other)
{
    QStringList ret;
    QJsonObject otherObj = other.data();

    auto it = m_data.constBegin();
    while (it != m_data.constEnd()) {
        auto otherIt = otherObj.constFind(it.key());
        if (otherIt == otherObj.constEnd() || it.value() != otherIt.value()) {
            ret.append(it.key());
        }
        ++it;
    }

    return ret.join(QLatin1Char(','));
}

QJsonObject AndroidManagementPolicy::data() const
{
    return m_data;
}
