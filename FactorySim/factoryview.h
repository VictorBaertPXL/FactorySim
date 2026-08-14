// vraag 42: useful Qt class
// vraag 47: usage of a GUI

#ifndef FACTORYVIEW_H
#define FACTORYVIEW_H

#include <QWidget>
#include <QPainter>
#include "FactoryEngine.h"

class FactoryView : public QWidget
{
    Q_OBJECT

public:
    explicit FactoryView(FactoryEngine* engine, QWidget* parent = nullptr);

protected:
    // vraag 11: virtual function
    void paintEvent(QPaintEvent* event) override;

private:
    FactoryEngine* engine;
};

#endif
