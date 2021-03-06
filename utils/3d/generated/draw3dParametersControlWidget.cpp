/**
 * \file draw3dParametersControlWidget.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "draw3dParametersControlWidget.h"
#include "ui_draw3dParametersControlWidget.h"
#include "qSettingsGetter.h"
#include "qSettingsSetter.h"

#include "rgbColorParametersControlWidget.h"
#include "rgbColorParametersControlWidget.h"

Draw3dParametersControlWidget::Draw3dParametersControlWidget(QWidget *parent, bool _autoInit, QString _rootPath)
    : ParametersControlWidgetBase(parent)
    , mUi(new Ui::Draw3dParametersControlWidget)
    , autoInit(_autoInit)
    , rootPath(_rootPath)
{
    mUi->setupUi(this);

    QObject::connect(mUi->styleComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->colorControlWidget, SIGNAL(paramsChanged()), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->secondaryColorControlWidget, SIGNAL(paramsChanged()), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->textureCorrodinatesComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->textureAlphaSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->textureScaleSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->decalMatrixTypeSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->decalLeftCamCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->decalLeftAlphaSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->decalRightCamCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->decalRightAlphaSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(paramsChanged()));
}

Draw3dParametersControlWidget::~Draw3dParametersControlWidget()
{

    delete mUi;
}

void Draw3dParametersControlWidget::loadParamWidget(WidgetLoader &loader)
{
    Draw3dParameters *params = createParameters();
    loader.loadParameters(*params, rootPath);
    setParameters(*params);
    delete params;
}

void Draw3dParametersControlWidget::saveParamWidget(WidgetSaver  &saver)
{
    Draw3dParameters *params = createParameters();
    saver.saveParameters(*params, rootPath);
    delete params;
}


Draw3dParameters *Draw3dParametersControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/

    RgbColorParameters *tmp1 = NULL;
    RgbColorParameters *tmp2 = NULL;

    Draw3dParameters *result = new Draw3dParameters(
          static_cast<Draw3dStyle::Draw3dStyle>(mUi->styleComboBox->currentIndex())
        , * (tmp1 = mUi->colorControlWidget->createParameters())
        , * (tmp2 = mUi->secondaryColorControlWidget->createParameters())
        , static_cast<Draw3dTextureGen::Draw3dTextureGen>(mUi->textureCorrodinatesComboBox->currentIndex())
        , mUi->textureAlphaSpinBox->value()
        , mUi->textureScaleSpinBox->value()
        , mUi->decalMatrixTypeSpinBox->value()
        , mUi->decalLeftCamCheckBox->isChecked()
        , mUi->decalLeftAlphaSpinBox->value()
        , mUi->decalRightCamCheckBox->isChecked()
        , mUi->decalRightAlphaSpinBox->value()
    );
    delete tmp1;
    delete tmp2;
    return result;
}

void Draw3dParametersControlWidget::setParameters(const Draw3dParameters &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);
    mUi->styleComboBox->setCurrentIndex(input.style());
    mUi->colorControlWidget->setParameters(input.color());
    mUi->secondaryColorControlWidget->setParameters(input.secondaryColor());
    mUi->textureCorrodinatesComboBox->setCurrentIndex(input.textureCorrodinates());
    mUi->textureAlphaSpinBox->setValue(input.textureAlpha());
    mUi->textureScaleSpinBox->setValue(input.textureScale());
    mUi->decalMatrixTypeSpinBox->setValue(input.decalMatrixType());
    mUi->decalLeftCamCheckBox->setChecked(input.decalLeftCam());
    mUi->decalLeftAlphaSpinBox->setValue(input.decalLeftAlpha());
    mUi->decalRightCamCheckBox->setChecked(input.decalRightCam());
    mUi->decalRightAlphaSpinBox->setValue(input.decalRightAlpha());
    blockSignals(wasBlocked);
    emit paramsChanged();
}

void Draw3dParametersControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    Draw3dParameters *inputCasted = static_cast<Draw3dParameters *>(input);
    setParameters(*inputCasted);
}
