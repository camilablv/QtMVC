#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVariant>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), database(QSqlDatabase::addDatabase("QMYSQL")),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openDB(database);
    QSqlTableModel* model = new QSqlTableModel(this, database);
    Delegate* delegate = new Delegate(model);
    model->setTable("persons");
    model->select();
    ui->listView->setModel(model);
    ui->listView->setItemDelegate(delegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDB(QSqlDatabase& db)
{
    db.setDatabaseName("FaceRecognitionSystem");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPort(3306);
    QSqlQuery query(db);
    if(!db.open()) qDebug() << "Cannot open database:" << db.lastError();
    else qDebug() << "Connected";
}
