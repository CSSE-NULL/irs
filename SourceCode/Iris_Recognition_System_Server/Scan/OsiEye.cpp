#include <fstream>
#include <stdexcept>
#include "cv.h"
#include "OsiEye.h"
#include "OsiProcessings.h"

using namespace std;

namespace osiris
{

    // CONSTRUCTORS & DESTRUCTORS
    /////////////////////////////

    OsiEye::OsiEye()
    {
        mpOriginalImage = 0;
        mpSegmentedImage = 0;
        mpMask = 0;
        mpNormalizedImage = 0;
        mpNormalizedMask = 0;
        mpIrisCode = 0;
        mPupil.setCircle(0, 0, 0);
        mIris.setCircle(0, 0, 0);
    }

    OsiEye::~OsiEye()
    {
        cvReleaseImage(&mpOriginalImage);
        cvReleaseImage(&mpSegmentedImage);
        cvReleaseImage(&mpMask);
        cvReleaseImage(&mpNormalizedImage);
        cvReleaseImage(&mpNormalizedMask);
        cvReleaseImage(&mpIrisCode);
    }

    // Functions for loading images and parameters
    //////////////////////////////////////////////
    //具体加载图片函数
    void OsiEye::loadImage(const string & rFilename, IplImage ** ppImage)
    {
        // :WARNING: ppImage is a pointer of pointer
        try
        {
            if (*ppImage)
            {
                cvReleaseImage(ppImage);
            }

            *ppImage = cvLoadImage(rFilename.c_str(), 0);
            if (!*ppImage)
            {
                cout << "Cannot load image : " << rFilename << endl;
            }
        }
        catch (exception & e)
        {
            cout << e.what() << endl;
        }
    }


    //执行加载原始图片的入口
    void OsiEye::loadOriginalImage(const string & rFilename)
    {
        loadImage(rFilename, &mpOriginalImage);
    }


    //执行加载掩码图片的入口
    void OsiEye::loadMask(const string & rFilename)
    {
        loadImage(rFilename, &mpMask);
    }


    //执行加载归一化后的图片的入口
    void OsiEye::loadNormalizedImage(const string & rFilename)
    {
        loadImage(rFilename, &mpNormalizedImage);
    }


    //执行加载归一化后的掩码图片的入口
    void OsiEye::loadNormalizedMask(const string & rFilename)
    {
        loadImage(rFilename, &mpNormalizedMask);
    }



    void OsiEye::loadIrisCode(const string & rFilename)
    {
        loadImage(rFilename, &mpIrisCode);
    }



    void OsiEye::loadParameters(const string & rFilename)
    {
        // Open the file
        ifstream file(rFilename.c_str(), ios::in);

        // If file is not opened
        if (!file)
        {
            throw runtime_error("Cannot load the parameters in " + rFilename);
        }
        try
        {
            //int xp , yp , rp , xi , yi , ri ;
            //file >> xp ;
            //file >> yp ;
            //file >> rp ;
            //file >> xi ;
            //file >> yi ;
            //file >> ri ;
            //mPupil.setCircle(xp,yp,rp) ;
            //mIris.setCircle(xi,yi,ri) ;
            int nbp = 0;
            int nbi = 0;
            file >> nbp;
            file >> nbi;
            mThetaCoarsePupil.resize(nbp, 0.0);
            mThetaCoarseIris.resize(nbi, 0.0);
            mCoarsePupilContour.resize(nbp, cvPoint(0, 0));
            mCoarseIrisContour.resize(nbi, cvPoint(0, 0));
            //matrix.resize( num_of col , vector<double>( num_of_row , init_value ) );
            for (int i = 0; i < nbp; i++)
            {
                file >> mCoarsePupilContour[i].x;
                file >> mCoarsePupilContour[i].y;
                file >> mThetaCoarsePupil[i];
            }
            for (int j = 0; j < nbi; j++)
            {
                file >> mCoarseIrisContour[j].x;
                file >> mCoarseIrisContour[j].y;
                file >> mThetaCoarseIris[j];
            }

        }
        catch (exception & e)
        {
            cout << e.what() << endl;
            throw runtime_error("Error while loading parameters from " + rFilename);
        }

        // Close the file
        file.close();
    }






