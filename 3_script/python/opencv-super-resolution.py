#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
opencv图片超分辨
"""

# import the necessary packages
import argparse
import time
import cv2
import os

# modelPath = args['model']
# imagePath = args['image']
# modelPath = 'model/EDSR_Tensorflow/models/EDSR_x2.pb'
# modelPath = 'model/FSRCNN_Tensorflow/models/FSRCNN_x2.pb'
# modelPath = 'model/TF-ESPCN/export/ESPCN_x2.pb'
modelPath = 'model/TF-LapSRN/export/LapSRN_x2.pb'
imagePath = 'assets/img.png'
# extract the model name and model scale from the file path
modelName = modelPath.split(os.path.sep)[-1].split("_")[0].lower()
modelScale = modelPath.split("_x")[-1]
modelScale = int(modelScale[:modelScale.find(".")])

# initialize OpenCV's super resolution DNN object, load the supper
# resolution model from disk, and set the model name and scale
print("[INFO] loading super resolution model: {}".format(modelPath))
print("[INFO] model name: {}".format(modelName))
print("[INFO] model scale: {}".format(modelScale))
sr = cv2.dnn_superres.DnnSuperResImpl_create()
sr.readModel(modelPath)
sr.setModel(modelName, modelScale)

# load the input image from disk and display its spatial dimensions
image = cv2.imread(imagePath)
print("[INFO] w: {}, h: {}".format(image.shape[1], image.shape[0]))
# use the super resolution model to upscale the image, timing how long it takes
start = time.time()
upscaled = sr.upsample(image)
end = time.time()
print("[INFO] super resolution took {:.6f} seconds".format(end - start))
# show the spatial dimensions of the super resolution image
# print("[INFO] w: {}, h: {}".format(upscaled.shape[1], upscaled.shape[0]))

# resize the image using standard bicubic imterpolation
start = time.time()
# bicubic = cv2.resize(image, (upscaled.shape[1], upscaled.shape[0]), interpolation=cv2.INTER_CUBIC)
bicubic = cv2.resize(image, (1280, 720), interpolation=cv2.INTER_CUBIC)
end = time.time()
print("[INFO] bicubic interpolation took {:.6f} seconds".format(end - start))

# show the original input image, bicubic interpolation image, and super resolution deep learning output
cv2.imshow("Original(原始图)", image)
cv2.imwrite("Bicubic11(三次插值图).png", bicubic)
# cv2.imwrite("Super Resolution11(超分辨率图像).png", upscaled)
cv2.waitKey(0)
