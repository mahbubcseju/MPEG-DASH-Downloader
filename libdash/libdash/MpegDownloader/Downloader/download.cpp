#include "download.h"
#include<iostream>
#include "../libdashframework/MPD/AdaptationSetHelper.h"

using namespace libdash::framework::mpd;
using namespace dash::mpd;

using namespace com::anyconnect::mpegloader;
//using namespace sampleplayer::managers;
using namespace libdash::framework::adaptation;
MpegDownloader::MpegDownloader()
{
	this->mpd=NULL;
	this->MultimediaManager = new sampleplayer::managers::MultimediaManager();
}
void MpegDownloader::init(std::string url)
{
           this->MultimediaManager->Init(url);
           this->mpd=this->MultimediaManager->GetMPD();
           this->MultimediaManager->period=this->mpd->GetPeriods().at(0);
           this->MultimediaManager->videoAdaptationSet=AdaptationSetHelper::GetVideoAdaptationSets(this->MultimediaManager->period).at(0);
           this->MultimediaManager->videoRepresentation= this->MultimediaManager->videoAdaptationSet->GetRepresentation().at(0);
            this->MultimediaManager->frameRate=24;
           std::cout<<(this->mpd)<<std::endl;
}
void MpegDownloader::startdownload()
{
       this->MultimediaManager->Start();

}
