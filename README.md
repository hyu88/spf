
# SPF-CellTracker

This is a software suite for tracking more than a hundred of cells from 4D live cell
imaging data with following characteristics:

1. grey scale image, 
2. globular-like cell shapes, 
3. strong covariation of cells to be tracked, 
4. no background image except background noise and salt- and-pepper noise. 

This software suite is composed of three executables: **convert**, **track**, and **view**.
The first and second software are implemented in C while the third is implemented in C++.
OpenCV 2.4+ is used for _convert_. OpenGL 3.3+ and freeglut are used for _view_.

## convert

The first software **convert** converts a set of 2D images that compose 4D live-cell
imaging data into a single file encoded as our original binary format. The software
**convert** utilizes OpenCV 2.4+ only for loading original image files, and thereby
all the image file formats to which OpenCV 2.4.9 supports can be converted. During
conversion, average subtraction and 3D median filter can be optionally applied for
each 3D image in order to remove background noise and salt-and-pepper noise. We
implemented a linear-time algorithm for computing median to make 3D median filter faster.

### COMPILATION:

1. Install OpenCV 2.4+.

2. Get all the source codes registered in **converter** directory of this 
   repository and move them to the current directory.

3. Modify paths to OpenCV library and header files indicated by **LIBPATH** 
   and **INCLUDE** in **makefile** if needed. 

4. Type `make` in the terminal window.


### USAGE:

1. Modify the configuration file **conf-convert.txt** according to your preference.

2. Type `./convert` in the terminal window.

## track
The second software **track** is the main software for automatic detection and tracking of
multiple cells based on the SPF algorithm from the converted 4D image file. For details of
the algorithm, please refer to the article titled *SPF-CellTracker: Multiple cell tracking with a
spatial particle filter* (in submission).

### COMPILATION:

1. Get all the source codes registered in **tracker** directory of this
   repository and move them to the current directory.

2. Type `make` in the terminal window.

### USAGE:

1. Modify the configuration file `conf-track.txt` according to your preference.

2. Type `./track` in the terminal window.

## view

The third software **view** is to visualize the 4D image data with a
tracking result. This software allows us to zoom in, zoom out, and rotate
4D image during playing 4D image data. Currently, only a binary file for
Mac OS X is available for the software *view*. We will distribute source
codes in the near future.

### INSTALL (Mac only):

1. Install the software **Xquartz**, an implementation of X window system 
   which runs on OS X. 

2. Get the binary file **view** in **bin/Mac** directory of this repository 
   and move it to the current directory.

### USAGE:

1. Put a 4D image file converted by *convert* and a trajectory file output 
   by *tracker* in the current directory.

2. Type the following command:

  `./view input-file-name trajectory-file-name`





