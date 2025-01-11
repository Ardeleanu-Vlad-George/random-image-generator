# Purpose
Make project that generates a random image, with pixels having random values, based on the following parameters:
- the sizes of the image, width first, than height, first two CLAs;
- the name of the image, the file in which it will get stored, the last CLA;

# Below is the OLD help
First args must be the following three in the next order
Give the following mandatory args in the next order
	1. width  of image
	2. height of image
	3. name   of storage file
After that, the next options can be activated
	r <value> - reds   of all pixels are the same value, default one, if value is not present
	g <value> - greens of all pixels are the same value, default one, if value is not present
	b <value> - blues  of all pixels are the same value, default one, if value is not present
	a <value> - alphas of all pixels are the same, random values for each pixel, if value is missing
If a color option is not activated, than the component is randomnly selected
If the alpha option is not activated, than it's opaque

# Next is the new help, and how the application should actually behave
Give the following mandatory args in the next order
	1. width  of image
	2. height of image
	3. name   of storage file
After that, the next options can be activated
	r \<dec\_value\> - reds   of all pixels are the given value
	g \<dec\_value\> - greens of all pixels are the given value
	b \<dec\_value\> - blues  of all pixels are the given value
	a \<text\> - text can be:
        a) a decimal value to set all alphas
        b) the letter 'r' to indicate random choice of opacity values
OBS: The 'arg' of each option is mandatory! Output image is not generated if not given.
If an option is not activated than the following default behaviours are executed:
a) for the 'r', 'g' and 'b' components, their values are randomly selected
b) for the 'a' one, it's value is opaque for all of the pixels
If any of the specified requirements are not met, an error message is written to the console.
