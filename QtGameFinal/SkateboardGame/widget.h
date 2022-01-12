#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <scene.h>
#include "obstacle.h"
#include "clouds.h"
#include "skateitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
   void hideButtons();
   void showButtons();
   void setupButtonsTimer();

private slots:
    void on_startButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::Widget *ui;
    Scene *scene;
    QTimer *buttonsTimer;
};
#endif // WIDGET_H
