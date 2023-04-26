#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_lexer(new Lexer(new Fsm()))
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << __FUNCTION__ << ui->linePrompt->toPlainText();
    m_lexer->setPrompt(ui->linePrompt->toPlainText());
    m_lexer->compute();

}

