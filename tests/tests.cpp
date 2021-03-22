#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../header/basic_shapes.hpp"
#include "../header/shape.hpp"
#include <fstream>
#include <sstream>

TEST_CASE("draw a circle"){
    std::ostringstream output;

    Circle circle(120);

    circle.draw(output);

    REQUIRE(output.str() == "gsave\nnewpath\n0 0 120 0 360 arc \nstroke\ngrestore\n");
}

TEST_CASE("Draw a polygon.") {
  std::ostringstream output;

  Poly poly(4, 100);

  poly.draw(output);

 REQUIRE(output.str() ==
          "gsave\nnewpath\n/S 4 def /H 50 \ndef /A 360 S div "
          "def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 "
          "moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } "
          "repeat\nclosepath\nstroke\ngrestore\n");
}