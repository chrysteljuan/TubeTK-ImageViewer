/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    liVesselsRegistrator.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
//--------------------------------------------
//
//     Project: Operating Room
//
//     Author:  Luis Ibanez
//
//     Division of Neurosugery
//     Department of Surgery
//     University of North Carolina
//     Chapel Hill, NC 27599
//
//--------------------------------------------

#ifndef liVESSELSREGISTRATORCLASS
#define liVESSELSREGISTRATORCLASS

#include "liVectorTubes3D.h"
#include "itkImage.h"
#include "itkPointSetToImageRigid3DPerspectivePatternIntensityRegularStepGradientDescentRegistration.h"


namespace li {


/**  This class implements a Registration method */
class ITK_EXPORT VesselsRegistrator : public itk::Object 
{
public:
  /** Standard class typedefs. */
  typedef VesselsRegistrator   Self;
  typedef itk::Object  Superclass;
  typedef itk::SmartPointer<Self>  Pointer;
  typedef itk::SmartPointer<const Self>  ConstPointer;

  /** PointSet type */
  typedef PointSet3D::PointSetType  PointSetType;
  
  /*** Fluoroscopic image type  */
  typedef itk::Image<unsigned char, 2> FluoroscopicImageType;
  //typedef itk::Image<unsigned short, 2> FluoroscopicImageType;

  /*** PointSet / Fluoroscopic Image Registration Method */
  typedef itk::PointSetToImageRigid3DPerspectivePatternIntensityRegularStepGradientDescentRegistration<FluoroscopicImageType,PointSetType>  RegistrationMethod;

  /** Registration Optimizer */
   typedef  RegistrationMethod::OptimizerType  RegistrationOptimizer;

  /** Run-time type information (and related methods). */
  itkTypeMacro( VesselsRegistrator, Object );

  /** Method for creation through the object factory. */
  itkNewMacro( Self );
        
  /**  Get the Vessels */
  VectorTubes3D::Pointer GetVessels( void );

  /**  Set the Vessels */
  void SetVessels( VectorTubes3D  * vessels );
  
  /**  Set the Fluoroscopic image */
  void SetImage( FluoroscopicImageType  * image );

  /**  Get the  Registrator */
  RegistrationMethod::Pointer GetRegistrator(void);
        
protected:
  /**  Constructor */
  VesselsRegistrator();

  /**  Destructor */
  ~VesselsRegistrator();

private:
  /**  Model of the Vertebral Segment */
  VectorTubes3D::Pointer        m_Vessels;

  /**  Registration method for PointSet / Fluoroscopic Image */
  RegistrationMethod::Pointer   m_Registrator;

  /**  Fluoroscopic Image  */
  FluoroscopicImageType::Pointer  m_Image;

};

} // end namespace li

#endif




