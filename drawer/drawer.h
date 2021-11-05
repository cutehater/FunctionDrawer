#pragma once

#include<qgraphicsview.h>
#include<qgraphicsscene.h>
#include<function.h>

class Drawer
{
public:
    Drawer(QGraphicsView* const plot_box, QGraphicsView* const x_axis_box,
           QGraphicsView* const y_axis_box);

    void SetFunction(const Function& function);
    void SetLeftBound(const double& left_bound);
    void SetRightBound(const double& right_bound);
    
    void DrawFunction();
    
private:
    enum class AxisType{
        X,
        Y
    };

    const size_t X_MARK_LINE_LENGTH = 10;
    const size_t Y_MARK_LINE_LENGTH = 30;
    const size_t NUMBER_OF_MARK_LINES = 12;
    const size_t INDENT = 5;
    const size_t TEXT_SIZE = 12;
    const size_t ACCURACY = 100;

    void DrawPlot();
    void DrawAxis(AxisType axis_type);

    void RecalcMinMaxValues();

    double ConvertValue (const double& x, const double &lower_bound,
                              const double& upper_bound, const size_t& box_size);
    size_t UnconvertValue(const double &x, const double& lower_bound,
                                  const double& upper_bound, const size_t& box_size);
    
    QGraphicsView* const plot_box;
    QGraphicsView* const x_axis_box;
    QGraphicsView* const y_axis_box;

    Function function;

    double left_bound;
    double right_bound;

    double f_min_value;
    double f_max_value;
};
