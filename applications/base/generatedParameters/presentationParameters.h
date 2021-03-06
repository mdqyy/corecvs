#ifndef PRESENTATION_PARAMETERS_H_
#define PRESENTATION_PARAMETERS_H_
/**
 * \file presentationParameters.h
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "reflection.h"
#include "defaultSetter.h"
#include "printerVisitor.h"

/*
 *  Embed includes.
 */
/*
 *  Additional includes for Composite Types.
 */

using namespace corecvs;

/*
 *  Additional includes for Pointer Types.
 */

namespace corecvs {
}
/*
 *  Additional includes for enum section.
 */
#include "stereoStyle.h"
#include "flowStyle.h"
#include "outputStyle.h"

/**
 * \brief Presentation parameters 
 * Presentation parameters 
 **/
class PresentationParameters : public BaseReflection<PresentationParameters>
{
public:
    enum FieldId {
        LEFTFRAME_ID,
        RIGHTFRAME_ID,
        STEREO_ID,
        FLOW_ID,
        OUTPUT_ID,
        SHOWCLUSTERS_ID,
        SHOWHISTOGRAM_ID,
        AUTO_UPDATE_HISTOGRAM_ID,
        SHOWAREAOFINTEREST_ID,
        PRODUCE3D_ID,
        PRODUCE6D_ID,
        DUMP3D_ID,
        PRESENTATION_PARAMETERS_FIELD_ID_NUM
    };

    /** Section with variables */

    /** 
     * \brief leftFrame 
     * leftFrame 
     */
    bool mLeftFrame;

    /** 
     * \brief rightFrame 
     * rightFrame 
     */
    bool mRightFrame;

    /** 
     * \brief Stereo 
     * Stereo 
     */
    int mStereo;

    /** 
     * \brief Flow 
     * Flow 
     */
    int mFlow;

    /** 
     * \brief Output 
     * Output 
     */
    int mOutput;

    /** 
     * \brief showClusters 
     * showClusters 
     */
    bool mShowClusters;

    /** 
     * \brief showHistogram 
     * showHistogram 
     */
    bool mShowHistogram;

    /** 
     * \brief Auto Update Histogram 
     * Auto Update Histogram 
     */
    bool mAutoUpdateHistogram;

    /** 
     * \brief showAreaOfInterest 
     * showAreaOfInterest 
     */
    bool mShowAreaOfInterest;

    /** 
     * \brief produce3D 
     * produce3D 
     */
    bool mProduce3D;

    /** 
     * \brief produce6D 
     * produce6D 
     */
    bool mProduce6D;

    /** 
     * \brief dump3D 
     * dump3D 
     */
    bool mDump3D;

    /** Static fields init function, this is used for "dynamic" field initialization */ 
    static int staticInit();

    /** Section with getters */
    const void *getPtrById(int fieldId) const
    {
        return (const unsigned char *)(this) + fields()[fieldId]->offset;
    }
    bool leftFrame() const
    {
        return mLeftFrame;
    }

    bool rightFrame() const
    {
        return mRightFrame;
    }

    StereoStyle::StereoStyle stereo() const
    {
        return static_cast<StereoStyle::StereoStyle>(mStereo);
    }

    FlowStyle::FlowStyle flow() const
    {
        return static_cast<FlowStyle::FlowStyle>(mFlow);
    }

    OutputStyle::OutputStyle output() const
    {
        return static_cast<OutputStyle::OutputStyle>(mOutput);
    }

    bool showClusters() const
    {
        return mShowClusters;
    }

    bool showHistogram() const
    {
        return mShowHistogram;
    }

    bool autoUpdateHistogram() const
    {
        return mAutoUpdateHistogram;
    }

    bool showAreaOfInterest() const
    {
        return mShowAreaOfInterest;
    }

    bool produce3D() const
    {
        return mProduce3D;
    }

    bool produce6D() const
    {
        return mProduce6D;
    }

    bool dump3D() const
    {
        return mDump3D;
    }

    /* Section with setters */
    void setLeftFrame(bool leftFrame)
    {
        mLeftFrame = leftFrame;
    }

