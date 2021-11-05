/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *plot_picture_box;
    QPushButton *action_button;
    QTextEdit *left_bound_text_box;
    QTextEdit *right_bound_text_box;
    QGraphicsView *y_axis_picture_box;
    QGraphicsView *x_axis_picture_box;
    QLabel *left_bound_label;
    QLabel *right_bound_label;
    QLabel *enter_bounds_label;
    QTextEdit *function_text_box;
    QLabel *function_label;
    QPushButton *help_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 1100);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plot_picture_box = new QGraphicsView(centralwidget);
        plot_picture_box->setObjectName(QString::fromUtf8("plot_picture_box"));
        plot_picture_box->setGeometry(QRect(370, 40, 900, 900));
        action_button = new QPushButton(centralwidget);
        action_button->setObjectName(QString::fromUtf8("action_button"));
        action_button->setGeometry(QRect(40, 490, 161, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Manjari"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        action_button->setFont(font);
        left_bound_text_box = new QTextEdit(centralwidget);
        left_bound_text_box->setObjectName(QString::fromUtf8("left_bound_text_box"));
        left_bound_text_box->setGeometry(QRect(70, 360, 131, 31));
        right_bound_text_box = new QTextEdit(centralwidget);
        right_bound_text_box->setObjectName(QString::fromUtf8("right_bound_text_box"));
        right_bound_text_box->setGeometry(QRect(70, 420, 131, 31));
        y_axis_picture_box = new QGraphicsView(centralwidget);
        y_axis_picture_box->setObjectName(QString::fromUtf8("y_axis_picture_box"));
        y_axis_picture_box->setGeometry(QRect(280, 40, 91, 901));
        y_axis_picture_box->setAutoFillBackground(false);
        y_axis_picture_box->setStyleSheet(QString::fromUtf8("background: transparent;"));
        x_axis_picture_box = new QGraphicsView(centralwidget);
        x_axis_picture_box->setObjectName(QString::fromUtf8("x_axis_picture_box"));
        x_axis_picture_box->setGeometry(QRect(370, 940, 900, 51));
        x_axis_picture_box->setStyleSheet(QString::fromUtf8("background: transparent;"));
        left_bound_label = new QLabel(centralwidget);
        left_bound_label->setObjectName(QString::fromUtf8("left_bound_label"));
        left_bound_label->setGeometry(QRect(10, 370, 51, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Manjari"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        left_bound_label->setFont(font1);
        right_bound_label = new QLabel(centralwidget);
        right_bound_label->setObjectName(QString::fromUtf8("right_bound_label"));
        right_bound_label->setGeometry(QRect(10, 430, 67, 21));
        right_bound_label->setFont(font1);
        enter_bounds_label = new QLabel(centralwidget);
        enter_bounds_label->setObjectName(QString::fromUtf8("enter_bounds_label"));
        enter_bounds_label->setGeometry(QRect(50, 320, 151, 21));
        enter_bounds_label->setFont(font1);
        function_text_box = new QTextEdit(centralwidget);
        function_text_box->setObjectName(QString::fromUtf8("function_text_box"));
        function_text_box->setGeometry(QRect(20, 230, 231, 31));
        function_label = new QLabel(centralwidget);
        function_label->setObjectName(QString::fromUtf8("function_label"));
        function_label->setGeometry(QRect(90, 200, 91, 21));
        function_label->setFont(font1);
        help_button = new QPushButton(centralwidget);
        help_button->setObjectName(QString::fromUtf8("help_button"));
        help_button->setGeometry(QRect(170, 190, 31, 31));
        help_button->setFont(font1);
        help_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #333;\n"
"    border: 2px solid #555;\n"
"    border-radius: 15px;\n"
"    border-style: outset;\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #888\n"
"        );\n"
"    padding: 5px;\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #bbb\n"
"        );\n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    border-style: inset;\n"
"    background: qradialgradient(\n"
"        cx: 0.4, cy: -0.1, fx: 0.4, fy: -0.1,\n"
"        radius: 1.35, stop: 0 #fff, stop: 1 #ddd\n"
"        );\n"
"    }"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1300, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_button->setText(QCoreApplication::translate("MainWindow", "Draw!", nullptr));
        left_bound_label->setText(QCoreApplication::translate("MainWindow", "Left:", nullptr));
        right_bound_label->setText(QCoreApplication::translate("MainWindow", "Right:", nullptr));
        enter_bounds_label->setText(QCoreApplication::translate("MainWindow", "Segment bounds", nullptr));
        function_label->setText(QCoreApplication::translate("MainWindow", "Function", nullptr));
        help_button->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
