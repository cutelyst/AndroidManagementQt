/*
 * SPDX-FileCopyrightText: (C) 2022 Daniel Nicoletti <dantti12@gmail.com>
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */
#ifndef ANDROIDMANAGEMENTPOLICY_H
#define ANDROIDMANAGEMENTPOLICY_H

#include <QJsonObject>
#include <QObject>

#include <androidmanagementexports.h>

namespace AndroidManagementQt {

class ANDROID_MANAGEMENT_QT_EXPORT AndroidManagementPolicy
{
    Q_GADGET
public:
    AndroidManagementPolicy();
    AndroidManagementPolicy(const AndroidManagementPolicy &other);
    AndroidManagementPolicy(const QJsonObject &data);

    /*!
     * The name of the policy in the form enterprises/{enterpriseId}/policies/{policyId}.
     */
    QString name() const;

    /*!
     * The version of the policy (int64).
     * This is a read-only field. The version is incremented each time the policy is updated.
     */
    QString version() const;

    /*!
     * Maximum time in milliseconds (int64) for user activity until the device locks.
     * A value of 0 means there is no restriction.
     */
    QString maximumTimeToLock() const;

    /*!
     * Maximum time in milliseconds (int64) for user activity until the device locks.
     * A value of 0 means there is no restriction.
     */
    AndroidManagementPolicy &setMaximumTimeToLock(qint64 value);

    bool screenCaptureDisabled() const;
    AndroidManagementPolicy &setScreenCaptureDisabled(bool value);

    bool cameraDisabled() const;
    AndroidManagementPolicy &setCameraDisabled(bool value);

    bool addUserDisabled() const;
    AndroidManagementPolicy &setAddUserDisabled(bool value);

    bool adjustVolumeDisabled() const;
    AndroidManagementPolicy &setAdjustVolumeDisabled(bool value);

    bool factoryResetDisabled() const;
    AndroidManagementPolicy &setFactoryResetDisabled(bool value);

    bool installAppsDisabled() const;
    AndroidManagementPolicy &setInstallAppsDisabled(bool value);

    bool mountPhysicalMediaDisabled() const;
    AndroidManagementPolicy &setMountPhysicalMediaDisabled(bool value);

    bool modifyAccountsDisabled() const;
    AndroidManagementPolicy &setModifyAccountsDisabled(bool value);

    bool safeBootDisabled() const;
    AndroidManagementPolicy &setSafeBootDisabled(bool value);

    bool uninstallAppsDisabled() const;
    AndroidManagementPolicy &setUninstallAppsDisabled(bool value);

    [[deprecated]] bool statusBarDisabled() const;
    [[deprecated]] AndroidManagementPolicy &setStatusBarDisabled(bool value);

    bool keyguardDisabled() const;
    AndroidManagementPolicy &setKeyguardDisabled(bool value);

    int minimumApiLevel() const;
    AndroidManagementPolicy &setMinimumApiLevel(int value);

    bool bluetoothContactSharingDisabled() const;
    AndroidManagementPolicy &setBluetoothContactSharingDisabled(bool value);

    [[deprecated]] bool wifiConfigsLockdownEnabled() const;
    [[deprecated]] AndroidManagementPolicy &setWifiConfigsLockdownEnabled(bool value);

    bool bluetoothConfigDisabled() const;
    AndroidManagementPolicy &setBluetoothConfigDisabled(bool value);

    bool cellBroadcastsConfigDisabled() const;
    AndroidManagementPolicy &setCellBroadcastsConfigDisabled(bool value);

    bool credentialsConfigDisabled() const;
    AndroidManagementPolicy &setCredentialsConfigDisabled(bool value);

    bool mobileNetworksConfigDisabled() const;
    AndroidManagementPolicy &setMobileNetworksConfigDisabled(bool value);

    bool tetheringConfigDisabled() const;
    AndroidManagementPolicy &setTetheringConfigDisabled(bool value);

    bool vpnConfigDisabled() const;
    AndroidManagementPolicy &setVpnConfigDisabled(bool value);

