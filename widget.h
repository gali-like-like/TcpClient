#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QCloseEvent>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void closeEvent(QCloseEvent* e) ;
private slots:
    void on_btnSend_clicked();
    void do_socket_connected();
    void do_socket_disconnected();
    void do_socket_readyRead();
    void do_socket_hostFound();
private:
    Ui::Widget *ui;
    QTcpSocket* tcpSocket;
};
#endif // WIDGET_H
