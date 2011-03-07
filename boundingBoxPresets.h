#ifndef BOUNDINGBOXPRESETS_H
#define BOUNDINGBOXPRESETS_H

#include "duplicateip.h"

boundingBox DuplicateIp::loadBox(VImage* vim) {
    boundingBox 
      fgBox(point(-1,-1),point(-1,-1));

/*
    if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9767.jpg") == 0) 
      
      fgBox = boundingBox(point(156,104),point(407,306));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9770.jpg") == 0) 
      
      fgBox = boundingBox(point(215,144),point(473,331));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9771.jpg") == 0) 
      
      fgBox = boundingBox(point(126,84),point(415,251));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9776.jpg") == 0) 
      fgBox = boundingBox(point(96,64),point(569,166));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9779.jpg") == 0) 
      fgBox = boundingBox(point(66,44),point(429,177));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9782.jpg") == 0) 
      fgBox = boundingBox(point(6,4),point(264,191));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9783.jpg") == 0) 
      fgBox = boundingBox(point(36,24),point(294,211));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0031.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(430,500));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0034.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(491,408));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0035.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(551,583));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0037.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(499,567));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0039.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(541,530));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0046.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(636,562));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0048.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(474,341));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0049.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(814,144));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0055.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(596,456));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0056.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(380,456));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0059.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(736,554));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0060.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(757,524));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0062.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(691,294));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0064.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(900,403));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0067.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(899,360));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0069.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(361,392));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0072.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(881,365));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0073.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(552,497));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0074.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(822,433));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0075.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(622,376));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0076.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(778,402));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0077.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(727,376));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0078.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(707,385));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0079.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(531,383));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0080.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(412,345));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0082.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(704,245));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0083.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(688,295));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0084.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(668,418));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0085.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(691,393));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0086.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(540,517));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0087.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(652,421));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0090.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(596,396));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0091.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(555,494));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0093.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(595,535));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0094.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(539,219));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0096.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(486,247));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0097.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(700,389));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0098.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(506,554));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0099.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(659,215));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0100.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(489,411));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0101.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(731,374));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0102.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(755,364));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0103.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(392,468));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0104.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(611,512));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0105.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(621,503));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0106.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(651,476));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0107.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(525,528));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0109.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(549,504));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0110.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(544,315));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0111.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(310,366));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0114.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(333,539));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0115.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(326,543));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0116.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(327,547));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0117.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(668,352));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0119.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(596,456));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0120.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(488,587));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0121.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(408,580));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0122.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(437,586));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0126.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(491,594));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0127.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(318,358));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0128.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(442,485));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0130.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(597,526));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0131.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(455,533));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0137.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(822,177));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0139.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(559,251));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0140.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(832,176));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0142.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(887,166));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0143.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(713,295));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0146.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(809,346));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0147.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(384,554));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0148.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(723,382));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0150.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(284,510));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0151.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(263,566));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0152.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(283,509));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0153.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(440,558));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0155.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(399,521));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0156.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(390,558));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0157.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(824,387));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0158.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(562,432));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0159.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(530,444));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0160.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(394,563));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0162.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(290,495));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0163.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(595,397));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0166.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(837,478));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0167.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(419,490));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0173.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(620,506));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0174.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(640,485));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0175.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(310,483));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0176.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(890,453));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0177.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(849,524));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0178.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(632,451));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0179.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(600,523));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0180.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(693,510));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0181.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(577,506));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0182.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(545,510));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0183.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(493,501));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0184.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(591,532));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0185.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(411,504));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0186.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(468,514));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0187.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(417,493));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0188.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(419,496));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0189.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(353,496));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0190.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(292,493));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0191.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(332,426));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0192.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(355,509));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0193.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(301,505));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0196.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(427,581));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0197.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(451,251));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0198.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(389,538));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0199.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(354,397));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0200.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(266,428));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0201.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(341,556));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0202.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(339,341));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0205.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(241,476));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0209.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(808,529));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0214.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(900,164));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0216.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(875,131));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0218.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0219.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0220.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(696,506));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0221.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(871,516));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0223.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(577,549));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0224.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(677,522));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0225.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(891,129));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0226.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(669,530));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0227.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(784,508));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0228.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(796,505));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0229.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(542,597));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0231.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(754,154));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0232.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(559,203));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0233.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(706,163));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0234.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(668,181));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0235.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(682,167));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0236.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(900,498));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0237.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(729,558));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0238.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(774,541));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0239.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(814,494));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0240.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(771,587));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0241.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(582,199));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0243.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(673,172));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0251.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(788,145));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0252.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(901,239));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0253.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(895,361));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0254.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(455,411));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0255.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(470,430));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0259.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(344,511));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0261.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(442,554));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0262.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(260,564));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0263.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(432,421));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0264.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(525,382));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0265.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(388,441));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0267.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(484,493));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0268.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(806,261));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0269.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(786,356));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0270.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(838,141));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0277.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(855,296));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0278.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(857,304));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0279.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(766,422));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0280.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(705,501));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0281.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(705,504));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0283.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(893,501));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0285.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(671,406));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0002.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(686,166));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0004.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(609,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0005.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(825,180));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0009.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(643,422));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0010.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(752,192));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0012.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(898,330));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0015.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(890,407));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0017.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(879,512));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0029.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(671,527));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0031.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(550,257));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0033.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(457,248));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0034.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(900,403));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0035.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(900,449));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0036.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(900,360));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0037.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(897,456));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0039.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(606,599));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0041.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(900,449));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0042.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(432,262));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0043.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(499,587));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0046.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(776,366));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0047.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(729,328));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0050.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(893,206));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0051.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(612,281));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0053.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(408,358));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0055.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(406,421));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0057.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(622,592));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0058.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(463,301));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0061.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(655,473));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0066.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(898,129));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0070.JPG") == 0) 
      fgBox = boundingBox(point(460,306),point(834,596));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0074.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(658,412));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0075.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,174));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0076.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(900,376));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0078.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(899,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0080.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(851,425));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0081.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(895,366));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0082.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(625,498));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0084.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(650,310));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0089.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(829,338));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0092.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(615,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0093.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(418,599));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0094.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(545,592));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0095.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(673,461));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0099.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(607,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0100.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(365,586));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0101.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(655,596));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0103.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(675,599));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0106.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(873,207));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0111.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(627,581));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0112.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(841,519));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0113.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(894,132));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0115.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(821,541));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0126.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(814,436));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0129.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(756,319));

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0137.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(669,475));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0138.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(546,433));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0141.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(830,254));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0142.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(841,294));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0145.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(855,373));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0147.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(625,517));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0148.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(900,449));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0152.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(780,324));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0153.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(875,168));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0156.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(689,394));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0001.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(899,360));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0002.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(815,387));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0003.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(899,382));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0004.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(779,357));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0005.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(671,408));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0006.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(892,280));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0007.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(862,287));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0008.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(882,409));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0009.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(430,307));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0010.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(596,392));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0011.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(585,290));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0012.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(892,280));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0013.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(549,255));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0014.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(901,201));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0015.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(891,166));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0016.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(682,168));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0017.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(654,217));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0018.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(587,398));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0019.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(855,134));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0020.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(875,131));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0021.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(898,284));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0022.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(671,170));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0023.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0024.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(875,135));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0025.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(847,173));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0026.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(900,164));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0027.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(887,166));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0028.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(823,486));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0029.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(855,468));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0030.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(898,451));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0031.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(687,514));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0032.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0033.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(875,131));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0034.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(899,204));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0035.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(888,183));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0036.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(779,188));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0037.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(900,212));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0038.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(862,133));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0039.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(874,206));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0040.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(900,164));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0041.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(887,166));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0042.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(649,218));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0043.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(901,201));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0044.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(897,240));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0045.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(883,282));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0046.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(456,308));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0047.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(870,290));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0048.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(597,335));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0049.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(768,313));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0050.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(897,279));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0051.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(895,320));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0052.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(899,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0053.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(742,474));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0054.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0055.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(539,511));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0056.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(655,261));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0057.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(848,347));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0058.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(657,361));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0059.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(631,571));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0060.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0061.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(825,216));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0062.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(901,239));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0063.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(893,212));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0064.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(891,241));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0065.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(761,587));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0066.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(725,485));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0067.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(780,573));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0068.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(807,500));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0069.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(806,508));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0070.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(787,504));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0071.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(721,553));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0072.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(708,578));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0073.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(840,530));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0074.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(765,519));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0075.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(680,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0076.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(820,545));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0077.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(829,536));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0078.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(851,523));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0079.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(611,529));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0080.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(698,574));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0081.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(708,593));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0082.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(640,566));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0083.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(821,543));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0084.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(684,591));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0085.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(695,586));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0086.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(685,588));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0087.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(751,597));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0088.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(804,494));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0089.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(717,565));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0090.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(677,597));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0091.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(866,535));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0092.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(806,553));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0093.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(775,543));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0094.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(639,559));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0095.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(686,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0096.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(741,477));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0097.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(760,589));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0098.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(772,582));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0099.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(751,552));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0100.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(750,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0101.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(672,479));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0102.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(709,499));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0103.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(743,423));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0104.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(772,526));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0105.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(801,497));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0106.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(830,481));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0107.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(752,531));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0108.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(869,418));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0109.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(895,202));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0110.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(894,165));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0111.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(892,452));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0112.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(806,441));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0113.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(406,596));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0114.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(705,504));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0115.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(728,427));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0116.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(739,421));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0117.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(712,389));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0118.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(611,596));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0119.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(687,588));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0120.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(681,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0121.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(822,140));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0122.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(874,511));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0123.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(893,129));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0124.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(542,597));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0125.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0126.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(860,134));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0127.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(535,528));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0128.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(867,207));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0129.JPG") == 0) 
      fgBox = boundingBox(point(460,306),point(831,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0130.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(193,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0131.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(222,519));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0132.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(796,266));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0133.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(756,273));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0134.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(878,412));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0135.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(878,523));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0136.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(706,573));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0137.JPG") == 0) 
      fgBox = boundingBox(point(460,306),point(858,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0138.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(759,589));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0139.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(718,433));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0140.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(733,433));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0141.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(688,169));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0142.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(899,130));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0143.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(532,446));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0144.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(716,392));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0145.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(687,398));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0146.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(638,424));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0147.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(643,421));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0148.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(577,405));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0149.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(659,470));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0150.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(621,436));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0151.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(636,375));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0152.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(654,419));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0153.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(574,419));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0154.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(630,419));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0155.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(580,404));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0156.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(549,437));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0157.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(612,444));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0158.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(610,444));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0159.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(651,476));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0160.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(700,504));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0161.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(701,442));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0162.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(810,344));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0163.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(889,407));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0164.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(869,488));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0165.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(554,424));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0166.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(871,413));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0167.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(600,395));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0168.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(549,446));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0169.JPG") == 0) 
      fgBox = boundingBox(point(460,306),point(856,594));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0170.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(757,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0171.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(866,246));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0172.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(885,210));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0173.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(762,521));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0174.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(887,458));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0175.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(587,402));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0176.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(230,496));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0177.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(856,520));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0178.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(871,515));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0179.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(328,383));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0180.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(506,554));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0181.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(502,578));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0183.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(574,476));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0184.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(592,537));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0185.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(581,468));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0186.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(580,470));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0187.JPG") == 0) 
      fgBox = boundingBox(point(460,306),point(885,561));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0188.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(448,459));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0189.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(467,432));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0190.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(456,443));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0191.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(479,421));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0192.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(543,432));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0193.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(244,467));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0194.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(450,379));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0195.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(731,156));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0196.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(712,160));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0197.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(545,208));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0198.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(850,172));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0199.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(850,172));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0200.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(576,197));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0201.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(674,169));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0202.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(351,341));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0203.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(354,343));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0204.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(834,394));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0205.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(714,440));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0206.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(858,376));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0207.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(802,347));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0208.JPG") == 0) 
      fgBox = boundingBox(point(234,156),point(868,327));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0209.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(892,280));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0210.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(884,284));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0211.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(290,392));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0212.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(527,319));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0213.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(484,234));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0214.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(643,556));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0215.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(602,522));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0216.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(657,541));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0217.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(678,521));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0218.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(897,404));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0219.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(900,403));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0220.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(868,414));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0221.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(574,380));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0222.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(214,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0223.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(272,418));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0224.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(887,170));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0225.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(875,131));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0226.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(547,310));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0227.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(215,557));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0228.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(750,474));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0229.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(860,523));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0230.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(872,517));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0231.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(468,514));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0232.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(284,400));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0233.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(241,474));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0234.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(862,296));

    else if(strcmp(vim->getFilename(), "/media/94F8A417F8A3F620/Documents and Settings/Artoonie/I/results/data/zoo_imagesorter/DSC_0086.jpg") == 0) 
      fgBox = boundingBox(point(6,4),point(135,380));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9769.jpg") == 0) 
      fgBox = boundingBox(point(156,104),point(407,306));

    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9784.jpg") == 0) 
      fgBox = boundingBox(point(120,80),point(480,321));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9785.jpg") == 0) 
      fgBox = boundingBox(point(156,104),point(402,323));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9786.jpg") == 0) 
      fgBox = boundingBox(point(185,124),point(443,311));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9787.jpg") == 0) 
      fgBox = boundingBox(point(185,124),point(443,311));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9788.jpg") == 0) 
      fgBox = boundingBox(point(126,84),point(384,271));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9789.jpg") == 0) 
      fgBox = boundingBox(point(185,124),point(372,382));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9794.jpg") == 0) 
      fgBox = boundingBox(point(6,4),point(253,200));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9795.jpg") == 0) 
      fgBox = boundingBox(point(6,4),point(152,389));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9796.jpg") == 0) 
      fgBox = boundingBox(point(6,4),point(193,262));
    else if(strcmp(vim->getFilename(), "/home/artoonie/Documents/School/2010-2011/ImageSorter/testimages/compare2/DSC_9797.jpg") == 0) 
      fgBox = boundingBox(point(245,164),point(552,323));

    // Ke
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/46_57854854_2f6dcdf3a1_b.jpg") == 0) 
      fgBox = boundingBox(point(215,143),point(701,430));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/47_rose-2.jpg") == 0) 
      fgBox = boundingBox(point(176,132),point(1362,473));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/48_44661953_96ccc6caf5_o.jpg") == 0) 
      fgBox = boundingBox(point(190,148),point(596,294));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/49_Roseblanchelisererose800.jpg") == 0) 
      fgBox = boundingBox(point(128,96),point(583,307));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/51_pickingapple044.jpg") == 0) 
      fgBox = boundingBox(point(8,6),point(453,222));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/52_AppleEgremontRusset.jpg") == 0) 
      fgBox = boundingBox(point(97,66),point(374,508));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/53_Apple6.jpg") == 0) 
      fgBox = boundingBox(point(362,236),point(1722,522));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/54_CodlingMothBite7K.jpg") == 0) 
      fgBox = boundingBox(point(295,247),point(714,517));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/58_00.07.eli.violin.jpg") == 0) 
      fgBox = boundingBox(point(545,359),point(1581,754));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/59_3530244_a6924d938c_b.jpg") == 0) 
      fgBox = boundingBox(point(163,122),point(587,493));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/60_VictoriaPlayingViolin.jpg") == 0) 
      fgBox = boundingBox(point(575,431),point(1597,812));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/61_playingviolinedited.jpg") == 0) 
      fgBox = boundingBox(point(199,266),point(450,894));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/62_01-ILikeThisBMW.jpg") == 0) 
      fgBox = boundingBox(point(8,6),point(759,153));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/63_3-bmw318i-991.jpg") == 0) 
      fgBox = boundingBox(point(53,34),point(570,233));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/64_BMWC1.jpg") == 0) 
      fgBox = boundingBox(point(266,199),point(647,657));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/65_9744484_90e44a2890_o.jpg") == 0) 
      fgBox = boundingBox(point(30,23),point(401,129));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/65_Statue of Liberty BZs.jpg") == 0) 
      fgBox = boundingBox(point(201,268),point(604,879));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/66_statue-of-liberty 12.jpg") == 0) 
      fgBox = boundingBox(point(116,101),point(257,281));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/67_1333234_7510a7b757_o.jpg") == 0) 
      fgBox = boundingBox(point(132,198),point(310,505));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/67_Statue of Liberty (1).jpg") == 0) 
      fgBox = boundingBox(point(61,46),point(555,368));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/68_DSC04343-cow.jpg") == 0) 
      fgBox = boundingBox(point(287,215),point(540,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/68_statue-of-liberty 2.jpg") == 0) 
      fgBox = boundingBox(point(416,312),point(1337,729));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/69_36370488_c5e200c8f6_o.jpg") == 0) 
      fgBox = boundingBox(point(4,6),point(448,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/70_CowMoose.jpg") == 0) 
      fgBox = boundingBox(point(8,5),point(567,183));

    else if(strcmp(vim->getFilename(), "/media/94F8A417F8A3F620/Documents and Settings/Artoonie/I/results/data/zoo_imagesorter/DSC_0081.jpg") == 0) 
      fgBox = boundingBox(point(126,84),point(376,277));
    else if(strcmp(vim->getFilename(), "/media/94F8A417F8A3F620/Documents and Settings/Artoonie/I/results/data/zoo_imagesorter/DSC_0082.jpg") == 0) 
      fgBox = boundingBox(point(126,84),point(356,294));
    else if(strcmp(vim->getFilename(), "/media/94F8A417F8A3F620/Documents and Settings/Artoonie/I/results/data/zoo_imagesorter/DSC_0083.jpg") == 0) 
      fgBox = boundingBox(point(275,184),point(525,377));
    else if(strcmp(vim->getFilename(), "/media/94F8A417F8A3F620/Documents and Settings/Artoonie/I/results/data/zoo_imagesorter/DSC_0084.jpg") == 0) 
      fgBox = boundingBox(point(245,164),point(452,399));
    else if(strcmp(vim->getFilename(), "/media/94F8A417F8A3F620/Documents and Settings/Artoonie/I/results/data/zoo_imagesorter/DSC_0085.jpg") == 0) 
      fgBox = boundingBox(point(36,24),point(276,226));
    else if(strcmp(vim->getFilename(), "/media/94F8A417F8A3F620/Documents and Settings/Artoonie/I/results/data/zoo_imagesorter/DSC_0087.jpg") == 0) 
      fgBox = boundingBox(point(96,64),point(398,224));
    else if(strcmp(vim->getFilename(), "/media/94F8A417F8A3F620/Documents and Settings/Artoonie/I/results/data/zoo_imagesorter/DSC_0088.jpg") == 0) 
      fgBox = boundingBox(point(126,84),point(280,398));

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/mug/DSC_0543.JPG") == 0) 
      fgBox = boundingBox(point(182,120),point(441,372));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/mug/DSC_0544.JPG") == 0) 
      fgBox = boundingBox(point(216,144),point(509,388));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/mug/DSC_0545.JPG") == 0) 
      fgBox = boundingBox(point(182,120),point(429,385));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/mug/DSC_0546.JPG") == 0) 
      fgBox = boundingBox(point(147,97),point(348,421));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/mug/DSC_0547.JPG") == 0) 
      fgBox = boundingBox(point(112,74),point(510,317));
*/

    // Begin new bounding boxes with x!=y (starting point not always diagonally across)
    if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/zoo_imagesorter/DSC_0082.jpg") == 0) 
      fgBox = boundingBox(point(215,24),point(408,274));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/zoo_imagesorter/DSC_0083.jpg") == 0) 
      fgBox = boundingBox(point(306,124),point(493,382));

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0001.JPG") == 0) 
      fgBox = boundingBox(point(54,215),point(883,347));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0002.JPG") == 0) 
      fgBox = boundingBox(point(9,245),point(813,382));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0003.JPG") == 0) 
      fgBox = boundingBox(point(9,185),point(899,310));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0004.JPG") == 0) 
      fgBox = boundingBox(point(234,185),point(868,357));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0005.JPG") == 0) 
      fgBox = boundingBox(point(234,245),point(899,408));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0006.JPG") == 0) 
      fgBox = boundingBox(point(234,96),point(813,283));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0007.JPG") == 0) 
      fgBox = boundingBox(point(234,126),point(889,292));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0008.JPG") == 0) 
      fgBox = boundingBox(point(324,96),point(574,529));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0009.JPG") == 0) 
      fgBox = boundingBox(point(9,156),point(457,398));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0010.JPG") == 0) 
      fgBox = boundingBox(point(54,185),point(598,384));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0011.JPG") == 0) 
      fgBox = boundingBox(point(144,66),point(596,308));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0012.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(880,280));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0013.JPG") == 0) 
      fgBox = boundingBox(point(9,126),point(808,267));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0014.JPG") == 0) 
      fgBox = boundingBox(point(9,66),point(899,193));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0015.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(891,166));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0016.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(682,168));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0017.JPG") == 0) 
      fgBox = boundingBox(point(9,36),point(650,206));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0018.JPG") == 0) 
      fgBox = boundingBox(point(144,126),point(560,388));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0019.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(855,134));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0020.JPG") == 0) 
      fgBox = boundingBox(point(9,36),point(897,158));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0021.JPG") == 0) 
      fgBox = boundingBox(point(54,156),point(900,284));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0022.JPG") == 0) 
      fgBox = boundingBox(point(9,36),point(892,160));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0023.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0024.JPG") == 0) 
      fgBox = boundingBox(point(144,6),point(896,150));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0025.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(847,173));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0026.JPG") == 0) 
      fgBox = boundingBox(point(9,36),point(900,158));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0027.JPG") == 0) 
      fgBox = boundingBox(point(9,36),point(897,158));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0028.JPG") == 0) 
      fgBox = boundingBox(point(414,215),point(826,478));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0029.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(855,468));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0030.JPG") == 0) 
      fgBox = boundingBox(point(505,245),point(898,522));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0031.JPG") == 0) 
      fgBox = boundingBox(point(324,185),point(670,514));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0032.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0033.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(875,131));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0034.JPG") == 0) 
      fgBox = boundingBox(point(9,96),point(899,218));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0035.JPG") == 0) 
      fgBox = boundingBox(point(9,66),point(897,188));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0036.JPG") == 0) 
      fgBox = boundingBox(point(9,66),point(897,188));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0037.JPG") == 0) 
      fgBox = boundingBox(point(9,96),point(900,218));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0038.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(862,133));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0039.JPG") == 0) 
      fgBox = boundingBox(point(9,96),point(875,221));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0040.JPG") == 0) 
      fgBox = boundingBox(point(9,36),point(891,161));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0041.JPG") == 0) 
      fgBox = boundingBox(point(9,36),point(885,160));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0042.JPG") == 0) 
      fgBox = boundingBox(point(99,36),point(681,222));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0043.JPG") == 0) 
      fgBox = boundingBox(point(54,66),point(896,195));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0044.JPG") == 0) 
      fgBox = boundingBox(point(54,96),point(835,237));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0045.JPG") == 0) 
      fgBox = boundingBox(point(9,156),point(882,280));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0046.JPG") == 0) 
      fgBox = boundingBox(point(9,185),point(900,308));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0047.JPG") == 0) 
      fgBox = boundingBox(point(99,156),point(895,292));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0048.JPG") == 0) 
      fgBox = boundingBox(point(9,215),point(845,345));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0049.JPG") == 0) 
      fgBox = boundingBox(point(9,185),point(855,313));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0050.JPG") == 0) 
      fgBox = boundingBox(point(9,156),point(894,279));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0051.JPG") == 0) 
      fgBox = boundingBox(point(9,156),point(805,292));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0052.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(899,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0053.JPG") == 0) 
      fgBox = boundingBox(point(324,185),point(722,457));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0054.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0055.JPG") == 0) 
      fgBox = boundingBox(point(9,215),point(614,394));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0056.JPG") == 0) 
      fgBox = boundingBox(point(99,96),point(660,290));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0057.JPG") == 0) 
      fgBox = boundingBox(point(414,126),point(849,375));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0058.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(657,361));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0059.JPG") == 0) 
      fgBox = boundingBox(point(369,36),point(573,567));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0060.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0061.JPG") == 0) 
      fgBox = boundingBox(point(144,66),point(867,216));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0062.JPG") == 0) 
      fgBox = boundingBox(point(9,96),point(893,219));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0063.JPG") == 0) 
      fgBox = boundingBox(point(9,96),point(897,218));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0064.JPG") == 0) 
      fgBox = boundingBox(point(9,126),point(897,248));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0065.JPG") == 0) 
      fgBox = boundingBox(point(460,126),point(805,440));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0066.JPG") == 0) 
      fgBox = boundingBox(point(414,156),point(747,482));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0067.JPG") == 0) 
      fgBox = boundingBox(point(414,245),point(780,542));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0068.JPG") == 0) 
      fgBox = boundingBox(point(460,185),point(812,500));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0069.JPG") == 0) 
      fgBox = boundingBox(point(414,245),point(818,514));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0070.JPG") == 0) 
      fgBox = boundingBox(point(460,96),point(748,474));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0071.JPG") == 0) 
      fgBox = boundingBox(point(414,66),point(683,471));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0072.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(708,578));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0073.JPG") == 0) 
      fgBox = boundingBox(point(369,275),point(819,525));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0074.JPG") == 0) 
      fgBox = boundingBox(point(414,185),point(777,486));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0075.JPG") == 0) 
      fgBox = boundingBox(point(144,306),point(736,489));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0076.JPG") == 0) 
      fgBox = boundingBox(point(189,366),point(790,547));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0077.JPG") == 0) 
      fgBox = boundingBox(point(9,426),point(747,573));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0078.JPG") == 0) 
      fgBox = boundingBox(point(9,396),point(710,551));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0079.JPG") == 0) 
      fgBox = boundingBox(point(9,396),point(803,535));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0080.JPG") == 0) 
      fgBox = boundingBox(point(9,366),point(708,521));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0081.JPG") == 0) 
      fgBox = boundingBox(point(414,215),point(708,593));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0082.JPG") == 0) 
      fgBox = boundingBox(point(54,396),point(638,591));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0083.JPG") == 0) 
      fgBox = boundingBox(point(54,366),point(673,543));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0084.JPG") == 0) 
      fgBox = boundingBox(point(54,366),point(542,596));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0085.JPG") == 0) 
      fgBox = boundingBox(point(189,366),point(694,586));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0086.JPG") == 0) 
      fgBox = boundingBox(point(369,215),point(685,558));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0087.JPG") == 0) 
      fgBox = boundingBox(point(144,396),point(741,578));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0088.JPG") == 0) 
      fgBox = boundingBox(point(550,96),point(803,545));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0089.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(607,562));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0090.JPG") == 0) 
      fgBox = boundingBox(point(279,336),point(694,597));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0091.JPG") == 0) 
      fgBox = boundingBox(point(460,156),point(748,532));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0092.JPG") == 0) 
      fgBox = boundingBox(point(460,66),point(699,519));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0093.JPG") == 0) 
      fgBox = boundingBox(point(99,396),point(760,561));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0094.JPG") == 0) 
      fgBox = boundingBox(point(369,185),point(639,596));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0095.JPG") == 0) 
      fgBox = boundingBox(point(505,66),point(710,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0096.JPG") == 0) 
      fgBox = boundingBox(point(414,185),point(741,518));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0097.JPG") == 0) 
      fgBox = boundingBox(point(414,96),point(632,593));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0098.JPG") == 0) 
      fgBox = boundingBox(point(414,156),point(714,520));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0099.JPG") == 0) 
      fgBox = boundingBox(point(414,245),point(754,564));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0100.JPG") == 0) 
      fgBox = boundingBox(point(505,66),point(733,547));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0101.JPG") == 0) 
      fgBox = boundingBox(point(369,126),point(674,481));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0102.JPG") == 0) 
      fgBox = boundingBox(point(279,215),point(691,478));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0103.JPG") == 0) 
      fgBox = boundingBox(point(9,306),point(598,492));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0104.JPG") == 0) 
      fgBox = boundingBox(point(279,275),point(728,519));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0105.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(801,497));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0106.JPG") == 0) 
      fgBox = boundingBox(point(369,245),point(830,481));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0107.JPG") == 0) 
      fgBox = boundingBox(point(460,156),point(752,543));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0108.JPG") == 0) 
      fgBox = boundingBox(point(279,245),point(855,433));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0109.JPG") == 0) 
      fgBox = boundingBox(point(189,336),point(688,554));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0110.JPG") == 0) 
      fgBox = boundingBox(point(414,66),point(684,467));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0111.JPG") == 0) 
      fgBox = boundingBox(point(460,156),point(836,444));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0112.JPG") == 0) 
      fgBox = boundingBox(point(99,306),point(471,597));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0113.JPG") == 0) 
      fgBox = boundingBox(point(99,306),point(473,596));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0114.JPG") == 0) 
      fgBox = boundingBox(point(144,306),point(704,504));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0115.JPG") == 0) 
      fgBox = boundingBox(point(144,275),point(484,594));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0116.JPG") == 0) 
      fgBox = boundingBox(point(460,6),point(739,394));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0117.JPG") == 0) 
      fgBox = boundingBox(point(234,275),point(577,593));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0118.JPG") == 0) 
      fgBox = boundingBox(point(99,275),point(516,537));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0119.JPG") == 0) 
      fgBox = boundingBox(point(234,275),point(589,588));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0120.JPG") == 0) 
      fgBox = boundingBox(point(144,306),point(520,594));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0121.JPG") == 0) 
      fgBox = boundingBox(point(189,275),point(529,594));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0122.JPG") == 0) 
      fgBox = boundingBox(point(54,336),point(811,479));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0123.JPG") == 0) 
      fgBox = boundingBox(point(189,275),point(535,588));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0124.JPG") == 0) 
      fgBox = boundingBox(point(460,6),point(777,353));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0125.JPG") == 0) 
      fgBox = boundingBox(point(234,275),point(601,570));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0126.JPG") == 0) 
      fgBox = boundingBox(point(189,275),point(533,590));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0127.JPG") == 0) 
      fgBox = boundingBox(point(234,275),point(601,574));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0128.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(867,207));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0129.JPG") == 0) 
      fgBox = boundingBox(point(279,396),point(848,587));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0130.JPG") == 0) 
      fgBox = boundingBox(point(9,456),point(772,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0131.JPG") == 0) 
      fgBox = boundingBox(point(9,396),point(630,571));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0132.JPG") == 0) 
      fgBox = boundingBox(point(144,36),point(796,206));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0133.JPG") == 0) 
      fgBox = boundingBox(point(54,126),point(740,286));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0134.JPG") == 0) 
      fgBox = boundingBox(point(9,306),point(390,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0135.JPG") == 0) 
      fgBox = boundingBox(point(685,6),point(878,579));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0136.JPG") == 0) 
      fgBox = boundingBox(point(369,336),point(781,599));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0137.JPG") == 0) 
      fgBox = boundingBox(point(460,336),point(872,599));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0138.JPG") == 0) 
      fgBox = boundingBox(point(324,306),point(758,558));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0139.JPG") == 0) 
      fgBox = boundingBox(point(505,156),point(755,589));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0140.JPG") == 0) 
      fgBox = boundingBox(point(460,185),point(771,535));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0141.JPG") == 0) 
      fgBox = boundingBox(point(324,6),point(588,429));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0142.JPG") == 0) 
      fgBox = boundingBox(point(144,215),point(545,485));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0143.JPG") == 0) 
      fgBox = boundingBox(point(99,185),point(521,446));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0144.JPG") == 0) 
      fgBox = boundingBox(point(460,6),point(716,431));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0145.JPG") == 0) 
      fgBox = boundingBox(point(414,6),point(687,404));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0146.JPG") == 0) 
      fgBox = boundingBox(point(414,6),point(653,461));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0147.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(657,442));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0148.JPG") == 0) 
      fgBox = boundingBox(point(460,6),point(829,300));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0149.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(644,464));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0150.JPG") == 0) 
      fgBox = boundingBox(point(279,96),point(601,436));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0151.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(644,460));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0152.JPG") == 0) 
      fgBox = boundingBox(point(324,96),point(658,421));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0153.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(660,440));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0154.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(648,454));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0155.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(652,451));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0156.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(635,473));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0157.JPG") == 0) 
      fgBox = boundingBox(point(369,96),point(651,480));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0158.JPG") == 0) 
      fgBox = boundingBox(point(324,66),point(612,442));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0159.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(651,450));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0160.JPG") == 0) 
      fgBox = boundingBox(point(369,66),point(601,538));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0161.JPG") == 0) 
      fgBox = boundingBox(point(414,66),point(711,431));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0162.JPG") == 0) 
      fgBox = boundingBox(point(460,36),point(812,344));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0163.JPG") == 0) 
      fgBox = boundingBox(point(279,215),point(878,398));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0164.JPG") == 0) 
      fgBox = boundingBox(point(324,66),point(712,345));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0165.JPG") == 0) 
      fgBox = boundingBox(point(324,66),point(657,397));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0166.JPG") == 0) 
      fgBox = boundingBox(point(324,96),point(671,408));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0167.JPG") == 0) 
      fgBox = boundingBox(point(279,96),point(624,410));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0168.JPG") == 0) 
      fgBox = boundingBox(point(324,126),point(665,446));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0169.JPG") == 0) 
      fgBox = boundingBox(point(9,336),point(817,470));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0170.JPG") == 0) 
      fgBox = boundingBox(point(189,366),point(715,591));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0171.JPG") == 0) 
      fgBox = boundingBox(point(189,66),point(819,238));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0172.JPG") == 0) 
      fgBox = boundingBox(point(9,306),point(391,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0173.JPG") == 0) 
      fgBox = boundingBox(point(54,366),point(762,521));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0174.JPG") == 0) 
      fgBox = boundingBox(point(9,245),point(882,369));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0175.JPG") == 0) 
      fgBox = boundingBox(point(9,245),point(793,387));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0176.JPG") == 0) 
      fgBox = boundingBox(point(9,306),point(656,478));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0177.JPG") == 0) 
      fgBox = boundingBox(point(279,336),point(856,524));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0178.JPG") == 0) 
      fgBox = boundingBox(point(9,396),point(875,521));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0179.JPG") == 0) 
      fgBox = boundingBox(point(9,156),point(328,500));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0180.JPG") == 0) 
      fgBox = boundingBox(point(234,306),point(695,541));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0181.JPG") == 0) 
      fgBox = boundingBox(point(234,366),point(875,535));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0183.JPG") == 0) 
      fgBox = boundingBox(point(279,396),point(866,584));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0184.JPG") == 0) 
      fgBox = boundingBox(point(414,6),point(649,470));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0185.JPG") == 0) 
      fgBox = boundingBox(point(324,36),point(577,464));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0186.JPG") == 0) 
      fgBox = boundingBox(point(324,6),point(562,461));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0187.JPG") == 0) 
      fgBox = boundingBox(point(324,336),point(884,536));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0188.JPG") == 0) 
      fgBox = boundingBox(point(279,36),point(523,480));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0189.JPG") == 0) 
      fgBox = boundingBox(point(234,36),point(511,428));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0190.JPG") == 0) 
      fgBox = boundingBox(point(189,36),point(457,440));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0191.JPG") == 0) 
      fgBox = boundingBox(point(234,6),point(496,421));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0192.JPG") == 0) 
      fgBox = boundingBox(point(234,66),point(542,422));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0193.JPG") == 0) 
      fgBox = boundingBox(point(9,185),point(402,463));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0194.JPG") == 0) 
      fgBox = boundingBox(point(99,96),point(464,393));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0195.JPG") == 0) 
      fgBox = boundingBox(point(189,36),point(496,396));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0196.JPG") == 0) 
      fgBox = boundingBox(point(234,6),point(551,348));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0197.JPG") == 0) 
      fgBox = boundingBox(point(234,6),point(532,376));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0198.JPG") == 0) 
      fgBox = boundingBox(point(144,6),point(824,166));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0199.JPG") == 0) 
      fgBox = boundingBox(point(9,36),point(838,167));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0200.JPG") == 0) 
      fgBox = boundingBox(point(369,6),point(581,517));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0201.JPG") == 0) 
      fgBox = boundingBox(point(414,6),point(635,496));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0202.JPG") == 0) 
      fgBox = boundingBox(point(9,96),point(462,341));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0203.JPG") == 0) 
      fgBox = boundingBox(point(9,66),point(393,348));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0204.JPG") == 0) 
      fgBox = boundingBox(point(279,215),point(881,395));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0205.JPG") == 0) 
      fgBox = boundingBox(point(279,215),point(714,465));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0206.JPG") == 0) 
      fgBox = boundingBox(point(414,185),point(858,430));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0207.JPG") == 0) 
      fgBox = boundingBox(point(234,185),point(854,365));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0208.JPG") == 0) 
      fgBox = boundingBox(point(54,185),point(811,328));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0209.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(892,280));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0210.JPG") == 0) 
      fgBox = boundingBox(point(234,126),point(899,289));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0211.JPG") == 0) 
      fgBox = boundingBox(point(99,6),point(458,308));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0212.JPG") == 0) 
      fgBox = boundingBox(point(99,66),point(527,319));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0213.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(484,234));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0214.JPG") == 0) 
      fgBox = boundingBox(point(324,66),point(561,538));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0215.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(602,522));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0216.JPG") == 0) 
      fgBox = boundingBox(point(234,215),point(563,544));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0217.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(678,521));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0218.JPG") == 0) 
      fgBox = boundingBox(point(505,126),point(896,404));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0219.JPG") == 0) 
      fgBox = boundingBox(point(324,245),point(900,434));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0220.JPG") == 0) 
      fgBox = boundingBox(point(279,245),point(874,427));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0221.JPG") == 0) 
      fgBox = boundingBox(point(9,185),point(527,395));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0222.JPG") == 0) 
      fgBox = boundingBox(point(324,6),point(649,345));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0223.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(272,418));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0224.JPG") == 0) 
      fgBox = boundingBox(point(279,6),point(895,182));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0225.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(875,131));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0226.JPG") == 0) 
      fgBox = boundingBox(point(54,66),point(547,286));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0227.JPG") == 0) 
      fgBox = boundingBox(point(189,366),point(775,551));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0228.JPG") == 0) 
      fgBox = boundingBox(point(189,306),point(750,499));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0229.JPG") == 0) 
      fgBox = boundingBox(point(9,426),point(890,549));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0230.JPG") == 0) 
      fgBox = boundingBox(point(9,426),point(875,551));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0231.JPG") == 0) 
      fgBox = boundingBox(point(144,306),point(892,453));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0232.JPG") == 0) 
      fgBox = boundingBox(point(9,66),point(330,404));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0233.JPG") == 0) 
      fgBox = boundingBox(point(9,66),point(268,484));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new-DSC_0234.JPG") == 0) 
      fgBox = boundingBox(point(505,6),point(863,309));

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0031.JPG") == 0) 
      fgBox = boundingBox(point(234,66),point(443,584));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0034.JPG") == 0) 
      fgBox = boundingBox(point(234,96),point(490,519));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0035.JPG") == 0) 
      fgBox = boundingBox(point(279,156),point(542,578));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0037.JPG") == 0) 
      fgBox = boundingBox(point(279,96),point(499,592));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0039.JPG") == 0) 
      fgBox = boundingBox(point(369,36),point(563,594));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0046.JPG") == 0) 
      fgBox = boundingBox(point(324,185),point(629,552));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0048.JPG") == 0) 
      fgBox = boundingBox(point(369,36),point(605,497));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0049.JPG") == 0) 
      fgBox = boundingBox(point(54,6),point(822,147));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0055.JPG") == 0) 
      fgBox = boundingBox(point(279,6),point(534,432));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0056.JPG") == 0) 
      fgBox = boundingBox(point(54,66),point(349,454));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0059.JPG") == 0) 
      fgBox = boundingBox(point(99,275),point(746,443));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0060.JPG") == 0) 
      fgBox = boundingBox(point(99,275),point(666,466));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0062.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(691,294));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0064.JPG") == 0) 
      fgBox = boundingBox(point(324,66),point(531,589));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0067.JPG") == 0) 
      fgBox = boundingBox(point(279,66),point(521,514));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0069.JPG") == 0) 
      fgBox = boundingBox(point(189,6),point(395,534));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0072.JPG") == 0) 
      fgBox = boundingBox(point(369,156),point(888,365));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0073.JPG") == 0) 
      fgBox = boundingBox(point(189,215),point(561,506));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0074.JPG") == 0) 
      fgBox = boundingBox(point(279,126),point(634,433));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0075.JPG") == 0) 
      fgBox = boundingBox(point(144,156),point(623,382));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0076.JPG") == 0) 
      fgBox = boundingBox(point(234,185),point(757,392));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0077.JPG") == 0) 
      fgBox = boundingBox(point(144,185),point(719,374));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0078.JPG") == 0) 
      fgBox = boundingBox(point(234,185),point(720,408));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0079.JPG") == 0) 
      fgBox = boundingBox(point(144,215),point(720,403));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0080.JPG") == 0) 
      fgBox = boundingBox(point(54,96),point(421,391));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0082.JPG") == 0) 
      fgBox = boundingBox(point(414,6),point(705,378));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0083.JPG") == 0) 
      fgBox = boundingBox(point(460,6),point(739,394));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0084.JPG") == 0) 
      fgBox = boundingBox(point(414,6),point(670,429));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0085.JPG") == 0) 
      fgBox = boundingBox(point(460,6),point(739,394));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0086.JPG") == 0) 
      fgBox = boundingBox(point(324,36),point(550,515));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0087.JPG") == 0) 
      fgBox = boundingBox(point(324,126),point(659,450));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0090.JPG") == 0) 
      fgBox = boundingBox(point(279,66),point(596,408));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0091.JPG") == 0) 
      fgBox = boundingBox(point(234,185),point(606,483));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0093.JPG") == 0) 
      fgBox = boundingBox(point(369,126),point(614,568));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0094.JPG") == 0) 
      fgBox = boundingBox(point(369,6),point(567,571));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0096.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(486,247));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0097.JPG") == 0) 
      fgBox = boundingBox(point(414,6),point(700,385));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0098.JPG") == 0) 
      fgBox = boundingBox(point(54,156),point(497,413));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0099.JPG") == 0) 
      fgBox = boundingBox(point(369,96),point(586,596));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0100.JPG") == 0) 
      fgBox = boundingBox(point(99,126),point(489,411));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0101.JPG") == 0) 
      fgBox = boundingBox(point(234,185),point(752,394));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0102.JPG") == 0) 
      fgBox = boundingBox(point(279,245),point(758,471));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0103.JPG") == 0) 
      fgBox = boundingBox(point(234,66),point(497,478));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0104.JPG") == 0) 
      fgBox = boundingBox(point(324,156),point(615,528));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0105.JPG") == 0) 
      fgBox = boundingBox(point(324,156),point(629,511));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0106.JPG") == 0) 
      fgBox = boundingBox(point(324,126),point(636,473));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0107.JPG") == 0) 
      fgBox = boundingBox(point(234,126),point(515,516));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0109.JPG") == 0) 
      fgBox = boundingBox(point(9,185),point(291,589));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0110.JPG") == 0) 
      fgBox = boundingBox(point(279,6),point(545,413));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0111.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(310,366));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0114.JPG") == 0) 
      fgBox = boundingBox(point(9,215),point(345,539));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0115.JPG") == 0) 
      fgBox = boundingBox(point(9,336),point(547,540));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0116.JPG") == 0) 
      fgBox = boundingBox(point(9,275),point(411,547));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0117.JPG") == 0) 
      fgBox = boundingBox(point(99,156),point(657,350));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0119.JPG") == 0) 
      fgBox = boundingBox(point(189,6),point(461,408));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0120.JPG") == 0) 
      fgBox = boundingBox(point(234,126),point(481,587));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0121.JPG") == 0) 
      fgBox = boundingBox(point(189,66),point(408,580));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0122.JPG") == 0) 
      fgBox = boundingBox(point(234,6),point(420,590));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0126.JPG") == 0) 
      fgBox = boundingBox(point(234,126),point(491,594));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0127.JPG") == 0) 
      fgBox = boundingBox(point(99,6),point(391,377));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0128.JPG") == 0) 
      fgBox = boundingBox(point(54,366),point(637,555));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0130.JPG") == 0) 
      fgBox = boundingBox(point(279,275),point(795,486));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0131.JPG") == 0) 
      fgBox = boundingBox(point(9,245),point(455,488));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0137.JPG") == 0) 
      fgBox = boundingBox(point(99,36),point(868,177));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0139.JPG") == 0) 
      fgBox = boundingBox(point(234,36),point(503,459));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0140.JPG") == 0) 
      fgBox = boundingBox(point(9,66),point(875,191));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0142.JPG") == 0) 
      fgBox = boundingBox(point(9,36),point(883,160));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0143.JPG") == 0) 
      fgBox = boundingBox(point(144,96),point(713,295));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0146.JPG") == 0) 
      fgBox = boundingBox(point(460,6),point(821,306));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0147.JPG") == 0) 
      fgBox = boundingBox(point(144,215),point(449,570));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0148.JPG") == 0) 
      fgBox = boundingBox(point(189,185),point(723,390));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0150.JPG") == 0) 
      fgBox = boundingBox(point(54,215),point(403,526));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0151.JPG") == 0) 
      fgBox = boundingBox(point(9,215),point(385,503));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0152.JPG") == 0) 
      fgBox = boundingBox(point(54,215),point(420,514));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0153.JPG") == 0) 
      fgBox = boundingBox(point(9,215),point(341,544));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0155.JPG") == 0) 
      fgBox = boundingBox(point(144,156),point(407,568));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0156.JPG") == 0) 
      fgBox = boundingBox(point(99,185),point(390,558));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0157.JPG") == 0) 
      fgBox = boundingBox(point(189,215),point(732,415));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0158.JPG") == 0) 
      fgBox = boundingBox(point(144,156),point(538,432));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0159.JPG") == 0) 
      fgBox = boundingBox(point(144,156),point(522,444));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0160.JPG") == 0) 
      fgBox = boundingBox(point(99,185),point(387,563));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0162.JPG") == 0) 
      fgBox = boundingBox(point(9,156),point(339,495));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0163.JPG") == 0) 
      fgBox = boundingBox(point(324,36),point(624,397));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0166.JPG") == 0) 
      fgBox = boundingBox(point(9,306),point(834,438));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0167.JPG") == 0) 
      fgBox = boundingBox(point(54,275),point(558,490));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0173.JPG") == 0) 
      fgBox = boundingBox(point(99,306),point(648,506));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0174.JPG") == 0) 
      fgBox = boundingBox(point(144,275),point(640,498));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0175.JPG") == 0) 
      fgBox = boundingBox(point(54,336),point(900,476));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0176.JPG") == 0) 
      fgBox = boundingBox(point(54,306),point(790,459));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0177.JPG") == 0) 
      fgBox = boundingBox(point(9,336),point(849,465));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0178.JPG") == 0) 
      fgBox = boundingBox(point(9,306),point(726,457));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0179.JPG") == 0) 
      fgBox = boundingBox(point(279,306),point(779,523));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0180.JPG") == 0) 
      fgBox = boundingBox(point(144,306),point(705,505));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0181.JPG") == 0) 
      fgBox = boundingBox(point(99,275),point(577,506));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0182.JPG") == 0) 
      fgBox = boundingBox(point(99,306),point(629,511));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0183.JPG") == 0) 
      fgBox = boundingBox(point(9,306),point(540,511));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0184.JPG") == 0) 
      fgBox = boundingBox(point(54,306),point(580,512));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0185.JPG") == 0) 
      fgBox = boundingBox(point(54,306),point(600,505));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0186.JPG") == 0) 
      fgBox = boundingBox(point(54,306),point(585,510));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0187.JPG") == 0) 
      fgBox = boundingBox(point(54,275),point(533,501));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0188.JPG") == 0) 
      fgBox = boundingBox(point(9,275),point(503,502));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0189.JPG") == 0) 
      fgBox = boundingBox(point(54,245),point(477,502));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0190.JPG") == 0) 
      fgBox = boundingBox(point(9,245),point(437,504));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0191.JPG") == 0) 
      fgBox = boundingBox(point(9,245),point(424,506));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0192.JPG") == 0) 
      fgBox = boundingBox(point(9,306),point(600,509));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0193.JPG") == 0) 
      fgBox = boundingBox(point(54,275),point(543,505));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0196.JPG") == 0) 
      fgBox = boundingBox(point(54,215),point(418,513));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0197.JPG") == 0) 
      fgBox = boundingBox(point(99,6),point(313,529));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0198.JPG") == 0) 
      fgBox = boundingBox(point(144,36),point(387,485));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0199.JPG") == 0) 
      fgBox = boundingBox(point(99,6),point(344,448));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0200.JPG") == 0) 
      fgBox = boundingBox(point(9,96),point(286,491));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0201.JPG") == 0) 
      fgBox = boundingBox(point(144,6),point(341,556));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0202.JPG") == 0) 
      fgBox = boundingBox(point(144,6),point(359,510));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0205.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(241,476));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0209.JPG") == 0) 
      fgBox = boundingBox(point(369,336),point(808,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0214.JPG") == 0) 
      fgBox = boundingBox(point(369,6),point(900,210));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0216.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(875,131));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0218.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(897,128));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0219.JPG") == 0) 
      fgBox = boundingBox(point(189,6),point(897,159));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0220.JPG") == 0) 
      fgBox = boundingBox(point(324,185),point(693,490));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0221.JPG") == 0) 
      fgBox = boundingBox(point(640,6),point(877,463));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0223.JPG") == 0) 
      fgBox = boundingBox(point(324,185),point(627,548));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0224.JPG") == 0) 
      fgBox = boundingBox(point(369,156),point(675,522));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0225.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(891,129));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0226.JPG") == 0) 
      fgBox = boundingBox(point(324,215),point(669,530));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0227.JPG") == 0) 
      fgBox = boundingBox(point(369,185),point(707,508));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0228.JPG") == 0) 
      fgBox = boundingBox(point(369,275),point(803,525));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0229.JPG") == 0) 
      fgBox = boundingBox(point(279,215),point(562,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0231.JPG") == 0) 
      fgBox = boundingBox(point(505,6),point(891,287));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0232.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(559,203));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0233.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(706,163));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0234.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(668,181));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0235.JPG") == 0) 
      fgBox = boundingBox(point(99,6),point(681,210));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0236.JPG") == 0) 
      fgBox = boundingBox(point(414,66),point(667,494));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0237.JPG") == 0) 
      fgBox = boundingBox(point(505,36),point(729,523));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0238.JPG") == 0) 
      fgBox = boundingBox(point(369,275),point(774,543));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0239.JPG") == 0) 
      fgBox = boundingBox(point(369,215),point(814,477));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0240.JPG") == 0) 
      fgBox = boundingBox(point(414,275),point(771,587));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0241.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(582,199));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0243.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(673,172));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0251.JPG") == 0) 
      fgBox = boundingBox(point(550,6),point(767,505));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0252.JPG") == 0) 
      fgBox = boundingBox(point(595,6),point(890,375));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0253.JPG") == 0) 
      fgBox = boundingBox(point(234,185),point(895,350));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0254.JPG") == 0) 
      fgBox = boundingBox(point(189,6),point(455,413));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0255.JPG") == 0) 
      fgBox = boundingBox(point(189,6),point(452,420));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0259.JPG") == 0) 
      fgBox = boundingBox(point(99,126),point(379,513));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0261.JPG") == 0) 
      fgBox = boundingBox(point(144,126),point(396,556));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0262.JPG") == 0) 
      fgBox = boundingBox(point(54,96),point(286,564));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0263.JPG") == 0) 
      fgBox = boundingBox(point(9,185),point(431,445));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0264.JPG") == 0) 
      fgBox = boundingBox(point(9,126),point(486,375));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0265.JPG") == 0) 
      fgBox = boundingBox(point(9,126),point(361,435));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0267.JPG") == 0) 
      fgBox = boundingBox(point(189,96),point(466,488));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0268.JPG") == 0) 
      fgBox = boundingBox(point(9,126),point(811,261));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0269.JPG") == 0) 
      fgBox = boundingBox(point(144,215),point(882,362));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0270.JPG") == 0) 
      fgBox = boundingBox(point(505,6),point(751,447));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0277.JPG") == 0) 
      fgBox = boundingBox(point(640,96),point(861,586));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0278.JPG") == 0) 
      fgBox = boundingBox(point(640,126),point(877,583));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0279.JPG") == 0) 
      fgBox = boundingBox(point(505,156),point(766,579));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0280.JPG") == 0) 
      fgBox = boundingBox(point(460,36),point(684,531));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0281.JPG") == 0) 
      fgBox = boundingBox(point(460,36),point(705,510));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0283.JPG") == 0) 
      fgBox = boundingBox(point(99,366),point(895,502));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new1-DSC_0285.JPG") == 0) 
      fgBox = boundingBox(point(369,156),point(674,511));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0002.JPG") == 0) 
      fgBox = boundingBox(point(54,6),point(731,166));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0004.JPG") == 0) 
      fgBox = boundingBox(point(9,456),point(820,590));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0005.JPG") == 0) 
      fgBox = boundingBox(point(9,36),point(855,164));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0009.JPG") == 0) 
      fgBox = boundingBox(point(9,215),point(604,397));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0010.JPG") == 0) 
      fgBox = boundingBox(point(279,6),point(738,242));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0012.JPG") == 0) 
      fgBox = boundingBox(point(54,215),point(897,344));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0015.JPG") == 0) 
      fgBox = boundingBox(point(685,96),point(901,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0017.JPG") == 0) 
      fgBox = boundingBox(point(369,215),point(730,515));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0029.JPG") == 0) 
      fgBox = boundingBox(point(369,156),point(671,517));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0031.JPG") == 0) 
      fgBox = boundingBox(point(324,6),point(608,390));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0033.JPG") == 0) 
      fgBox = boundingBox(point(685,66),point(891,593));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0034.JPG") == 0) 
      fgBox = boundingBox(point(54,215),point(900,343));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0035.JPG") == 0) 
      fgBox = boundingBox(point(9,245),point(898,367));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0036.JPG") == 0) 
      fgBox = boundingBox(point(9,215),point(900,337));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0037.JPG") == 0) 
      fgBox = boundingBox(point(685,6),point(897,517));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0039.JPG") == 0) 
      fgBox = boundingBox(point(234,396),point(770,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0041.JPG") == 0) 
      fgBox = boundingBox(point(54,245),point(726,407));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0042.JPG") == 0) 
      fgBox = boundingBox(point(9,156),point(617,344));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0043.JPG") == 0) 
      fgBox = boundingBox(point(99,456),point(897,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0046.JPG") == 0) 
      fgBox = boundingBox(point(54,215),point(776,366));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0047.JPG") == 0) 
      fgBox = boundingBox(point(189,126),point(729,328));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0050.JPG") == 0) 
      fgBox = boundingBox(point(279,96),point(859,341));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0051.JPG") == 0) 
      fgBox = boundingBox(point(234,66),point(617,349));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0053.JPG") == 0) 
      fgBox = boundingBox(point(54,66),point(409,371));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0055.JPG") == 0) 
      fgBox = boundingBox(point(54,156),point(691,326));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0057.JPG") == 0) 
      fgBox = boundingBox(point(234,66),point(454,597));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0058.JPG") == 0) 
      fgBox = boundingBox(point(54,36),point(463,301));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0061.JPG") == 0) 
      fgBox = boundingBox(point(9,275),point(654,443));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0066.JPG") == 0) 
      fgBox = boundingBox(point(9,6),point(898,129));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0070.JPG") == 0) 
      fgBox = boundingBox(point(414,366),point(885,596));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0074.JPG") == 0) 
      fgBox = boundingBox(point(234,126),point(643,403));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0075.JPG") == 0) 
      fgBox = boundingBox(point(279,6),point(898,181));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0076.JPG") == 0) 
      fgBox = boundingBox(point(9,275),point(900,397));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0078.JPG") == 0) 
      fgBox = boundingBox(point(9,275),point(897,397));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0080.JPG") == 0) 
      fgBox = boundingBox(point(9,306),point(875,431));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0081.JPG") == 0) 
      fgBox = boundingBox(point(9,245),point(897,367));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0082.JPG") == 0) 
      fgBox = boundingBox(point(189,245),point(617,498));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0084.JPG") == 0) 
      fgBox = boundingBox(point(234,215),point(890,387));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0089.JPG") == 0) 
      fgBox = boundingBox(point(369,156),point(898,367));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0092.JPG") == 0) 
      fgBox = boundingBox(point(9,426),point(659,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0093.JPG") == 0) 
      fgBox = boundingBox(point(144,215),point(426,599));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0094.JPG") == 0) 
      fgBox = boundingBox(point(279,215),point(570,587));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0095.JPG") == 0) 
      fgBox = boundingBox(point(324,6),point(646,343));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0099.JPG") == 0) 
      fgBox = boundingBox(point(99,366),point(581,598));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0100.JPG") == 0) 
      fgBox = boundingBox(point(144,396),point(686,596));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0101.JPG") == 0) 
      fgBox = boundingBox(point(189,366),point(663,595));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0103.JPG") == 0) 
      fgBox = boundingBox(point(99,396),point(641,597));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0106.JPG") == 0) 
      fgBox = boundingBox(point(324,6),point(873,204));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0111.JPG") == 0) 
      fgBox = boundingBox(point(9,275),point(627,545));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0112.JPG") == 0) 
      fgBox = boundingBox(point(324,336),point(841,548));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0113.JPG") == 0) 
      fgBox = boundingBox(point(144,6),point(790,178));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0115.JPG") == 0) 
      fgBox = boundingBox(point(369,185),point(650,573));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0126.JPG") == 0) 
      fgBox = boundingBox(point(414,6),point(667,436));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0129.JPG") == 0) 
      fgBox = boundingBox(point(414,6),point(777,305));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0137.JPG") == 0) 
      fgBox = boundingBox(point(144,185),point(668,392));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0138.JPG") == 0) 
      fgBox = boundingBox(point(9,185),point(546,389));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0141.JPG") == 0) 
      fgBox = boundingBox(point(369,185),point(810,432));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0142.JPG") == 0) 
      fgBox = boundingBox(point(279,6),point(632,313));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0145.JPG") == 0) 
      fgBox = boundingBox(point(279,185),point(855,373));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0147.JPG") == 0) 
      fgBox = boundingBox(point(279,215),point(634,520));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0148.JPG") == 0) 
      fgBox = boundingBox(point(54,185),point(533,411));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0152.JPG") == 0) 
      fgBox = boundingBox(point(9,185),point(780,326));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0153.JPG") == 0) 
      fgBox = boundingBox(point(460,36),point(899,285));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ourdata/new2-DSC_0156.JPG") == 0) 
      fgBox = boundingBox(point(324,96),point(689,393));

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/1843.jpg") == 0) 
      fgBox = boundingBox(point(172,5),point(398,222));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/4992.jpg") == 0) 
      fgBox = boundingBox(point(208,175),point(417,413));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/5267.jpg") == 0) 
      fgBox = boundingBox(point(235,121),point(417,389));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/7041.jpg") == 0) 
      fgBox = boundingBox(point(382,107),point(573,288));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/7398.jpg") == 0) 
      fgBox = boundingBox(point(92,51),point(543,173));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/9017.jpg") == 0) 
      fgBox = boundingBox(point(266,115),point(537,306));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/10621.jpg") == 0) 
      fgBox = boundingBox(point(74,171),point(203,645));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/11086.jpg") == 0) 
      fgBox = boundingBox(point(150,3),point(390,187));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/11663.jpg") == 0) 
      fgBox = boundingBox(point(168,72),point(256,623));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/13055.jpg") == 0) 
      fgBox = boundingBox(point(78,6),point(355,240));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/13063.jpg") == 0) 
      fgBox = boundingBox(point(185,353),point(419,578));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/15673.jpg") == 0) 
      fgBox = boundingBox(point(270,134),point(554,336));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/16148.jpg") == 0) 
      fgBox = boundingBox(point(117,40),point(271,312));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/18862.jpg") == 0) 
      fgBox = boundingBox(point(214,324),point(418,563));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/19817.jpg") == 0) 
      fgBox = boundingBox(point(150,324),point(326,566));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/20365.jpg") == 0) 
      fgBox = boundingBox(point(324,46),point(455,418));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/23173.jpg") == 0) 
      fgBox = boundingBox(point(125,266),point(307,528));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/23798.jpg") == 0) 
      fgBox = boundingBox(point(5,202),point(352,339));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/28221.jpg") == 0) 
      fgBox = boundingBox(point(129,179),point(318,401));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/29021.jpg") == 0) 
      fgBox = boundingBox(point(18,129),point(287,223));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/32059.jpg") == 0) 
      fgBox = boundingBox(point(26,435),point(287,658));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/34048.jpg") == 0) 
      fgBox = boundingBox(point(52,121),point(198,499));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/35045.jpg") == 0) 
      fgBox = boundingBox(point(105,182),point(550,335));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/35089.jpg") == 0) 
      fgBox = boundingBox(point(204,109),point(504,295));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_test/35204.jpg") == 0) 
      fgBox = boundingBox(point(201,5),point(384,283));

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_6219832_335762c361_b.jpg") == 0) 
      fgBox = boundingBox(point(112,468),point(640,766));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_7620245_0255136806_b.jpg") == 0) 
      fgBox = boundingBox(point(522,238),point(867,694));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_51321909_2dbba9e35e_o.jpg") == 0) 
      fgBox = boundingBox(point(266,237),point(755,560));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_apple-tree-2.jpg") == 0) 
      fgBox = boundingBox(point(6,290),point(320,601));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_BMW-Z8.jpg") == 0) 
      fgBox = boundingBox(point(208,275),point(761,449));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/1_Cowandcalf20.jpg") == 0) 
      fgBox = boundingBox(point(449,587),point(1726,900));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_99.01.violin.jpg") == 0) 
      fgBox = boundingBox(point(163,629),point(772,1146));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_000394_l.jpg") == 0) 
      fgBox = boundingBox(point(99,912),point(857,1197));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_21331105_32634c8e0c_b.jpg") == 0) 
      fgBox = boundingBox(point(7,573),point(715,781));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_51382800_5b257b7196_o.jpg") == 0) 
      fgBox = boundingBox(point(522,84),point(945,456));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_56321495_382f0c36f8_o.jpg") == 0) 
      fgBox = boundingBox(point(732,48),point(1057,640));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/2_F1000005.jpg") == 0) 
      fgBox = boundingBox(point(317,349),point(877,600));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_8362383_76855a026d_o.jpg") == 0) 
      fgBox = boundingBox(point(88,109),point(291,521));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_26028292_d2b7a32e1c_o.jpg") == 0) 
      fgBox = boundingBox(point(112,236),point(581,397));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_56391069_f224b7cfdc_o.jpg") == 0) 
      fgBox = boundingBox(point(36,306),point(308,578));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_59680439_3093a00838_o.jpg") == 0) 
      fgBox = boundingBox(point(215,276),point(629,656));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_cow-and-coastal-mountains-70.4.jpg") == 0) 
      fgBox = boundingBox(point(715,484),point(1304,1041));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/3_NYC_New_York_Liberty_Statue_b.jpg") == 0) 
      fgBox = boundingBox(point(311,270),point(614,1007));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_005 Statue of Liberty.jpg") == 0) 
      fgBox = boundingBox(point(139,96),point(277,489));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_1294081_bdf11afec3_o.jpg") == 0) 
      fgBox = boundingBox(point(208,6),point(474,419));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_30156988_73ccdb9b53_b.jpg") == 0) 
      fgBox = boundingBox(point(61,382),point(917,548));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_30250725_6554321391_o.jpg") == 0) 
      fgBox = boundingBox(point(7,410),point(622,562));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_56904923_b790a0b060_o.jpg") == 0) 
      fgBox = boundingBox(point(189,131),point(705,308));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/4_57070363_5529a4ae88_o.jpg") == 0) 
      fgBox = boundingBox(point(98,260),point(422,812));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/46_57854854_2f6dcdf3a1_b.jpg") == 0) 
      fgBox = boundingBox(point(419,143),point(735,599));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/47_rose-2.jpg") == 0) 
      fgBox = boundingBox(point(256,132),point(1366,478));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/48_44661953_96ccc6caf5_o.jpg") == 0) 
      fgBox = boundingBox(point(375,148),point(605,405));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/49_Roseblanchelisererose800.jpg") == 0) 
      fgBox = boundingBox(point(327,96),point(526,583));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/51_pickingapple044.jpg") == 0) 
      fgBox = boundingBox(point(48,6),point(460,240));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/52_AppleEgremontRusset.jpg") == 0) 
      fgBox = boundingBox(point(670,36),point(875,556));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/53_Apple6.jpg") == 0) 
      fgBox = boundingBox(point(17,855),point(1720,1111));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/54_CodlingMothBite7K.jpg") == 0) 
      fgBox = boundingBox(point(295,6),point(542,464));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/58_00.07.eli.violin.jpg") == 0) 
      fgBox = boundingBox(point(633,69),point(1362,630));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/59_3530244_a6924d938c_b.jpg") == 0) 
      fgBox = boundingBox(point(266,84),point(689,456));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/60_VictoriaPlayingViolin.jpg") == 0) 
      fgBox = boundingBox(point(655,431),point(1599,838));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/61_playingviolinedited.jpg") == 0) 
      fgBox = boundingBox(point(161,368),point(491,845));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/62_01-ILikeThisBMW.jpg") == 0) 
      fgBox = boundingBox(point(8,36),point(770,163));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/63_3-bmw318i-991.jpg") == 0) 
      fgBox = boundingBox(point(275,5),point(640,282));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/64_BMWC1.jpg") == 0) 
      fgBox = boundingBox(point(215,238),point(651,671));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/65_9744484_90e44a2890_o.jpg") == 0) 
      fgBox = boundingBox(point(30,23),point(401,129));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/65_Statue of Liberty BZs.jpg") == 0) 
      fgBox = boundingBox(point(201,204),point(578,856));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/66_statue-of-liberty 12.jpg") == 0) 
      fgBox = boundingBox(point(3,216),point(279,307));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/67_1333234_7510a7b757_o.jpg") == 0) 
      fgBox = boundingBox(point(110,230),point(308,505));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/67_Statue of Liberty (1).jpg") == 0) 
      fgBox = boundingBox(point(61,122),point(556,440));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/68_DSC04343-cow.jpg") == 0) 
      fgBox = boundingBox(point(8,426),point(583,593));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/68_statue-of-liberty 2.jpg") == 0) 
      fgBox = boundingBox(point(735,312),point(1404,886));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/69_36370488_c5e200c8f6_o.jpg") == 0) 
      fgBox = boundingBox(point(27,6),point(449,134));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/ke/70_CowMoose.jpg") == 0) 
      fgBox = boundingBox(point(604,119),point(847,519));

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/cluster/DSC_0329.jpg") == 0) 
      fgBox = boundingBox(point(247,5),point(471,409));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/cluster/DSC_0330.jpg") == 0) 
      fgBox = boundingBox(point(247,32),point(521,345));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/cluster/DSC_0331.jpg") == 0) 
      fgBox = boundingBox(point(208,5),point(609,219));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/cluster/DSC_0332.jpg") == 0) 
      fgBox = boundingBox(point(168,5),point(521,248));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/cluster/DSC_0333.jpg") == 0) 
      fgBox = boundingBox(point(168,5),point(481,279));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/cluster/DSC_0334.jpg") == 0) 
      fgBox = boundingBox(point(327,32),point(726,247));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/cluster/DSC_0335.jpg") == 0) 
      fgBox = boundingBox(point(128,5),point(430,289));

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/exposuretest/DSC_0342-16.jpg") == 0) 
      fgBox = boundingBox(point(350,6),point(655,427));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/exposuretest/DSC_0342-17.jpg") == 0) 
      fgBox = boundingBox(point(594,202),point(910,605));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/exposuretest/DSC_0342-18.jpg") == 0) 
      fgBox = boundingBox(point(546,137),point(883,537));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/exposuretest/DSC_0342-19.jpg") == 0) 
      fgBox = boundingBox(point(448,137),point(827,473));

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/1299.jpg") == 0) 
      fgBox = boundingBox(point(14,47),point(81,214));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/1324.jpg") == 0) 
      fgBox = boundingBox(point(32,14),point(160,57));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/1463.jpg") == 0) 
      fgBox = boundingBox(point(255,2),point(331,260));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/2823.jpg") == 0) 
      fgBox = boundingBox(point(5,109),point(513,207));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/2876.jpg") == 0) 
      fgBox = boundingBox(point(179,76),point(548,191));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/3309.jpg") == 0) 
      fgBox = boundingBox(point(133,87),point(496,209));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/6951.jpg") == 0) 
      fgBox = boundingBox(point(4,5),point(152,396));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/7325.jpg") == 0) 
      fgBox = boundingBox(point(161,100),point(423,211));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/9407.jpg") == 0) 
      fgBox = boundingBox(point(123,295),point(299,500));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/10257.jpg") == 0) 
      fgBox = boundingBox(point(105,33),point(205,87));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/15596.jpg") == 0) 
      fgBox = boundingBox(point(5,3),point(165,270));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/16789.jpg") == 0) 
      fgBox = boundingBox(point(194,193),point(538,325));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/16893.jpg") == 0) 
      fgBox = boundingBox(point(63,37),point(563,116));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/19619.jpg") == 0) 
      fgBox = boundingBox(point(5,40),point(164,310));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/20076.jpg") == 0) 
      fgBox = boundingBox(point(5,130),point(576,224));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/bad_test/20346.jpg") == 0) 
      fgBox = boundingBox(point(150,109),point(356,349));

    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/2598.jpg") == 0) 
      fgBox = boundingBox(point(179,288),point(487,501));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/2699.jpg") == 0) 
      fgBox = boundingBox(point(105,25),point(256,400));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/6035.jpg") == 0) 
      fgBox = boundingBox(point(353,68),point(535,342));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/6898.jpg") == 0) 
      fgBox = boundingBox(point(68,353),point(407,499));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/9580.jpg") == 0) 
      fgBox = boundingBox(point(179,95),point(371,317));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/13384.jpg") == 0) 
      fgBox = boundingBox(point(4,204),point(404,346));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/13553.jpg") == 0) 
      fgBox = boundingBox(point(208,277),point(554,418));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/15689.jpg") == 0) 
      fgBox = boundingBox(point(34,84),point(323,273));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/15995.jpg") == 0) 
      fgBox = boundingBox(point(5,157),point(574,227));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/18432.jpg") == 0) 
      fgBox = boundingBox(point(208,402),point(450,657));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/18707.jpg") == 0) 
      fgBox = boundingBox(point(150,3),point(357,212));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/21600.jpg") == 0) 
      fgBox = boundingBox(point(179,46),point(539,185));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/21997.jpg") == 0) 
      fgBox = boundingBox(point(121,115),point(343,311));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/22183.jpg") == 0) 
      fgBox = boundingBox(point(204,34),point(353,319));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/22955.jpg") == 0) 
      fgBox = boundingBox(point(6,205),point(279,400));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/23460.jpg") == 0) 
      fgBox = boundingBox(point(179,148),point(525,278));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/23954.jpg") == 0) 
      fgBox = boundingBox(point(6,162),point(641,256));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/24865.jpg") == 0) 
      fgBox = boundingBox(point(34,252),point(492,342));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/26263.jpg") == 0) 
      fgBox = boundingBox(point(58,237),point(300,421));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/27713.jpg") == 0) 
      fgBox = boundingBox(point(121,301),point(467,490));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/28751.jpg") == 0) 
      fgBox = boundingBox(point(6,88),point(294,284));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/29501.jpg") == 0) 
      fgBox = boundingBox(point(121,3),point(473,124));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/29971.jpg") == 0) 
      fgBox = boundingBox(point(34,256),point(558,349));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/30369.jpg") == 0) 
      fgBox = boundingBox(point(150,172),point(405,390));
    else if(strcmp(vim->getFilename(), "/home/artoonie/I/results/data/good_training/33069.jpg") == 0) 
      fgBox = boundingBox(point(179,277),point(525,418));

    return fgBox;
}

#endif // BOUNDINGBOXPRESETS_H