    // Functions for saving images and parameters
    /////////////////////////////////////////////
    void OsiEye::saveImage(const string & rFilename, const IplImage * pImage)
    {
        // :TODO: no exception here, but 2 error messages
        // 1. pImage does NOT exist => "image was neither comptued nor loaded"
        // 2. cvSaveImage returns <=0 => "rFilename = invalid for saving"
        if (!pImage)
        {
            throw runtime_error("Cannot save image " + rFilename + " because this image is not built");
        }
        if (!cvSaveImage(rFilename.c_str(), pImage))
        {
            cout << "Cannot save image as " << rFilename << endl;
        }
    }

    void OsiEye::saveSegmentedImage(const string & rFilename)
    {
        saveImage(rFilename, mpSegmentedImage);
    }

    void OsiEye::saveMask(const string & rFilename)
    {
        saveImage(rFilename, mpMask);
    }

    void OsiEye::saveNormalizedImage(const string & rFilename)
    {
        saveImage(rFilename, mpNormalizedImage);
    }



    void OsiEye::saveNormalizedMask(const string & rFilename)
    {
        saveImage(rFilename, mpNormalizedMask);
    }

    void OsiEye::saveIrisCode(const string & rFilename)
    {
        saveImage(rFilename, mpIrisCode);
    }

    void OsiEye::saveParameters(const string & rFilename)
    {
        // Open the file
        ofstream file(rFilename.c_str(), ios::out);

        // If file is not opened
        if (!file)
        {
            throw runtime_error("Cannot save the parameters in " + rFilename);
        }

        try
        {
            //    file << mPupil.getCenter().x << " " ;
            //    file << mPupil.getCenter().y << " " ;
            //    file << mPupil.getRadius() << endl ;
            //    file << mIris.getCenter().x << " " ;
            //    file << mIris.getCenter().y << " " ;
            //    file << mIris.getRadius() << endl ;
            file << mCoarsePupilContour.size() << endl;
            file << mCoarseIrisContour.size() << endl;
            for (int i = 0; i<(mCoarsePupilContour.size()); i++)
            {
                file << mCoarsePupilContour[i].x << " ";
                file << mCoarsePupilContour[i].y << " ";
                file << mThetaCoarsePupil[i] << " ";
            }
            file << endl;
            for (int j = 0; j<(mCoarseIrisContour.size()); j++)
            {
                file << mCoarseIrisContour[j].x << " ";
                file << mCoarseIrisContour[j].y << " ";
                file << mThetaCoarseIris[j] << " ";
            }
        }
        catch (exception & e)
        {
            cout << e.what() << endl;
            throw runtime_error("Error while saving parameters in " + rFilename);
        }

        // Close the file
        file.close();
    }


    // Functions for processings
    ////////////////////////////

    void OsiEye::initMask()
    {
        if (mpMask)
        {
            cvReleaseImage(&mpMask);
        }
        if (!mpOriginalImage)
        {
            throw runtime_error("Cannot initialize the mask because original image is not loaded");
        }
        mpMask = cvCreateImage(cvGetSize(mpOriginalImage), IPL_DEPTH_8U, 1);
        cvSet(mpMask, cvScalar(255));
    }

