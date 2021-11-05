#include "drawer.h"

#include <math.h>
#include <string>
#include <stdexcept>
#include <QGraphicsTextItem>

Drawer::Drawer(QGraphicsView* const plot_box, QGraphicsView* const x_axis_box, QGraphicsView* const y_axis_box) :
plot_box(plot_box), x_axis_box(x_axis_box), y_axis_box(y_axis_box) {

}

void Drawer::SetFunction(const Function& function) {
    this->function = function;
}

void Drawer::SetLeftBound(const double& left_bound) {
    this->left_bound = left_bound;
}

void Drawer::SetRightBound(const double& right_bound) {
    this->right_bound = right_bound;
}

void Drawer::DrawFunction() {
    if (left_bound > right_bound)
    {
        throw std::invalid_argument("left bound is greater then right");
    }

    f_min_value = INFINITY;
    f_max_value = -INFINITY;

    for (size_t x = INDENT; x < plot_box->width() - INDENT; ++x)
    {
        double converted_x = ConvertValue(x, left_bound, right_bound, plot_box->width() - 2 * INDENT);

        try
        {
            f_min_value = std::min(f_min_value, function.GetValue(converted_x));
            f_max_value = std::max(f_max_value, function.GetValue(converted_x));
        }
        catch (const std::out_of_range& e)
        {
        }
    }

    DrawAxis(AxisType::X);
    DrawAxis(AxisType::Y);

    DrawPlot();
}

void Drawer::DrawPlot() {
    QGraphicsScene* plot = new QGraphicsScene;
    
    QPen pen(Qt::black, 2);

    for (size_t x = INDENT; x < plot_box->width(); ++x)
    {
        try
        {
            double converted_x = ConvertValue(x, left_bound, right_bound, plot_box->width() - 2 * INDENT);

            double converted_y = function.GetValue(converted_x);

            size_t y = UnconvertValue(converted_y, f_min_value, f_max_value, plot_box->height() - 2 * INDENT);

            plot->addLine(x, y, x + 1, y, pen);
        }
        catch (const std::out_of_range& e)
        {
            continue;
        }
    }

    delete plot_box->scene();
    plot_box->setScene(plot);
}

void Drawer::DrawAxis(Drawer::AxisType axis_type) {
    QGraphicsScene* axis = new QGraphicsScene;

    QGraphicsView* axis_box;
    if (axis_type == AxisType::X)
    {
        axis_box = x_axis_box;
    }
    else
    {
        axis_box = y_axis_box;
    }

    QPen pen(Qt::black, 2);

    size_t line_pos;
    size_t box_bound;
    size_t box_size;

    double lower_bound;
    double upper_bound;

    if (axis_type == AxisType::X)
    {
        line_pos = INDENT;
        box_bound = x_axis_box->width() - INDENT;
        box_size = x_axis_box->width() - 2 * INDENT;
        lower_bound = left_bound;
        upper_bound = right_bound;

        axis->addLine(INDENT, line_pos, box_bound, line_pos, pen);
    }
    else
    {
        line_pos = y_axis_box->width() - INDENT;
        box_bound = y_axis_box->height() - INDENT;
        box_size = y_axis_box->height() - 2 * INDENT;
        lower_bound = f_min_value;
        upper_bound = f_max_value;

        axis -> addLine(line_pos, INDENT, line_pos, box_bound, pen);
    }
    
    for (size_t coordinate = INDENT; coordinate <= box_bound; coordinate += box_size / NUMBER_OF_MARK_LINES)
    {
        if (axis_type == AxisType::X)
        {
            axis->addLine(coordinate, line_pos, coordinate, line_pos + X_MARK_LINE_LENGTH, pen);
        }
        else
        {
            axis->addLine(line_pos - Y_MARK_LINE_LENGTH, coordinate, line_pos, coordinate, pen);
        }

        QString converted_coordinate = QString::number(std::round(ConvertValue(coordinate, lower_bound, upper_bound, box_size) * ACCURACY) / ACCURACY);

        QFont font;

        font.setPixelSize(TEXT_SIZE);

        QGraphicsTextItem* coordinate_text_item = new QGraphicsTextItem(converted_coordinate);

        if (axis_type == AxisType::X)
        {
            coordinate_text_item->setPos(coordinate - TEXT_SIZE * converted_coordinate.length() / 2 * (coordinate > INDENT), //corner markline case
                                         axis_box->height() - TEXT_SIZE * 3);
        }
        else
        {
            coordinate_text_item->setPos(INDENT, box_size - coordinate + INDENT * (coordinate > INDENT)); //corner markline case
        }

        coordinate_text_item->setFont(font);

        axis->addItem(coordinate_text_item);
    }

    delete axis_box->scene();
    axis_box->setScene(axis);
}

double Drawer::ConvertValue(const double &x, const double& lower_bound,
                            const double& upper_bound, const size_t& box_size) {
    return lower_bound + (upper_bound - lower_bound) / box_size * x;
}

size_t Drawer::UnconvertValue(const double &x, const double& lower_bound,
                              const double& upper_bound, const size_t& box_size) {
    return std::round(box_size - (x - lower_bound) / (upper_bound - lower_bound) * box_size) + INDENT;
}
