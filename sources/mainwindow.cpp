#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_MoveLevel_RB->setColumnWidth(0,28);
    ui->tableWidget_MoveLevel_RB->setColumnWidth(1,138);
    ui->tableWidget_MoveLevel_Y->setColumnWidth(0,28);
    ui->tableWidget_MoveLevel_Y->setColumnWidth(1,138);
    ui->tableWidget_MoveTM->setColumnWidth(0,28);
    ui->tableWidget_MoveTM->setColumnWidth(1,120);

    QHeaderView *verticalHeader1 = ui->tableWidget_StartingMoves->verticalHeader();
    QHeaderView *verticalHeader2 = ui->tableWidget_MoveLevel_RB->verticalHeader();
    QHeaderView *verticalHeader3 = ui->tableWidget_MoveLevel_Y->verticalHeader();
    QHeaderView *verticalHeader4 = ui->tableWidget_MoveTM->verticalHeader();
    verticalHeader1->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader1->setDefaultSectionSize(19);
    verticalHeader2->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader2->setDefaultSectionSize(19);
    verticalHeader3->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader3->setDefaultSectionSize(19);
    verticalHeader4->sectionResizeMode(QHeaderView::Fixed);
    verticalHeader4->setDefaultSectionSize(19);

    ui->tableWidget_MoveTM->setRowCount(55);
    ui->tableWidget_MoveTM->setColumnCount(2);
    ui->tableWidget_MoveTM->setHorizontalHeaderItem(1, new QTableWidgetItem("TM HM Moves"));
    ui->tableWidget_MoveTM->verticalHeader()->setVisible(false);
    for(short i=1;i<56;i++){
        ui->tableWidget_MoveTM->setCellWidget(i-1,0, new QCheckBox);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