    void OsiEye::segment(int minIrisDiameter, int minPupilDiameter, int maxIrisDiameter, int maxPupilDiameter)
    {
        if (!mpOriginalImage)
        {
            throw runtime_error("Cannot segment image because original image is not loaded");
        }

        // Initialize mask and segmented image
        mpMask = cvCreateImage(cvGetSize(mpOriginalImage), IPL_DEPTH_8U, 1);
        mpSegmentedImage = cvCreateImage(cvGetSize(mpOriginalImage), IPL_DEPTH_8U, 3);
        cvCvtColor(mpOriginalImage, mpSegmentedImage, CV_GRAY2BGR);

        // Processing functions
        OsiProcessings op;

        // Segment the eye
        op.segment(mpOriginalImage, mpMask, mPupil, mIris, mThetaCoarsePupil, mThetaCoarseIris, mCoarsePupilContour, mCoarseIrisContour, minIrisDiameter, minPupilDiameter, maxIrisDiameter, maxPupilDiameter);

        // Draw on segmented image
        IplImage * tmp = cvCloneImage(mpMask);
        cvZero(tmp);
        cvCircle(tmp, mIris.getCenter(), mIris.getRadius(), cvScalar(255), -1);
        cvCircle(tmp, mPupil.getCenter(), mPupil.getRadius(), cvScalar(0), -1);
        cvSub(tmp, mpMask, tmp);
        cvSet(mpSegmentedImage, cvScalar(0, 0, 255), tmp);
        cvReleaseImage(&tmp);
        cvCircle(mpSegmentedImage, mPupil.getCenter(), mPupil.getRadius(), cvScalar(0, 255, 0));
        cvCircle(mpSegmentedImage, mIris.getCenter(), mIris.getRadius(), cvScalar(0, 255, 0));

    }

    void OsiEye::normalize(int rWidthOfNormalizedIris, int rHeightOfNormalizedIris)
    {
        // Processing functions
        OsiProcessings op;

        // For the image
        if (!mpOriginalImage)
        {
            throw runtime_error("Cannot normalize image because original image is not loaded");
        }

        mpNormalizedImage = cvCreateImage(cvSize(rWidthOfNormalizedIris, rHeightOfNormalizedIris), IPL_DEPTH_8U, 1);

        if (mThetaCoarsePupil.empty() || mThetaCoarseIris.empty())
        {
            //throw runtime_error("Cannot normalize image because circles are not correctly computed") ;
            throw runtime_error("Cannot normalize image because contours are not correctly computed/loaded");
        }

        //op.normalize(mpOriginalImage,mpNormalizedImage,mPupil,mIris) ;
        op.normalizeFromContour(mpOriginalImage, mpNormalizedImage, mPupil, mIris, mThetaCoarsePupil, mThetaCoarseIris, mCoarsePupilContour, mCoarseIrisContour);

        // For the mask
        if (!mpMask)
        {
            initMask();
        }

        mpNormalizedMask = cvCreateImage(cvSize(rWidthOfNormalizedIris, rHeightOfNormalizedIris), IPL_DEPTH_8U, 1);

        //op.normalize(mpMask,mpNormalizedMask,mPupil,mIris) ;
        op.normalizeFromContour(mpMask, mpNormalizedMask, mPupil, mIris, mThetaCoarsePupil, mThetaCoarseIris, mCoarsePupilContour, mCoarseIrisContour);
    }

    void OsiEye::encode(const vector<CvMat*> & rGaborFilters)
    {
        if (!mpNormalizedImage)
        {
            throw runtime_error("Cannot encode because normalized image is not loaded");
        }

        // Create the image to store the iris code
        CvSize size = cvGetSize(mpNormalizedImage);
        mpIrisCode = cvCreateImage(cvSize(size.width, size.height*rGaborFilters.size()), IPL_DEPTH_8U, 1);

        // Encode
        OsiProcessings op;
        op.encode(mpNormalizedImage, mpIrisCode, rGaborFilters);
    }

