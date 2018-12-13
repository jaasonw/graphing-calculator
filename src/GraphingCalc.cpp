#include "GraphingCalc.h"

GraphingCalc::GraphingCalc() {
    srand(time(0));
    new Graph();
    engine.run();
}