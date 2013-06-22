## This script generates the geometrical fractal(set of points in a complex plane spread out according to an algorithm) of Mandelbrot set: Zn+1 = Zn^2 + C, Z0 = C, where Z is a complex number of the form x+iy
## Simply to put, Mandelbrot set is a set of all C's such that a corresponding Zn doesn't equal infinity when n -> infinity

import sys
from PIL import Image

#Declaring the constants
image_size = 512			# considering an image of resolution 300X300 pixels
maxIterations = 256

image = Image.new("RGB", (image_size, image_size))
width, height = image.size 	# width and height of the rectangle, in which we are going to plot our Mandelbrot set, are equal to the image widht and height
MaxRe = 1 					# setting the minimum point as -2+i 
MinRe = -2
MinIm = -1.5
MaxIm = 1.5

Re_factor = (MaxRe-MinRe)/(width-1)
Im_factor = (MaxIm-MinIm)/(height-1)

for y in range(height):
	c_im = MinIm + y * Im_factor
	for x in range(width):
		c_re = MinRe + x * Re_factor
		c = complex(c_re, c_im)
		Z = 0		
		for n in range(maxIterations):	# Iterating for a certain number of times and checking whether |Z| > 2. If so, it will jump to infinity and hence we quit the iterations for a pixel corresponding to (x,y)			
			if abs(Z) > 2: 
				break
			Z = Z * Z + c 				# if (x,y) is inside, then for the next iteration, Zn+1 = Zn^2 + C			
		r = n % 4 * 64
        g = n % 8 * 32
        b = n % 16 * 16
        image.putpixel((x, y), b * 65536 + g * 256 + r)		

image.save("mandelbrot.png", "PNG")
print "Created the Mandelbrot fractal..Sayo nara!"
sys.exit()	