    float OsiEye::match(OsiEye & rEye, const CvMat * pApplicationPoints)
    {
        // Check that both iris codes are built
        if (!mpIrisCode)
        {
            throw runtime_error("Cannot match because iris code 1 is not built (nor computed neither loaded)");
        }
        if (!rEye.mpIrisCode)
        {
            throw runtime_error("Cannot match because iris code 2 is not built (nor computed neither loaded)");
        }

        // Initialize the normalized masks
        // :TODO: must inform the user of this step, for example if user provides masks for all images
        // but one is missing for only one image. However, message must not be spammed if the user
        // did not provide any mask ! So it must be found a way to inform user but without spamming
        if (!mpNormalizedMask)
        {
            mpNormalizedMask = cvCreateImage(cvGetSize(pApplicationPoints), IPL_DEPTH_8U, 1);
            cvSet(mpNormalizedMask, cvScalar(255));
            //cout << "Normalized mask of image 1 is missing for matching. All pixels are initialized to 255" << endl ;
        }
        if (!rEye.mpNormalizedMask)
        {
            rEye.mpNormalizedMask = cvCreateImage(cvGetSize(pApplicationPoints), IPL_DEPTH_8U, 1);
            cvSet(rEye.mpNormalizedMask, cvScalar(255));
            //cout << "Normalized mask of image 2 is missing for matching. All pixels are initialized to 255" << endl ;
        }

        // Build the total mask = mask1 * mask2 * points
        IplImage * temp = cvCreateImage(cvGetSize(pApplicationPoints), mpIrisCode->depth, 1);
        cvSet(temp, cvScalar(0));
        cvAnd(mpNormalizedMask, rEye.mpNormalizedMask, temp, pApplicationPoints);

        // Copy the mask f times, where f correspond to the number of codes (= number of filters)
        int n_codes = mpIrisCode->height / pApplicationPoints->height;
        IplImage * total_mask = cvCreateImage(cvGetSize(mpIrisCode), IPL_DEPTH_8U, 1);
        for (int n = 0; n < n_codes; n++)
        {
            cvSetImageROI(total_mask, cvRect(0, n*pApplicationPoints->height, pApplicationPoints->width, pApplicationPoints->height));
            cvCopy(temp, total_mask);
            cvResetImageROI(total_mask);
        }

        // Match
        OsiProcessings op;
        float score = op.match(mpIrisCode, rEye.mpIrisCode, total_mask);

        // Free memory
        cvReleaseImage(&temp);
        cvReleaseImage(&total_mask);

        return score;
    }

    void OsiEye::releaseBinaryCode()
    {
        delete binaryCode;
        delete binaryMask;
    }

