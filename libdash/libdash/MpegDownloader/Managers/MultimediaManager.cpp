/*
 * MultimediaManager.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MultimediaManager.h"

using namespace libdash::framework::adaptation;
using namespace libdash::framework::buffer;
using namespace sampleplayer::managers;
using namespace dash::mpd;

#define SEGMENTBUFFER_SIZE 2

MultimediaManager::MultimediaManager            ():
                   mpd                          (NULL),
                   period                       (NULL),
                   videoAdaptationSet           (NULL),
                   videoRepresentation          (NULL),
                   videoLogic                   (NULL),
                   videoStream                  (NULL),
                   audioAdaptationSet           (NULL),
                   audioRepresentation          (NULL),
                   audioLogic                   (NULL),
                   audioStream                  (NULL),
                   isStarted                    (false),
                   framesDisplayed              (0),
                   segmentsDownloaded           (0),
                   isVideoRendering             (false),
                   isAudioRendering             (false) 
{
    InitializeCriticalSection (&this->monitorMutex);

    this->manager = CreateDashManager();
    av_register_all();
}
MultimediaManager::~MultimediaManager           ()
{
    this->manager->Delete();
    DeleteCriticalSection (&this->monitorMutex);
}

IMPD*   MultimediaManager::GetMPD                           ()
{
    return this->mpd;
}
bool    MultimediaManager::Init                             (const std::string& url)
{
    EnterCriticalSection(&this->monitorMutex);

    this->mpd = this->manager->Open((char *)url.c_str());

    if(this->mpd == NULL)
    {
       // std::cout<<"I am here at MultimediaManager :: Init"<<std::endl;
        LeaveCriticalSection(&this->monitorMutex);
        return false;
    }
    // std::cout<<"I am here at MultimediaManager :: Init2"<<std::endl;

    LeaveCriticalSection(&this->monitorMutex);
    return true;
}
void    MultimediaManager::Start                            ()
{
  std::cout<<" MultimediaManager::Start 1"<<std::endl;
    EnterCriticalSection(&this->monitorMutex);
      this->videoLogic = AdaptationLogicFactory::Create(libdash::framework::adaptation::Manual, this->mpd, this->period, this->videoAdaptationSet);
     std::cout<<" MultimediaManager::Start 2"<<std::endl;
    this->videoStream = new MultimediaStream(sampleplayer::managers::VIDEO, this->mpd, SEGMENTBUFFER_SIZE, 2, 0);
     std::cout<<" MultimediaManager::Start 3"<<std::endl;
    this->videoStream->AttachStreamObserver(this);
      std::cout<<" MultimediaManager::Start 4"<<std::endl;
     this->videoStream->SetRepresentation(this->period, this->videoAdaptationSet, this->videoRepresentation);
      std::cout<<" MultimediaManager::Start 5"<<std::endl;
     this->videoStream->SetPosition(0);
   std::cout<<" MultimediaManager::Start 6"<<std::endl;
    this->videoStream->Start();
    

    LeaveCriticalSection(&this->monitorMutex);
}

void    MultimediaManager::OnSegmentDownloaded              ()
{
    this->segmentsDownloaded++;
}
void    MultimediaManager::OnSegmentBufferStateChanged    (StreamType type, uint32_t fillstateInPercent)
{
    switch (type)
    {
        case AUDIO:
            this->NotifyAudioSegmentBufferObservers(fillstateInPercent);
            break;
        case VIDEO:
            this->NotifyVideoSegmentBufferObservers(fillstateInPercent);
            break;
        default:
            break;
    }
}
void    MultimediaManager::OnVideoBufferStateChanged      (uint32_t fillstateInPercent)
{
    this->NotifyVideoBufferObservers(fillstateInPercent);
}
void    MultimediaManager::OnAudioBufferStateChanged      (uint32_t fillstateInPercent)
{
    this->NotifyAudioBufferObservers(fillstateInPercent);
}
void    MultimediaManager::NotifyVideoBufferObservers       (uint32_t fillstateInPercent)
{
    for (size_t i = 0; i < this->managerObservers.size(); i++)
        this->managerObservers.at(i)->OnVideoBufferStateChanged(fillstateInPercent);
}
void    MultimediaManager::NotifyVideoSegmentBufferObservers(uint32_t fillstateInPercent)
{
    for (size_t i = 0; i < this->managerObservers.size(); i++)
        this->managerObservers.at(i)->OnVideoSegmentBufferStateChanged(fillstateInPercent);
}
void    MultimediaManager::NotifyAudioSegmentBufferObservers(uint32_t fillstateInPercent)
{
    for (size_t i = 0; i < this->managerObservers.size(); i++)
        this->managerObservers.at(i)->OnAudioSegmentBufferStateChanged(fillstateInPercent);
}
void    MultimediaManager::NotifyAudioBufferObservers       (uint32_t fillstateInPercent)
{
    for (size_t i = 0; i < this->managerObservers.size(); i++)
        this->managerObservers.at(i)->OnAudioBufferStateChanged(fillstateInPercent);
}