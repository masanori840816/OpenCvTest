//
//  ViewMovie.cpp
//  OpenCvTest
//
//  Created by masanori on 2014/03/02.
//  Copyright (c) 2014年 masanori. All rights reserved.
//

#include "viewMovie.h"

int ViewMovie::viewMovies(){
    cv::VideoCapture vdcCapture(strFileName);
    // ファイルが見つからなければエラー
    if(!vdcCapture.isOpened()){
        std::cout << "Could not open any files";
        return -1;
    }
    cv::namedWindow("Movies", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
    while(1) {
        cv::Mat matFrame;
        vdcCapture >> matFrame;
        
        // 再生が終了したら閉じる
        if(matFrame.empty()){
            std::cout << "Finished";
            break;
        }
        // ウインドウに映像を表示する
        cv::imshow("Movies", matFrame);
        
        // Escapeキー押下で閉じる
        if(cv::waitKey(10) == 27){
            break;
        }
    }
    return 0;
}