#include<iostream>
#include "Downloader/download.h"

using namespace com::mahbubcseju::mpegloader;


int main()
{
     MpegDownloader *frame=new MpegDownloader();
     frame->init("http://www-itec.uni-klu.ac.at/ftp/datasets/DASHDataset2014/ElephantsDream/1sec/ElephantsDream_1s_onDemand_2014_05_09.mpd");
	std::cout<<"lol"<<std::endl;
	frame->startdownload();
	return 0;

}