// vraag 33: enum

#ifndef TOOLBARCONTROLLER_H
#define TOOLBARCONTROLLER_H

#include <QObject>

enum class Tool {
    None,
    PlaceDrill,
    PlaceConveyor    // vraag 33
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
    void onAddConveyorClicked();

private:
    Tool tool;   // vraag 22: useful member variable
};

#endif