    void setRightFrame(bool rightFrame)
    {
        mRightFrame = rightFrame;
    }

    void setStereo(StereoStyle::StereoStyle stereo)
    {
        mStereo = stereo;
    }

    void setFlow(FlowStyle::FlowStyle flow)
    {
        mFlow = flow;
    }

    void setOutput(OutputStyle::OutputStyle output)
    {
        mOutput = output;
    }

    void setShowClusters(bool showClusters)
    {
        mShowClusters = showClusters;
    }

    void setShowHistogram(bool showHistogram)
    {
        mShowHistogram = showHistogram;
    }

    void setAutoUpdateHistogram(bool autoUpdateHistogram)
    {
        mAutoUpdateHistogram = autoUpdateHistogram;
    }

    void setShowAreaOfInterest(bool showAreaOfInterest)
    {
        mShowAreaOfInterest = showAreaOfInterest;
    }

    void setProduce3D(bool produce3D)
    {
        mProduce3D = produce3D;
    }

    void setProduce6D(bool produce6D)
    {
        mProduce6D = produce6D;
    }

    void setDump3D(bool dump3D)
    {
        mDump3D = dump3D;
    }

    /* Section with embedded classes */
    /* visitor pattern - http://en.wikipedia.org/wiki/Visitor_pattern */
template<class VisitorType>
    void accept(VisitorType &visitor)
    {
        visitor.visit(mLeftFrame,                 static_cast<const BoolField *>    (fields()[LEFTFRAME_ID]));
        visitor.visit(mRightFrame,                static_cast<const BoolField *>    (fields()[RIGHTFRAME_ID]));
        visitor.visit((int &)mStereo,             static_cast<const EnumField *>    (fields()[STEREO_ID]));
        visitor.visit((int &)mFlow,               static_cast<const EnumField *>    (fields()[FLOW_ID]));
        visitor.visit((int &)mOutput,             static_cast<const EnumField *>    (fields()[OUTPUT_ID]));
        visitor.visit(mShowClusters,              static_cast<const BoolField *>    (fields()[SHOWCLUSTERS_ID]));
        visitor.visit(mShowHistogram,             static_cast<const BoolField *>    (fields()[SHOWHISTOGRAM_ID]));
        visitor.visit(mAutoUpdateHistogram,       static_cast<const BoolField *>    (fields()[AUTO_UPDATE_HISTOGRAM_ID]));
        visitor.visit(mShowAreaOfInterest,        static_cast<const BoolField *>    (fields()[SHOWAREAOFINTEREST_ID]));
        visitor.visit(mProduce3D,                 static_cast<const BoolField *>    (fields()[PRODUCE3D_ID]));
        visitor.visit(mProduce6D,                 static_cast<const BoolField *>    (fields()[PRODUCE6D_ID]));
        visitor.visit(mDump3D,                    static_cast<const BoolField *>    (fields()[DUMP3D_ID]));
    }

    PresentationParameters()
    {
        DefaultSetter setter;
        accept(setter);
    }

    PresentationParameters(
          bool leftFrame
        , bool rightFrame
        , StereoStyle::StereoStyle stereo
        , FlowStyle::FlowStyle flow
        , OutputStyle::OutputStyle output
        , bool showClusters
        , bool showHistogram
        , bool autoUpdateHistogram
        , bool showAreaOfInterest
        , bool produce3D
        , bool produce6D
        , bool dump3D
    )
    {
        mLeftFrame = leftFrame;
        mRightFrame = rightFrame;
        mStereo = stereo;
        mFlow = flow;
        mOutput = output;
        mShowClusters = showClusters;
        mShowHistogram = showHistogram;
        mAutoUpdateHistogram = autoUpdateHistogram;
        mShowAreaOfInterest = showAreaOfInterest;
        mProduce3D = produce3D;
        mProduce6D = produce6D;
        mDump3D = dump3D;
    }

    friend ostream& operator << (ostream &out, PresentationParameters &toSave)
    {
        PrinterVisitor printer(out);
        toSave.accept<PrinterVisitor>(printer);
        return out;
    }

    void print ()
    {
        cout << *this;
    }
};
#endif  //PRESENTATION_PARAMETERS_H_
