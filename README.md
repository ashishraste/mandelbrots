mandelbrots
===========

### Generating a set of points satisfying the Mandelbrot set equation
---------------------------------------------------------------------
1.  `mandelbrot_set.py` script generates the geometrical fractal (set of points in a complex plane spread out according to an algorithm) of a Mandelbrot set given by the equation: 
  * `Zn+1 = Zn^2 + c, Z0 = c`, where Z is a complex number of the form `x+iy`
2.  Simply to put, Mandelbrot set is a set of all `c`'s such that a corresponding Zn doesn't touch infinity when n -> infinity.
3.  Images ![mandelbrot1](https://github.com/ashishraste/mandelbrots/blob/master/mandelbrot_fractal1.png) This image is the fractal obtained by applying the above equation.
3.  The equation in point 1. is a quadratic. For a 4-dimensional Mandelbrot set, we need a cubic equation with the same logic. Shall test it soon.



### Notes
---------
Following recipes need to be covered soon. <br/>
 1. 4-dimensional Mandelbrot fractal <br/>
 2. Julia set and its fractal images
