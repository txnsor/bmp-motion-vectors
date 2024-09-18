BMP Motion Vectors by Marceline (Marc) Browning

This is a simple project designed to read 2 png files, and export an image that displays the approximate motion vectors between the two images.

There are three main parts:

1. read_file.c - initialize a single image file in an array stored on the heap (and process the file header).
2. lk_vectors.c - take two images and compute the Lucas-Kanade (LK) optical flow iteratively on both images.
3. export_file.c - take a heap array and export it to a new, empty bmp.

Functionality is provided to create an optical flow based, motion vector encoding codec.
