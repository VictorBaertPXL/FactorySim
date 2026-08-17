#include "ToolbarController.h"

ToolbarController::ToolbarController(QObject* parent)
    : QObject(parent), current(Tool::None)
{
}

void ToolbarController::onPlaceDrillClicked()
{
    current = Tool::PlaceDrill;
}

void ToolbarController::onPlaceConveyorClicked()
{
    current = Tool::PlaceConveyor;
}

void ToolbarController::onRotateConveyorClicked()
{
    current = Tool::RotateConveyor;
}

void ToolbarController::onDeleteMachineClicked()
{
    current = Tool::DeleteMachine;
}

void ToolbarController::onDeselectClicked()
{
    current = Tool::None;
}
