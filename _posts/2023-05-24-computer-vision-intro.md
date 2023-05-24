---
layout: post
title: Computer Vision Introduction
description: opencv 
tags: opencv 
---


# Computer Vision with OpenCV

My notes on my ongoing CV experiences and introductions with [OpenCV](https://opencv.org).


OpenCV is an open-source library that includes several hundreds of computer vision algorithms. 


## Modules

OpenCV has a modular structure and different modules available:


| Module        | Feature       | 
| ------------- |:-------------:| 
| core          | basic data structures |
| imgproc      | Image Processing - transformations (resize, affine and perspective warping, generic table-based remapping), color space conversion, histograms, and so on  |
| video  | video analysis - motion estimation,  background subtraction, object tracking algorithms     |    
| calib3d   | Camera Calibration and 3D Reconstruction - basic multiple-view geometry algorithms, single and stereo camera calibration, object pose estimation, stereo correspondence algorithms, and elements of 3D reconstruction |
| features2d | 2D Features Framework - salient feature detectors, descriptors, and descriptor matchers |
| objdetect | detection of objects and instances of the predefined classes (for example, faces, eyes, mugs, people, cars, and so on) |
| highgui   | High-level GUI |
| videoio   | Video I/O |
| gpu      | GPU-accelarated algorithms (supports CUDA) |



## Use cases

- OCR and face recognition (blink detection, smile shutter, unlocking). 
- Object recognition (mobile devices, glasses) 
  - supermarket: did you forget something in your basket? 
  - quality analysis
  - counting
  - tracking
- vfx (special effects, motion detection) 
- image stitching
- intrusion detection
- intelligent cars 
  - traffic analysis
- robots navigation or picking up objects
- sports (sports vision downline, accidents)
- image-based interaction (Kinect, Wii, Realsense)
- medical imaging (3D imaging MRI, CT, guided surgery)
- interactive art
- ...


## Why it is difficult

For the computer, the same colors can appear on different objects, for example due to shadows.

Image processing does not work in that case, so it is not image processing, but vision. 
Computer vision builds models from changes.

Computerized models that process depth, ground truth, e.g. using a "scanline".

- Image processing (basic structure, manipulation for interaction)
- Camera models and views 
- Brightness and luminosity 
- Sequence of images: Motion, tracking (how do things move?)
- basic classification and recognition


## Images as functions

An image can be more than a 2D array of numbers.

`f(x,y)` Image as function


Example: image intensity `I(x,y)`, computing a grayscale image where the depths are darker. Process a blurred image to get smoother values.

Identify locations and determine bounds as a rectangle `R(x,y)` in the finite range of image width and height.


A 3-channel color image is a mapping from a 2-dimensional space of locations to a 3-dimensional space of color intensity values.

Most often, a color image consists of 3 stacked functions written as "vector-valued" functions:

```
f(x,y)=[
  r(x,y)
  g(x,y)
  b(x,y)
]
```

## Discrete Images

- *Sample* the 2D space on grid (rows, columns)
- *Quantize* each Sample (to nearest integer)


Digital images are represented as a Matrix of integers.

Calculate an area: `x2-x1=width, y2-y1=height, area=width*height`


## Pels or Pixels technically

Pixels (px), also called picture elements (pel), are the smallest addressable element (that can be manipulated) on most displays.
Each pixel on an LCD display is usually represented by a triad (3 vertically aligned subpixels). 
These separately addressable elements are called subpixels and can be ignored or included, for example in subpixel rendering. 

A logical pixel (often used in graphics and web design) denotes a value that does not necessarily represent a pixel of the screen. 


## Quantize an Image

Round each Pixel value of an input image to the nearest integer.


Example:

![](/images/opencv-quantize.gif)

![](/images/openvc-quantize-result.png)




## Links

1. [OpenCV WIKI](https://github.com/opencv/opencv/wiki) and [OpenCV Docs 4.7](https://docs.opencv.org/4.7.0/d1/dfb/intro.html) 
2. [Udacity Course](https://www.udacity.com/course/introduction-to-computer-vision--ud810)
3. [Computer Vision on the GPU with OpenCV - James Fung (2012)](https://developer.download.nvidia.com/GTC/PDF/1085_Fung.pdf)

