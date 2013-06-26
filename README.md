mandelbrots
===========

### Generating a set of points satisfying the Mandelbrot set equation
---------------------------------------------------------------------
1.  `mandelbrot_set.py` script generates the geometrical fractal (set of points in a complex plane spread out according to an algorithm) of a Mandelbrot set given by the formula: 
  * `Zn+1 = Zn^2 + c, Z0 = c`, where Z is a complex number of the form `x+iy`
2.  Simply to put, Mandelbrot set is a set of all `c`'s such that a corresponding Zn doesn't touch infinity when n -> infinity.
3.  Just learnt that the equation in point 1. is a quadratic one. For a 4-dimensional Mandelbrot set, we need a cubic equation with the same logic. Shall test it soon.
