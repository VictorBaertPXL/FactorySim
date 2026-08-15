// vraag 33: enum

#ifndef TOOLBARCONTROLLER_H
#define TOOLBARCONTROLLER_H

#include <QObject>

enum class Tool {
    None,
    PlaceDrill
};

class ToolbarController : public QObject
{
    Q_OBJECT

public:
    explicit ToolbarController(QObject* parent = nullptr);

    Tool currentTool() const;

public slots:
    void onAddDrillClicked();
    void onDeselectClicked();

private:
    Tool tool;   // vraag 22: useful member variable
};

#endif
