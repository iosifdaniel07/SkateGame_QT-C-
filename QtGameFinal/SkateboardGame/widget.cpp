#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsPixmapItem>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

   this->setFixedSize(1700,790);

    scene = new Scene(this);
    scene->setSceneRect(0,0,1750,796);

    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap(":/Images/background.png"));
    pixItem->setZValue(-1);
    scene->addItem(pixItem);

    QPixmap iconPixmap(":/Images/start.png");
    QIcon pixmapIcon(iconPixmap);
    ui->startButton->setIcon(pixmapIcon);
    ui->startButton->setIconSize(iconPixmap.rect().size());
    ui->startButton->setFixedSize(iconPixmap.rect().size());


    QPixmap iconPixmap2(":/Images/exit.png");
    QIcon pixmapIcon2(iconPixmap2);
     ui->closeButton->setIcon(pixmapIcon2);
     ui->closeButton->setIconSize(iconPixmap2.rect().size());
     ui->closeButton->setFixedSize(iconPixmap2.rect().size());


    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(1800,800);

    setupButtonsTimer();
}

Widget::~Widget()
{
    delete buttonsTimer;
    delete scene;
    delete ui;
}

void Widget::hideButtons()
{
    ui->startButton->hide();
    ui->closeButton->hide();
}

void Widget::showButtons()
{
    ui->startButton->show();
    ui->closeButton->show();
}

void Widget::setupButtonsTimer()
{
    buttonsTimer = new QTimer();

    connect(buttonsTimer,&QTimer::timeout, [=] () {

        connect(scene,&Scene::showButtons,[=](){
           showButtons();
        });


    });

     buttonsTimer->start(100);
}


void Widget::on_startButton_clicked()
{
   scene->startGame();
   hideButtons();
}

void Widget::on_closeButton_clicked()
{
    this->close();
}
