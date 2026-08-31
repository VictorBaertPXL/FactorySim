#include "ToolbarController.h"

ToolbarController::ToolbarController(QObject* parent)
    : QObject(parent), current(Tool::None)   // vraag 16: member initialization list
{
}

void ToolbarController::onPlaceDrillClicked()       // vraag 43: slot
{
    current = Tool::PlaceDrill;
}

void ToolbarController::onPlaceConveyorClicked()    // vraag 43
{
    current = Tool::PlaceConveyor;
}

void ToolbarController::onPlaceAssemblerClicked()   // vraag 43
{
    current = Tool::PlaceAssembler;
}

void ToolbarController::onRotateConveyorClicked()   // vraag 43
{
    current = Tool::RotateConveyor;
}

void ToolbarController::onDeleteMachineClicked()    // vraag 43
{
    current = Tool::DeleteMachine;
}

void ToolbarController::onDeselectClicked()         // vraag 43
{
    current = Tool::None;
}
