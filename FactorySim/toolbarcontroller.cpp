#include "ToolbarController.h"

ToolbarController::ToolbarController(QObject* parent)
    : QObject(parent), tool(Tool::None)
{
}

Tool ToolbarController::currentTool() const
{
    return tool;
}

void ToolbarController::onAddDrillClicked()
{
    tool = Tool::PlaceDrill;
}

void ToolbarController::onDeselectClicked()
{
    tool = Tool::None;
}

void ToolbarController::onAddConveyorClicked()
{
    tool = Tool::PlaceConveyor;
}
