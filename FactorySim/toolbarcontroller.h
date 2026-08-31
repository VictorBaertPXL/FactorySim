// vraag 3: useful and correct class
// vraag 4: useful and correct abstraction
// vraag 5: useful and correct encapsulation
// vraag 8: useful and correct object composition
// vraag 22: useful member variable
// vraag 33: enum

#ifndef TOOLBARCONTROLLER_H
#define TOOLBARCONTROLLER_H

#include <QObject>   // vraag 42: useful Qt class

enum class Tool {
    None,
    PlaceDrill,
    PlaceConveyor,
    PlaceAssembler,
    RotateConveyor,
    DeleteMachine
}; // vraag 33: enum

class ToolbarController : public QObject
{
    Q_OBJECT

public:
    explicit ToolbarController(QObject* parent = nullptr);   // vraag 12: default constructor

    Tool currentTool() const { return current; }             // vraag 23: useful getter

public slots:
    void onPlaceDrillClicked();       // vraag 43: signals/slots
    void onPlaceConveyorClicked();    // vraag 43
    void onPlaceAssemblerClicked();   // vraag 43
    void onRotateConveyorClicked();   // vraag 43
    void onDeleteMachineClicked();    // vraag 43
    void onDeselectClicked();         // vraag 43

private:
    Tool current;   // vraag 22: useful member variable
};

#endif
