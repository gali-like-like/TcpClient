#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(QHostAddress::LocalHost,2666);
    connect(tcpSocket,&QTcpSocket::hostFound,this,&Widget::do_socket_hostFound);
    connect(tcpSocket,&QTcpSocket::connected,this,&Widget::do_socket_connected);
    connect(tcpSocket,&QTcpSocket::disconnected,this,&Widget::do_socket_disconnected);
    connect(tcpSocket,&QTcpSocket::readyRead,this,&Widget::do_socket_readyRead);
}

Widget::~Widget()
{
    delete this->tcpSocket;
    delete ui;
}

void Widget::closeEvent(QCloseEvent *e)
{
    if(tcpSocket->state() != tcpSocket->ClosingState)
    {
        tcpSocket->disconnectFromHost();
    }
}

void Widget::do_socket_connected()
{
    ui->textEditRecevice->append("连上服务器了");
}

void Widget::do_socket_disconnected()
{
    ui->textEditRecevice->append("下线了");
}

void Widget::do_socket_readyRead()
{
    QString info = tcpSocket->readAll();
    ui->textEditRecevice->append("[in]"+info);
}

void Widget::do_socket_hostFound()
{
    ui->textEditRecevice->append("找到服务器了");
}

void Widget::on_btnSend_clicked()
{
    QString info = ui->lineEditMessage->text();
    qint64 size = tcpSocket->write(info.toUtf8());
    qDebug()<<"实际写入字节数:"<<size;
    ui->textEditRecevice->append("[out]"+info);
}

