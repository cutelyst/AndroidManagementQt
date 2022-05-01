/*
 * SPDX-FileCopyrightText: (C) 2022 Daniel Nicoletti <dantti12@gmail.com>
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */
#include "androidmanagementpolicy.h"
#include "googlecloudoauth2.h"

#include <QJsonArray>
#include <QMetaEnum>
#include <QStringList>

using namespace AndroidManagementQt;

EnterprisePolicy::EnterprisePolicy()
{

}

EnterprisePolicy::EnterprisePolicy(const EnterprisePolicy &other) : m_data(other.m_data)
{

}

EnterprisePolicy::EnterprisePolicy(const QJsonObject &data) : m_data(data)
{

}

EnterprisePolicy::EnterprisePolicy(const GoogleCloudReply &data) : m_data(data.data)
{

}

QList<EnterprisePolicy> EnterprisePolicy::policiesFromReply(const GoogleCloudReply &data)
{
    QList<EnterprisePolicy> ret;
    const QJsonArray array = data.data.value(QStringLiteral("policies")).toArray();
    for (const QJsonValue &p : array) {
        ret.push_back(p.toObject());
    }
    return ret;
}

QString EnterprisePolicy::name() const
{
    return m_data[u"name"].toString();
}

QString EnterprisePolicy::version() const
{
    return m_data[u"version"].toString();
}

QString EnterprisePolicy::maximumTimeToLock() const
{
    return m_data[u"maximumTimeToLock"].toString();
}

EnterprisePolicy &EnterprisePolicy::setMaximumTimeToLock(qint64 value)
{
    m_data[u"maximumTimeToLock"] = QString::number(value);
    return *this;
}

