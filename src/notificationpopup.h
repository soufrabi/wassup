#ifndef NOTIFICATIONPOPUP_H
#define NOTIFICATIONPOPUP_H

#include <QWidget>
#include <QWebEngineNotification>
#include <QLabel>
#include <QMouseEvent>
#include <QTimer>

class NotificationPopup : public QWidget
{
    Q_OBJECT

    QLabel m_icon, m_title, m_message;
    std::unique_ptr<QWebEngineNotification> notification;
public:
    explicit NotificationPopup(QWidget *parent = nullptr);
    void onClosed();
    void present(std::unique_ptr<QWebEngineNotification> &newNotification);
    void mouseReleaseEvent(QMouseEvent *event) override;



signals:

};

#endif // NOTIFICATIONPOPUP_H
