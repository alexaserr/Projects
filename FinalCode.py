# This code was created based on the three codes made by the team.
# It does two main things, in first place it recognizes a Face,
# in second place, it detects the color red in the live image.

import cv2
import numpy as np

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')

capture = cv2.VideoCapture(0)

while (True):
    ret, img = capture.read()
    hav = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
		grayscale = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

		faces = face_cascade.detectMultiScale(grayscale, 1.3, 5)
		
		for(x, y, w, h) in faces:
			cv2.rectangle(img, (x, y), (x+w, y+h), (255, 255, 0), 2)
			roi_gray = grayscale[y:y+h, x:x+w]
			roi_color = img[y:y+h, x:x+w]

			eyes = eye_cascade.detectMultiScale(roi_gray)

			for(ex, ey, ew, eh) in eyes:
				cv2.rectangle(roi_color, (ex, ey), (ex+ew, ey+eh),
				(0, 127, 255), 2)

			# Displays an image in a window
			cv2.imshow('img',img)

			# Waits for Esc key to stop
			k = cv2.waitKey(30) & 0xff
			if k == 27:
				break

    lower_red = np.array([50, 150, 150])
    uper_red = np.array([180, 255, 255])
    
    mask = cv2.inRange(hav, lower_red, uper_red)
    res = cv2.bitwise_and(frame, frame, mask = mask)

    cv2.imshow('Visor', frame)
    cv2.imshow('Mask', mask)
    cv2.imshow('Result', res)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()