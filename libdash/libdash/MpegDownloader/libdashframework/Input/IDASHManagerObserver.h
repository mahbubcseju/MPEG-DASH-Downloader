/*
 * IDASHManagerObserver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_INPUT_IDASHMANAGEROBSERVER_H_
#define LIBDASH_FRAMEWORK_INPUT_IDASHMANAGEROBSERVER_H_

#include <cv.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class IDASHManagerObserver
            {
                public:
                    virtual ~IDASHManagerObserver           () {}

                    virtual void AddFrame       (cv::Mat *frame)                 = 0;
                
                    //virtual void AddSubtitle    ()  = 0;
                    virtual void OnSegmentBufferStateChanged   (uint32_t fillstateInPercent) = 0;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_INPUT_IDASHMANAGEROBSERVER_H_ */
