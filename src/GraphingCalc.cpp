#include "GraphingCalc.h"

GraphingCalc::GraphingCalc() {
    engine.create_instance(new Graph());
    engine.run();
}