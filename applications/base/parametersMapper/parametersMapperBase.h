#ifndef PARAMETERS_MAPPER_BASE_H_
#define PARAMETERS_MAPPER_BASE_H_
/**
 * \file parametersMapperBase.h
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include <iostream>
#include <QtCore/QSharedPointer>

#include "reflection.h"
#include "defaultSetter.h"

#include "baseParametersControlWidget.h"
#include "presentationParametersControlWidget.h"

class ParametersMapperBase : public QObject
{
    Q_OBJECT
public:
    ParametersMapperBase();

    void setBaseParametersControlWidget(BaseParametersControlWidget *widget);
    void setPresentationParametersControlWidget(PresentationParametersControlWidget *widget);

public slots:
    void paramsChanged();

signals:
    void baseParametersParamsChanged(QSharedPointer<BaseParameters> params);
    void presentationParametersParamsChanged(QSharedPointer<PresentationParameters> params);

private:
    BaseParametersControlWidget *mBaseParametersControlWidget;
    PresentationParametersControlWidget *mPresentationParametersControlWidget;
};
#endif //PARAMETERS_MAPPER_BASE_H_