    bool wifiConfigDisabled() const;
    AndroidManagementPolicy &setWifiConfigDisabled(bool value);

    bool createWindowsDisabled() const;
    AndroidManagementPolicy &setCreateWindowsDisabled(bool value);

    bool networkResetDisabled() const;
    AndroidManagementPolicy &setNetworkResetDisabled(bool value);

    bool outgoingBeamDisabled() const;
    AndroidManagementPolicy &setOutgoingBeamDisabled(bool value);

    bool outgoingCallsDisabled() const;
    AndroidManagementPolicy &setOutgoingCallsDisabled(bool value);

    bool removeUserDisabled() const;
    AndroidManagementPolicy &setRemoveUserDisabled(bool value);

    bool shareLocationDisabled() const;
    AndroidManagementPolicy &setShareLocationDisabled(bool value);

    bool smsDisabled() const;
    AndroidManagementPolicy &setSmsDisabled(bool value);

    bool unmuteMicrophoneDisabled() const;
    AndroidManagementPolicy &setUnmuteMicrophoneDisabled(bool value);

    bool usbFileTransferDisabled() const;
    AndroidManagementPolicy &setUsbFileTransferDisabled(bool value);

    bool ensureVerifyAppsEnabled() const;
    AndroidManagementPolicy &setEnsureVerifyAppsEnabled(bool value);

    /*!
     * Whether changing the user icon is disabled.
     */
    bool setUserIconDisabled() const;

    /*!
     * Whether changing the user icon is disabled.
     */
    AndroidManagementPolicy &setUserIconDisabled(bool value);

    /*!
     * Whether changing the wallpaper is disabled.
     */
    bool setWallpaperDisabled() const;

    /*!
     * Whether changing the wallpaper is disabled.
     */
    AndroidManagementPolicy &setWallpaperDisabled(bool value);

    bool dataRoamingDisabled() const;
    AndroidManagementPolicy &setDataRoamingDisabled(bool value);

    enum LocationMode {
        LOCATION_MODE_UNSPECIFIED,
        HIGH_ACCURACY,
        SENSORS_ONLY,
        BATTERY_SAVING,
        OFF,
    };
    Q_ENUM(LocationMode)

    LocationMode locationMode() const;
    AndroidManagementPolicy &setLocationMode(LocationMode value);

    bool networkEscapeHatchEnabled() const;
    AndroidManagementPolicy &setNetworkEscapeHatchEnabled(bool value);

    bool bluetoothDisabled() const;
    AndroidManagementPolicy &setBluetoothDisabled(bool value);

    [[deprecated]] bool blockApplicationsEnabled() const;
    [[deprecated]] AndroidManagementPolicy &setBlockApplicationsEnabled(bool value);

    bool installUnknownSourcesAllowed() const;
    AndroidManagementPolicy &setInstallUnknownSourcesAllowed(bool value);

    bool debuggingFeaturesAllowed() const;
    AndroidManagementPolicy &setDebuggingFeaturesAllowed(bool value);

    bool funDisabled() const;
    AndroidManagementPolicy &setFunDisabled(bool value);

    bool autoTimeRequired() const;
    AndroidManagementPolicy &setAutoTimeRequired(bool value);

    bool kioskCustomLauncherEnabled() const;
    AndroidManagementPolicy &setKioskCustomLauncherEnabled(bool value);

    bool skipFirstUseHintsEnabled() const;
    AndroidManagementPolicy &setSkipFirstUseHintsEnabled(bool value);

    bool privateKeySelectionEnabled() const;
    AndroidManagementPolicy &setPrivateKeySelectionEnabled(bool value);

    [[deprecated]] bool usbMassStorageEnabled() const;
    [[deprecated]] AndroidManagementPolicy &setUsbMassStorageEnabled(bool value);

    QString updateMask(const AndroidManagementPolicy &other = {});

    QJsonObject data() const;

private:
    QJsonObject m_data;
};

}

#endif // ANDROIDMANAGEMENTPOLICY_H
