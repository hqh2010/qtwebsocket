#include "echoclient.h"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

//! [constructor]
EchoClient::EchoClient(const QUrl &url, bool debug, QObject *parent) :
    QObject(parent),
    m_url(url),
    m_debug(debug)
{
    if (m_debug)
        qInfo() << "WebSocket server:" << url;
    // 不用匿名函数也可以。
    // connect(&m_webSocket, &QWebSocket::connected, this, &EchoClient::onConnected);
    connect(&m_webSocket, &QWebSocket::connected, [&]() { 
        qInfo() << "connected success"; 
        EchoClient::onConnected();
        });

    connect(&m_webSocket, &QWebSocket::disconnected, this, &EchoClient::closed);
    m_webSocket.open(QUrl(url));
}

// 代码参考地址
// https://code.qt.io/cgit/qt/qtwebsockets.git/tree/examples/websockets?h=6.4

// lib 测试websocket
// curl --header "Connection: Upgrade" \
//      --header "Upgrade: websocket" \
//      --header "Sec-WebSocket-Key: 123456==" \
//      --header "Sec-WebSocket-Version: 13" \
// http://10.20.54.2:10100/websocket/watcher/17236529-5149-9572-71f7-8512ad5e2f21

//! [onConnected]
void EchoClient::onConnected()
{
    if (m_debug)
        qInfo() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived,
            this, &EchoClient::onTextMessageReceived);
    m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}
//! [onConnected]

void EchoClient::onTextMessageReceived(QString message)
{
    if (m_debug)
        qInfo() << "Message received:" << message;
    m_webSocket.close();
}
