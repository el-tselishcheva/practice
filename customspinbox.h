#ifndef CUSTOMSPINBOX_H
#define CUSTOMSPINBOX_H

#include <QDoubleSpinBox>

class CustomSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    CustomSpinBox(QWidget* parent = Q_NULLPTR);
    // QAbstractSpinBox interface
public:
    virtual void stepBy(int steps) override;
};

#endif // CUSTOMSPINBOX_H
