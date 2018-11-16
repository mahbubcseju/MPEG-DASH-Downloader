#ifndef DOWNLOAD_H_
#define DOWNLOAD_H_

#include "../Buffer/MediaObjectBuffer.h"
#include "DASHReceiver.h"
#include "../../Decoder/IVideoObserver.h"
#include "IDASHReceiverObserver.h"
#include "IMediaObjectDecoderObserver.h"
#include "MediaObjectDecoder.h"
#include "libdash.h"
#include "IMPD.h"
//#include <QtMultimedia/qaudioformat.h>
#include "IDASHManagerObserver.h"
#include "../Buffer/IMediaObjectBufferObserver.h"

#include<iostream>
#include<sstream>
#include "../Managers/MultimediaManager.h"

namespace com{
	namespace mahbubcseju{
		namespace mpegloader{
			class MpegDownloader{
			public:
			 MpegDownloader();
			 void init(std:: string url);
			 void startdownload();
			private:

				dash::mpd::IMPD *mpd;
				sampleplayer::managers::MultimediaManager *MultimediaManager;
			};
		}
	}
}

#endif