#include "Graph.h"
#include "engine/Engine.h"

class GraphingCalc {
private:
    Engine engine;
public:
    GraphingCalc();
};

GraphingCalc::GraphingCalc() : engine() {
    engine.create_instance(new Graph());
    engine.run();
}
