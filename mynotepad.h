#ifndef MYNOTEPAD_H
#define MYNOTEPAD_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyNotepad;
}
QT_END_NAMESPACE

class MyNotepad : public QMainWindow
{
    Q_OBJECT

public:
    MyNotepad(QWidget *parent = nullptr);
    ~MyNotepad();

private slots:
    void on_actionExit_triggered();

    void on_actionNew_triggered();

    void on_actionAbout_triggered();

    void on_actionRedo_triggered();

    void on_actionSave_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionColor_triggered();

    void on_actionFont_triggered();

    void on_actionPrint_triggered();

private:
    Ui::MyNotepad *ui;
    QString file_path;
};
#endif // MYNOTEPAD_H