    void OsiEye::outputBinaryCode(const CvMat * pApplicationPoints, const char * filename)
    {
        // Check that both iris codes are built
        if (!mpIrisCode)
        {
            throw runtime_error("Cannot match because iris code 1 is not built (nor computed neither loaded)");
        }

        // Initialize the normalized masks
        // :TODO: must inform the user of this step, for example if user provides masks for all images
        // but one is missing for only one image. However, message must not be spammed if the user
        // did not provide any mask ! So it must be found a way to inform user but without spamming
        if (!mpNormalizedMask)
        {
            mpNormalizedMask = cvCreateImage(cvGetSize(pApplicationPoints), IPL_DEPTH_8U, 1);
            cvSet(mpNormalizedMask, cvScalar(255));
            //cout << "Normalized mask of image 1 is missing for matching. All pixels are initialized to 255" << endl ;
        }

        // Build the total mask = mask1 * points
        IplImage * temp = cvCreateImage(cvGetSize(pApplicationPoints), mpIrisCode->depth, 1);
        //		cvGetImage(pApplicationPoints,temp);
        cvSet(temp, cvScalar(0));
        cvXor(temp, pApplicationPoints, temp);

        // Copy the mask f times, where f correspond to the number of codes (= number of filters)
        int n_codes = mpIrisCode->height / pApplicationPoints->height;
        IplImage * appPoints = cvCreateImage(cvGetSize(mpIrisCode), IPL_DEPTH_8U, 1);
        IplImage * total_mask = cvCreateImage(cvGetSize(mpIrisCode), IPL_DEPTH_8U, 1);
        for (int n = 0; n < n_codes; n++)
        {
            cvSetImageROI(total_mask, cvRect(0, n*pApplicationPoints->height, pApplicationPoints->width, pApplicationPoints->height));
            cvSetImageROI(appPoints, cvRect(0, n*pApplicationPoints->height, pApplicationPoints->width, pApplicationPoints->height));

            cvCopy(mpNormalizedMask, total_mask);
            cvCopy(temp, appPoints);

            cvResetImageROI(total_mask);
            cvResetImageROI(appPoints);
        }

        // convert to full binary code.
        binaryCode = convertToBinary(mpIrisCode, binaryCodeLen);
        binaryMask = convertToBinary(total_mask, binaryMaskLen);
        int sn;
        char * binaryAppPoints = convertToBinary(appPoints, sn);
        //output full binary code
        char fullFilename[100];
        sprintf(fullFilename, "code/fullBinaryCode/%s.txt", filename);
        ofstream out(fullFilename, ios::out);
        for (int i = 0; i<binaryCodeLen; i++)
        {
            out << binaryCode[i];
        }
        out << endl;
        for (int i = 0; i<binaryMaskLen; i++)
        {
            out << binaryMask[i];
        }
        out << endl;
        out.close();

        fstream _file("code/fullBinaryCode/appPoints.txt", ios::in);
        if (!_file)
        {
            _file.close();
            out.open("code/fullBinaryCode/appPoints.txt", ios::out);
            for (int i = 0; i<sn; i++)
            {
                out << binaryAppPoints[i];
            }
            out << endl;
            out.close();
        }

        //output miniBinaryCode, decrease code length by recording only useful bits.
        sprintf(fullFilename, "code/binaryCode/%s.txt", filename);
        out.open(fullFilename, ios::out);
        sn = 0;
        //输出关键点上的二进制值（原始图+掩码）
        for (int i = 0; i<binaryCodeLen; i++)
        {
            if (binaryAppPoints[i] == '1')
            {
                out << binaryCode[i];
                sn++;
            }
        }
        out << endl;
        for (int i = 0; i<binaryCodeLen; i++)
        {
            if (binaryAppPoints[i] == '1')
            {
                out << binaryMask[i];
            }
        }
        out << endl;
        out.close();

        //output shifted binary code
        //共21行（从-10ds到10ds）
        sprintf(fullFilename, "code/shiftedBinaryCode/%s.txt", filename);
        out.open(fullFilename, ios::out);
        int ds = mpIrisCode->height;
        int shift = 10 * ds;
        int minv = 1000000000;
        for (int s = -shift; s <= shift; s += ds)
        {
            sn = 0;
            for (int i = 0; i<binaryCodeLen; i++)
            {
                int p = (i + binaryCodeLen + s) % binaryCodeLen;
                if (binaryAppPoints[i] == '1')
                {
                    out << binaryCode[p];
                    sn++;
                }
            }
            out << endl;
        }
        out.close();
        // Free memory
        delete[] binaryCode;
        delete[] binaryMask;
        delete[] binaryAppPoints;
        cvReleaseImage(&temp);
        cvReleaseImage(&total_mask);
    }

