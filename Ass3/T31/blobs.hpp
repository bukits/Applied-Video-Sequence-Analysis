/* Applied Video Analysis of Sequences (AVSA)
 *
 *	LAB2: Blob detection & classification
 *	Lab2.0: Sample Opencv project
 *
 *
 * Authors: José M. Martínez (josem.martinez@uam.es), Paula Moral (paula.moral@uam.es), Juan C. San Miguel (juancarlos.sanmiguel@uam.es)
 */

 //class description
/**
 * \class BasicBlob
 * \brief Class to describe a basic blob and associated functions
 *
 * 
 */

#ifndef BLOBS_H_INCLUDE
#define BLOBS_H_INCLUDE

#include "opencv2/opencv.hpp"
using namespace cv; //avoid using 'cv' to declare OpenCV functions and variables (cv::Mat or Mat)


// Maximun number of char in the blob's format
const int MAX_FORMAT = 1024;

/// Type of labels for blobs
typedef enum {	
	UNKNOWN=0, 
	PERSON=1, 
	GROUP=2, 
	CAR=3, 
	OBJECT=4
} CLASS;

struct cvBlob {
	int     ID;  /* blob ID        */
	int   x, y;  /* blob position  */
	int   w, h;  /* blob sizes     */	
	CLASS label; /* type of blob   */
	char format[MAX_FORMAT];
};

inline cvBlob initBlob(int id, int x, int y, int w, int h)
{
	cvBlob B = { id,x,y,w,h,UNKNOWN};
	return B;
}

/*
* Headers of blob-based functions
*
*/

//blob drawing functions
Mat paintBlobImage(Mat frame, std::vector<cvBlob> bloblist, bool labelled);

//blob extraction functions
int extractBlobs(Mat fgmask, std::vector<cvBlob> &bloblist, int connectivity);
int removeSmallBlobs(std::vector<cvBlob> bloblist_in, std::vector<cvBlob> &bloblist_out, int min_width, int min_height);

bool biggestBlob(std::vector<cvBlob> bloblist_in, cvBlob &bigBlob, int min_width, int min_height);//
//blob classification functions
int classifyBlobs(std::vector<cvBlob> &bloblist);

//stationary blob extraction functions
int extractStationaryFG (Mat fgmask, Mat &fgmask_history, Mat &sfgmask);


#endif

