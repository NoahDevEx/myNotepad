#include "mynotepad.h"
#include "ui_mynotepad.h"
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include<QColor>
#include<QColorDialog>
#include<QFont>
#include<QFontDialog>
#include<QPrinter>
#include<QPrintDialog>
#include<QMessageBox>



MyNotepad::MyNotepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyNotepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

}

MyNotepad::~MyNotepad()
{
    delete ui;
}

void MyNotepad::on_actionExit_triggered()
{
    QApplication:: quit();
}


void MyNotepad::on_actionNew_triggered()
{

    file_path = "";
    ui->textEdit->setText("");
}


void MyNotepad::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About MyNotepad", "Developer: Noah Olatunde \n Date: 16th Oct, 2024");
}


void MyNotepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MyNotepad::on_actionSave_triggered()
{
    //QString fileName = QFileDialog::getSaveFileName(this, "Save file", "C://",".txt ;; .pdf;; .doc;; .docx;;");
    QFile file(file_path);
    file.open(QFile:: WriteOnly | QFile::Text);
    QTextStream out(&file);
    QString file_content = ui->textEdit->toPlainText();
    out << file_content;
    file.flush();
    file.close();
}


void MyNotepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MyNotepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MyNotepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MyNotepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MyNotepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Choose file", "C://", "*.*;;.txt ;; .pdf;; .doc;; .docx;;");
    QFile file(fileName);
    fileName = file_path;
    file.open(QFile:: ReadOnly | QFile::Text);
    QTextStream in(&file);
    QString file_content = in.readAll();
    ui->textEdit->setText(file_content);
    file.close();

}

void MyNotepad::on_actionSave_As_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(this, "Save file", "C://",",*.*. ;; txt ;; .pdf;; .doc;; .docx;;");
    QFile file(fileName);
    file.open(QFile:: WriteOnly | QFile::Text);
    QTextStream out(&file);
    QString file_content = ui->textEdit->toPlainText();
    out << file_content;
    file.flush();
    file.close();
}


void MyNotepad::on_actionColor_triggered()
{
    QColor color = QColorDialog:: getColor(Qt::black, this, "Select color");
    ui->textEdit->setTextColor(color);

}


void MyNotepad::on_actionFont_triggered()
{
    bool ok;
    QFont font= QFontDialog::getFont(&ok, this);
    ui->textEdit->setFont(font);


}


void MyNotepad::on_actionPrint_triggered()
{
    QPrinter print;
    print.setPrinterName("any printer");
    QPrintDialog printDialog(&print, this);
    ui->textEdit->print(&print);
}