    //match using binary code and binary mask.
    float OsiEye::binaryMatch(OsiEye & rEye, const CvMat * pApplicationPoints)
    {
        // Check that both iris codes are built
        if (!mpIrisCode)
        {
            throw runtime_error("Cannot match because iris code 1 is not built (nor computed neither loaded)");
        }
        if (!rEye.mpIrisCode)
        {
            throw runtime_error("Cannot match because iris code 2 is not built (nor computed neither loaded)");
        }

        // Initialize the normalized masks
        // :TODO: must inform the user of this step, for example if user provides masks for all images
        // but one is missing for only one image. However, message must not be spammed if the user
        // did not provide any mask ! So it must be found a way to inform user but without spamming
        if (!mpNormalizedMask)
        {
            mpNormalizedMask = cvCreateImage(cvGetSize(pApplicationPoints), IPL_DEPTH_8U, 1);
            cvSet(mpNormalizedMask, cvScalar(255));
            //cout << "Normalized mask of image 1 is missing for matching. All pixels are initialized to 255" << endl ;
        }
        if (!rEye.mpNormalizedMask)
        {
            rEye.mpNormalizedMask = cvCreateImage(cvGetSize(pApplicationPoints), IPL_DEPTH_8U, 1);
            cvSet(rEye.mpNormalizedMask, cvScalar(255));
            //cout << "Normalized mask of image 2 is missing for matching. All pixels are initialized to 255" << endl ;
        }


        // Build the total mask = mask1 * mask2 * points
        IplImage * temp = cvCreateImage(cvGetSize(pApplicationPoints), mpIrisCode->depth, 1);
        cvSet(temp, cvScalar(0));
        cvAnd(mpNormalizedMask, rEye.mpNormalizedMask, temp, pApplicationPoints);

        // Copy the mask f times, where f correspond to the number of codes (= number of filters)
        int n_codes = mpIrisCode->height / pApplicationPoints->height;
        IplImage * total_mask = cvCreateImage(cvGetSize(mpIrisCode), IPL_DEPTH_8U, 1);
        for (int n = 0; n < n_codes; n++)
        {
            cvSetImageROI(total_mask, cvRect(0, n*pApplicationPoints->height, pApplicationPoints->width, pApplicationPoints->height));
            cvCopy(temp, total_mask);
            cvResetImageROI(total_mask);
        }

        // convert to binary code.
        binaryCode = convertToBinary(mpIrisCode, binaryCodeLen);
        rEye.binaryCode = convertToBinary(rEye.mpIrisCode, rEye.binaryCodeLen);
        int sn;
        char * bmask = convertToBinary(total_mask, sn);

        // Match
        int ds = mpIrisCode->height;
        int shift = 10 * ds;
        int minv = 1000000000;
        float score = 1;
        for (int s = -shift; s <= shift; s += ds)
        {
            int snum = 0;
            int mnum = 0;
            for (int i = 0; i<binaryCodeLen; i++)
            {
                int p = (i + binaryCodeLen + s) % binaryCodeLen;
                bool bm = (bmask[i] == '1');
                snum += (binaryCode[p] != rEye.binaryCode[i]) && bm;
                mnum += bm;
            }
            float dv = 1.0*snum / mnum;
            //			cout<<snum<<"/"<<mnum<<" ";
            if (score > dv)
                score = dv;
        }
        //		cout<<score<<endl;
        delete[] binaryCode;
        delete[] rEye.binaryCode;
        delete[] bmask;
        return score;
    }

    /*
    char * OsiEye:: convertToBinary(IplImage * img,int & sn)
    {
    char * S = new char[2000000];
    sn = 0;
    for(int i = 0;i<img->width;i++)
    {
    for(int j = 0;j<img->height;j++)
    {
    int v = (int)((uchar *)(img->imageData + j*img->widthStep))[i];
    int w = 0;
    if(v == 0)
    {
    w=0;
    }
    else if(v == 255)
    {
    w=1;
    }
    else
    {
    cout<<"res???????"<<endl;
    cin>>w;
    cin>>w;
    }
    for(int k=0;k<8;k++)
    {
    S[sn++]=w+'0';
    }
    }
    }
    return S;
    }*/

    char * OsiEye::convertToBinary(IplImage * img, int & sn)
    {
        char * S = new char[200000];
        sn = 0;
        for (int i = 0; i<img->width; i++)
        {
            for (int j = 0; j<img->height; j++)
            {
                int v = (int)((uchar *)(img->imageData + j*img->widthStep))[i];
                if (v<128)
                {
                    S[sn++] = '0';
                }
                else
                {
                    S[sn++] = '1';
                }
            }
        }
        return S;
    }

    char * OsiEye::impConvert2Binary(IplImage * appPoints, IplImage * img, int & sn)
    {
        char * S = new char[200000];
        sn = 0;
        for (int i = 0; i<img->width; i++)
        {
            for (int j = 0; j<img->height; j++)
            {
                int v = (int)((uchar *)(img->imageData + j*img->widthStep))[i];
                int w = (int)((uchar *)(appPoints->imageData + j*appPoints->widthStep))[i];
                if (w<128) continue;
                if (v < 128)
                {
                    S[sn++] = '0';
                }
                else
                {
                    S[sn++] = '1';
                }
            }
        }
        return S;
    }
} // end of namespace
