#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "includes.h"
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void toUpper(std::string &str) {
    if (str.length() == 0) {
        return;
    }

    str[0] = std::toupper(str[0]);
}

void MainWindow::on_pushButton_clicked()
{
    string UsernameInFile;
    string UsernameExtent;
    fstream namesfile("C:/Users/Public/names.txt");
    fstream adjectives("C:/Users/Public/adj.txt");
    QString Username;
    QString Username1;
    QString Username2;
    QString Password;
    int randomIndex;

    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    int ch = 15;
    QString result = "";
    for (int i = 0; i<ch; i++)
        result = result + alphanum[rand() % 62];
        Password += result;

    srand(time(NULL));
    int line_number = rand() % 81475;
    for (int i = 1; i < line_number; ++i) {
      getline(namesfile, UsernameInFile);
    }

    line_number = rand() % 1347;
    for (int i = 1; i < line_number; ++i) {
      getline(adjectives, UsernameExtent);
    }

    toUpper(UsernameExtent);
    toUpper(UsernameInFile);

    Username1 = QString::fromStdString(UsernameExtent);
    Username2 = QString::fromStdString(UsernameInFile);

    Username = Username1 + Username2;
    ui->textEdit->setText(Username);
    ui->textEdit_2->setText(Password);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString Username = ui->textEdit->toPlainText();
    QString Password = ui->textEdit_2->toPlainText();
}

