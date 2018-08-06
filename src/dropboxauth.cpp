#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "endpoints.h"
#include "dropboxauth.h"


namespace Dropbox {

DropboxAuth::DropboxAuth(QString token, QObject *parent)
    : DropboxBase(parent), m_apiToken(token)
{}

DropboxAuth::DropboxAuth(QString key, QString secret, QObject *parent)
    : DropboxBase(parent), m_appKey(key), m_appSecret(secret)
{}

void DropboxAuth::setAppKey(QString key)
{
    m_appKey = key;
}

void DropboxAuth::setApiToken(QString token)
{
    m_apiToken = token;
}

void DropboxAuth::setAppSecret(QString secret)
{
    m_appSecret = secret;
}

QString DropboxAuth::getAppKey() const
{
    return m_appKey;
}

QString DropboxAuth::getApiToken() const
{
    return m_apiToken;
}

QString DropboxAuth::getAppSecret() const
{
    return m_appSecret;
}

QString DropboxAuth::appAuthentication()
{
    return "TODO";
}

QString DropboxAuth::userAuthentication()
{
    request()->setUrl(Auth::getHttpUrl(Auth::USER_AUTHENTICATION));
    request()->setRawHeader(QByteArray("Authorization"),
                            QString("Bearer " + getApiToken()).toUtf8());

    manager()->post(*(request()), QByteArray());
}

QString DropboxAuth::teamAuthentication()
{
    request()->setUrl(Auth::getHttpUrl(Auth::TEAM_AUTHENTICATION));
    request()->setRawHeader(QByteArray("Authorization"),
                            QString("Bearer " + getApiToken()).toUtf8());

    manager()->post(*(request()), QByteArray());
}

}