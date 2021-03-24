#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../header/basic_shapes.hpp"
#include "../header/shape.hpp"
#include "../header/primatives.hpp"
#include <fstream>
#include <sstream>

TEST_CASE("draw a circle"){
    std::ostringstream output;

    SECTION("draw a Circle at 0,0."){

      Circle circle({0, 0}, 120);
      circle.draw(output);

      REQUIRE(output.str() == "gsave\nnewpath\n0 0 120 0 360 arc \nstroke\ngrestore\nshowpage");
    }

    // Reset output stringstream 
    std::ostringstream().swap(output);
  
    SECTION("draw a circle at 4,5 different position."){

      Circle circle1({4.0, 5.0}, 120);
      circle1.draw(output);

      REQUIRE(output.str() == "gsave\nnewpath\n4 5 120 0 360 arc \nstroke\ngrestore\nshowpage");
    }
}

TEST_CASE("Draw a polygon.") {
    std::ostringstream output;

    Poly poly({0, 0}, 5, 200);
    poly.draw(output);

    REQUIRE(output.str() ==
          "gsave\nnewpath\n/S 5 def /H 153.884 \ndef /A 360 S div "
          "def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 "
          "moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } "
          "repeat\nclosepath\nstroke\ngrestore\nshowpage");
}

TEST_CASE("draw a Square."){

    std::ostringstream output;

    Square square({0, 0}, 200);
    square.draw(output);

    REQUIRE(output.str() == "gsave\nnewpath\n/S 4 def /H 100 \ndef /A 360 S div "
          "def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 "
          "moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } "
          "repeat\nclosepath\nstroke\ngrestore\nshowpage");
}

TEST_CASE("draw a Triangle."){
    std::ostringstream output;
    Triangle triangle({0, 0}, 120);
    triangle.draw(output);

    REQUIRE(output.str() == "gsave\nnewpath\n/S 3 def /H 51.9615 \ndef /A 360 S div "
          "def A cos H mul H sub A sin H mul 0 sub atan rotate -90 rotate H 0 "
          "moveto S{ A cos H mul A sin H mul lineto /A A 360 S div add def } "
          "repeat\nclosepath\nstroke\ngrestore\nshowpage");

}

TEST_CASE("draw a rectangle."){
  std::ostringstream output;
  Rect rect({10,10},50,100);
  rect.draw(output);

  REQUIRE(output.str() == "10 10 moveto\ngsave\nnewpath\n-25 -50 50 100 rectstroke \nstroke\ngrestore\nshowpage");
}
