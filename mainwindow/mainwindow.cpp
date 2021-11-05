#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plot_picture_box->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->plot_picture_box->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->x_axis_picture_box->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->x_axis_picture_box->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->y_axis_picture_box->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->y_axis_picture_box->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_button_clicked()
{
    try
    {
        Drawer drawer(ui->plot_picture_box, ui->x_axis_picture_box, ui->y_axis_picture_box);

        Function function(ui->function_text_box->toPlainText().toStdString());

        if (ui->left_bound_text_box->document()->isEmpty())
        {
            throw std::invalid_argument("segment left bound isn't specified");
        }
        else
        {
            drawer.SetLeftBound(ui->left_bound_text_box->toPlainText().toDouble());
        }

        if (ui->right_bound_text_box->document()->isEmpty())
        {
            throw std::invalid_argument("segment right bound isn't specified");
        }
        else
        {
            drawer.SetRightBound(ui->right_bound_text_box->toPlainText().toDouble());
        }

        drawer.SetFunction(function);
        drawer.DrawFunction();
    }
    catch (const std::invalid_argument& e)
    {
        invalid_function_format_error(e);
    }
}


void MainWindow::on_help_button_clicked()
{
    QString title = "Help";

    QString main_text = "Please enter your function f(x) following these rules:\n"
                        "1) Do not use implicit multiplication \n"
                        "(write \"23*x\" instead of \"23x\")\n"
                        "2) Do not use unary minus \n"
                        "(write \"0 - x\" instead of \"-x\"\n"
                        "3) Surround complex functions with brackets \n"
                        "(write \"log(x)\" instead of \"logx\")\n"
                        "4) We support following complex functions:\n"
                        "· sin(x) - sine x\n"
                        "· cos(x) - cosine x\n"
                        "· tan(x) - tangent x\n"
                        "· asin(x) - arcsine x\n"
                        "· acos(x) - arccosine x\n"
                        "· atan(x) - arctangent x\n"
                        "· sqrt(x) - x square root\n"
                        "· log(x) - x natural logarithm\n"
                        "· log10(x) - x decimal logarithm\n"
                        "· log2(x) - x binary logarithm\n"
                        "· abs(x) - x absolute value\n"
                        "You can also use \"^\" sign to get power of x";

    QMessageBox::information(this, title, main_text);
}

void MainWindow::invalid_function_format_error(const std::invalid_argument& exception)
{
    QString title = "Error";

    QString main_text = "Error: " + QString::fromUtf8(exception.what()) + "\n"
                        "Press \"?\" button to get help\n";

    QMessageBox::critical(this, title, main_text);
}
