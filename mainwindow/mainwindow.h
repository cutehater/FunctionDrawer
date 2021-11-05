#pragma once

#include "../drawer/drawer.h"
#include "../function/function.h"

#include <stdexcept>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_button_clicked();

    void on_help_button_clicked();

    void invalid_function_format_error(const std::invalid_argument& exception);

private:
    Ui::MainWindow *ui;
};
