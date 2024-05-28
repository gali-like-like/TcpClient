#ifndef MYRUNNABLE_H
#define MYRUNNABLE_H

#include <QRunnable>
#include <QObject>
class MyRunnable : public QObject, public QRunnable
{
    Q_OBJECT
public:
    MyRunnable();
    void run();
private:

};

#endif // MYRUNNABLE_H
