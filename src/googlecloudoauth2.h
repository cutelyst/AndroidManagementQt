/*
 * SPDX-FileCopyrightText: (C) 2022 Daniel Nicoletti <dantti12@gmail.com>
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */
#ifndef GOOGLECLOUDOAUTH2_H
#define GOOGLECLOUDOAUTH2_H

#include <QObject>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QElapsedTimer>
#include <QPointer>

#include <androidmanagementexports.h>

namespace AndroidManagementQt {

struct ANDROID_MANAGEMENT_QT_EXPORT GoogleCloudReply {
    QJsonObject data;
    bool error = false;
};

struct ANDROID_MANAGEMENT_QT_EXPORT GoogleCloudCode {
    QPointer<const QObject> receiver;
    std::function<void(const GoogleCloudReply &)> code;
};

class ANDROID_MANAGEMENT_QT_EXPORT GoogleCloudOAuth2 : public QObject
{
    Q_OBJECT
public:
    explicit GoogleCloudOAuth2(QObject *parent = nullptr);

    void setAccountCredentialFile(const QString &filename);
    void setAccountCredentialData(const QByteArray &data);

    void setAccountCredential(const QJsonObject &accountCredential);
    QJsonObject accountCredential() const;

    QNetworkAccessManager *networkAccessManager() const;
    void setNetworkAccessManager(QNetworkAccessManager *nam);

    virtual QNetworkRequest defaultRequest(const QUrl &url) const;
    QByteArray accessTokenHeader() const;

    void setScopes(const QStringList &scopes);

    void getAccessToken();

    void getAccessToken(const QObject *receiver, std::function<void(const GoogleCloudReply &)> code);

protected:
    QNetworkAccessManager *m_nam;

private:
    QByteArray m_accessTokenHeader;
    QStringList m_scopes;
    QJsonObject m_credentialsFile;
    QJsonObject m_token;
    std::vector<GoogleCloudCode> m_codeToRun;
    QElapsedTimer m_expiresTimer;
    qint64 m_expires = 0;
    bool m_gettingToken = false;
};

}

#endif // GOOGLECLOUDOAUTH2_H
