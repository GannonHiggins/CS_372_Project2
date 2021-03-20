#include "shape.hpp"
#include "basic_shapes.hpp"
#include "catch.hpp"
#include <fstream>
#include <sstream>

TEST_CASE("draw a circle"){
    std::ostringstream output;

    Circle circle(120);

    circle.draw(output);

    REQUIRE(output.str() == "gsave\nnewpath\n120 120 120 0 360 arc\nstroke\ngrestore\n");
}