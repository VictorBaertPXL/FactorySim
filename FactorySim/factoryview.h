// vraag 3: useful and correct class
// vraag 4: useful and correct abstraction
// vraag 5: useful and correct encapsulation
// vraag 7: useful and correct polymorphism
// vraag 8: useful and correct object composition
// vraag 42: useful Qt class
// vraag 47: usage of a GUI

#ifndef FACTORYVIEW_H
#define FACTORYVIEW_H

#include <QWidget>   // vraag 42: useful Qt class

class FactoryEngine;
class ToolbarController;

class FactoryView : public QWidget
{
    Q_OBJECT

public:
    FactoryView(FactoryEngine* eng, ToolbarController* tb, QWidget* parent = nullptr); // vraag 13: parameterized constructor

protected:
    void paintEvent(QPaintEvent* event) override;     // vraag 11: virtual function
    void mousePressEvent(QMouseEvent* event) override; // vraag 11

private slots:
    void tick();   // vraag 43: signals/slots

private:
    FactoryEngine* engine;        // vraag 22: useful member variable
    ToolbarController* toolbar;   // vraag 22
};

#endif
