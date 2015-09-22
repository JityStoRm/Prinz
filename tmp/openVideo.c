#include <cv.h>
#include <highgui.h>

main()
{
IplImage *image;
CvCapture *capture;
unsigned char key;

capture = cvCreateCameraCapture(0);
cvNamedWindow("Video", CV_WINDOW_AUTOSIZE);

do{
image = cvQueryFrame(capture);
cvShowImage("Video",image);

key = (unsigned char)cvWaitKey(10);
}while (key != 'q');

cvDestroyWindow("Video");
cvReleaseCapture(&capture);
}
