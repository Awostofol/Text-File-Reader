#ifndef NBWND_H
#define NBWND_H

#include <QWidget>
#include <QLineEdit>
#include <QFont>
#include <QLabel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QPushButton>
#include <QFile>
#include <QSize>
#include <QFileDialog>
#include <QTextEdit>
#include <QDateTime>
#include <iostream>
#include <cmath>

class NBWnd : public QWidget
{
    Q_OBJECT
public:
    explicit NBWnd(QWidget *parent = nullptr);
    QString FilePath;
    //QFile file;

signals:

private:
    QPushButton * btn_ChooseFile;
    QLineEdit * qle_FilePath;
    QFileDialog * FP;
    QPushButton *btn_GetFile;
    //QLineEdit *qle_ShowText;
    QTextEdit * qte_ShowText;
    QTextEdit * qte_ShowInfo;
    QLabel * qlb_Info;
public slots:
    void GetPath();
    void ChangePath();
    void ReadFile();


};
#endif // NBWND_H