bool EnterprisePolicy::screenCaptureDisabled() const
{
    return m_data[u"screenCaptureDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setScreenCaptureDisabled(bool value)
{
    m_data[u"screenCaptureDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::cameraDisabled() const
{
    return m_data[u"cameraDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setCameraDisabled(bool value)
{
    m_data[u"cameraDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::addUserDisabled() const
{
    return m_data[u"addUserDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setAddUserDisabled(bool value)
{
    m_data[u"addUserDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::adjustVolumeDisabled() const
{
    return m_data[u"adjustVolumeDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setAdjustVolumeDisabled(bool value)
{
    m_data[u"adjustVolumeDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::factoryResetDisabled() const
{
    return m_data[u"factoryResetDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setFactoryResetDisabled(bool value)
{
    m_data[u"factoryResetDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::installAppsDisabled() const
{
    return m_data[u"installAppsDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setInstallAppsDisabled(bool value)
{
    m_data[u"installAppsDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::mountPhysicalMediaDisabled() const
{
    return m_data[u"mountPhysicalMediaDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setMountPhysicalMediaDisabled(bool value)
{
    m_data[u"mountPhysicalMediaDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::modifyAccountsDisabled() const
{
    return m_data[u"modifyAccountsDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setModifyAccountsDisabled(bool value)
{
    m_data[u"modifyAccountsDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::safeBootDisabled() const
{
    return m_data[u"safeBootDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setSafeBootDisabled(bool value)
{
    m_data[u"safeBootDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::uninstallAppsDisabled() const
{
    return m_data[u"uninstallAppsDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setUninstallAppsDisabled(bool value)
{
    m_data[u"uninstallAppsDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::statusBarDisabled() const
{
    return m_data[u"statusBarDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setStatusBarDisabled(bool value)
{
    m_data[u"statusBarDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::keyguardDisabled() const
{
    return m_data[u"keyguardDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setKeyguardDisabled(bool value)
{
    m_data[u"keyguardDisabled"] = value;
    return *this;
}

int EnterprisePolicy::minimumApiLevel() const
{
    return m_data[u"minimumApiLevel"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setMinimumApiLevel(int value)
{
    m_data[u"minimumApiLevel"] = value;
    return *this;
}

bool EnterprisePolicy::bluetoothContactSharingDisabled() const
{
    return m_data[u"bluetoothContactSharingDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setBluetoothContactSharingDisabled(bool value)
{
    m_data[u"bluetoothContactSharingDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::wifiConfigsLockdownEnabled() const
{
    return m_data[u"wifiConfigsLockdownEnabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setWifiConfigsLockdownEnabled(bool value)
{
    m_data[u"wifiConfigsLockdownEnabled"] = value;
    return *this;
}

bool EnterprisePolicy::bluetoothConfigDisabled() const
{
    return m_data[u"bluetoothConfigDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setBluetoothConfigDisabled(bool value)
{
    m_data[u"bluetoothConfigDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::cellBroadcastsConfigDisabled() const
{
    return m_data[u"cellBroadcastsConfigDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setCellBroadcastsConfigDisabled(bool value)
{
    m_data[u"cellBroadcastsConfigDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::credentialsConfigDisabled() const
{
    return m_data[u"credentialsConfigDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setCredentialsConfigDisabled(bool value)
{
    m_data[u"credentialsConfigDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::mobileNetworksConfigDisabled() const
{
    return m_data[u"mobileNetworksConfigDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setMobileNetworksConfigDisabled(bool value)
{
    m_data[u"mobileNetworksConfigDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::tetheringConfigDisabled() const
{
    return m_data[u"tetheringConfigDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setTetheringConfigDisabled(bool value)
{
    m_data[u"tetheringConfigDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::vpnConfigDisabled() const
{
    return m_data[u"vpnConfigDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setVpnConfigDisabled(bool value)
{
    m_data[u"vpnConfigDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::wifiConfigDisabled() const
{
    return m_data[u"wifiConfigDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setWifiConfigDisabled(bool value)
{
    m_data[u"wifiConfigDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::createWindowsDisabled() const
{
    return m_data[u"createWindowsDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setCreateWindowsDisabled(bool value)
{
    m_data[u"createWindowsDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::networkResetDisabled() const
{
    return m_data[u"networkResetDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setNetworkResetDisabled(bool value)
{
    m_data[u"networkResetDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::outgoingBeamDisabled() const
{
    return m_data[u"outgoingBeamDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setOutgoingBeamDisabled(bool value)
{
    m_data[u"outgoingBeamDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::outgoingCallsDisabled() const
{
    return m_data[u"outgoingCallsDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setOutgoingCallsDisabled(bool value)
{
    m_data[u"outgoingCallsDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::removeUserDisabled() const
{
    return m_data[u"removeUserDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setRemoveUserDisabled(bool value)
{
    m_data[u"removeUserDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::shareLocationDisabled() const
{
    return m_data[u"shareLocationDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setShareLocationDisabled(bool value)
{
    m_data[u"shareLocationDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::smsDisabled() const
{
    return m_data[u"smsDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setSmsDisabled(bool value)
{
    m_data[u"smsDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::unmuteMicrophoneDisabled() const
{
    return m_data[u"unmuteMicrophoneDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setUnmuteMicrophoneDisabled(bool value)
{
    m_data[u"unmuteMicrophoneDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::usbFileTransferDisabled() const
{
    return m_data[u"usbFileTransferDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setUsbFileTransferDisabled(bool value)
{
    m_data[u"usbFileTransferDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::ensureVerifyAppsEnabled() const
{
    return m_data[u"ensureVerifyAppsEnabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setEnsureVerifyAppsEnabled(bool value)
{
    m_data[u"ensureVerifyAppsEnabled"] = value;
    return *this;
}

bool EnterprisePolicy::setUserIconDisabled() const
{
    return m_data[u"setUserIconDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setUserIconDisabled(bool value)
{
    m_data[u"setUserIconDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::setWallpaperDisabled() const
{
    return m_data[u"setWallpaperDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setWallpaperDisabled(bool value)
{
    m_data[u"setWallpaperDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::dataRoamingDisabled() const
{
    return m_data[u"dataRoamingDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setDataRoamingDisabled(bool value)
{
    m_data[u"dataRoamingDisabled"] = value;
    return *this;
}

EnterprisePolicy::LocationMode EnterprisePolicy::locationMode() const
{
    const QString mode = m_data[u"locationMode"].toString();
    const int idx = staticMetaObject.indexOfEnumerator("LocationMode");
    if (idx != -1) {
        QMetaEnum me = staticMetaObject.enumerator(idx);
        return static_cast<EnterprisePolicy::LocationMode>(me.keyToValue(mode.toLatin1().constData()));
    }
    return LOCATION_MODE_UNSPECIFIED;
}

EnterprisePolicy &EnterprisePolicy::setLocationMode(EnterprisePolicy::LocationMode value)
{
    const int idx = staticMetaObject.indexOfEnumerator("LocationMode");
    if (idx != -1) {
        QMetaEnum me = staticMetaObject.enumerator(idx);
        m_data[u"locationMode"] = QString::fromLatin1(me.valueToKey(value));
    }
    return *this;
}

bool EnterprisePolicy::networkEscapeHatchEnabled() const
{
    return m_data[u"networkEscapeHatchEnabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setNetworkEscapeHatchEnabled(bool value)
{
    m_data[u"networkEscapeHatchEnabled"] = value;
    return *this;
}

bool EnterprisePolicy::bluetoothDisabled() const
{
    return m_data[u"bluetoothDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setBluetoothDisabled(bool value)
{
    m_data[u"bluetoothDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::blockApplicationsEnabled() const
{
    return m_data[u"blockApplicationsEnabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setBlockApplicationsEnabled(bool value)
{
    m_data[u"blockApplicationsEnabled"] = value;
    return *this;
}

bool EnterprisePolicy::installUnknownSourcesAllowed() const
{
    return m_data[u"installUnknownSourcesAllowed"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setInstallUnknownSourcesAllowed(bool value)
{
    m_data[u"installUnknownSourcesAllowed"] = value;
    return *this;
}

bool EnterprisePolicy::debuggingFeaturesAllowed() const
{
    return m_data[u"debuggingFeaturesAllowed"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setDebuggingFeaturesAllowed(bool value)
{
    m_data[u"debuggingFeaturesAllowed"] = value;
    return *this;
}

bool EnterprisePolicy::funDisabled() const
{
    return m_data[u"funDisabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setFunDisabled(bool value)
{
    m_data[u"funDisabled"] = value;
    return *this;
}

bool EnterprisePolicy::autoTimeRequired() const
{
    return m_data[u"autoTimeRequired"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setAutoTimeRequired(bool value)
{
    m_data[u"autoTimeRequired"] = value;
    return *this;
}

bool EnterprisePolicy::kioskCustomLauncherEnabled() const
{
    return m_data[u"kioskCustomLauncherEnabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setKioskCustomLauncherEnabled(bool value)
{
    m_data[u"kioskCustomLauncherEnabled"] = value;
    return *this;
}

bool EnterprisePolicy::skipFirstUseHintsEnabled() const
{
    return m_data[u"skipFirstUseHintsEnabled"].toBool();
}

EnterprisePolicy &EnterprisePolicy::setSkipFirstUseHintsEnabled(bool value)
{
    m_data[u"skipFirstUseHintsEnabled"] = value;
    return *this;
}

const static auto s_privateKeySelectionEnabled = u"privateKeySelectionEnabled";
bool EnterprisePolicy::privateKeySelectionEnabled() const
{
    return m_data[s_privateKeySelectionEnabled].toBool();
}

EnterprisePolicy &EnterprisePolicy::setPrivateKeySelectionEnabled(bool value)
{
    m_data[s_privateKeySelectionEnabled] = value;
    return *this;
}

const static auto s_usbMassStorageEnabled = u"usbMassStorageEnabled";
bool EnterprisePolicy::usbMassStorageEnabled() const
{
    return m_data[s_usbMassStorageEnabled].toBool();
}

EnterprisePolicy &EnterprisePolicy::setUsbMassStorageEnabled(bool value)
{
    m_data[s_usbMassStorageEnabled] = value;
    return *this;
}

QString EnterprisePolicy::updateMask(const EnterprisePolicy &other)
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

QJsonObject EnterprisePolicy::data() const
{
    return m_data;
}

void EnterprisePolicy::operator=(const EnterprisePolicy &other)
{
    m_data = other.m_data;
}
