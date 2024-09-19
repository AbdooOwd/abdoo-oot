#include "playground_scene.h"
#include "z64cutscene.h"
#include "z64cutscene_commands.h"


CutsceneData playground_introCS[] = {
    CS_BEGIN_CUTSCENE(2, 152),
        CS_CAM_EYE_SPLINE(0, 151),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 0, 60.0f, 56, 0, 0, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 0, 60.0f, 112, 0, -50, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 0, 60.0f, -232, -80, 104, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 0, 60.0f, -236, -90, 154, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 0, 60.0f, -60, -25, 9, 0),
            CS_CAM_POINT(CS_CAM_STOP, 0, 0, 0.0f, 0, 0, 0, 0),
        CS_CAM_AT_SPLINE(0, 180),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 30, 60.0f, 56, 0, -56, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 30, 60.0f, 112, 0, -106, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 30, 60.0f, -232, -80, 160, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 30, 60.0f, -236, -90, 210, 0),
            CS_CAM_POINT(CS_CAM_CONTINUE, 0, 30, 60.0f, -114, -25, 24, 0),
            CS_CAM_POINT(CS_CAM_STOP, 0, 0, 0.0f, 0, 0, 0, 0),
    CS_END(),
};

