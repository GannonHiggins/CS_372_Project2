# CS_372_Project2

1. Formalize the shape language as one or more recursive type definitions.
2. Design and implement CPS.
3. Design one or more nice shapes of your own and generate PostScript from them. You'll probably want to write some classes that build on the shape language. For example, you might implement a class Skylines that contains methods returning randomized skylines with the number/height/shape of buildings specified as input arguments to the methods. Or you might implement a class Fractals that creates some fractal figures with a recursion limit specified by the user. These are just examples; it's entirely up to you. 
4. Design and implement a test strategy for this project. In addition to the test cases themselves, you should give a brief commentary explaining your strategy.
5. Critique the specification of the shape language. Is the language expressive enough to create interesting drawings? Are the shape abstractions well-designed, or not? Do they make certain drawings easy/difficult to create? If you were to design the shape language from scratch, what would you do differently?

## Formal Shape Language Definiton

### A shape has a bounding box, units, and a current point. 
A bounding box is an undrawn rectangle that encloses the shape. 
The current point represents the coordinates of the current location of the cursor (PostScripts moveto will define our current point).

### BASIC SHAPES

#### A Circle is a shape
The height and width of a circle are both 2*radius. The units have a basic measurement of 1/72 of an inch.

#### A Polygon is a shape
A polygon has a number of sides (must be greater than 2), each at a given length. Oriented so that the lowermost side is horizontal.

#### A Square is a polygon
A square has 4 sides

#### A Triangle is a Polygon
A Triangle is a polygon with 3 sides and sideLength

#### A Rectangle is a shape
A rectangle has a given width and height

#### A Spacer is a rectangle
A spacer is not visible on the page

### COMPOUND SHAPES

#### A Rotated is a shape
A rotated takes a shape and a rotation angle which is either 90, 180, or 270 degrees.

#### A Scaled is a shape
A scaled takes a shape, a horizontal scaling factor, and a vertical scaling factor. Creates a shape scaled by the given scaling factors.

#### A Layered is a shape
A layered takes a collection of shapes and creates a new shape consisting of all the shapes drawn with their bounding boxes centered on the current point.

#### A Vertical is a shape
A vertical takes an ordered collection of shapes and creates a shape structured as follows:
* shape i+1 is above shape i
* all shapes are vertically centered by their bouding boxes
* the bounding box has width equal to the maximum component shape's width
* the bounding box has height equal to the sum of the component shape's heights

#### A Horizontal is a shape
A horizontal takes an ordered collection of shapes and creates a shape structured as follows:
* shape i+1 is right of shape i
* all shapes are horizontally centered by their bouding boxes
* the bounding box has height equal to the maximum component shape's height
* the bounding box has width equal to the sum of the component shape's widths

