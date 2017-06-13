# ImageProcessing

A simple program to help create a database from a set of image.

The project was realised with the Desktop Qt 5.7.0 GCC 64bit kit and opencv 2.4.13

Sor far there are two options :

* Extracting ROI from the image and store it to the folder linked to the ROI class
* Selecting ROI, cutting the image down into parts and store the part to the correct folder depending on the ROI class

## Extracting ROI

* Resize is for resizing the output image to the desired sized
* The classes are used for the roi selection and to set the output directory
* Image path, the directory were to find the images to process

## Cutting the image down

* Resize is for resizing the output image to the desired sized
* Module size, the size of the module once the image is cut into pieces (ie. 64*32 image with base module will output 2 images)
* The classes are used for the roi selection and to set the output directory
* Base path, were to send the images belonging to no classes
* Image path, the directory were to find the images to process

A module can belong to more than one class.

## Extraction

* Select class
* Draw the rectangle around the target objects (do this for each class)
* Ok button will process the image
* Return will remove the last rectangle
* Reset will remove every rectangle
