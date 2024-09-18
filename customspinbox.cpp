#include "customspinbox.h"

CustomSpinBox::CustomSpinBox(QWidget* parent) : QDoubleSpinBox(parent) {
}

void CustomSpinBox::stepBy(int steps)
{
    switch (steps) {
        case 1:
            setValue(value()*10);
            break;
        case -1:
            setValue(value()/10);
            break;
        default:
            QDoubleSpinBox::stepBy(steps);
            break;
    }
}
