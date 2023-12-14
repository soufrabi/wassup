#include "notificationpopup.h"


NotificationPopup::NotificationPopup(QWidget *parent)
    : QWidget{parent}
{

}

void NotificationPopup::present(std::unique_ptr<QWebEngineNotification> &newNotification)
{
       if (notification) {
           notification->close();
           notification.reset();
       }

        notification.swap(newNotification);

        m_title.setText("<b>" + notification->title() + "</b>");
                m_message.setText(notification->message());
                m_icon.setPixmap(QPixmap::fromImage(notification->icon()).scaledToHeight(m_icon.height()));

        show();
        notification->show();


        connect(notification.get(), &QWebEngineNotification::closed, this, &NotificationPopup::onClosed);
                QTimer::singleShot(10000, notification.get(), [&] () { onClosed(); });




}

void NotificationPopup::onClosed()
{
        hide();
        notification->close();
        notification.reset();
}


void NotificationPopup::mouseReleaseEvent(QMouseEvent *event)
    {
        QWidget::mouseReleaseEvent(event);
        if (notification && event->button() == Qt::LeftButton) {
            notification->click();
            onClosed();
        }
    }
