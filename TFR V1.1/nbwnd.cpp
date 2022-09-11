#include "nbwnd.h"

NBWnd::NBWnd(QWidget *parent) : QWidget(parent)
{
    QFont font1("Kaiti",10,55);
    QFont font2("Kaiti",11,60);

    FP = new QFileDialog(this);
    FP->setLabelText(QFileDialog::FileName,"文件名:");
    FP->setLabelText(QFileDialog::Accept,"确定");
    QStringList Filters;
    Filters<<"Text File (*.txt)";
    FP->setNameFilters(Filters);

    btn_ChooseFile = new QPushButton(this);
    btn_ChooseFile->setGeometry(390,20,100,35);
    btn_ChooseFile->setText("选择文件");
    btn_ChooseFile->setFont(font1);
    btn_ChooseFile->show();

    qle_FilePath = new QLineEdit(this);
    qle_FilePath->setGeometry(30,20,350,35);
    qle_FilePath->setFrame(false);
    qle_FilePath->setEchoMode(QLineEdit::Normal);
    qle_FilePath->setFont(font1);
    qle_FilePath->setPlaceholderText("文件地址");
    qle_FilePath->show();

    btn_GetFile = new QPushButton(this);
    btn_GetFile->setText("读取文件");
    btn_GetFile->setFont(font1);
    btn_GetFile->setGeometry(30,65,460,35);
    btn_GetFile->show();

    /*qle_ShowText = new QLineEdit(this);
    qle_ShowText->setGeometry(30,120,460,350);
    qle_ShowText->setFrame(false);
    qle_ShowText->setFont(font1);
    qle_ShowText->show();
    */

    qte_ShowText = new QTextEdit(this);
    qte_ShowText->setFont(font2);
    qte_ShowText->setFrameStyle(QFrame::Sunken);
    qte_ShowText->setGeometry(30,110,460,300);
    qte_ShowText->setReadOnly(true);
    qte_ShowText->setWordWrapMode(QTextOption::NoWrap);
    qte_ShowText->show();

    qte_ShowInfo = new QTextEdit(this);
    qte_ShowInfo->setFont(font2);
    qte_ShowInfo->setFrameStyle(QFrame::Sunken);
    qte_ShowInfo->setGeometry(30,440,460,200);
    qte_ShowInfo->setReadOnly(true);
    qte_ShowInfo->setWordWrapMode(QTextOption::NoWrap);
    qte_ShowInfo->show();

    qlb_Info = new QLabel(this);
    qlb_Info->setFont(font2);
    qlb_Info->setText("Info:");
    qlb_Info->setGeometry(30,410,460,30);
    qlb_Info->show();

    /*FP = new QFileDialog(this);
    FP->setLabelText(QFileDialog::FileName,"文件名:");
    FP->setLabelText(QFileDialog::Accept,"确定");
    QStringList Filters;
    Filters<<"Text File (*.txt)";
    FP->setNameFilters(Filters);*/

    QObject::connect(btn_ChooseFile,SIGNAL(clicked()),this,SLOT(GetPath()));
    QObject::connect(qle_FilePath,SIGNAL(returnPressed()),this,SLOT(ChangePath()));
    QObject::connect(btn_GetFile,SIGNAL(clicked()),this,SLOT(ReadFile()));

    resize(520,650);
    this->setFixedSize(520,650);
    this->show();
}

/*
pIPLineEdit->setInputMask("000.000.000.000;_");
pMACLineEdit->setInputMask("HH:HH:HH:HH:HH:HH;_");
pDateLineEdit->setInputMask("0000-00-00");
pLicenseLineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
*/

void NBWnd::GetPath(){
    FilePath = FP->getOpenFileName(this,"选择文件","C:/","*.txt");
    qle_FilePath->setText(FilePath);
    qDebug()<<FilePath;
}

void NBWnd::ChangePath(){
    FilePath = qle_FilePath->text();
    qDebug()<<FilePath;
}

void NBWnd::ReadFile(){
    QFile file(FilePath);
    QFileInfo fileInfo(FilePath);
    file.open(QIODevice::ReadOnly);
    if(fileInfo.isFile() == false){
        QMessageBox::warning(this,"ERROR","File not found.");
        return;
    }
    else{
    QByteArray Msg = file.readAll();

    qte_ShowText->setText(Msg);
    qte_ShowInfo->append("文件路径:");
    qte_ShowInfo->append(fileInfo.filePath());
    qte_ShowInfo->append("\n");

    qte_ShowInfo->append("文件名:");
    qte_ShowInfo->append(fileInfo.fileName());
    qte_ShowInfo->append("\n");

    qte_ShowInfo->append("基本名称:");
    qte_ShowInfo->append(fileInfo.baseName());
    qte_ShowInfo->append("\n");

    qte_ShowInfo->append("后缀:");
    qte_ShowInfo->append(fileInfo.suffix());
    qte_ShowInfo->append("\n");

    qte_ShowInfo->append("创建时间:");
    QString createdTime = fileInfo.created().toString("yyyy:MM:dd hh:mm:ss.zzz ddd");
    qte_ShowInfo->append(createdTime);
    qte_ShowInfo->append("\n");

    qte_ShowInfo->append("大小:");
    QString fileSize = tr("%1").arg(fileInfo.size());
    qte_ShowInfo->append(fileSize+"B");
    qte_ShowInfo->append("\n");

    }
}
