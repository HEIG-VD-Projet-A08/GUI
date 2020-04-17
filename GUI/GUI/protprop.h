#ifndef PROTPROP_H
#define PROTPROP_H

#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ProtProp; }
QT_END_NAMESPACE

class ProtProp : public QMainWindow
{
    Q_OBJECT

public:
    ProtProp(QWidget *parent = nullptr);
    ~ProtProp();

private slots:
    void on_btn_run_clicked();
    void on_btn_stop_clicked();
    void on_btn_save_actual_clicked();
    void on_btn_save_res_clicked();
    void on_plot_clicked();
private:
    Ui::ProtProp *ui;
    QString nbWords;
    QString nbChars;
    QString nbIter;
    QString ip;
};
#endif // PROTPROP_H
