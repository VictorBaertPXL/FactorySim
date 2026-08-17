#ifndef FACTORYVIEW_H
#define FACTORYVIEW_H

#include <QWidget>

class FactoryEngine;
class ToolbarController;

class FactoryView : public QWidget
{
    Q_OBJECT

public:
    FactoryView(FactoryEngine* eng, ToolbarController* tb, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private slots:
    void tick();

private:
    FactoryEngine* engine;
    ToolbarController* toolbar;
};

#endif
