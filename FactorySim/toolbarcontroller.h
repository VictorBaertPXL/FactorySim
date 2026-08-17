#ifndef TOOLBARCONTROLLER_H
#define TOOLBARCONTROLLER_H

#include <QObject>

enum class Tool {
    None,
    PlaceDrill,
    PlaceConveyor,
    RotateConveyor,
    DeleteMachine
};

class ToolbarController : public QObject
{
    Q_OBJECT

public:
    explicit ToolbarController(QObject* parent = nullptr);

    Tool currentTool() const { return current; }

public slots:
    void onPlaceDrillClicked();
    void onPlaceConveyorClicked();
    void onRotateConveyorClicked();
    void onDeleteMachineClicked();
    void onDeselectClicked();

private:
    Tool current;
};

#endif
