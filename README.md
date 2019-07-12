## Introduction
This project is a modification of libdash library of Bitmobin.(https://github.com/bitmovin/libdash). Using this you can download into mat frame from  any MPEG-DASH file (.mpd) from http server.

## Installation Process

### Windows
1. Download the tarball or clone the repository from github (git://github.com/bitmovin/libdash.git)
2. Open the libdash.sln with Visual Studio 2010
3. Build the solution
4. After that all files will be provided in the bin folder
5. You can test the library with the sampleplayer.exe. This application simply downloads the lowest representation of one of our dataset MPDs.

### Ubuntu 12.04
1. sudo apt-get install git-core build-essential cmake libxml2-dev libcurl4-openssl-dev
2. git clone git://github.com/bitmovin/libdash.git
3. cd libdash/libdash
4. mkdir build
5. cd build
6. cmake ../
7. make
8. cd bin
9. The library and a simple test of the network part of the library should be available now. You can test the network part of the library with
10. ./libdash_networkpart_test

#### MpegdeshDownloader
Prerequisite: libdash  must be built as described in the previous section.Also opencv is required.

1. sudo apt-add-repository ppa:ubuntu-sdk-team/ppa
2. sudo apt-get update
3. sudo apt-get install  libav-tools libavcodec-dev libavdevice-dev libavfilter-dev libavformat-dev libavutil-dev libpostproc-dev libswscale-dev
4. cd libdash/libdash/MpegDownloader
5. mkdir build
6. cd build
7. wget http://www.cmake.org/files/v2.8/cmake-2.8.12-Linux-i386.sh
8. chmod a+x cmake-2.8.12-Linux-i386.sh
9. ./cmake-2.8.12-Linux-i386.sh
10. ./cmake-2.8.12-Linux-i386/bin/cmake ../
11. make
12. ./mpegdownloader
13. Opencv will show each frame.


## License

libdash is open source available and licensed under LGPL:

“This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA“

As libdash is licensed under LGPL, changes to the library have to be published again to the open-source project. As many user and companies do not want to publish their specific changes, libdash can be also relicensed to a commercial license on request. Please contact <a href="mailto:sales@bitmovin.com">sales@bitmovin.com</a> to provide you an offer.

## Acknowledgements

We specially want to thank our passionate developers at [Bitmovin](http://www.bitmovin.com) as well as the researchers at the [Institute of Information Technology](http://www-itec.aau.at/dash/) (ITEC) from the Alpen Adria Universitaet Klagenfurt (AAU)!

Furthermore we want to thank the [Netidee](http://www.netidee.at) initiative from the [Internet Foundation Austria](http://www.nic.at/ipa) for partially funding the open source development of libdash.

![netidee logo](http://www.bitmovin.com/files/bitmovin/img/logos/netidee.png "netidee")

## Citation of libdash
We kindly ask you to refer the following paper in any publication mentioning libdash:

Christopher Mueller, Stefan Lederer, Joerg Poecher, and Christian Timmerer, “libdash – An Open Source Software Library for the MPEG-DASH Standard”, in Proceedings of the IEEE International Conference on Multimedia and Expo 2013, San Jose, USA, July, 2013





