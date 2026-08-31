# FactorySim

FactorySim is a small factory simulation where you can place machines (Drill, Conveyor, Assembler) on a grid and watch items flow through the production line. It focuses on clean OOP design, Qt GUI usage, and modern C++ features.

---

## 1. Projectomschrijving

**Topic:** FactorySim – fabriekssimulatie  
**Beschrijving:**  
Je bouwt een eenvoudige fabriek op een raster.  
Je kan:
- **Drills** plaatsen die grondstoffen genereren  
- **Conveyors** plaatsen die items verplaatsen  
- **Assemblers** plaatsen die items combineren tot nieuwe producten  

De simulatie toont:
- Hoe machines samenwerken  
- Hoe items door de fabriek bewegen  
- Hoe rotatie, verwijdering en interactie werken via een GUI

---

## 2. Class structuur (OOP)

Belangrijkste classes:

- **Machine (abstract base class)**
  - Basis voor alle machines
  - Pure virtual functies: `draw(QPainter&)`, `process(FactoryEngine&)`
  - Positie (`row`, `col`) en type

- **Drill (inherits Machine)**
  - Genereert nieuwe items op vaste intervallen
  - Gebruikt `process()` om items in de wereld te plaatsen

- **Conveyor (inherits Machine)**
  - Verplaatst items in een bepaalde `Direction`
  - Gebruikt een interne buffer (`std::vector<Item*>`)
  - Rotatie via toolbar (Up/Down/Left/Right)

- **Assembler (inherits Machine)**
  - Combineert inkomende items tot nieuwe producten
  - Gebruikt `process()` om items te consumeren en nieuwe te maken

- **Item**
  - Stelt een grondstof of product voor
  - Bevat type, positie en flags (bv. `unsigned char` voor status)

- **FactoryEngine**
  - Beheert alle machines en items
  - Houdt een `std::vector<Machine*>` bij
  - Verantwoordelijk voor:
    - Simulatiestap (`processAll()`)
    - Machines toevoegen/verwijderen
    - File I/O (save/load)
    - Memory cleanup (destructor met `delete`)

- **FactoryView (QWidget)**
  - Tekent de fabriek (grid + machines + items)
  - Gebruikt `QPainter` in `paintEvent`
  - Handelt muisklikken (`mousePressEvent`) om machines te plaatsen/verwijderen

- **ToolbarController (QObject)**
  - Houdt bij welke tool actief is (enum `Tool`)
  - Slots voor knoppen: PlaceDrill, PlaceConveyor, PlaceAssembler, Rotate, Delete, Deselect

- **MainWindow (QMainWindow)**
  - Verbindt toolbar, FactoryView en FactoryEngine
  - Bevat menu/toolbar en centrale widget

- **Direction (enum class)**
  - `Up`, `Down`, `Left`, `Right` voor conveyors

- **Utils (template)**
  - `template<typename T> T clamp(T value, T min, T max);`

---

## 3. Gebruikte C++ features

Project demonstreert:

- **Inheritance & polymorphism**
  - `Machine` als base class
  - `Drill`, `Conveyor`, `Assembler` als derived classes
  - Virtual functions (`draw`, `process`)

- **Encapsulation**
  - Members private/protected
  - Getters/setters voor positie, tool, etc.

- **Object composition**
  - `FactoryEngine` bevat machines en items
  - `Conveyor` bevat een buffer van items

- **Constructors & destructors**
  - Default en parameterized constructors
  - Copy constructor (bv. FactoryGrid)
  - Member initialization lists
  - Destructors met `delete` voor dynamic memory

- **Advanced C++**
  - `template` functie in Utils
  - `enum class Direction`, `enum class Tool`
  - `std::vector` als container
  - `nullptr`
  - `call-by-reference` (`draw(QPainter&)`, `process(FactoryEngine&)`)
  - `unsigned char` voor compacte flags
  - `lambda` voor bv. autosave of filtering
  - `std::thread` voor achtergrondtaken
  - File I/O + exception handling

---

## 4. Qt & GUI

Project gebruikt:

- **Qt classes**
  - `QApplication`, `QMainWindow`, `QWidget`, `QPainter`, `QTimer`, `QMouseEvent`

- **Signals/slots**
  - Toolbar knoppen → `ToolbarController` slots
  - Timer → simulatie‑update

- **GUI**
  - Hoofdvenster (`MainWindow`)
  - Centrale view (`FactoryView`)
  - Toolbar voor tools (Drill, Conveyor, Assembler, Rotate, Delete)

---

## 5. Build instructies

### Vereisten

- C++17 of hoger
- Qt 5/6 (Widgets)
- CMake of qmake (afhankelijk van jouw projectsetup)

### Stappen (voorbeeld met CMake)

```bash
git clone https://github.com/VictorBaertPXL/FactorySim.git
cd FactorySim
mkdir build
cd build
cmake ..
cmake --build .
