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

class GoogleCloudReply;
class ANDROID_MANAGEMENT_QT_EXPORT EnterprisePolicy
{
    Q_GADGET
public:
    EnterprisePolicy();
    EnterprisePolicy(const EnterprisePolicy &other);
    EnterprisePolicy(const QJsonObject &data);
    EnterprisePolicy(const GoogleCloudReply &data);

    static QList<EnterprisePolicy> policiesFromReply(const GoogleCloudReply &data);

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
    EnterprisePolicy &setMaximumTimeToLock(qint64 value);

    bool screenCaptureDisabled() const;
    EnterprisePolicy &setScreenCaptureDisabled(bool value);

    bool cameraDisabled() const;
    EnterprisePolicy &setCameraDisabled(bool value);

    bool addUserDisabled() const;
    EnterprisePolicy &setAddUserDisabled(bool value);

    bool adjustVolumeDisabled() const;
    EnterprisePolicy &setAdjustVolumeDisabled(bool value);

    bool factoryResetDisabled() const;
    EnterprisePolicy &setFactoryResetDisabled(bool value);

    bool installAppsDisabled() const;
    EnterprisePolicy &setInstallAppsDisabled(bool value);

    bool mountPhysicalMediaDisabled() const;
    EnterprisePolicy &setMountPhysicalMediaDisabled(bool value);

    bool modifyAccountsDisabled() const;
    EnterprisePolicy &setModifyAccountsDisabled(bool value);

    bool safeBootDisabled() const;
    EnterprisePolicy &setSafeBootDisabled(bool value);

    bool uninstallAppsDisabled() const;
    EnterprisePolicy &setUninstallAppsDisabled(bool value);

    [[deprecated]] bool statusBarDisabled() const;
    [[deprecated]] EnterprisePolicy &setStatusBarDisabled(bool value);

    bool keyguardDisabled() const;
    EnterprisePolicy &setKeyguardDisabled(bool value);

    int minimumApiLevel() const;
    EnterprisePolicy &setMinimumApiLevel(int value);

    bool bluetoothContactSharingDisabled() const;
    EnterprisePolicy &setBluetoothContactSharingDisabled(bool value);

    [[deprecated]] bool wifiConfigsLockdownEnabled() const;
    [[deprecated]] EnterprisePolicy &setWifiConfigsLockdownEnabled(bool value);

    bool bluetoothConfigDisabled() const;
    EnterprisePolicy &setBluetoothConfigDisabled(bool value);

    bool cellBroadcastsConfigDisabled() const;
    EnterprisePolicy &setCellBroadcastsConfigDisabled(bool value);

    bool credentialsConfigDisabled() const;
    EnterprisePolicy &setCredentialsConfigDisabled(bool value);

    bool mobileNetworksConfigDisabled() const;
    EnterprisePolicy &setMobileNetworksConfigDisabled(bool value);

    bool tetheringConfigDisabled() const;
    EnterprisePolicy &setTetheringConfigDisabled(bool value);

    bool vpnConfigDisabled() const;
    EnterprisePolicy &setVpnConfigDisabled(bool value);

    bool wifiConfigDisabled() const;
    EnterprisePolicy &setWifiConfigDisabled(bool value);

    bool createWindowsDisabled() const;
    EnterprisePolicy &setCreateWindowsDisabled(bool value);

    bool networkResetDisabled() const;
    EnterprisePolicy &setNetworkResetDisabled(bool value);

    bool outgoingBeamDisabled() const;
    EnterprisePolicy &setOutgoingBeamDisabled(bool value);

    bool outgoingCallsDisabled() const;
    EnterprisePolicy &setOutgoingCallsDisabled(bool value);

    bool removeUserDisabled() const;
    EnterprisePolicy &setRemoveUserDisabled(bool value);

    bool shareLocationDisabled() const;
    EnterprisePolicy &setShareLocationDisabled(bool value);

    bool smsDisabled() const;
    EnterprisePolicy &setSmsDisabled(bool value);

    bool unmuteMicrophoneDisabled() const;
    EnterprisePolicy &setUnmuteMicrophoneDisabled(bool value);

    bool usbFileTransferDisabled() const;
    EnterprisePolicy &setUsbFileTransferDisabled(bool value);

    bool ensureVerifyAppsEnabled() const;
    EnterprisePolicy &setEnsureVerifyAppsEnabled(bool value);

    /*!
     * Whether changing the user icon is disabled.
     */
    bool setUserIconDisabled() const;

    /*!
     * Whether changing the user icon is disabled.
     */
    EnterprisePolicy &setUserIconDisabled(bool value);

    /*!
     * Whether changing the wallpaper is disabled.
     */
    bool setWallpaperDisabled() const;

    /*!
     * Whether changing the wallpaper is disabled.
     */
    EnterprisePolicy &setWallpaperDisabled(bool value);

    bool dataRoamingDisabled() const;
    EnterprisePolicy &setDataRoamingDisabled(bool value);

    enum LocationMode {
        LOCATION_MODE_UNSPECIFIED,
        HIGH_ACCURACY,
        SENSORS_ONLY,
        BATTERY_SAVING,
        OFF,
    };
    Q_ENUM(LocationMode)

    LocationMode locationMode() const;
    EnterprisePolicy &setLocationMode(LocationMode value);

    bool networkEscapeHatchEnabled() const;
    EnterprisePolicy &setNetworkEscapeHatchEnabled(bool value);

    bool bluetoothDisabled() const;
    EnterprisePolicy &setBluetoothDisabled(bool value);

    [[deprecated]] bool blockApplicationsEnabled() const;
    [[deprecated]] EnterprisePolicy &setBlockApplicationsEnabled(bool value);

    bool installUnknownSourcesAllowed() const;
    EnterprisePolicy &setInstallUnknownSourcesAllowed(bool value);

    bool debuggingFeaturesAllowed() const;
    EnterprisePolicy &setDebuggingFeaturesAllowed(bool value);

    bool funDisabled() const;
    EnterprisePolicy &setFunDisabled(bool value);

    bool autoTimeRequired() const;
    EnterprisePolicy &setAutoTimeRequired(bool value);

    bool kioskCustomLauncherEnabled() const;
    EnterprisePolicy &setKioskCustomLauncherEnabled(bool value);

    bool skipFirstUseHintsEnabled() const;
    EnterprisePolicy &setSkipFirstUseHintsEnabled(bool value);

    bool privateKeySelectionEnabled() const;
    EnterprisePolicy &setPrivateKeySelectionEnabled(bool value);

    [[deprecated]] bool usbMassStorageEnabled() const;
    [[deprecated]] EnterprisePolicy &setUsbMassStorageEnabled(bool value);

    QString updateMask(const EnterprisePolicy &other = {});

    QJsonObject data() const;

    void operator=(const EnterprisePolicy &other);

private:
    QJsonObject m_data;
};

}

#endif // ANDROIDMANAGEMENTPOLICY_H
