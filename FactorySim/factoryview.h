// vraag 11: virtual function
// vraag 42: useful Qt class

#ifndef FACTORYVIEW_H
#define FACTORYVIEW_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "FactoryEngine.h"
#include "ToolbarController.h"

class FactoryView : public QWidget
{
    Q_OBJECT

public:
    FactoryView(FactoryEngine* engine, ToolbarController* toolbar, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;       // vraag 11
    void mousePressEvent(QMouseEvent* event) override;  // vraag 11

private:
    FactoryEngine* engine;
    ToolbarController* toolbar;
};

#endif
